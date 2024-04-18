#include "pch.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI(void)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
        grupEstudiService = gcnew GrupEstudiService();
        //this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    /*void GrupEstudi_ConsultarUI::CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        this->Hide();
		MainPageUI^ form = gcnew MainPageUI();
		form->ShowDialog();
		this->Close();
    }*/

    void GrupEstudi_ConsultarUI::EliminarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        //dialog message box with an input to confirm the deletion of the group by introducing the group name
        //if the group name is correct, the group will be deleted
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir el grup '" + Noms_ListBox->Text + "'?", "Confirmation", buttons);

        // Check the user's response
        if (result == System::Windows::Forms::DialogResult::Yes)
        {
            try {
                grupEstudiService->DeleteGrupEstudi(Noms_ListBox->Text);
                MessageManager::InfoMessage("Grup eliminat correctament.");
                // Reload the list of groups after deletion
                GrupEstudi_ConsultarUIreload();


            }
            catch (Exception^ e) {
                MessageManager::ErrorMessage(e->Message);
            }


        }
    }

    void GrupEstudi_ConsultarUI::EditarButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
    		GrupEstudi_EditarUI^ PanelUI = gcnew GrupEstudi_EditarUI(Noms_ListBox->Text);

            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
    }

    void GrupEstudi_ConsultarUI::consulta_membres_Click(System::Object^ sender, System::EventArgs^ e)
    {

        GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(Noms_ListBox->Text);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void GrupEstudi_ConsultarUI::Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        bool isOwner = grupEstudiService->CheckUserIsOwner(Noms_ListBox->Text);

        if (isOwner) {
            Editar_Button->Visible = true;
            Eliminar_Button->Visible = true;
            consulta_membres->Visible = true;
        }
        if (not isOwner and Noms_ListBox->Text != "") {
            Editar_Button->Visible = false;
            Eliminar_Button->Visible = false;
            consulta_membres->Visible = true;
        }
    }

    void GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUIreload() {
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        array<Int64^>^ arrayIdGroupEstudisOfUser = grupEstudiMembershipService->LoadGrupsEstudiMembershipByUserId(currentUser->GetUserId());

        // Limpiar el ListBox antes de cargar los nuevos grupos
        Noms_ListBox->Items->Clear();

        for (int i = 0; i < arrayIdGroupEstudisOfUser->Length; i++) {
            GrupEstudi^ grupEstudiUser = grupEstudiMembershipService->LoadAllGrupEstudibyId(arrayIdGroupEstudisOfUser[i]);
            Noms_ListBox->Items->Add(grupEstudiUser->GetGroupName());
        }

        //Falta que el estudiant pugui gestionar els grups d'estudi que te
    }

    void GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_ConsultarUIreload();
    }
}

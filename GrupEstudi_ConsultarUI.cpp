#include "pch.h"
#include "GrupEstudi_ConsultarUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI(void)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
        grupEstudiService = gcnew GrupEstudiService();
    }
    void GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        //this->Close();

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

    void GrupEstudi_ConsultarUI::CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        this->Close();
    }

    void GrupEstudi_ConsultarUI::Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        bool isOwner = grupEstudiService->CheckUserIsOwner(Noms_ListBox->Text);

        if (isOwner) {
			Editar_Button->Visible = true;
			Eliminar_Button->Visible = true;
		}
    }

    void GrupEstudi_ConsultarUI::EliminarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        //dialog message box with an input to confirm the deletion of the group by introducing the group name
        //if the group name is correct, the group will be deleted
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir el grup '"+ Noms_ListBox->Text +"'?", "Confirmation", buttons);

        // Check the user's response
        if (result == System::Windows::Forms::DialogResult::Yes)
        {
            try {
                grupEstudiService->DeleteGrupEstudi(Noms_ListBox->Text);
                MessageManager::InfoMessage("Grup eliminat correctament.");
                //FIXME: este refresh no va
                this->Refresh();
            }
            catch (Exception^ e) {
				MessageManager::ErrorMessage(e->Message);
			}
            
            
        }
	}

    void GrupEstudi_ConsultarUI::EditarButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
    		this->Hide();
    		GrupEstudi_EditarUI^ form = gcnew GrupEstudi_EditarUI();
            form->ShowDialog();
            this->Show();
    }
}

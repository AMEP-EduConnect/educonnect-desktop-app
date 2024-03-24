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
        listaNoms->Items->Clear();

        for (int i = 0; i < arrayIdGroupEstudisOfUser->Length; i++) {
            GrupEstudi^ grupEstudiUser = grupEstudiMembershipService->LoadAllGrupEstudibyId(arrayIdGroupEstudisOfUser[i]);
            listaNoms->Items->Add(grupEstudiUser->GetGroupName());
        }

        //Falta que el estudiant pugui gestionar els grups d'estudi que te
	}

    void GrupEstudi_ConsultarUI::button_Cancel(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        this->Close();
    }

    void GrupEstudi_ConsultarUI::listaNoms_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        bool isOwner = grupEstudiService->CheckUserIsOwner(currentUser->GetUserId(), listaNoms->Text);

        if (isOwner) {
			EditarButton->Visible = true;
			EliminarButton->Visible = true;
		}
    }

    void GrupEstudi_ConsultarUI::EliminarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        //dialog message box with an input to confirm the deletion of the group by introducing the group name
        //if the group name is correct, the group will be deleted
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir el grup '"+ listaNoms->Text +"'?", "Confirmation", buttons);

        // Check the user's response
        if (result == System::Windows::Forms::DialogResult::Yes)
        {
            try {
                grupEstudiService->DeleteGrupEstudi(listaNoms->Text);
                MessageManager::InfoMessage("Grup eliminat correctament.");
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

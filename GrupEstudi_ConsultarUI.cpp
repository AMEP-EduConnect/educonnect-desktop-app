#include "pch.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "Usuari.h"


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
            abandonar_button->Visible = true;
        }
        if (not isOwner and Noms_ListBox->Text != "") {
            Editar_Button->Visible = false;
            Eliminar_Button->Visible = false;
            consulta_membres->Visible = true;
            abandonar_button->Visible = true;
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

    void GrupEstudi_ConsultarUI::abandonar_button_Click(System::Object^ sender, System::EventArgs^ e) {
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        String^ user_name = currentUser->GetName();
            if (Noms_ListBox->Text != "") {
                if (grupEstudiService->CheckIfUserExists(user_name)) {
                    if (grupEstudiService->CheckIfGroupExists(Noms_ListBox->Text)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(user_name);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(Noms_ListBox->Text);
                            if (not (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id))) {
                                MessageManager::WarningMessage("L'usuari no esta assignat al grup d'estudi.");
                                return;
                            }
                            else {
                                //Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
                                bool owner = grupEstudiService->CheckUserIsOwner(Noms_ListBox->Text);
                                if (owner) {
                                    MessageManager::WarningMessage("Ets el owner del grup.");
                                }
                                else {
                                    int user_id_int = static_cast<int>(*user_id);
                                    int current_user_id_int = static_cast<int>(*currentUser->GetUserId());
                                    //if (current_user_id_int == user_id_int) {
                                        //MessageManager::WarningMessage("No pots expulsar-te a tu mateix del grup.");
                                        //return;
                                    //}
                                    //else {
                                        grupEstudiMembershipService->DeleteUserFromGroup(user_id, group_id);
                                        //Membres_Box->Text = "";
                                        //Noms_ListBox = "";
                                        MessageManager::InfoMessage("Usuari expulsat del grup d'estudi amb exit.");

                                        GrupEstudi_ConsultarUI^ PanelUI = gcnew GrupEstudi_ConsultarUI();

                                        PanelUI->TopLevel = false;
                                        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                                        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                                        MainPageUI::Instance->screen->Controls->Clear();
                                        MainPageUI::Instance->screen->Controls->Add(PanelUI);
                                        PanelUI->Show();
                                    //}
                                }
                            }
                        }
                        catch (Exception^ e) {
                            MessageManager::ErrorMessage(e->Message);
                        }
                    }
                    else {
                        MessageManager::WarningMessage("El grup no existeix.");
                    }
                }
                else {
                    MessageManager::WarningMessage("L'usuari no existeix");
                }
            }
            else {
                MessageManager::WarningMessage("Falten camps per omplir.");
            }
        //}
        //else {
            //MessageManager::WarningMessage("Falten camps per omplir.");
        //}
    }
}

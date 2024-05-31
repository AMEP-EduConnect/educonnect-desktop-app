#include "pch.h"
#include "GrupEstudi_MembresUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "GrupEstudi_ExplorarUI.h"
#include "GrupEstudi_InfoUI.h"
#include "Usuari.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {
    GrupEstudi_Membres::GrupEstudi_Membres(String^ nomsListBox, bool pagina)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
        grupEstudiService = gcnew GrupEstudiService();
        Noms_ListBox = nomsListBox;
        consulta = pagina;
        this->Icon = gcnew System::Drawing::Icon("app.ico");

        bool isOwner = grupEstudiService->CheckUserIsOwner(Noms_ListBox);
        Assignar_Button->Visible = isOwner;
    }

    void GrupEstudi_Membres::GrupEstudi_Membres_Load(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_Membresreload();
    }

    void GrupEstudi_Membres::GrupEstudi_Membresreload() {
        Int64^ id_group = grupEstudiService->GetGroupIdByName(Noms_ListBox);
        String^ name = grupEstudiService->GetGrupEstudiById(id_group)->GetGroupName();
        this->ConsultarGrupEstudi_Label->Text = "Membres de " + name;
        array<Int64^>^ arrayIdMemberOfGroupEstudis = grupEstudiMembershipService->LoadMembershipByGrupsEstudi(id_group);

        Membres_Box->Items->Clear();

        for (int i = 0; i < arrayIdMemberOfGroupEstudis->Length; i++) {
            Usuari^ grupEstudiUser = grupEstudiMembershipService->LoadAllUsersById(arrayIdMemberOfGroupEstudis[i]);
            Membres_Box->Items->Add(grupEstudiUser->GetUsername());
        }
    }

    void GrupEstudi_Membres::CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (consulta) {
            GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(Noms_ListBox,1);
            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
        }
        else if (not consulta) {
			GrupEstudi_Explorar^ PanelUI = gcnew GrupEstudi_Explorar("");
            
            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
		}
    }


    void GrupEstudi_Membres::Membres_Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        bool isOwner = grupEstudiService->CheckUserIsOwner(Noms_ListBox);

        if (Membres_Box->SelectedIndex != -1) {
            if (isOwner) {
                Expulsar_Button->Visible = true;
                Assignar_Button->Visible = true;
            }
            if (not isOwner) {
                Expulsar_Button->Visible = false;
                Assignar_Button->Visible = false;
            }
        }
        
    }

    void GrupEstudi_Membres::Expulsar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (Membres_Box->Text != "") {
            if (Noms_ListBox != "") {
                if (grupEstudiService->CheckIfUserExists(Membres_Box->Text)) {
                    if (grupEstudiService->CheckIfGroupExists(Noms_ListBox)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(Membres_Box->Text);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(Noms_ListBox);
                            if (not (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id))) {
                                MessageManager::WarningMessage("L'usuari no esta assignat al grup d'estudi.");
                                return;
                            }
                            else {
                                Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
                                bool owner = grupEstudiService->CheckUserIsOwner(Noms_ListBox);
                                if (not owner) {
                                    MessageManager::WarningMessage("No ets el propietari del grup.");
                                }
                                else {
                                    int user_id_int = static_cast<int>(*user_id);
                                    int current_user_id_int = static_cast<int>(*currentUser->GetUserId());
                                    if (current_user_id_int == user_id_int) {
                                        MessageManager::WarningMessage("No pots expulsar-te a tu mateix del grup.");
                                        return;
                                    }
                                    else {
                                        MessageManager::InfoMessage("Usuari expulsat del grup d'estudi amb exit.");
                                        grupEstudiMembershipService->DeleteUserFromGroup(user_id, group_id);

                                        GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(Noms_ListBox, 1);
                                        PanelUI->TopLevel = false;
                                        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                                        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                                        MainPageUI::Instance->screen->Controls->Clear();
                                        MainPageUI::Instance->screen->Controls->Add(PanelUI);
                                        PanelUI->Show();
                                        
                                        Membres_Box->Text = "";
                                        Noms_ListBox = "";  
                                    }
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
        }
        else {
            MessageManager::WarningMessage("Falten camps per omplir.");
        }
    }

    void GrupEstudi_Membres::Assignar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        
        GrupEstudi_AssignarUI^ PanelUI = gcnew GrupEstudi_AssignarUI(Noms_ListBox);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }
}
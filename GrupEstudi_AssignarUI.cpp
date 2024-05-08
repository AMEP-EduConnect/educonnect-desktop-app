#include "pch.h"
#include "GrupEstudi_AssignarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_AssignarUI::GrupEstudi_AssignarUI(String^ nomsListBox)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService;
        grupEstudiService = gcnew GrupEstudiService();
        Noms_ListBox = nomsListBox;
        NomGrup_TextBox->Text = Noms_ListBox;
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void GrupEstudi_AssignarUI::CancelarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(Noms_ListBox, true);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void GrupEstudi_AssignarUI::AssignaButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (NomUsuari_TextBox->Text != "") {
            if (NomGrup_TextBox->Text != "") {
                if (grupEstudiService->CheckIfUserExists(NomUsuari_TextBox->Text)) {
					if (grupEstudiService->CheckIfGroupExists(NomGrup_TextBox->Text)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(NomUsuari_TextBox->Text);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(NomGrup_TextBox->Text);
                            if (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id)) {
								MessageManager::WarningMessage("L'usuari ja esta assignat al grup d'estudi.");
								return;
							}
                            else {
                                bool owner = grupEstudiService->CheckUserIsOwner(NomGrup_TextBox->Text);
                                if (not owner) {
                                    MessageManager::WarningMessage("No ets el propietari del grup.");
                                }
                                else {
                                    grupEstudiMembershipService->UserToGroup(user_id, group_id);
                                    NomUsuari_TextBox->Text = "";
                                    NomGrup_TextBox->Text = "";
                                    MessageManager::InfoMessage("Usuari assignat al grup d'estudi amb exit.");
                                    
                                    GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(Noms_ListBox, true);

                                    PanelUI->TopLevel = false;
                                    PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                                    PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                                    MainPageUI::Instance->screen->Controls->Clear();
                                    MainPageUI::Instance->screen->Controls->Add(PanelUI);
                                    PanelUI->Show();
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


}




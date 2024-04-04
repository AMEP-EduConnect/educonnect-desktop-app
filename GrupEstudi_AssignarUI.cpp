#include "pch.h"
#include "GrupEstudi_AssignarUI.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_AssignarUI::GrupEstudi_AssignarUI(void)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService;
        grupEstudiService = gcnew GrupEstudiService();
        this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void GrupEstudi_AssignarUI::CancelarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
		MainPageUI^ form = gcnew MainPageUI();
		form->ShowDialog();
		this->Close();
    }

    void GrupEstudi_AssignarUI::ExpulsaButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (NomUsuari_TextBox->Text != "") {
            if (NomGrup_TextBox->Text != "") {
                if (grupEstudiService->CheckIfUserExists(NomUsuari_TextBox->Text)) {
                    if (grupEstudiService->CheckIfGroupExists(NomGrup_TextBox->Text)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(NomUsuari_TextBox->Text);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(NomGrup_TextBox->Text);
                            if (not (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id))) {
                                MessageManager::WarningMessage("L'usuari no esta assignat al grup d'estudi.");
                                return;
                            }
                            else {
                                Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
                                bool owner = grupEstudiService->CheckUserIsOwner(NomGrup_TextBox->Text);
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
                                        grupEstudiMembershipService->DeleteUserFromGroup(user_id, group_id);
                                        NomUsuari_TextBox->Text = "";
                                        NomGrup_TextBox->Text = "";
                                        MessageManager::InfoMessage("Usuari expulsat del grup d'estudi amb exit.");
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




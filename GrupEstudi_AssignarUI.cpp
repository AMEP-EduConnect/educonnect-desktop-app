#include "pch.h"
#include "GrupEstudi_AssignarUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_AssignarUI::GrupEstudi_AssignarUI(void)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService;
        grupEstudiService = gcnew GrupEstudiService();
    }

    void GrupEstudi_AssignarUI::testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e) {
        //MessageManager::InfoMessage("Segur que vol sortir? No es guardara cap modificacio.");
        this->Close();
    }

    void GrupEstudi_AssignarUI::testbutton_Expulsar(System::Object^ sender, System::EventArgs^ e) {
        if (textBox_NomUsuari->Text != "") {
            if (boxNom_Grup->Text != "") {
                if (grupEstudiService->CheckIfUserExists(textBox_NomUsuari->Text)) {
                    if (grupEstudiService->CheckIfGroupExists(boxNom_Grup->Text)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(textBox_NomUsuari->Text);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(boxNom_Grup->Text);
                            if (not (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id))) {
                                MessageManager::WarningMessage("L'usuari no esta assignat al grup d'estudi.");
                                return;
                            }
                            else {
                                Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
                                bool owner = grupEstudiService->CheckUserIsOwner(currentUser->GetUserId(), boxNom_Grup->Text);
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
                                        textBox_NomUsuari->Text = "";
                                        boxNom_Grup->Text = "";
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

    void GrupEstudi_AssignarUI::testbutton_Assignar(System::Object^ sender, System::EventArgs^ e)
    {
        if (textBox_NomUsuari->Text != "") {
            if (boxNom_Grup->Text != "") {
                if (grupEstudiService->CheckIfUserExists(textBox_NomUsuari->Text)) {
					if (grupEstudiService->CheckIfGroupExists(boxNom_Grup->Text)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(textBox_NomUsuari->Text);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(boxNom_Grup->Text);
                            if (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id)) {
								MessageManager::WarningMessage("L'usuari ja esta assignat al grup d'estudi.");
								return;
							}
                            else {
                                Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
                                bool owner = grupEstudiService->CheckUserIsOwner(currentUser->GetUserId(), boxNom_Grup->Text);
                                if (not owner) {
                                    MessageManager::WarningMessage("No ets el propietari del grup.");
                                }
                                else {
                                    grupEstudiMembershipService->UserToGroup(user_id, group_id);
                                    textBox_NomUsuari->Text = "";
                                    boxNom_Grup->Text = "";
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




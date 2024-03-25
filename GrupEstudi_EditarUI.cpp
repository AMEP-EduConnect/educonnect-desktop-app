#include "pch.h"
#include "GrupEstudi_EditarUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_EditarUI::GrupEstudi_EditarUI(void)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
    }

    void GrupEstudi_EditarUI::CancelarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Close();
    }

    void GrupEstudi_EditarUI::testEdita_Button(System::Object^ sender, System::EventArgs^ e)
    {
        if (grupEstudiService->CheckIfGroupExists(NomActual_TextBox->Text)) {
            bool checkD = false;
            bool checkN = false;
            Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
            Int64^ currentUser_id = currentUser->GetUserId();
            bool owner = grupEstudiService->CheckUserIsOwner(NomActual_TextBox->Text);

            if (owner == false) {
                MessageManager::WarningMessage("No pots editar un grup que no siguis propietari.");
                return;
            }

            else {
                if (EditarDescripcio_TextBox->Text != "") {
                    grupEstudiService->ModifyGroupDescription(NomActual_TextBox->Text, EditarDescripcio_TextBox->Text);
                    checkD = true;
                    //MessageManager::InfoMessage("Descripció del grup modificat correctament.");
                }

                if (EditarNom_TextBox->Text != "") {
                    if (grupEstudiService->CheckIfGroupExists(EditarNom_TextBox->Text) == false) {
                        try {
                            grupEstudiService->ModifyGroupName(NomActual_TextBox->Text, EditarNom_TextBox->Text);
                            checkN = true;
                            //MessageManager::InfoMessage("Nom del grup modificat correctament.");
                        }
                        catch (Exception^ e) {
                            MessageManager::ErrorMessage(e->Message);
                        }

                    }
                    else {
                        MessageManager::WarningMessage("Ja existeix un grup amb aquest nom.");
                    }
                }

                if (checkD == true and checkN == false) {
                    MessageManager::InfoMessage("Descripció del grup modificada correctament.");
                }
                else if (checkN == true and checkD == false) {
                    MessageManager::InfoMessage("Nom del grup modificat correctament.");
                }
                else if (checkN == true and checkD == true) {
                    MessageManager::InfoMessage("Nom i descripció del grup modificats correctament.");
                }
            }
        }
        else {
            MessageManager::WarningMessage("No existeix cap grup amb aquest nom.");
        }
    }
}


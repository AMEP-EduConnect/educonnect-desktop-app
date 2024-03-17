#include "pch.h"
#include "GrupEstudi.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudiService.h"
#include "MessageManager.h"


namespace CppCLRWinFormsProject {

    GrupEstudi_EditarUI::GrupEstudi_EditarUI(void)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
    }

    void GrupEstudi_EditarUI::testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e)
    {
        MessageManager::InfoMessage("Segur que vol sortir? No es guardara cap modificacio.");
        this->Close();
    }

    void GrupEstudi_EditarUI::testbutton_Edita(System::Object^ sender, System::EventArgs^ e)
    {
        if (grupEstudiService->CheckIfGroupExists(textBox_NomActual->Text)) {
            if (textBox_DescripcioEditar->Text != "") {
                grupEstudiService->ModifyGroupDescription(textBox_NomActual->Text, textBox_DescripcioEditar->Text);
            }
            else {
                MessageManager::WarningMessage("Falten camps per omplir.");
            }

            if (textBox_NomEditar->Text != "") {
                if (grupEstudiService->CheckIfGroupExists(textBox_NomEditar->Text) == false) {
                    try {
                        grupEstudiService->ModifyGroupName(textBox_NomActual->Text, textBox_NomEditar->Text);
                        MessageManager::InfoMessage("Grup modificat correctament.");
                    }
                    catch (Exception^ e) {
						MessageManager::ErrorMessage(e->Message);
					}
                    
                }
                else {
					MessageManager::WarningMessage("Ja existeix un grup amb aquest nom.");
				}
            }
            else {
                MessageManager::WarningMessage("Falten camps per omplir.");
            }
        }
        else {
            MessageManager::WarningMessage("No existeix cap grup amb aquest nom.");
        }
    }
}


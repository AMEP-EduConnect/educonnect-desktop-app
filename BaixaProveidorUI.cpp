#include "pch.h"
#include "BaixaProveidorUI.h"
#include "Proveidor.h"
#include "BaixaProveidorService.h"
#include "MessageManager.h"

using namespace System;
namespace CppCLRWinFormsProject {
void BaixaProveidorUI::BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = this->BaixaProveidorTextBox->Text;
    if(username!=nullptr and username!="") {
        bool success = baixaProveidorService->BaixaProveidor(username);
        if(success) {
            MessageManager::InfoMessage("Proveidor donat de baixa correctament");
            this->BaixaProveidorTextBox->Text = "";
        }
        else {
            MessageManager::InfoMessage("No existeix el Proveidor " + username + "!");
            this->BaixaProveidorTextBox->Text = "";
        }
    }
    else {
        MessageManager::WarningMessage("Por favor, introduce el nombre del proveedor a eliminar.");
    }
}
}

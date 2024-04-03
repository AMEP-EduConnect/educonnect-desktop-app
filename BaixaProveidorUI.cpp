#include "pch.h"
#include "BaixaProveidorUI.h"
#include "Proveidor.h"
#include "BaixaProveidorService.h"
#include "MessageManager.h"

using namespace System;
using namespace CppCLRWinFormsProject;

BaixaProveidorUI::BaixaProveidorUI(void) {
    InitializeComponent();
    baixaProveidorService = gcnew BaixaProveidorService();
    this->BaixaProveidorButton->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::BaixaProveidorButton_Click);
}

void BaixaProveidorUI::BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ username = this->BaixaProveidorTextBox->Text;
    if (!String::IsNullOrWhiteSpace(username)) {
        try {
            bool success = baixaProveidorService->BaixaProveidor(username);
            if (success) {
                MessageManager::InfoMessage("Proveedor eliminado con �xito.");
            }
            else {
                MessageManager::WarningMessage("El proveedor no pudo ser eliminado.");
            }
        }
        catch (Exception^ ex) {
            MessageManager::ErrorMessage("Error al eliminar el proveedor: " + ex->Message);
        }
    }
    else {
        MessageManager::WarningMessage("Por favor, introduce el nombre del proveedor a eliminar.");
    }
}

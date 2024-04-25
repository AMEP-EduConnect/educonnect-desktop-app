#include "pch.h"
#include "BaixaProveidorUI.h"
#include "BaixaProveidorService.h"
#include "MessageManager.h"
#include "MainPageUI.h"
#include "AdministradorUI.h"

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
                MessageManager::ErrorMessage("No existeix el Proveidor " + username + "!");
                this->BaixaProveidorTextBox->Text = "";
            }
        }
        else {
            MessageManager::WarningMessage("Introdueix el nom del proveïdor que es esborrar!.");
        }
    }

    Void BaixaProveidorUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    
    }
    

}

#include "pch.h"
#include "BaixaProveidorUI.h"

using namespace System;
namespace CppCLRWinFormsProject {

    Void BaixaProveidorUI::LoadProvidersList(System::Object^ sender, System::EventArgs^ e) {
        //Creem array amb tots els proveuidors
        List<Usuari^>^ providers = baixaProveidorService->ListProveidors();
        System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = providers->GetEnumerator();
        while (enumerator->MoveNext())
            Llista_Proveidors->Items->Add(enumerator->Current->GetUsername());
    }

    void BaixaProveidorUI::BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (Llista_Proveidors->SelectedItem != nullptr) {
            String^ selectedProvider = Llista_Proveidors->SelectedItem->ToString();
            if (baixaProveidorService->BaixaProveidor(selectedProvider)) {
                MessageManager::InfoMessage("Proveidor " + selectedProvider + " donat de baixa correctament.");
                Llista_Proveidors->Items->Clear();
                LoadProvidersList(sender, e);
            }
        }
        else {
            MessageManager::WarningMessage("Selecciona un proveïdor de la llista.");
        }
    }

    void BaixaProveidorUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
         PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
         PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
         MainPageUI::Instance->screen->Controls->Clear();
         MainPageUI::Instance->screen->Controls->Add(PanelUI);
         PanelUI->Show();
    }


}
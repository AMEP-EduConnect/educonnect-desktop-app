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
            MessageBoxButtons buttons = MessageBoxButtons::YesNo;
            String^ selectedProvider = Llista_Proveidors->SelectedItem->ToString();
            System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir el proveïdor '" + selectedProvider + "'?", "Confirmation", buttons);
            if (result == System::Windows::Forms::DialogResult::Yes) {
                if (baixaProveidorService->BaixaProveidor(selectedProvider)) {
                    MessageManager::InfoMessage("Proveidor " + selectedProvider + " donat de baixa correctament.");
                    Llista_Proveidors->Items->Clear();
                    LoadProvidersList(sender, e);
                }
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

    Void BaixaProveidorUI::buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e) {
        if (buscador_textBox->Text == "Buscar Proveïdor...") { buscador_textBox->Clear(); }
        buscador_textBox->ForeColor = Color::Black;
    }

    Void BaixaProveidorUI::buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (buscador_textBox->Text == "Buscar Proveïdor...") {
            LoadProvidersList(sender, e);
        }
        else {
            String^ buscar_proveidor = buscador_textBox->Text;
            List<Usuari^>^ providers = baixaProveidorService->LoadProvidersByStartingLetter(buscar_proveidor);
            if (providers->Count == Llista_Proveidors->Items->Count) {
                return;
            }
            Llista_Proveidors->Items->Clear();
            System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = providers->GetEnumerator();
            while (enumerator->MoveNext())
                Llista_Proveidors->Items->Add(enumerator->Current->GetUsername());
            if (Llista_Proveidors->Items->Count == 0) {
                MessageManager::ErrorMessage("No s'ha trobat cap proveïdor amb aquest nom");
                buscador_textBox->Enabled = false;
                buscador_textBox->Enabled = true;
                buscador_textBox->ForeColor = System::Drawing::SystemColors::ActiveCaption;
                buscador_textBox->Text = L"Buscar Proveïdor...";
            }
        }
    }


}
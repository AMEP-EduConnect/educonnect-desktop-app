#include "pch.h"
#include "ConsultaEspaisUI.h"


using namespace System;
namespace CppCLRWinFormsProject {

    Void ConsultaEspaisUI::LoadEspaisList(System::Object^ sender, System::EventArgs^ e) {
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        Int64^ id_provider = currentUser->GetUserId();
        List<Espais^>^ espais = consultaEspaisService->ListEspais(id_provider);
        System::Collections::Generic::IEnumerator<Espais^>^ enumerator = espais->GetEnumerator();
        while (enumerator->MoveNext())
            Llista_Espais->Items->Add(enumerator->Current->GetNom());
    }

    void ConsultaEspaisUI::BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e) {
        /*if (Llista_Espais->SelectedItem != nullptr) {
            String^ selectedProvider = Llista_Espais->SelectedItem->ToString();
            if (baixaProveidorService->BaixaProveidor(selectedProvider)) {
                MessageManager::InfoMessage("Proveidor " + selectedProvider + " donat de baixa correctament.");
                Llista_Espais->Items->Clear();
                LoadEspaisList(sender, e);
            }
        }
        else {
            MessageManager::WarningMessage("Selecciona un proveïdor de la llista.");
        }*/
    }

    void ConsultaEspaisUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        MainPageUI^ PanelUI = gcnew MainPageUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }


}
#include "pch.h"
#include "NotificacionsUI.h"
#include "Notificacio.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "UsuariRepository.h"
using namespace System;

namespace CppCLRWinFormsProject {

        Void NotificacionsUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
            MainPageUI^ PanelUI = gcnew  MainPageUI();

            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();

        }


    Void NotificacionsUI::LoadNotificacionsList(System::Object^ sender, System::EventArgs^ e) {
        usuariRepository = gcnew UsuariRepository();
        List<Notificacio^>^ notificacions = notificacionsService->ListNotificacions();
        System::Collections::Generic::IEnumerator<Notificacio^>^ enumerator = notificacions->GetEnumerator();
        while (enumerator->MoveNext()) {
            Int64^ id_source = enumerator->Current->GetSourceUserId();
            Usuari^ nom_source = usuariRepository->GetUsuariById(id_source);
            Llista_Notificacions->Items->Add(enumerator->Current->GetSourceUser());
        }
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


}
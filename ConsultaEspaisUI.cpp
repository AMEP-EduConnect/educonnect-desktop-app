#include "pch.h"
#include "ConsultaEspaisUI.h"


using namespace System;
namespace CppCLRWinFormsProject {

    Void ConsultaEspaisUI::LoadEspaisList(System::Object^ sender, System::EventArgs^ e) {
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        Int64^ id_provider = currentUser->GetUserId();
        List<Espai^>^ espais = consultaEspaisService->ListEspais(id_provider);
        System::Collections::Generic::IEnumerator<Espai^>^ enumerator = espais->GetEnumerator();
        while (enumerator->MoveNext())
            Llista_Espais->Items->Add(enumerator->Current->GetName());
    }

    Void ConsultaEspaisUI::ButtonGestio_Click(System::Object^ sender, System::EventArgs^ e) {
        if (Llista_Espais->SelectedItem != nullptr) {
           // Espai^ espai = Llista_Espais->SelectedItem();
           String^ selectedEspais = Llista_Espais->SelectedItem->ToString();
          
           //GOTO: Agafar el Espai i transportarlo al modificar espai 
           ModificaEspaisUI^ PanelUI = gcnew ModificaEspaisUI(selectedEspais);
           PanelUI->TopLevel = false;
           PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
           PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
           MainPageUI::Instance->screen->Controls->Clear();
           MainPageUI::Instance->screen->Controls->Add(PanelUI);
           PanelUI->Show();
        }
        else {
            MessageManager::WarningMessage("Selecciona un espai de la llista per gestionar-la.");
        }
    }

    Void ConsultaEspaisUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        IniciUI^ PanelUI = gcnew IniciUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }
    // create a function that eliminates the selected item from the list
    Void ConsultaEspaisUI::ButtonEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
        if (Llista_Espais->SelectedItem != nullptr) {
			String^ selectedEspais = Llista_Espais->SelectedItem->ToString(); 
			if(eliminarEspaisService->eliminarEspais(selectedEspais) == true) 
            {
                Llista_Espais->Items->Remove(Llista_Espais->SelectedItem);
                MessageManager::InfoMessage("Espai eliminat correctament!");
            }
            else MessageManager::ErrorMessage("No s'ha pogut eliminar l'espai.");
		}
        else {
			MessageManager::WarningMessage("Selecciona un espai de la llista per eliminar-la.");
		}
	}

    Void ConsultaEspaisUI::ButtonAlta_Click(System::Object^ sender, System::EventArgs^ e) {
		AltaEspaisUI^ PanelUI = gcnew AltaEspaisUI();
		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}
}
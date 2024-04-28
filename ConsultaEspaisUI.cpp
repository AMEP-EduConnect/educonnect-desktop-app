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

    Void ConsultaEspaisUI::ButtonGestio_Click(System::Object^ sender, System::EventArgs^ e) {
        if (Llista_Espais->SelectedItem != nullptr) {
           // String^ selectedEspais = Llista_Espais->SelectedItem->ToString();
           //GOTO: Agafar el Espai i transportarlo al modificar espai 
        }
        else {
            MessageManager::WarningMessage("Selecciona un espai de la llista per gestionar-la.");
        }
    }

    Void ConsultaEspaisUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        MainPageUI^ PanelUI = gcnew MainPageUI();
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

}
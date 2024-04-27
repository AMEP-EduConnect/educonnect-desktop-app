#include "pch.h"
#include "AltaEspaisUI.h"
#include "AltaEspaisService.h"
#include "MessageManager.h"
#include "MainPageUI.h"

using namespace System;

namespace CppCLRWinFormsProject {

    

    void AltaEspaisUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {

        String^ nom = textBox3->Text;
        String^ capacitatText = textBox1->Text;
        Int64^ capacitat = Int64::Parse(capacitatText);

        if (!String::IsNullOrWhiteSpace(nom)) {
            this->altaEspaisService->AltaEspai(nom, capacitat);
            MessageManager::InfoMessage("Espai donat d'alta!");
            this->textBox3->Text = "";
            this->textBox1->Text = "";

        }
        else {

            MessageManager::WarningMessage("Falta informació de l'espai.");
        }
    }

    Void AltaEspaisUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();

    }


}


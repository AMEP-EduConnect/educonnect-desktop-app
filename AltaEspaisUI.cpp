#include "pch.h"
#include "AltaEspaisUI.h"
#include "AltaEspaisService.h"
#include "MessageManager.h"
#include "MainPageUI.h"

using namespace System;

namespace CppCLRWinFormsProject {
    bool AltaEspaisUI::NomEspai_TextBox_Validating(String^ nom) {
        if (nom != nullptr) {
            bool isNotValid = this->altaEspaisService->CheckNameEspai(nom);
            if (isNotValid) {
                MessageManager::WarningMessage("El nom de l'espai ja existeix.");
                this->textBox3->Text = "";
                return false;
            }
            else return true;
        }
        else return false;
    }

    bool AltaEspaisUI::IsValidCapacitat(String^ capacitat) {
        String^ pattern = "^[0-9]+$";
        System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(pattern);
        return regex->IsMatch(capacitat);
    }


    Void AltaEspaisUI::Capacitat_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (textBox != nullptr) {
            if ((!IsValidCapacitat(textBox->Text) and textBox->Text != "") or (textBox->Text == "0")) {
                MessageManager::WarningMessage("La capacitat ha de ser un n�mero enter major a 0.");
                this->textBox1->Text = "";
               
            }
            
            
        }
    }

    void AltaEspaisUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {

        String^ nom = textBox3->Text;
        String^ capacitatText = textBox1->Text;

        if (!String::IsNullOrWhiteSpace(nom) && !String::IsNullOrWhiteSpace(capacitatText)) {           
            if (NomEspai_TextBox_Validating(nom) == false) {

                return;
            }
            Int64^ capacitat = Int64::Parse(capacitatText);

            this->altaEspaisService->AltaEspai(nom, capacitat);
            MessageManager::InfoMessage("Espai donat d'alta!");
            this->textBox3->Text = "";
            this->textBox1->Text = "";
        }
       
        else {        
            MessageBox::Show("Falta informaci� de l'espai.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
       
    }

    Void AltaEspaisUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        ConsultaEspaisUI^ PanelUI = gcnew ConsultaEspaisUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();

    }


}


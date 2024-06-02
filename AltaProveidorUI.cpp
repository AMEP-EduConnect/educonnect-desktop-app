#include "pch.h"
#include "AltaProveidorUI.h"
#include "AltaProveidorService.h"
#include "MessageManager.h"
#include "MainPageUI.h"

using namespace System;

namespace CppCLRWinFormsProject {

    bool AltaProveidorUI::IsValidEmail(String^ email) {
        String^ pattern = R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)";
        Regex^ regex = gcnew Regex(pattern);
        return regex->IsMatch(email);
    }

    bool AltaProveidorUI::IsPasswordStrong(String^ password) {
        if (password->Length < 8) return false;
        if (!Regex::IsMatch(password, R"([A-Z])")) return false;
        if (!Regex::IsMatch(password, R"([a-z])")) return false;
        if (!Regex::IsMatch(password, R"(\d)")) return false;
        if (!Regex::IsMatch(password, R"([\!\@\#\$\%\^\&\*\(\)\-\=\+\[\]\{\}\;\:\'\"\<\>\,\.\?\/\~\`\|\\])")) return false;
        return true;
    }

    Void AltaProveidorUI::textBoxPassword_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (!IsPasswordStrong(textBox->Text) and textBox->Text != "") {
            MessageBox::Show("La contrasenya no és prou robusta.\nHa de contenir 8 o més caràcters, caràcters especials i números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            textBox->Text = "";
        }
    }

    Void AltaProveidorUI::NomUsuari_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (textBox != nullptr) {
            bool isnotValid = this->altaProveidorService->CheckUsername(textBox->Text);
            if (isnotValid) {
                MessageBox::Show("El nom de l'usuari ja existeix o no és vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                textBox->Text = "";
                e->Cancel = true;
            }

        }
    }

    Void AltaProveidorUI::Email_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (textBox != nullptr) {
            if (!IsValidEmail(textBox->Text) and textBox->Text != "") {
                MessageBox::Show("El correu electrònic no té un format vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                this->textBox2->Text = "";
            }
            else {
                bool isnotValid = this->altaProveidorService->CheckEmail(textBox->Text);
                if (isnotValid) {
                    MessageBox::Show("El correu electrònic de l'usuari ja està registrat.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    textBox->Text = "";
                    e->Cancel = true;
                }
            }
        }
    }

   
    
    void AltaProveidorUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        
        String^ username = textBox3->Text;
        String^ password = textBox5->Text;
        String^ email = textBox2->Text;
        String^ name = textBox4->Text;
        if ((!String::IsNullOrWhiteSpace(username)) && (!String::IsNullOrWhiteSpace(password)) && (!String::IsNullOrWhiteSpace(email)) && (!String::IsNullOrWhiteSpace(name))) {
            this->altaProveidorService->AltaProveidor( username, email, name, password);
            MessageManager::InfoMessage("Proveidor donat d'alta!");
            this->textBox2->Text = "";
            this->textBox3->Text = "";
            this->textBox4->Text = "";
            this->textBox5->Text = "";
        }
        else {
            
            MessageManager::WarningMessage("Falta informació del proveïdor.");
        }
    }

    Void AltaProveidorUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    
    }

   
}


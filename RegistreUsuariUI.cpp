#include "pch.h"
#include "RegistreUsuariUI.h"
#include "StartPageUI.h"
#include "MessageManager.h"

using namespace System;

namespace CppCLRWinFormsProject {

	    bool RegistreUsuariUI::IsValidEmail(String^ email) {
		    String^ pattern = R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)";
		    Regex^ regex = gcnew Regex(pattern);
		    return regex->IsMatch(email);
	    }

        bool RegistreUsuariUI::IsPasswordStrong(String^ password) {
            if (password->Length < 8) return false;
            if (!Regex::IsMatch(password, R"([A-Z])")) return false;
            if (!Regex::IsMatch(password, R"([a-z])")) return false;
            if (!Regex::IsMatch(password, R"(\d)")) return false;
            if (!Regex::IsMatch(password, R"([\!\@\#\$\%\^\&\*\(\)\-\=\+\[\]\{\}\;\:\'\"\<\>\,\.\?\/\~\`\|\\])")) return false;
            return true;
        }

		Void RegistreUsuariUI::textBoxPassword_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {

		}

        Void RegistreUsuariUI::NomUsuari_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
            TextBox^ textBox = dynamic_cast<TextBox^>(sender);
            if (textBox != nullptr) {
                    bool isnotValid = this->registreService->CheckUsername(textBox->Text);
                    if (isnotValid) {
                        MessageManager::ErrorMessage("El nom de l'usuari ja existeix o no és vàlid");
                        textBox->Text = "";
                        e->Cancel = true;
                    }
                
            }
        }

		Void RegistreUsuariUI::Email_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			if (textBox != nullptr) {
				if (!IsValidEmail(textBox->Text) and textBox->Text != "") {
                    MessageManager::ErrorMessage("El correu electrònic no té un format vàlid");
                    textBox->Text = "";
				}
                else {
                    bool isnotValid = this->registreService->CheckEmail(textBox->Text);
                    if (isnotValid) {
                        MessageManager::ErrorMessage("El correu electrònic de l'usuari ja està registrat.");
                        textBox->Text = "";
                        e->Cancel = true;
                    }
                }
			}
		}

        void RegistreUsuariUI::ContinuarRegistreButton_Click(Object^ sender, EventArgs^ e) {

            
            String^ username = NomUsuari_TextBox->Text;
            String^ email = Email_TextBox->Text;
            String^ name = Nom_TextBox->Text;
            String^ password = Contrasenya_TextBox->Text;

            if (!IsPasswordStrong(Contrasenya_TextBox->Text) and Contrasenya_TextBox->Text != "") {
                MessageManager::InfoMessage("La contrasenya no és prou robusta.\nHa de contenir 8 o més caràcters, caràcters especials i números");
                Contrasenya_TextBox->Text = "";
                if (username == "" or email == "" or name == "" or password == "") this->EmplenaTots->Visible = true;

            }
            else {

                if (username == "" or email == "" or name == "" or password == "") this->EmplenaTots->Visible = true;

                else {
                    this->registreService->CreateUser(username, email, name, password);

                    MessageManager::InfoMessage("S'ha registrat correctament!");
                    FirstPageUI^ PanelUI = gcnew FirstPageUI();
                    PanelUI->TopLevel = false;
                    PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                    PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                    StartPageUI::Instance->screen->Controls->Clear();
                    StartPageUI::Instance->screen->Controls->Add(PanelUI);
                    PanelUI->Show();

                }
            }
        }

        Void RegistreUsuariUI::GoBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
            FirstPageUI^ PanelUI = gcnew FirstPageUI();
            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            StartPageUI::Instance->screen->Controls->Clear();
            StartPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
            this->Close();
        }

        Void RegistreUsuariUI::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
            if (password_visible) {
                this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
                this->Contrasenya_TextBox->PasswordChar = true;
                password_visible = false;
                this->Contrasenya_TextBox->UseSystemPasswordChar = true;
            }
            else {
                this->pictureBox1->Image = Image::FromFile("resources/Icons/eye.png");
                this->Contrasenya_TextBox->PasswordChar = false;
                password_visible = true;
                this->Contrasenya_TextBox->UseSystemPasswordChar = false;
            }
        }

        Void RegistreUsuariUI::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
            this->Contrasenya_TextBox->Focus();
        }

}



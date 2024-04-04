#include "pch.h"
#include "RegistreUsuariUI.h"

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
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			if (!IsPasswordStrong(textBox->Text) and textBox->Text != "") {
				MessageBox::Show("La contrasenya no és prou robusta.\nHa de contenir 8 o més caràcters, caràcters especials i números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				//e->Cancel = true; // Previene que el foco cambie de control hasta que la entrada sea válida.
			}
		}

        Void RegistreUsuariUI::NomUsuari_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
            TextBox^ textBox = dynamic_cast<TextBox^>(sender);
            if (textBox != nullptr) {
                    bool isnotValid = this->registreService->CheckUsername(textBox->Text);
                    if (isnotValid) {
                        MessageBox::Show("El nom de l'usuari ja existeix o no és vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        textBox->Text = "";
                        e->Cancel = true;
                    }
                
            }
        }

		Void RegistreUsuariUI::Email_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			if (textBox != nullptr) {
				if (!IsValidEmail(textBox->Text) and textBox->Text != "") {
					MessageBox::Show("El correu electrònic no té un format vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					//e->Cancel = true; // Esto previene que el foco cambie al siguiente control si la validación falla.
				}
                else {
                    bool isnotValid = this->registreService->CheckEmail(textBox->Text);
                    if (isnotValid) {
                        MessageBox::Show("El correu electrònic de l'usuari ja està registrat.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
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

            if (username == "" or email == "" or name == "" or password == "") EmplenaTotsError_Label->Visible = true;

            else {
                this->registreService->CreateUser(username,email,name,password);
                MessageBox::Show("S'ha registrat correctament! Benvingut!", "Registre Correcte", MessageBoxButtons::OK);

                this->Hide();
                FirstPageUI^ form = gcnew FirstPageUI();
                form->ShowDialog();
                this->Close();
            }
        }

        Void RegistreUsuariUI::GoBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
            this->Hide();
            FirstPageUI^ form = gcnew FirstPageUI();
            form->ShowDialog();
            this->Close();
        }

}



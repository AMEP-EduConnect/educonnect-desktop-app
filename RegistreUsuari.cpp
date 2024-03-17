#include "pch.h"
#include "RegistreUsuari.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>

using namespace System;

namespace CppCLRWinFormsProject {
	    bool RegistreUsuari::IsValidEmail(String^ email) {
		    // Patrón para validar un correo electrónico.
		    String^ pattern = R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)";
		    Regex^ regex = gcnew Regex(pattern);
		    return regex->IsMatch(email);
	    }

        bool RegistreUsuari::IsPasswordStrong(String^ password) {
            if (password->Length < 8) return false;
            if (!Regex::IsMatch(password, R"([A-Z])")) return false;
            if (!Regex::IsMatch(password, R"([a-z])")) return false;
            if (!Regex::IsMatch(password, R"(\d)")) return false;
            if (!Regex::IsMatch(password, R"([\!\@\#\$\%\^\&\*\(\)\-\=\+\[\]\{\}\;\:\'\"\<\>\,\.\?\/\~\`\|\\])")) return false;
            return true;
        }

		Void RegistreUsuari::textBoxPassword_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			if (!IsPasswordStrong(textBox->Text) and textBox->Text != "") {
				MessageBox::Show("La contrasenya no és prou robusta.\nHa de contenir 8 o més caràcters, caràcters especials i números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				//e->Cancel = true; // Previene que el foco cambie de control hasta que la entrada sea válida.
			}
		}

        Void RegistreUsuari::textBox1_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
            TextBox^ textBox = dynamic_cast<TextBox^>(sender);
            if (textBox != nullptr) {
                    bool isnotValid = this->txRegistre->CheckUsername(textBox->Text);
                    if (isnotValid) {
                        MessageBox::Show("El nom de l'usuari ja existeix o no és vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        textBox->Text = "";
                        e->Cancel = true;
                    }
                
            }
        }

		Void RegistreUsuari::textBox2_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			if (textBox != nullptr) {
				if (!IsValidEmail(textBox->Text) and textBox->Text != "") {
					MessageBox::Show("El correu electrònic no té un format vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					//e->Cancel = true; // Esto previene que el foco cambie al siguiente control si la validación falla.
				}
                else {
                    bool isnotValid = this->txRegistre->CheckEmail(textBox->Text);
                    if (isnotValid) {
                        MessageBox::Show("El correu electrònic de l'usuari ja està registrat.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        textBox->Text = "";
                        e->Cancel = true;
                    }
                }
			}
		}

        void RegistreUsuari::Button_Click(Object^ sender, EventArgs^ e) {

            
            String^ username = textBox1->Text;
            String^ email = textBox2->Text;
            String^ name = textBox3->Text;
            //String^ surname = textBox4->Text;
            String^ password = textBox5->Text;

            if (username == "" or email == "" or name == "" or password == "") label6->Visible = true;

            else {
                this->txRegistre->CreateUser(username,email,name,password);
                MessageBox::Show("S'ha registrat correctament! Benvinguts!.", "Registre Correcte", MessageBoxButtons::OK);
            }
        }


    
}



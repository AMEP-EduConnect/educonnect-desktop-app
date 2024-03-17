#include "pch.h"
#include "RegistreUsuari.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>


namespace CppCLRWinFormsProject {
        System::Void RegistreUsuari::textBox1_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
            TextBox^ textBox = dynamic_cast<TextBox^>(sender);
            if (textBox != nullptr) {
                bool isnotValid = this->txRegistre->CheckUsername(textBox->Text);
                if (isnotValid) {
                    MessageBox::Show("El nombre de usuario ya existe o no es válido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    textBox->Text = "";
                    e->Cancel = true;
                }
            }
        }


    

}


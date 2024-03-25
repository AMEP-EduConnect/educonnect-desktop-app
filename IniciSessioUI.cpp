#include "pch.h"
#include "IniciSessioUI.h"

using namespace System;


namespace CppCLRWinFormsProject {


    void IniciSessioUI::ContinuarIniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e) {

        IniciSessioService inici;
        String^ username = NomUsuari_TextBox->Text;
        String^ password = Contrasenya_TextBox->Text;

        if (username == "" or password == "") CredencialsIncorrectes_Label->Visible = true;

        else {

            bool check = inici.CheckUsername(username, password);


            if (check == true) {
                MessageBox::Show("Inici de sessió amb exit");

            }

            else CredencialsIncorrectes_Label->Visible = true;
        }
    }


    Void IniciSessioUI::GoBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }


}
#include "pch.h"
#include "IniciSessioUI.h"
#include "MainPageUI.h"
#include "FirstPageUI.h"

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
                this->Hide();
                MainPageUI^ form = gcnew MainPageUI();
                form->ShowDialog();
                this->Close();
            }

            else CredencialsIncorrectes_Label->Visible = true;
        }
    }


    Void IniciSessioUI::GoBackButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        FirstPageUI^ form = gcnew FirstPageUI();
        form->ShowDialog();
        this->Close();
    }


}
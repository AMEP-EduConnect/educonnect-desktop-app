#include "pch.h"
#include "IniciSessio.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>
#include "TxIniciSessio.h"
#include "FirstPage.h"

using namespace System;


namespace CppCLRWinFormsProject {


    void IniciSessio::Button_Click(System::Object^ sender, System::EventArgs^ e) {

        TxIniciSessio inici;
        String^ username = textBox1->Text;
        String^ password = textBox2->Text;

        if (username == "" or password == "") label5->Visible = true;

        else {

            bool check = inici.CheckUsername(username, password);


            if (check == true) {
                MessageBox::Show("Inici de sessió amb exit");

            }

            else label5->Visible = true;
        }
    }


    Void IniciSessio::Button_Click_Retorna(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }


}
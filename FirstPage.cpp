#include "pch.h"
#include "FirstPage.h"
#include "IniciSessio.h"
#include "RegistreUsuari.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>

using namespace System;


namespace CppCLRWinFormsProject {

    void FirstPage::Button_Click_IniciSessio(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        IniciSessio^ form = gcnew IniciSessio();
        form->ShowDialog();
        this->Show();
    }

    void FirstPage::Button_Click_Registrat(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        RegistreUsuari^ form = gcnew RegistreUsuari();
        form->ShowDialog();
        this->Show();
        
    }

}
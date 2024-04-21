#include "pch.h"
#include "FirstPageUI.h"
#include "IniciSessioUI.h"
#include "RegistreUsuariUI.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>

using namespace System;


namespace CppCLRWinFormsProject {

    void FirstPageUI::IniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e) {
        /*this->Hide();
        IniciSessioUI^ form = gcnew IniciSessioUI();
        form->ShowDialog();
        this->Close();*/
        this->Hide();
        CaptchaUI^ form = gcnew CaptchaUI();
        form->ShowDialog();
        this->Close();
    }

    void FirstPageUI::RegistrarseButton_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        RegistreUsuariUI^ form = gcnew RegistreUsuariUI();
        form->ShowDialog();
        this->Close();
        
    }

}
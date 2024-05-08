#include "pch.h"
#include "FirstPageUI.h"
#include "IniciSessioUI.h"
#include "RegistreUsuariUI.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include "StartPageUI.h"
#include <iostream>
#include <string>

using namespace System;


namespace CppCLRWinFormsProject {

    void FirstPageUI::IniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e) {
        IniciSessioUI^ PanelUI = gcnew IniciSessioUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        StartPageUI::Instance->screen->Controls->Clear();
        StartPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
        this->Close();
        //this->System::ComponentModel::Component::Dispose();
    }

    void FirstPageUI::RegistrarseButton_Click(System::Object^ sender, System::EventArgs^ e) {
        RegistreUsuariUI^ PanelUI = gcnew RegistreUsuariUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        StartPageUI::Instance->screen->Controls->Clear();
        StartPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
        this->Close();
        //this->System::ComponentModel::Component::Dispose();
    }

}
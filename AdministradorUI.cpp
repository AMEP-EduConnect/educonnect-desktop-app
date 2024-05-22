#include "pch.h"
#include "AdministradorUI.h"
#include "MainPageUI.h"
#include "AltaProveidorUI.h"
#include "BaixaProveidorUI.h"
#include "BaixaUsuariUI.h"
using namespace System;

namespace CppCLRWinFormsProject {

    AdministradorUI::AdministradorUI(void) {
        InitializeComponent();

    }

	void AdministradorUI::BotoAltaProveidor_Click(System::Object^ sender, System::EventArgs^ e) {
        AltaProveidorUI^ PanelUI = gcnew AltaProveidorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);

        PanelUI->Show();
	}

    void AdministradorUI::BotoBaixa_Click(System::Object^ sender, System::EventArgs^ e) {
        BaixaProveidorUI^ PanelUI = gcnew BaixaProveidorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);

        PanelUI->Show();

    }

    Void AdministradorUI::BotoBaixaUser_Click(System::Object^ sender, System::EventArgs^ e) {
        BaixaUsuariUI^ PanelUI = gcnew BaixaUsuariUI();
		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);

		PanelUI->Show();
    }

    void AdministradorUI::BotoReports_Click(System::Object^ sender, System::EventArgs^ e) {
    
    }

}
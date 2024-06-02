#include "pch.h"
#include "AdministradorUI.h"
#include "MainPageUI.h"
#include "AltaProveidorUI.h"
#include "BaixaProveidorUI.h"
#include "BaixaUsuariAdminUI.h"
#include "BaixaUsuariUI.h"
#include "Reports_ConsultaUI.h"
using namespace System;

namespace CppCLRWinFormsProject {

    AdministradorUI::AdministradorUI(void) {
        InitializeComponent();
		SetWelcomeMessage();
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
        BaixaUsuariAdminUI^ PanelUI = gcnew BaixaUsuariAdminUI();
		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);

		PanelUI->Show();
    }

    void AdministradorUI::BotoReports_Click(System::Object^ sender, System::EventArgs^ e) {

        Reports_ConsultaUI^ PanelUI = gcnew Reports_ConsultaUI();

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    Void AdministradorUI::SetWelcomeMessage() {

        String^ name = CurrentSession::Instance->GetCurrentUser()->GetName();

        time_t now = time(0);
        tm* time = localtime(&now);

        if (time->tm_hour > 6 and time->tm_hour < 12) this->Benvinguda->Text = "Bon dia, " + name;

        else if (time->tm_hour >= 12 and time->tm_hour < 20) this->Benvinguda->Text = "Bona tarda, " + name;

        else if (time->tm_hour >= 20 or time->tm_hour <= 6) this->Benvinguda->Text = "Bona nit, " + name;

    }

}
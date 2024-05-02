#include "pch.h"
#include "Session_CrearUI.h"
#include "GrupEstudi_InfoUI.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {

	Session_CrearUI::Session_CrearUI(GrupEstudi^ CurrentGrupEntity)
	{
		InitializeComponent();
		this->CurrentGrupEntity = CurrentGrupEntity;
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	System::Void Session_CrearUI::Session_CrearUI_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->CurrentGrupName_Label->Text = '"' + this->CurrentGrupEntity->GetGroupName() + '"';
	}

	System::Void Session_CrearUI::GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI((this->CurrentGrupEntity)->GetGroupName());

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}

	System::Void Session_CrearUI::DayMonth_Calendar_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e)
	{
		return System::Void();
	}

	System::Void Session_CrearUI::Proveidor_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		return System::Void();
	}

	System::Void Session_CrearUI::Espai_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		return System::Void();
	}

	System::Void Session_CrearUI::TimeHour_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		return System::Void();
	}

	System::Void Session_CrearUI::CreateSession_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		return System::Void();
	}

};


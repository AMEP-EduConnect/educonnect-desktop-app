#include "pch.h"
#include "Reports_GestioUI.h"
#include "Reports_ConsultaUI.h"
#include "Reports_InfoUI.h"
#include "MainPageUI.h"
#include "IniciUI.h"

namespace CppCLRWinFormsProject {

    Reports_GestioUI::Reports_GestioUI(Int64^ id_report, Int64^ reported_id, String^ reported_member, Int64^ reported_id2, String^ reported_member2)
    {
        InitializeComponent();
        reportService = gcnew ReportsService();
        report_id = id_report;
        PageTitle_Label->Text = "Gestiona Report Numero #" + report_id;

        id_reported = reported_id;
        member_reported = reported_member;
        id2_reported = reported_id2;
        member2_reported = reported_member2;

        nom_de->Text = member_reported;
        nom_per->Text = member2_reported;

        this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void Reports_GestioUI::Reports_GestioUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        array<Int64^>^ suspended;
        suspended = reportService->LoadSuspendedTimes();
        for (int i = 0; i < suspended->Length; i++) {
            this->Sancio_ComboBox->Items->Add(reportService->GetNamesTimes(suspended[i]));
        }
    }

    void Reports_GestioUI::Sanciona_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (Sancio_ComboBox->Text != "") {
            Int64^ time_suspended = reportService->GetSuspendedTime(Sancio_ComboBox->Text);
            reportService->SetBlacklist(id2_reported, Description_TextBox->Text, time_suspended);
            MessageManager::WarningMessage("L'usuari serà sancinat amb " + Sancio_ComboBox->Text + ".");
            //reportService->DeleteReport(report_id);

            Reports_ConsultaUI^ PanelUI = gcnew  Reports_ConsultaUI();

            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
		}
        else {
            MessageManager::ErrorMessage("Has de seleccionar una sanció.");
        }
    }

    void Reports_GestioUI::FormGrupName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
    }

    void Reports_GestioUI::FormGrupDescription_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
    }

    System::Void Reports_GestioUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
            Reports_InfoUI^ PanelUI = gcnew  Reports_InfoUI(report_id);

            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
    }
}



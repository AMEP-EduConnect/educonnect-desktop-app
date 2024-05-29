#include "pch.h"
#include "Reports_GestioUI.h"
#include "Reports_ConsultaUI.h"
#include "Reports_InfoUI.h"
#include "MainPageUI.h"
#include "IniciUI.h"

namespace CppCLRWinFormsProject {

    Reports_GestioUI::Reports_GestioUI(Int64^ id_report)
    {
        InitializeComponent();
        reportService = gcnew ReportsService();
        iniciSessioService = gcnew IniciSessioService();
        report_id = id_report;
        PageTitle_Label->Text = "Gestiona Report Numero #" + report_id;

        Int64^ reported_id = reportService->GetReportedMember(report_id);
        String^ reported_member = (iniciSessioService->GetUsuariById(reported_id))->GetUsername();
        nom_de->Text = reported_member;

        Int64^ reported_id2 = reportService->GetReportMember(report_id);
        String^ reported_member2 = (iniciSessioService->GetUsuariById(reported_id2))->GetUsername();
        nom_per->Text = reported_member2;

        this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void Reports_GestioUI::GrupEstudi_CrearUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        array<Int64^>^ suspended;
        suspended = reportService->LoadSuspendedTimes();
        MessageManager::WarningMessage("Times " + suspended->Length);
        for (int i = 0; i < suspended->Length; i++) {
            this->Sancio_ComboBox->Items->Add(reportService->GetNamesTimes(suspended[i]));
        }
    }

    void Reports_GestioUI::Sanciona_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {

        MessageManager::WarningMessage("L'usuari serà sancinat amb " /*++*/ "hores.");
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



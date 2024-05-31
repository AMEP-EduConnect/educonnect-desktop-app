#include "pch.h"
#include "Reports_InfoUI.h"
#include "Reports_ConsultaUI.h"
#include "Reports_GestioUI.h"
#include "ReportsService.h"
#include "Reports.h"
#include "IniciSessioService.h"
#include "MainPageUI.h"
#include "BaixaUsuariUI.h"


namespace CppCLRWinFormsProject {

    Reports_InfoUI::Reports_InfoUI(Int64^ id_report)
    {
        InitializeComponent();
        report_id  = id_report;
        NumReports_Label->Text = "Report Numero #" + report_id;
        reportService = gcnew ReportsService();
        iniciSessioService = gcnew IniciSessioService();

        reported_id = reportService->GetReportedMember(report_id);
        reported_member = (iniciSessioService->GetUsuariById(reported_id))->GetUsername();
        nom_de->Text = reported_member;

        reported_id2 = reportService->GetReportMember(report_id);
        reported_member2 = (iniciSessioService->GetUsuariById(reported_id2))->GetUsername();
        nom_per->Text = reported_member2;

        Cancelar_Button->Visible = true;
        acepta_button->Visible = true;
        denega_button->Visible = true;
        Noms_ListBox->Enabled = false;
        this->Icon = gcnew System::Drawing::Icon("app.ico"); 
    }

    void Reports_InfoUI::Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
    }

    void Reports_InfoUI::Reports_ConsultarUIreload() {

        String^ description_report = reportService->GetReportDescription(report_id);
        Noms_ListBox->Items->Clear();

        if (description_report == "") {
            Noms_ListBox->Items->Add("No hi ha cap motiu.");
            Noms_ListBox->ForeColor = System::Drawing::Color::Gray;
            Noms_ListBox->Enabled = false;
        }
        else {
            Noms_ListBox->ForeColor = System::Drawing::Color::Black;
            Noms_ListBox->Enabled = false;

            Noms_ListBox->Items->Add(description_report);
        }
    }

    void Reports_InfoUI::Reports_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        Reports_ConsultarUIreload();
    }

    System::Void Reports_InfoUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Reports_ConsultaUI^ PanelUI = gcnew Reports_ConsultaUI();

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void Reports_InfoUI::acepta_button_Click(System::Object^ sender, System::EventArgs^ e) {
            Reports_GestioUI^ PanelUI = gcnew Reports_GestioUI(report_id, reported_id, reported_member, reported_id2, reported_member2);

            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
    }


    void Reports_InfoUI::denega_button_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        System::Windows::Forms::DialogResult result = MessageBox::Show("Segur que vols denegar el report? L'Usuari '" + reported_member2 + "' no serà sancionat i el report #" + report_id+ " serà eliminat.", "Confirmation", buttons);

        if (result == System::Windows::Forms::DialogResult::No) {
        }
        else {
            reportService->DeleteReport(report_id);

            Reports_ConsultaUI^ PanelUI = gcnew Reports_ConsultaUI();

            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
        }
    }

}
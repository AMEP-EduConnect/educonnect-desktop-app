#include "pch.h"
#include "Reports_ConsultaUI.h"
#include "ReportsService.h"
#include "Reports.h"
#include "IniciSessioService.h"
#include "MainPageUI.h"
#include "Reports_InfoUI.h"
#include "AdministradorUI.h"

namespace CppCLRWinFormsProject {

    Reports_ConsultaUI::Reports_ConsultaUI(void)
    {
        InitializeComponent();
        reportService = gcnew ReportsService();
        iniciSessioService = gcnew IniciSessioService();
        MoreInfo_Button->Visible = false;
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void Reports_ConsultaUI::Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        //ATENCIO ATENCIO ATENCIO
        if (Noms_ListBox->Text != "") {
            MoreInfo_Button->Visible = true;
        }
        else {
			MoreInfo_Button->Visible = false;
		}

        if (Noms_ListBox->SelectedItem != nullptr) {
            String^ selectedItem = Noms_ListBox->SelectedItem->ToString();
            int hashIndex = selectedItem->IndexOf('#');
            if (hashIndex != -1) {
                int spaceIndex = selectedItem->IndexOf(' ', hashIndex);
                if (spaceIndex != -1) {
                    String^ reportIdString = selectedItem->Substring(hashIndex + 1, spaceIndex - hashIndex - 1);
                    reportId = Int64::Parse(reportIdString);
                }
            }
        }
    }

    void Reports_ConsultaUI::Reports_ConsultarUIreload() {

        array<Int64^>^ arrayReportData = reportService->LoadReportData();
        Noms_ListBox->Items->Clear();

        if (arrayReportData->Length == 0) {
            if (arrayReportData->Length == 0) {
				Noms_ListBox->Items->Add("No tens cap report.");
				Noms_ListBox->ForeColor = System::Drawing::Color::Gray;
				Noms_ListBox->Enabled = false;
			}
        }
        else {
            Noms_ListBox->ForeColor = System::Drawing::Color::Black;
            Noms_ListBox->Enabled = true;

            for (int i = 0; i < arrayReportData->Length; i += 3) {
                // Obtenemos los valores de cada fila
                Int64^ userRep = arrayReportData[i];
                Int64^ userId = arrayReportData[i + 1];
                Int64^ reportId = arrayReportData[i + 2];

                // Agregamos la información al ListBox
                Noms_ListBox->Items->Add(
                    "#" + reportId +
                    "  -  Usuari '" + (iniciSessioService->GetUsuariById(userRep))->GetUsername() +
                    "' reporta a '" + (iniciSessioService->GetUsuariById(userId))->GetUsername() + "'"
                );
            }
        }
    }

    void Reports_ConsultaUI::Reports_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        Reports_ConsultarUIreload();
    }

    void Reports_ConsultaUI::MoreInfo_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Reports_InfoUI^ PanelUI = gcnew Reports_InfoUI(reportId);
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void Reports_ConsultaUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
	}
}
#include "pch.h"
#include "ReportsUI.h"
#include "GrupEstudi_MembresUI.h"
#include "GrupEstudi_InfoUI.h"
#include "CurrentSession.h"
#include "ReportsService.h"
#include "GrupEstudiService.h"
#include "Usuari.h"
#include "ReportsRepository.h"
#include "MessageManager.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {
	ReportsUI::ReportsUI(String^ CurrentMembre, String^ CurrentGroup)
	{
		InitializeComponent();
		reportService = gcnew ReportsService();
		grupService = gcnew GrupEstudiService();
		MembreReport = CurrentMembre;
		GrupActual = CurrentGroup;
		FormUserRep_TextBox->Text = MembreReport;

		this->FormUserRep_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->FormUserRep_TextBox->Enabled = false;
		this->FormUserRep_TextBox->Enabled = false;

		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	void ReportsUI::Reportar_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (FormDescription_TextBox->Text == "") {
			MessageBox::Show("No pots enviar un report en blanc", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else {
			Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
			Int64^ MembreReportID = grupService->GetUserIdByName(MembreReport);

			if (not reportService->ReportExists(MembreReportID, currentUser->GetUserId())) {
				reportService->CreateReport(MembreReportID, currentUser->GetUserId(), FormDescription_TextBox->Text);
				FormDescription_TextBox->Text = "";
				MessageBox::Show("Report enviat correctament", "Report", MessageBoxButtons::OK, MessageBoxIcon::Information);
				Cancelar_Button_Click(sender, e);
			}
			else {
				MessageBox::Show("Ja has reportat al usuari " +MembreReport+ ". El teu report es troba en espera per a ser revisat per un Administrador.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
		}
	}

	void ReportsUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{

		//PREGUNTAR!!! Toranr a la vista anterior (Membres) o a la vista de GrupEstudi_InfoUI (Info Generica)

		/*GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(GrupActual, true);

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();*/

		GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(GrupActual);

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}
}
#include "pch.h"
#include "GrupEstudi_ExplorarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "Usuari.h"

namespace CppCLRWinFormsProject {
	GrupEstudi_Explorar::GrupEstudi_Explorar(String^ groupname)
	{
		InitializeComponent();
		grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
		grupEstudiService = gcnew GrupEstudiService();
		notificacioService = gcnew NotificacioService();
		arrayIdGroupEstudisOfUserNoIn = GrupEstudi_Explorar_Array();
		this->Icon = gcnew System::Drawing::Icon("app.ico");
		this->groupname = groupname;
		this->Description_titulo->Text = L"Descripci\u00f3";
	}

	array<GrupEstudi^>^ GrupEstudi_Explorar::GrupEstudi_Explorar_Array() {
		Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
		array<GrupEstudi^>^ arrayIdGroupEstudisOfUser = grupEstudiService->LoadGrupsNoMembers(currentUser->GetUserId());
		return arrayIdGroupEstudisOfUser;
	}

	void GrupEstudi_Explorar::GrupEstudi_Explorar_Load(System::Object^ sender, System::EventArgs^ e) {

		Noms_ListBox->Items->Clear();

		if (arrayIdGroupEstudisOfUserNoIn->Length == 0) {
			Noms_ListBox->Items->Add("No hi ha cap grup d'estudi disponible per a tu.");
			Noms_ListBox->ForeColor = System::Drawing::Color::Gray;
			Noms_ListBox->Enabled = false;
		}
		else {
			Noms_ListBox->ForeColor = System::Drawing::Color::Black;
			Noms_ListBox->Enabled = true;
			for (int i = 0; i < arrayIdGroupEstudisOfUserNoIn->Length; i++) {
				Noms_ListBox->Items->Add(arrayIdGroupEstudisOfUserNoIn[i]->GetGroupName());
				if (arrayIdGroupEstudisOfUserNoIn[i]->GetGroupName() == groupname) {
					Noms_ListBox->SelectedIndex = i;
				}
			}
		}
	}

	void GrupEstudi_Explorar::Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		Membres_Button->Visible = true;
		Unirse_Button->Visible = true;
		Unirse_Button->Text = "Solicitar unir-se";

		Description_titulo->Visible = true;
		Num_membres->Visible = true;
		academicTag_titulo->Visible = true;

		nummem->Clear();
		nummem->Visible = true;
		numero_membres(sender, e);

		academictag->Clear();
		academictag->Visible = true;
		academic_tag(sender, e);

		Description_ListBox->Items->Clear();
		Description_ListBox->Visible = true;
		Description_ListBox_Load(sender, e);

		Int64^ source_grup_id = grupEstudiService->GetGroupIdByName(Noms_ListBox->Text);
		Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
		Int64^ source_user_id = currentUser->GetUserId();

		if (notificacioService->CheckIfRequestExists(source_grup_id, source_user_id)) {
			Unirse_Button->Text = "Solicitud pendent";
		}
		else if (grupEstudiMembershipService->CheckIfUserIsInGroup(source_user_id, source_grup_id)) {
			Unirse_Button->Text = "Ja perteneixes al grup";
		}
	}

	void GrupEstudi_Explorar::GrupEstudi_Explorar_FormClosed() {
		Membres_Button->Visible = false;
		Unirse_Button->Visible = false;

		Description_titulo->Visible = false;
		Num_membres->Visible = false;
		academicTag_titulo->Visible = false;

		nummem->Visible = false;
		academictag->Visible = false;
		Description_ListBox->Visible = false;
	}

	void GrupEstudi_Explorar::academic_tag(System::Object^ sender, System::EventArgs^ e) {
		GrupEstudi^ grupEstudi = grupEstudiService->GetGrupEstudiByName(Noms_ListBox->Text);
		Int64^ academic_tag_id = grupEstudi->GetGroupAcademicTag();
		String^ academic_tag_name = grupEstudiService->GetAcademicTagNameById(academic_tag_id);
		academictag->Text = academic_tag_name;
	}

	void GrupEstudi_Explorar::numero_membres(System::Object^ sender, System::EventArgs^ e) {
		Int64^ id_group = grupEstudiService->GetGroupIdByName(Noms_ListBox->Text);
		array<Int64^>^ arrayIdMemberOfGroupEstudis = grupEstudiMembershipService->LoadMembershipByGrupsEstudi(id_group);
		int num_mem_int = arrayIdMemberOfGroupEstudis->Length;
		String^ num_mem_str = Convert::ToString(num_mem_int);
		nummem->Text = num_mem_str;
	}

	void GrupEstudi_Explorar::Description_ListBox_Load(System::Object^ sender, System::EventArgs^ e) {
		GrupEstudi^ grupEstudi = grupEstudiService->GetGrupEstudiByName(Noms_ListBox->Text);
		String^ description = grupEstudi->GetDescription();
		Description_ListBox->Items->Add(description);
	}

	void GrupEstudi_Explorar::Membres_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(Noms_ListBox->Text, false);

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}

	void GrupEstudi_Explorar::Unirse_Button_Click(System::Object^ sender, System::EventArgs^ e) {

		Int64^ source_grup_id = grupEstudiService->GetGroupIdByName(Noms_ListBox->Text);
		Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
		Int64^ source_user_id = currentUser->GetUserId();

		if (notificacioService->CheckIfRequestExists(source_grup_id, source_user_id)) {
			MessageManager::WarningMessage("Ja has sol·licitat unir-te a aquest grup.");
			return;
		}
		if (grupEstudiMembershipService->CheckIfUserIsInGroup(source_user_id, source_grup_id)) {
			MessageManager::WarningMessage("Ja perteneixes al grup.");
			return;
		}
		Int64^ destination_user_id = grupEstudiService->GetGrupOwnerId(source_grup_id);
		Int64^ status = 1LL;
		Int64^ notification_type = 1LL;
		MessageManager::InfoMessage("Solicitud enviada.");

		notificacioService->AddNotificacio(notification_type, status, source_grup_id, source_user_id, destination_user_id);
		Unirse_Button->Text = "Solicitud pendent";


		

	}

	void GrupEstudi_Explorar::buscar_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		String^ buscar_grup = buscador_textBox->Text;
		if (Noms_ListBox->Items->Contains(buscar_grup)) {
			Noms_ListBox->SelectedItem = buscar_grup;
		}
		else {
			MessageManager::ErrorMessage("No s'ha trobat cap grup amb aquest nom");

			buscador_textBox->Clear();
			GrupEstudi_Explorar_FormClosed();
		}
	}

	void GrupEstudi_Explorar::buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e) {
		if (buscador_textBox->Text == "Buscar Grup d'Estudi...") { buscador_textBox->Clear(); }
		buscador_textBox->ForeColor = Color::Black;
	}

	void GrupEstudi_Explorar::buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (buscador_textBox->Text == "Buscar Grup d'Estudi...") {
			GrupEstudi_Explorar_Load(sender, e);
		}
		else {
			String^ buscar_grup = buscador_textBox->Text;
			Noms_ListBox->Items->Clear();
			GrupEstudi_Explorar_FormClosed();
			for (int i = 0; i < arrayIdGroupEstudisOfUserNoIn->Length; i++) {
				GrupEstudi^ grupEstudiUser = arrayIdGroupEstudisOfUserNoIn[i];
				String^ groupName = grupEstudiUser->GetGroupName();
				if (groupName->Contains(buscar_grup)) {
					Noms_ListBox->Items->Add(groupName);
				}
			}

			if (Noms_ListBox->Items->Count == 0) {
				MessageManager::ErrorMessage("No s'ha trobat cap grup amb aquest nom");
				buscador_textBox->Enabled = false;
				buscador_textBox->Enabled = true;
				buscador_textBox->ForeColor = System::Drawing::SystemColors::ActiveCaption;
				buscador_textBox->Text = L"Buscar Grup d\'Estudi...";
				GrupEstudi_Explorar_FormClosed();
			}
		}
	}
}
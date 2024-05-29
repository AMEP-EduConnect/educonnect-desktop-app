#include "pch.h"
#include "Session_CalendariUI.h"

namespace CppCLRWinFormsProject {

	Session_CalendariUI::Session_CalendariUI(void) {
		InitializeComponent();
		i = 0;
		Session_CalendariUI_ReLoad();
	}

	System::Void Session_CalendariUI::Session_CalendariUI_Load(System::Object^ sender, System::EventArgs^ e) {
		Session_CalendariUI_ReLoad();
	}

	System::Void Session_CalendariUI::Session_CalendariUI_ReLoad() {
		Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
		array<Int64^>^ idgrups = grupEstudiMembershipService->LoadGrupsEstudiMembershipByUserId(currentUser->GetUserId());
		sessionsdia = sessionService->GetSessionsByGroupIdArray(idgrups);
		i = 0;
		DaySessions->Text = Convert::ToString(sessionsdia->Length);
		int aux = i + 1;
		Contador->Text = Convert::ToString(aux);
		NomGrup->Text = grupEstudiService->GetGrupEstudiById(sessionsdia[i]->GetGroupId())->GetGroupName();
		Espai^ espai = consultaEspaisService->GetEspaiByEspaiId(sessionsdia[i]->GetEspaiId());
		NomEspai->Text = espai->GetName();
		NomSessió->Text = sessionsdia[i]->GetSessionName();
		Data->Text = sessionsdia[i]->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = sessionsdia[i]->GetSessionStartDate()->ToString("HH:mm") + " - " + sessionsdia[0]->GetSessionEndDate()->ToString("HH:mm");
		Capacity->Text = Convert::ToString(espai->GetCapacity());
		Attendants->Text = Convert::ToString(grupSessionAttendantsService->GetSessionAttendantsCount(sessionsdia[i]->GetId()));
		Anterior_Button->Visible = false;
		if (sessionsdia->Length == 1) Seguent_Button->Visible = false;
		else Seguent_Button->Visible = true;
	}

	System::Void Session_CalendariUI::monthCalendar1_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		Session_CalendariUI_ReLoad();
	}

	System::Void Session_CalendariUI::SeguentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		++i;
		if (i >= sessionsdia->Length-1) Seguent_Button->Visible = false;
		Anterior_Button->Visible = true;

		int aux = i + 1;
		Contador->Text = Convert::ToString(aux);
		NomGrup->Text = grupEstudiService->GetGrupEstudiById(sessionsdia[i]->GetGroupId())->GetGroupName();
		NomEspai->Text = consultaEspaisService->GetEspaiByEspaiId(sessionsdia[i]->GetEspaiId())->GetName();
		NomSessió->Text = sessionsdia[i]->GetSessionName();
		Data->Text = sessionsdia[i]->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = sessionsdia[i]->GetSessionStartDate()->ToString("HH:mm") + " - " + sessionsdia[0]->GetSessionEndDate()->ToString("HH:mm");
	}

	System::Void Session_CalendariUI::AnteriorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		--i;
		if (i == 0) Anterior_Button->Visible = false;
		Seguent_Button->Visible = true;

		int aux = i + 1;
		Contador->Text = Convert::ToString(aux);
		NomGrup->Text = grupEstudiService->GetGrupEstudiById(sessionsdia[i]->GetGroupId())->GetGroupName();
		NomEspai->Text = consultaEspaisService->GetEspaiByEspaiId(sessionsdia[i]->GetEspaiId())->GetName();
		NomSessió->Text = sessionsdia[i]->GetSessionName();
		Data->Text = sessionsdia[i]->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = sessionsdia[i]->GetSessionStartDate()->ToString("HH:mm") + " - " + sessionsdia[0]->GetSessionEndDate()->ToString("HH:mm");
	}

}
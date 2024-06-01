#include "pch.h"
#include "Session_CalendariUI.h"

namespace CppCLRWinFormsProject {

	Session_CalendariUI::Session_CalendariUI(void) {
		InitializeComponent();
		i = 0;
		grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
		grupEstudiService = gcnew GrupEstudiService();
		sessionService = gcnew SessionService();
		grupSessionAttendantsService = gcnew GrupSessionAttendantsService();
		consultaEspaisService = gcnew ConsultaEspaisService();
		Session_CalendariUI_ReLoad();
	}

	System::Void Session_CalendariUI::Session_CalendariUI_ReLoad() {
		Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
		//array<Int64^>^ idgrups = grupEstudiMembershipService->LoadGrupsEstudiMembershipByUserId(currentUser->GetUserId());
		array<Int64^>^ idsessions = grupSessionAttendantsService->GetIdSessions(currentUser->GetUserId());
		array<Session^>^ sessions = gcnew array<Session^>(idsessions->Length);
		for (int i = 0; i < idsessions->Length; ++i) {
			sessions[i] = sessionService->GetSessionById(idsessions[i]);
		}
		DateTime selectedDate = monthCalendar1->SelectionStart;
		String^ dateString = selectedDate.ToString("yyyy-MM-dd");
		List<Session^>^ daySessions;
		for (int i = 0; i < sessions->Length; ++i) {
			DateTime^ sessionDate = sessions[i]->GetSessionStartDate();
			if ((*sessionDate).ToString("yyyy-MM-dd") == dateString) {
				daySessions->Add(sessions[i]);
			}
		}
		if (daySessions->Count == 0) {
			//Mensaje = "No tens sessions el dia + dateString"
		}
		else {
			i = 0;
			DaySessions->Text = Convert::ToString(daySessions->Count);
			int aux = i + 1;
			Contador->Text = Convert::ToString(aux);

			// create a Iterator daySessions
			enumerator = daySessions->GetEnumerator();
			while (enumerator->MoveNext()) {
				Session^ session = enumerator->Current;
				break;
			}
			
			NomGrup->Text = grupEstudiService->GetGrupEstudiById(enumerator->Current->GetGroupId())->GetGroupName();
			Espai^ espai = consultaEspaisService->GetEspaiByEspaiId(enumerator->Current->GetEspaiId());
			NomEspai->Text = espai->GetName();
			NomSessió->Text = enumerator->Current->GetSessionName();
			Data->Text = enumerator->Current->GetSessionStartDate()->ToString("dd/MM/yyyy");
			Horari->Text = enumerator->Current->GetSessionStartDate()->ToString("HH:mm") + " - " + enumerator->Current->GetSessionEndDate()->ToString("HH:mm");
			Capacity->Text = Convert::ToString(espai->GetCapacity());
			Attendants->Text = Convert::ToString(grupSessionAttendantsService->GetSessionAttendantsCount(enumerator->Current->GetId()));
			Anterior_Button->Visible = false;
			if (sessionsdia->Count == 1) Seguent_Button->Visible = false;
			else {
				Seguent_Button->Visible = true;
				Seguent_Button->Enabled = true;
			}

		}
		/*
		if (idgrups->Length == 0) {
			Anterior_Button->Visible = false;
			Seguent_Button->Visible = false;
			
		}
		
		else {
			
			DateTime selectedDate = monthCalendar1->SelectionStart;
			String^ dateString = selectedDate.ToString("yyyy-MM-dd");
			sessionsdia = sessionService->GetSessionsByGroupIdArray(idgrups, dateString+" 00:00:00", dateString+" 23:59:00");
			if (sessionsdia->Count == 0) {
				Anterior_Button->Visible = false;
				Seguent_Button->Visible = false;
				
			}
			else {
				i = 0;
				DaySessions->Text = Convert::ToString(sessionsdia->Count);
				int aux = i + 1;
				Contador->Text = Convert::ToString(aux);
				// create a Iterator sessionsdia
				enumerator = sessionsdia->GetEnumerator();
				while (enumerator->MoveNext()) {
					Session^ session = enumerator->Current;
					break;
				}

				NomGrup->Text = grupEstudiService->GetGrupEstudiById(enumerator->Current->GetGroupId())->GetGroupName();
				Espai^ espai = consultaEspaisService->GetEspaiByEspaiId(enumerator->Current->GetEspaiId());
				NomEspai->Text = espai->GetName();
				NomSessió->Text = enumerator->Current->GetSessionName();
				Data->Text = enumerator->Current->GetSessionStartDate()->ToString("dd/MM/yyyy");
				Horari->Text = enumerator->Current->GetSessionStartDate()->ToString("HH:mm") + " - " + enumerator->Current->GetSessionEndDate()->ToString("HH:mm");
				Capacity->Text = Convert::ToString(espai->GetCapacity());
				Attendants->Text = Convert::ToString(grupSessionAttendantsService->GetSessionAttendantsCount(enumerator->Current->GetId()));
				Anterior_Button->Visible = false;
				if (sessionsdia->Count == 1) Seguent_Button->Visible = false;
				else {
					Seguent_Button->Visible = true;
					Seguent_Button->Enabled = true;
				}*/
	}

	System::Void Session_CalendariUI::monthCalendar1_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {
		Session_CalendariUI_ReLoad();
	}

	System::Void Session_CalendariUI::SeguentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		++i;
		if (i >= sessionsdia->Count-1) Seguent_Button->Visible = false;
		Anterior_Button->Visible = true;
		Anterior_Button->Enabled = true;
		int aux = i + 1;
		Contador->Text = Convert::ToString(aux);
		enumerator->MoveNext();
		/*NomGrup->Text = grupEstudiService->GetGrupEstudiById(sessionsdia[i]->GetGroupId())->GetGroupName();
		NomEspai->Text = consultaEspaisService->GetEspaiByEspaiId(sessionsdia[i]->GetEspaiId())->GetName();
		NomSessió->Text = sessionsdia[i]->GetSessionName();
		Data->Text = sessionsdia[i]->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = sessionsdia[i]->GetSessionStartDate()->ToString("HH:mm") + " - " + sessionsdia[0]->GetSessionEndDate()->ToString("HH:mm");*/
		NomGrup->Text = grupEstudiService->GetGrupEstudiById(enumerator->Current->GetGroupId())->GetGroupName();
		NomEspai->Text = consultaEspaisService->GetEspaiByEspaiId(enumerator->Current->GetEspaiId())->GetName();
		NomSessió->Text = enumerator->Current->GetSessionName();
		Data->Text = enumerator->Current->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = enumerator->Current->GetSessionStartDate()->ToString("HH:mm") + " - " + enumerator->Current->GetSessionEndDate()->ToString("HH:mm");
	}

	System::Void Session_CalendariUI::AnteriorButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int aux2 = i;
		--i;
		if (i == 0) Anterior_Button->Visible = false;
		Seguent_Button->Visible = true;
		enumerator = sessionsdia->GetEnumerator();
		int aux_3 = 0;
		while(enumerator->MoveNext()) {
			if (aux_3 == aux2-1) break;
			++aux_3;
		}
		int aux = i + 1;
		Contador->Text = Convert::ToString(aux);
		/*NomGrup->Text = grupEstudiService->GetGrupEstudiById(sessionsdia[i]->GetGroupId())->GetGroupName();
		NomEspai->Text = consultaEspaisService->GetEspaiByEspaiId(sessionsdia[i]->GetEspaiId())->GetName();
		NomSessió->Text = sessionsdia[i]->GetSessionName();
		Data->Text = sessionsdia[i]->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = sessionsdia[i]->GetSessionStartDate()->ToString("HH:mm") + " - " + sessionsdia[0]->GetSessionEndDate()->ToString("HH:mm");*/
		NomGrup->Text = grupEstudiService->GetGrupEstudiById(enumerator->Current->GetGroupId())->GetGroupName();
		NomEspai->Text = consultaEspaisService->GetEspaiByEspaiId(enumerator->Current->GetEspaiId())->GetName();
		NomSessió->Text = enumerator->Current->GetSessionName();
		Data->Text = enumerator->Current->GetSessionStartDate()->ToString("dd/MM/yyyy");
		Horari->Text = enumerator->Current->GetSessionStartDate()->ToString("HH:mm") + " - " + enumerator->Current->GetSessionEndDate()->ToString("HH:mm");
	}

}
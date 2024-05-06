#include "pch.h"
#include "Session_EditarUI.h"
#include "Usuari.h"
#include "GrupEstudi_InfoUI.h"
#include "MainPageUI.h";
#include "Espai.h"

namespace CppCLRWinFormsProject {

	Session_EditarUI::Session_EditarUI(GrupEstudi^ CurrentGrupEntity, Int64^ sessionId)
	{
		InitializeComponent();
		this->CurrentGrupEntity = CurrentGrupEntity;
		this->sessionService = gcnew SessionService();
		this->consultaEspaisService = gcnew ConsultaEspaisService();
		this->iniciSessioService = gcnew IniciSessioService();
		this->baixaProveidorService = gcnew BaixaProveidorService();
		this->FullyFormatedSessionDate = gcnew DateTime();
		this->CurrentSessionEntity = this->sessionService->GetSessionById(sessionId);
		this->IsLoaded = false;
	}

	System::Void Session_EditarUI::Session_EditarUI_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->LoadProveidorsOnList();
		this->DayMonth_Calendar->SetDate((this->CurrentSessionEntity->GetSessionStartDate()->Date));
		this->TimeHour_ComboBox->Text = (this->CurrentSessionEntity->GetSessionStartDate()->ToString("HH:mm") + " - " + this->CurrentSessionEntity->GetSessionEndDate()->ToString("HH:mm"));
		this->LoadEspaiTimeStampsOfCurrentDay();
		this->SessionName_Label->Text = this->CurrentSessionEntity->GetSessionName();
		this->SessionName_TextBox->Text = this->CurrentSessionEntity->GetSessionName();
		String^ username = this->baixaProveidorService->GetProveidorByEspaiId(this->CurrentSessionEntity->GetEspaiId())->GetUsername();
		Object^ usernameObj = username; 
		int index = this->Proveidor_ListBox->Items->IndexOf(usernameObj);
		this->Proveidor_ListBox->SetSelected(index, true);
		this->LoadEspaisFromSelectedProveidor();
		Espai^ espai = this->consultaEspaisService->GetEspaiByEspaiId(this->CurrentSessionEntity->GetEspaiId());
		this->Espai_ComboBox->Text = espai->GetName() + " - max: " + espai->GetCapacity();
		this->IsLoaded = true;

	}

	System::Void Session_EditarUI::SessionName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if(IsLoaded) this->EditarNom_Button->Enabled = true;

	}

	System::Void Session_EditarUI::Proveidor_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (IsLoaded) this->EditarProveidor_Button->Enabled = true;
	}

	System::Void Session_EditarUI::TimeHour_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		
		if (this->FullyFormatedSessionDate != nullptr && this->TimeHour_ComboBox->Text != "")
		{
			if (IsLoaded)
			{
				this->FullyFormatedSessionDate = this->DayMonth_Calendar->SelectionStart;
				*FullyFormatedSessionDate = this->FormatTimeStringIntoDateTime(this->TimeHour_ComboBox->Text);
				MessageManager::InfoMessage(" 1 La data seleccionada és: " + FullyFormatedSessionDate->ToString());
				bool isFree = this->sessionService->CheckIfTimeStampIsFree(FullyFormatedSessionDate);
				if (!isFree)
				{
					MessageManager::ErrorMessage("La data seleccionada ja està ocupada per una sessió.");
				}
				else {
					if (IsLoaded) this->EditarTemps_Button->Enabled = true;
				}
			}
		}
	}

	System::Void Session_EditarUI::DayMonth_Calendar_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e)
	{
		if(IsLoaded) this->OnCalendarDateChanged();
	}
	System::Void Session_EditarUI::Espai_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (IsLoaded) this->EditarEspai_Button->Enabled = true;
	}

	System::Void Session_EditarUI::EditarNom_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->FieldsNotEmpty())
		{
			bool nameIsAvailable = this->sessionService->CheckIfSessionNameIsAvailable(this->SessionName_TextBox->Text);
			if (!nameIsAvailable) {
				MessageManager::ErrorMessage("Ja existeix una sessió amb aquest nom.");
				return;
			}
			else
			{
				if (this->sessionService->UpdateSessionName(this->SessionName_TextBox->Text, this->CurrentSessionEntity->GetSessionName()))
				{
					MessageManager::InfoMessage("Nom de la sessió actualitzat correctament.");
					this->SessionName_Label->Text = this->SessionName_TextBox->Text;
					this->EditarNom_Button->Enabled = false;
				}
				else
				{
					MessageManager::ErrorMessage("Error al actualitzar el nom de la sessió.");
				}

			}
		}
	}

	System::Void Session_EditarUI::EditarProveidor_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->LoadEspaisFromSelectedProveidor();
		this->EditarProveidor_Button->Enabled = false;
	}

	System::Void Session_EditarUI::EditarEspai_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->FieldsNotEmpty())
		{
			String^ realName = this->sessionService->GetFormattedEspai(this->Espai_ComboBox->Text);
			bool espaiExists = this->consultaEspaisService->CheckIfEspaiExistsByName(realName);
			if (!espaiExists)
			{
				MessageManager::ErrorMessage("L'espai seleccionat no existeix.");
				return;
			}
			else
			{
				Int64^ espaiId = this->consultaEspaisService->GetEspaiIdByName(realName);
				if (this->sessionService->UpdateSessionEspai(espaiId, this->CurrentSessionEntity->GetEspaiId()))
				{
					MessageManager::InfoMessage("Espai de la sessió actualitzat correctament.");
					this->EditarEspai_Button->Enabled = false;
				}
				else
				{
					MessageManager::ErrorMessage("Error al actualitzar l'espai de la sessió.");
				}
			}
		}
	}

	System::Void Session_EditarUI::EditarTemps_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->FieldsNotEmpty())
		{
			if (this->sessionService->UpdateSessionDate(FullyFormatedSessionDate, this->CurrentSessionEntity->GetId()))
			{
				MessageManager::InfoMessage("Data de la sessió actualitzada correctament.");
				this->EditarTemps_Button->Enabled = false;
			}
			else
			{
				MessageManager::ErrorMessage("Error al actualitzar la data de la sessió.");
			}
		}
	}
	System::Void Session_EditarUI::GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI((this->CurrentGrupEntity)->GetGroupName());

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}

	DateTime Session_EditarUI::FormatTimeStringIntoDateTime(String^ espaiString)
	{
		Double formattedHour = this->sessionService->GetFormattedHour(espaiString);
		DateTime sessionDate = *FullyFormatedSessionDate;
		sessionDate = sessionDate.Date;
		sessionDate = sessionDate.AddHours(formattedHour);
		return sessionDate;
	}

	void Session_EditarUI::LoadEspaiTimeStampsOfCurrentDay()
	{
		this->TimeHour_ComboBox->Items->Clear();
		this->TimeHour_ComboBox->Enabled = true;
		List<String^>^ TimeStamps = this->sessionService->GenerateAllTimeStamps();
		System::Collections::Generic::IEnumerator<String^>^ enumerator = TimeStamps->GetEnumerator();
		while (enumerator->MoveNext())
		{
			DateTime CurrentTimeStamp = this->FormatTimeStringIntoDateTime(enumerator->Current);
			bool isFree = this->sessionService->CheckIfTimeStampIsFree(CurrentTimeStamp);
			if (isFree)
			{
				this->TimeHour_ComboBox->Items->Add(enumerator->Current);
			}
		}
	}

	void Session_EditarUI::LoadEspaisFromSelectedProveidor()
	{
		this->Espai_ComboBox->Items->Clear();
		this->Espai_ComboBox->Enabled = true;
		Usuari^ Proveidor = this->iniciSessioService->GetUsuariByUser(this->Proveidor_ListBox->Text);
		List<Espai^>^ Espais = this->consultaEspaisService->ListEspais(Proveidor->GetUserId());
		System::Collections::Generic::IEnumerator<Espai^>^ enumerator = Espais->GetEnumerator();
		while (enumerator->MoveNext())
		{
			this->Espai_ComboBox->Items->Add(enumerator->Current->GetName() + " - max: " + enumerator->Current->GetCapacity());
		}
	}

	void Session_EditarUI::LoadProveidorsOnList()
	{
		List<Usuari^>^ Proveidors = this->baixaProveidorService->ListProveidors();
		System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = Proveidors->GetEnumerator();
		while (enumerator->MoveNext())
		{
			this->Proveidor_ListBox->Items->Add(enumerator->Current->GetUsername());
		}

	}
	
	void Session_EditarUI::OnCalendarDateChanged()
	{
		this->FullyFormatedSessionDate = this->DayMonth_Calendar->SelectionStart;
		this->LoadEspaiTimeStampsOfCurrentDay();
	}

	bool Session_EditarUI::FieldsNotEmpty()
	{
		if (this->Proveidor_ListBox->Text == "" ||
			this->Espai_ComboBox->Text == "" ||
			this->SessionName_TextBox->Text == "" ||
			this->TimeHour_ComboBox->Text == "")
		{
			MessageManager::ErrorMessage("Els camps no poden estar buits.");
			return false;
		}
		return true;
	}
}

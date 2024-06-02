#include "pch.h"
#include "Session_CrearUI.h"
#include "GrupEstudi_InfoUI.h"
#include "MainPageUI.h"
#include "MessageManager.h"

namespace CppCLRWinFormsProject {

	Session_CrearUI::Session_CrearUI(GrupEstudi^ CurrentGrupEntity)
	{
		InitializeComponent();
		this->CurrentGrupEntity = CurrentGrupEntity;
		this->baixaProveidorService = gcnew BaixaProveidorService();
		this->sessionService = gcnew SessionService();	
		this->grupEstudiService = gcnew GrupEstudiService();
		this->consultaEspaisService = gcnew ConsultaEspaisService();
		this->iniciSessioService = gcnew IniciSessioService();
		this->FullyFormatedSessionDate = gcnew DateTime();
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	System::Void Session_CrearUI::Session_CrearUI_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->CurrentGrupName_Label->Text = this->CurrentGrupEntity->GetGroupName();
		this->LoadProveidorsOnList();
	}

	System::Void Session_CrearUI::GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI((this->CurrentGrupEntity)->GetGroupName(),1);

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}

	System::Void Session_CrearUI::Proveidor_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->LoadEspaisFromSelectedProveidor();
	}

	System::Void Session_CrearUI::DayMonth_Calendar_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e)
	{
		if (!this->sessionService->CheckIfSelectedDayMonthIsOlderThanCurrentTime(this->DayMonth_Calendar->SelectionStart))
		{
			MessageManager::ErrorMessage("No es poden seleccionar dates passades.");
			this->DayMonth_Calendar->SelectionStart = DateTime::Now;
			return;
		}
		this->FullyFormatedSessionDate = this->DayMonth_Calendar->SelectionStart;
		this->LoadEspaiTimeStampsOfCurrentDay();
	}

	System::Void Session_CrearUI::Espai_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		return System::Void();
	}

	System::Void Session_CrearUI::TimeHour_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->FullyFormatedSessionDate != nullptr && this->TimeHour_ComboBox->Text != "")
		{

			*FullyFormatedSessionDate = this->FormatTimeStringIntoDateTime(this->TimeHour_ComboBox->Text);
			bool isFree = this->sessionService->CheckIfTimeStampIsFree(FullyFormatedSessionDate);
			if (isFree)
			{
				this->CreateSession_Button->Enabled = true;
			}
			else
			{
				MessageManager::ErrorMessage("La data seleccionada ja està ocupada per una sessi\u00F3.");
				this->CreateSession_Button->Enabled = false;
			}
		}
	}

	System::Void Session_CrearUI::CreateSession_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->FieldsNotEmpty())
		{
			bool nameIsAvailable = this->sessionService->CheckIfSessionNameIsAvailable(this->SessionName_TextBox->Text);
			if (!nameIsAvailable) {
				MessageManager::ErrorMessage("Ja existeix una sessi\u00F3 amb aquest nom.");
				return;
			}
			bool isFree = this->sessionService->CheckIfTimeStampIsFree(FullyFormatedSessionDate);
			if (!isFree)
			{
				MessageManager::ErrorMessage("La data seleccionada ja està ocupada per una sessi\u00F3.");
				return;
			}
			String^ realName = this->sessionService->GetFormattedEspai(this->Espai_ComboBox->Text);
			bool espaiExists = this->consultaEspaisService->CheckIfEspaiExistsByName(realName);
			if (!espaiExists)
			{
				MessageManager::ErrorMessage("L'espai seleccionat no existeix.");
				return;
			}

			bool isCreated = this->sessionService->CreateSession(
				this->CurrentGrupEntity->GetId(),
				this->Espai_ComboBox->Text,
				this->SessionName_TextBox->Text,
				this->FullyFormatedSessionDate
			);

			if (isCreated)
			{
				MessageManager::InfoMessage("Sessi\u00F3 creada correctament.");
				this->GoBack_Button_Click(sender, e);
			}
			else
			{
				MessageManager::ErrorMessage("No s'ha pogut crear la sessi\u00F3.");
			}
		}
	}

	bool Session_CrearUI::FieldsNotEmpty()
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

	DateTime Session_CrearUI::FormatTimeStringIntoDateTime(String^ espaiString)
	{
		Double formattedHour = this->sessionService->GetFormattedHour(espaiString);
		DateTime sessionDate = *FullyFormatedSessionDate;
		sessionDate = sessionDate.Date;
		sessionDate = sessionDate.AddHours(formattedHour);
		return sessionDate;
	}

	void Session_CrearUI::LoadEspaiTimeStampsOfCurrentDay()
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
				if (!this->sessionService->CheckIfTimeStampIsOlderThanCurrentTime(CurrentTimeStamp))
				{
					this->TimeHour_ComboBox->Items->Add(enumerator->Current);
				}
			}
		}
	}

	void Session_CrearUI::LoadEspaisFromSelectedProveidor()
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

	void Session_CrearUI::LoadProveidorsOnList()
	{
		List<Usuari^>^ Proveidors = this->baixaProveidorService->ListProveidors();
		System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = Proveidors->GetEnumerator();
		while (enumerator->MoveNext())
		{
			this->Proveidor_ListBox->Items->Add(enumerator->Current->GetUsername());
		}

	}
};


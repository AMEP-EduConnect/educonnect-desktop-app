#include "pch.h"
#include "GrupEstudi_InfoUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "MainPageUI.h"
#include "Session_CrearUI.h"
#include "Session_EditarUI.h"
#include "Session.h"
#include "CurrentSession.h"
#include "Usuari.h"


namespace CppCLRWinFormsProject {

    GrupEstudi_InfoUI::GrupEstudi_InfoUI(String^ CurrentGrup)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
        this->CurrentGrupEntity = this->grupEstudiService->GetGrupEstudiByName(CurrentGrup);
        sessionService = gcnew SessionService();
        grupSessionAttendantsService = gcnew GrupSessionAttendantsService();
        consultaEspaisService = gcnew ConsultaEspaisService();
        this->Icon = gcnew System::Drawing::Icon("app.ico");
        sessionService = gcnew SessionService();
        this->Sessions_Actuals_Load();
    }

    void GrupEstudi_InfoUI::GrupEstudi_InfoUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        this->AcademicTagsInfo_Label->Text = this->grupEstudiService->GetAcademicTagNameById(this->CurrentGrupEntity->GetGroupAcademicTag());
        this->InfoGrupEstudi_Label->Text = this->CurrentGrupEntity->GetGroupName();
        this->DescGrupEstudi_Label->Text = this->CurrentGrupEntity->GetDescription();
        this->ActivateButtonsIfOwner();
        this->Load += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::SelectLastSessionOrPlaceholder);

    }

    void GrupEstudi_InfoUI::SelectLastSessionOrPlaceholder(System::Object^ sender, System::EventArgs^ e)
    {
            System::Collections::Generic::IEnumerator<Session^>^ enumerator = SessionsList->GetEnumerator();
            if (Sessions_ListBox->SelectedIndex != -1)
            {
                // Cas
                int select_index = Sessions_ListBox->SelectedIndex;

                int i = 0;
                while (enumerator->MoveNext()) {
                    if (i == select_index) {
                        CurrentSessionEntity = enumerator->Current;
                        break;
                    }
                    i++;
                }

                session_name->Text = CurrentSessionEntity->GetSessionName();
                EspaiName_Label->Text = consultaEspaisService->GetEspaiInfoById(CurrentSessionEntity->GetEspaiId());
                DayMonthYear_label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("dd/MM/yyyy");
                StartEndDuration_Label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("HH:mm") + " - " + CurrentSessionEntity->GetSessionEndDate()->ToString("HH:mm");
                if (not grupSessionAttendantsService->IsAttendant(CurrentSessionEntity->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId())) {
                    this->Confirm_Cancel_Attent_Button->Text = "Asistir";
                }
                else {
                    this->Confirm_Cancel_Attent_Button->Text = L"Cancel·lar Asistència";
                }
                
            }
		

    }
   
    void GrupEstudi_InfoUI::ActivateButtonsIfOwner()
    {
    	Int64^ CurrentUserId = (CurrentSession::Instance->GetCurrentUser())->GetUserId();
        if (*CurrentUserId == *this->CurrentGrupEntity->GetGroupOwnerId())
        {
			this->ModifyGrupEstudi_Button->Visible = true;
			this->ModifySession_Button->Visible = true;
            this->DeleteGrupEstudi_Button->Visible = true;
            this->DeleteSession_Button->Visible = true;
            this->NewSession_Button->Visible = true;
        
		}
    
    }

    System::Void GrupEstudi_InfoUI::NewSession_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Session_CrearUI^ PanelUI = gcnew Session_CrearUI(this->CurrentGrupEntity);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    System::Void GrupEstudi_InfoUI::Sessions_Actuals_Load()
    {
        this->Sessions_ListBox->Items->Clear();
        SessionsList = this->sessionService->GetSessionsByGroupIdAndStartDate(this->CurrentGrupEntity->GetId(), DateTime::Now);

        if (SessionsList->Count > 0) {
            System::Collections::Generic::IEnumerator<Session^>^ Enumerator = SessionsList->GetEnumerator();
            int i = 0;
            while (Enumerator->MoveNext())
            {
                if (i == 0) {
                    CurrentSessionEntity = Enumerator->Current;
                    i = 1;
                }
                Session^ CurrentSession = Enumerator->Current;
                this->Sessions_ListBox->Items->Add(CurrentSession->GetSessionName());
            }
            EspaiName_Label->Visible = true;
            StartEndDuration_Label->Visible = true;
            DayMonthYear_label->Visible = true;
            Confirm_Cancel_Attent_Button->Visible = true;
            ViewSessionAttendants_Button->Visible = true;
            SessionCapacity_Label1->Visible = true;
            EspaiCapacity_Label->Visible = true;
            session_name->Visible = true;
            session_name->Text = CurrentSessionEntity->GetSessionName();
            EspaiName_Label->Text = consultaEspaisService->GetEspaiInfoById(CurrentSessionEntity->GetEspaiId());
            DayMonthYear_label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("dd/MM/yyyy");
            StartEndDuration_Label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("HH:mm") + " - " + CurrentSessionEntity->GetSessionEndDate()->ToString("HH:mm");
            if (not grupSessionAttendantsService->IsAttendant(CurrentSessionEntity->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId())) {
                this->Confirm_Cancel_Attent_Button->Text = "Asistir";
            }
            else {
				this->Confirm_Cancel_Attent_Button->Text = L"Cancel·lar Asistència";
			}
            
        }

    }
    System::Void GrupEstudi_InfoUI::Confirm_Cancel_Attent_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Int64^ idsession = CurrentSessionEntity->GetId();
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        Int64^ iduser = currentUser->GetUserId();

        if (not grupSessionAttendantsService->IsAttendant(idsession, iduser)) {
           
           grupSessionAttendantsService->AsistirSessionAttendant(idsession, iduser);
           String^ cap2 = capacity->Text;
           Int64^ cap = Convert::ToInt64(cap2);
           *cap += 1ll;
           capacity->Text = Convert::ToString(*cap);
           this->Confirm_Cancel_Attent_Button->Text = L"Cancel·lar Asistència";
           //sumar 1 a capacidad en base de datos
       }
       else {
           
           grupSessionAttendantsService->EliminaSessionAttendant(idsession, iduser);
           String^ cap2 = capacity->Text;
           Int64^ cap = Convert::ToInt64(cap2);
           *cap -= 1ll;
           capacity->Text = Convert::ToString(*cap);

           this->Confirm_Cancel_Attent_Button->Text = L"Asistir";
           //restar 1 a capacidad en base de datos
       }
    }

    System::Void GrupEstudi_InfoUI::DeleteSession_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (CurrentSessionEntity != nullptr)
        {
            MessageBoxButtons buttons = MessageBoxButtons::YesNo;
            System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir la sessió '" + this->CurrentSessionEntity->GetSessionName() + "'?", "Confirmation", buttons);

            if (result == System::Windows::Forms::DialogResult::Yes)
            {
                try {
                    if (this->sessionService->DeleteSession(CurrentSessionEntity->GetId()))
                    {
                        MessageManager::InfoMessage("Sessió eliminada correctament.");
                        this->Sessions_Actuals_Load();
                    }
                    else
                    {
                        MessageManager::ErrorMessage("Error eliminant la sessió.");
                    }
                }
                catch (Exception^ e) {
                    MessageManager::ErrorMessage(e->Message);
                }
            }
		}
    }

    System::Void GrupEstudi_InfoUI::ModifySession_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Session_EditarUI^ PanelUI = gcnew Session_EditarUI(this->CurrentGrupEntity, this->CurrentSessionEntity->GetId());

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    System::Void GrupEstudi_InfoUI::GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_ConsultarUI^ PanelUI = gcnew GrupEstudi_ConsultarUI();

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

}
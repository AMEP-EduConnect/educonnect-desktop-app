#include "pch.h"
#include "GrupEstudi_InfoUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"
#include "Session_CrearUI.h"
#include "Session_EditarUI.h"
#include "Session.h"
#include "CurrentSession.h"
#include "Usuari.h"
#include "ChatGrupEstudiUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_InfoUI::GrupEstudi_InfoUI(String^ CurrentGrup, bool return_page)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
        currentGrup = CurrentGrup;
		this->return_page = return_page;
        this->CurrentGrupEntity = this->grupEstudiService->GetGrupEstudiByName(CurrentGrup);
        sessionService = gcnew SessionService();
        grupSessionAttendantsService = gcnew GrupSessionAttendantsService();
        consultaEspaisService = gcnew ConsultaEspaisService();
        this->Icon = gcnew System::Drawing::Icon("app.ico");
        sessionService = gcnew SessionService();
        isSessionLoaded = false;
		label2->Text = "Descripci\u00F3";
        this->NewSession_Button->Text = L"Nova sessi\u00F3";
        this->pictureBox1->Image = Image::FromFile("resources/Icons/groups_48dp_FILL0_wght500_GRAD-25_opsz48.png");
    }

    void GrupEstudi_InfoUI::GrupEstudi_InfoUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        ActivateButtonsIfOwner();
        this->Sessions_Actuals_Load();
        this->AcademicTagsInfo_Label->Text = this->grupEstudiService->GetAcademicTagNameById(this->CurrentGrupEntity->GetGroupAcademicTag());
        this->InfoGrupEstudi_Label->Text = this->CurrentGrupEntity->GetGroupName();
        this->DescGrupEstudi_Label->Text = this->CurrentGrupEntity->GetDescription();
        this->Load += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::SelectLastSessionOrPlaceholder);

    }

    void GrupEstudi_InfoUI::SelectLastSessionOrPlaceholder(System::Object^ sender, System::EventArgs^ e)
    {
            System::Collections::Generic::IEnumerator<Session^>^ enumerator = SessionsList->GetEnumerator();
            if (Sessions_ListBox->SelectedIndex != -1)
            {
                int select_index = Sessions_ListBox->SelectedIndex;

                int i = 0;
                while (enumerator->MoveNext()) {
                    if (i == select_index) {
                        CurrentSessionEntity = enumerator->Current;
                        break;
                    }
                    i++;
                }
                isSessionLoaded = true;
                this->ActivateButtonsIfOwner();
                session_name->Text = CurrentSessionEntity->GetSessionName();
                EspaiName_Label->Text = consultaEspaisService->GetEspaiInfoById(CurrentSessionEntity->GetEspaiId());
                Int64^ currentSessionCapacity = grupSessionAttendantsService->GetSessionAttendantsCount(CurrentSessionEntity->GetId());
                Int64^ espaiCapacity = this->consultaEspaisService->GetEspaiByEspaiId(CurrentSessionEntity->GetEspaiId())->GetCapacity();
                Capacity_Label->Text = Convert::ToString(currentSessionCapacity) + "/" + espaiCapacity;
                DayMonthYear_label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("dd/MM/yyyy");
                StartEndDuration_Label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("HH:mm") + " - " + CurrentSessionEntity->GetSessionEndDate()->ToString("HH:mm");
                bool isSessionFull = *currentSessionCapacity >= *espaiCapacity;
                if (!isSessionFull && not grupSessionAttendantsService->IsAttendant(CurrentSessionEntity->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId())) {
                    this->Confirm_Cancel_Attent_Button->Enabled = true;
                    this->Confirm_Cancel_Attent_Button->Text = "Asistir";
                }
                else if (isSessionFull && not grupSessionAttendantsService->IsAttendant(CurrentSessionEntity->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId())) {
					this->Confirm_Cancel_Attent_Button->Text = "Complet";
					this->Confirm_Cancel_Attent_Button->Enabled = false;
                }
                else {
                    this->Confirm_Cancel_Attent_Button->Enabled = true;
                    this->Confirm_Cancel_Attent_Button->Text = L"Cancel\u00B7lar Asist\u00E8ncia";
                }
                
            }

    }
   
    void GrupEstudi_InfoUI::ActivateButtonsIfOwner()
    {
    	Int64^ CurrentUserId = (CurrentSession::Instance->GetCurrentUser())->GetUserId();
        if (*CurrentUserId == *this->CurrentGrupEntity->GetGroupOwnerId())
        {
			this->ModifyGrupEstudi_Button->Visible = true;
            this->DeleteGrupEstudi_Button->Visible = true;
            this->NewSession_Button->Visible = true;
       	    
            if (isSessionLoaded) {
                this->ModifySession_Button->Visible = true;
                this->DeleteSession_Button->Visible = true;
            }
		}
    
    }

    System::Void GrupEstudi_InfoUI::DisableModifyDeleteSessionButtons()
    {
        this->ModifySession_Button->Visible = false;
        this->DeleteSession_Button->Visible = false;
    }

    System::Void GrupEstudi_InfoUI::LoadEmptySessionPlaceholder()
    {
        isSessionLoaded = false;
        session_name->Visible = false;
        EspaiName_Label->Text = "No hi ha cap sessi\u00F3";
        Capacity_Label->Visible = false;
        SessionCapacity_Label1->Visible = false;
        DayMonthYear_label->Visible = false;
        StartEndDuration_Label->Visible = false;
        this->Confirm_Cancel_Attent_Button->Visible = false;

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

    System::Void GrupEstudi_InfoUI::Chat_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        ChatGrupEstudiUI::Instance = gcnew ChatGrupEstudiUI(this->CurrentGrupEntity->GetId());
        ChatGrupEstudiUI::Instance->TopLevel = false;
        ChatGrupEstudiUI::Instance->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        ChatGrupEstudiUI::Instance->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(ChatGrupEstudiUI::Instance);
        ChatGrupEstudiUI::Instance->Show();
    }

    System::Void GrupEstudi_InfoUI::Sessions_Actuals_Load()
    {
        this->Sessions_ListBox->Items->Clear();
        SessionsList = this->sessionService->GetSessionsByGroupIdAndStartDate(this->CurrentGrupEntity->GetId(), DateTime::Now);
        if (SessionsList->Count == 0) {
            this->LoadEmptySessionPlaceholder();
        }
        else {
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
            isSessionLoaded = true;
            this->ActivateButtonsIfOwner();
            EspaiName_Label->Visible = true;
            StartEndDuration_Label->Visible = true;
            DayMonthYear_label->Visible = true;
            Confirm_Cancel_Attent_Button->Visible = true;
            SessionCapacity_Label1->Visible = true;
            Capacity_Label->Visible = true;
            Int64^ currentSessionCapacity = grupSessionAttendantsService->GetSessionAttendantsCount(CurrentSessionEntity->GetId());
            Int64^ espaiCapacity = this->consultaEspaisService->GetEspaiByEspaiId(CurrentSessionEntity->GetEspaiId())->GetCapacity();
            Capacity_Label->Text = Convert::ToString(currentSessionCapacity) + "/" + espaiCapacity;
            session_name->Visible = true;
            session_name->Text = CurrentSessionEntity->GetSessionName();
            EspaiName_Label->Text = consultaEspaisService->GetEspaiInfoById(CurrentSessionEntity->GetEspaiId());
            DayMonthYear_label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("dd/MM/yyyy");
            StartEndDuration_Label->Text = CurrentSessionEntity->GetSessionStartDate()->ToString("HH:mm") + " - " + CurrentSessionEntity->GetSessionEndDate()->ToString("HH:mm");
            bool isSessionFull = *currentSessionCapacity >= *espaiCapacity;
            if (!isSessionFull && not grupSessionAttendantsService->IsAttendant(CurrentSessionEntity->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId())) {
                this->Confirm_Cancel_Attent_Button->Enabled = true;
                this->Confirm_Cancel_Attent_Button->Text = "Asistir";
            }
            else if (isSessionFull && not grupSessionAttendantsService->IsAttendant(CurrentSessionEntity->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId())) {
                this->Confirm_Cancel_Attent_Button->Text = "Complet";
                this->Confirm_Cancel_Attent_Button->Enabled = false;
            }
            else {
                this->Confirm_Cancel_Attent_Button->Enabled = true;
                this->Confirm_Cancel_Attent_Button->Text = L"Cancel\u00B7lar Asist\u00E8ncia";
            }
            
        }

    }
    System::Void GrupEstudi_InfoUI::Confirm_Cancel_Attent_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Int64^ idsession = CurrentSessionEntity->GetId();
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        Int64^ iduser = currentUser->GetUserId();
        Int64^ currentSessionCapacity = this->grupSessionAttendantsService->GetSessionAttendantsCount(this->CurrentSessionEntity->GetId());
        //TODO: disable button if capacity is full
        if (not grupSessionAttendantsService->IsAttendant(idsession, iduser) && (*currentSessionCapacity < *this->consultaEspaisService->GetEspaiByEspaiId(CurrentSessionEntity->GetEspaiId())->GetCapacity())) {
           
           grupSessionAttendantsService->AsistirSessionAttendant(idsession, iduser);
           String^ cap2 = Capacity_Label->Text->Substring(0, Capacity_Label->Text->IndexOf("/"));
           Int64^ currentSessionCapacity = grupSessionAttendantsService->GetSessionAttendantsCount(CurrentSessionEntity->GetId());
           Int64^ espaiCapacity = this->consultaEspaisService->GetEspaiByEspaiId(CurrentSessionEntity->GetEspaiId())->GetCapacity();
           Capacity_Label->Text = Convert::ToString(currentSessionCapacity) + "/" + espaiCapacity;
           this->Confirm_Cancel_Attent_Button->Text = L"Cancel\u00B7lar Asist\u00E8ncia";
       }
       else {
           
           grupSessionAttendantsService->EliminaSessionAttendant(idsession, iduser);
           String^ cap2 = Capacity_Label->Text->Substring(0, Capacity_Label->Text->IndexOf("/"));
           Int64^ currentSessionCapacity = grupSessionAttendantsService->GetSessionAttendantsCount(CurrentSessionEntity->GetId());
           Int64^ espaiCapacity = this->consultaEspaisService->GetEspaiByEspaiId(CurrentSessionEntity->GetEspaiId())->GetCapacity();
           Capacity_Label->Text = Convert::ToString(currentSessionCapacity) + "/" + espaiCapacity;
           this->Confirm_Cancel_Attent_Button->Text = L"Asistir";
       }
    }

    System::Void GrupEstudi_InfoUI::DeleteSession_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (CurrentSessionEntity != nullptr)
        {
            MessageBoxButtons buttons = MessageBoxButtons::YesNo;
            System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir la sessi\u00F3 '" + this->CurrentSessionEntity->GetSessionName() + "'?", "Confirmation", buttons);

            if (result == System::Windows::Forms::DialogResult::Yes)
            {
                try {
                    if (this->sessionService->DeleteSession(CurrentSessionEntity->GetId()))
                    {
                        MessageManager::InfoMessage("Sessi\u00F3 eliminada correctament.");
                        this->DisableModifyDeleteSessionButtons();
                        this->LoadEmptySessionPlaceholder();
                        this->Sessions_Actuals_Load();
                    }
                    else
                    {
                        MessageManager::ErrorMessage("Error eliminant la sessi\u00F3.");
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
        if (return_page == 1) {
            GrupEstudi_ConsultarUI^ PanelUI = gcnew GrupEstudi_ConsultarUI();
            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
        }
        else {
            IniciUI^ PanelUI = gcnew IniciUI();
            PanelUI->TopLevel = false;
            PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
            MainPageUI::Instance->screen->Controls->Clear();
            MainPageUI::Instance->screen->Controls->Add(PanelUI);
            PanelUI->Show();
        }
    }

    void GrupEstudi_InfoUI::EliminarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBoxButtons buttons = MessageBoxButtons::YesNo;
        System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir el grup '" + currentGrup + "'?", "Confirmation", buttons);

        if (result == System::Windows::Forms::DialogResult::Yes)
        {
            try {
                grupEstudiService->DeleteGrupEstudi(currentGrup);
                MessageManager::InfoMessage("Grup eliminat correctament.");
                GoBack_Button_Click(sender, e);

            }
            catch (Exception^ e) {
                MessageManager::ErrorMessage(e->Message);
            }
        }
    }

    void GrupEstudi_InfoUI::EditarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_EditarUI^ PanelUI = gcnew GrupEstudi_EditarUI(currentGrup);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void GrupEstudi_InfoUI::consulta_membres_Click(System::Object^ sender, System::EventArgs^ e)
    {

        GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(currentGrup, true);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

}
#include "pch.h"
#include "GrupEstudi_InfoUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "MainPageUI.h"
#include "Session_CrearUI.h"
#include "Session_EditarUI.h"
#include "Session.h"


namespace CppCLRWinFormsProject {

    GrupEstudi_InfoUI::GrupEstudi_InfoUI(String^ CurrentGrup)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
        this->CurrentGrupEntity = this->grupEstudiService->GetGrupEstudiByName(CurrentGrup);
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void GrupEstudi_InfoUI::GrupEstudi_InfoUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        this->AcademicTagsInfo_Label->Text = this->grupEstudiService->GetAcademicTagNameById(this->CurrentGrupEntity->GetGroupAcademicTag());
        this->InfoGrupEstudi_Label->Text = this->CurrentGrupEntity->GetGroupName();
        this->DescGrupEstudi_Label->Text = this->CurrentGrupEntity->GetDescription();
        this->ActivateButtonsIfOwner();
        this->SelectLastSessionOrPlaceholder();

    }

    void GrupEstudi_InfoUI::SelectLastSessionOrPlaceholder()
    {
        //FROM Gabriel para Marcos: 
        // 
        // tienes que hacer que seleccione la session más actual y la muestre en la ficha.
        // para ello rellenará los campos de el titulo, el dia, de que hora a que hora, nombre espai, capacidad maxima y los asistentes actuales, y deberá hacer visible el botón de
        // mostrar asistentes. Si no hay grupo, dejará vacio todos esos campos, la visibilidad de los botones y la capacitat en false, y en el titulo de sesion pondrá "no hay sesiones".
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

    System::Void GrupEstudi_InfoUI::ModifySession_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Session_EditarUI^ PanelUI = gcnew Session_EditarUI(this->CurrentGrupEntity, 1LL);

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
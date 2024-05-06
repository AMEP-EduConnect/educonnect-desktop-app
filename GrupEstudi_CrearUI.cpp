#include "pch.h"
#include "GrupEstudi_CrearUI.h"
#include "MainPageUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "IniciUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_CrearUI::GrupEstudi_CrearUI(void)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
        this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void GrupEstudi_CrearUI::GrupEstudi_CrearUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
		array<AcademicTag^>^ academicTags;
        academicTags = grupEstudiService->LoadAllAcademicTags();
        for (int i = 0; i < academicTags->Length; i++) {
            this->AcademicTag_ComboBox->Items->Add(academicTags[i]->GetTagName());
        }
	}

    void GrupEstudi_CrearUI::CreateGrup_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (FormGrupName_TextBox->Text != "" && FormGrupDescription_TextBox->Text != "" && AcademicTag_ComboBox->Text != "") {
            grupEstudiService->CreateNewGrupEstudi(FormGrupName_TextBox->Text, FormGrupDescription_TextBox->Text, AcademicTag_ComboBox->Text);
            FormGrupDescription_TextBox->Text = "";
            FormGrupName_TextBox->Text = "";
            AcademicTag_ComboBox->Text = "";
            this->Cancelar_Button_Click(sender, e);
		}
        else {
            MessageManager::WarningMessage("Falten camps per omplir.");
        }
    }

    void GrupEstudi_CrearUI::FormGrupName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{

    }

    void GrupEstudi_CrearUI::FormGrupDescription_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {

    }
    System::Void GrupEstudi_CrearUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        IniciUI^ PanelUI = gcnew  IniciUI();

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }
}

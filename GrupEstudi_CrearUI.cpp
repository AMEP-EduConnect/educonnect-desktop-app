#include "pch.h"
#include "GrupEstudi_CrearUI.h"
#include "MainPageUI.h"

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

    void GrupEstudi_CrearUI::GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
        this->Hide();
		MainPageUI^ form = gcnew MainPageUI();
		form->ShowDialog();
		this->Close();
    }

    void GrupEstudi_CrearUI::CreateGrup_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (FormGrupName_TextBox->Text != "" && FormGrupDescription_TextBox->Text != "" && AcademicTag_ComboBox->Text != "") {
            grupEstudiService->CreateNewGrupEstudi(FormGrupName_TextBox->Text, FormGrupDescription_TextBox->Text, AcademicTag_ComboBox->Text);
            FormGrupDescription_TextBox->Text = "";
            FormGrupName_TextBox->Text = "";
            AcademicTag_ComboBox->Text = "";
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
}

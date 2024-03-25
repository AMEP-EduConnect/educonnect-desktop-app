#include "pch.h"
#include "GrupEstudi_CrearUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_CrearUI::GrupEstudi_CrearUI(void)
    {
        InitializeComponent();
        grupEstudiService = gcnew GrupEstudiService();
    }

    void GrupEstudi_CrearUI::GrupEstudi_CrearUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
		array<AcademicTag^>^ academicTags;
        academicTags = grupEstudiService->LoadAllAcademicTags();
        for (int i = 0; i < academicTags->Length; i++) {
            this->AcademicTagComboBox->Items->Add(academicTags[i]->GetTagName());
        }
	}

    void GrupEstudi_CrearUI::goBackButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
    
    }

    void GrupEstudi_CrearUI::CreateGrupButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (FormGrupNameTextBox->Text != "" && FormGrupDescriptionTextBox->Text != "" && AcademicTagComboBox->Text != "") {
            grupEstudiService->CreateNewGrupEstudi(FormGrupNameTextBox->Text, FormGrupDescriptionTextBox->Text, AcademicTagComboBox->Text);
		}
        else {
            MessageManager::WarningMessage("Falten camps per omplir.");
        }
    }

    void GrupEstudi_CrearUI::FormGrupNameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{

    }

    void GrupEstudi_CrearUI::FormGrupDescriptionTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {

    }
}

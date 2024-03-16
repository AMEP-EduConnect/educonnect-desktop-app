#include "pch.h"
#include "GrupEstudi.h"
#include "GrupEstudiUI.h"
#include "GrupEstudiService.h"
#include "AcademicTag.h"
using namespace System;

namespace CppCLRWinFormsProject {

    GrupEstudiUI::GrupEstudiUI(void)
    {
        InitializeComponent();
        
    }

    void GrupEstudiUI::GrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudiService^ grupEstudiService = gcnew GrupEstudiService();
		array<AcademicTag^>^ academicTags;
        academicTags = grupEstudiService->LoadAllAcademicTags();
        for (int i = 0; i < academicTags->Length; i++) {
			this->AcademicTagComboBox->Items->Add(academicTags[i]->getTagName());
		}

	}

    void GrupEstudiUI::goBackButton_Click(System::Object^ sender, System::EventArgs^ e)
	{}

    void GrupEstudiUI::CreateGrupButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Grup creat correctament\n"+ FormGrupNameTextBox->Text + "\n"+ FormGrupDescriptionTextBox->Text + "\n" + AcademicTagComboBox->Text + "\n");
    }

    void GrupEstudiUI::FormGrupNameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
    }

    void GrupEstudiUI::FormGrupDescriptionTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
    {
    }
}

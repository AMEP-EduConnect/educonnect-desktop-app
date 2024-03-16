#include "pch.h"
#include "MyForm.h"
#include "Professor.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include "ProfessorService.h"


namespace CppCLRWinFormsProject {

    MyForm::MyForm(void)
    {
        InitializeComponent();
    }

    void MyForm::testButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
        MessageBox::Show("Database testing");
		
	}

    void MyForm::BClick(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Database testing");

    }
}

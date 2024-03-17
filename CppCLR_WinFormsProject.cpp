#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "MyForm.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudiUI.h"
#include "DatabaseConnector.h"
#include "GrupEstudi_ConsultarUI.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  //Application::Run(gcnew CppCLRWinFormsProject::MyForm());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_EditarUI());
  Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_ConsultarUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudiUI());
  return 0;
}
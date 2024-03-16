#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "MyForm.h"
#include "GrupEstudi_EditarUI.h"
#include "DatabaseConnector.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  //Application::Run(gcnew CppCLRWinFormsProject::MyForm());
  Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_EditarUI());
  return 0;
}
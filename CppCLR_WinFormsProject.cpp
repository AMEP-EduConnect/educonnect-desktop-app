#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "MyForm.h"
#include "GrupEstudiUI.h"
#include "DatabaseConnector.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::GrupEstudiUI());
  return 0;
}
#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "MyForm.h"
#include "IniciSessio.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
#include "RegistreUsuari.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  
  DatabaseConnector::Instance = gcnew DatabaseConnector();

  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::IniciSessio());
  Application::Run(gcnew CppCLRWinFormsProject::RegistreUsuari());
  //COMENTED FOR TEST Application::Run(gcnew CppCLRWinFormsProject::MyForm());
  return 0;

}
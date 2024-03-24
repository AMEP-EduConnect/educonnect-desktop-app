#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "MyForm.h"
#include "FirstPage.h"
#include "IniciSessio.h"
#include "RegistreUsuari.h"

#include "DatabaseConnector.h"
#include "CurrentSession.h"

#include "Usuari.h"



using namespace System;
using namespace System::Windows::Forms;
using namespace CppCLRWinFormsProject;

[STAThread]
int main()
{
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  CurrentSession::Instance = gcnew CurrentSession();

  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  Application::Run(gcnew CppCLRWinFormsProject::FirstPage());
  //Application::Run(gcnew CppCLRWinFormsProject::IniciSessio());
  //Application::Run(gcnew CppCLRWinFormsProject::RegistreUsuari());


  return 0;

}
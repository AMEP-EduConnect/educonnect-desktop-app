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
#include "CurrentSession.h"
#include "InformacioPersonal_ConsultaUI.h"

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
  Application::Run(gcnew CppCLRWinFormsProject::InformacioPersonal_ConsultaUI());

  IniciSessio^ IniciSessio = gcnew CppCLRWinFormsProject::IniciSessio();
  Application::Run(IniciSessio);
  



  //Application::Run(gcnew CppCLRWinFormsProject::RegistreUsuari());
  //COMENTED FOR TEST Application::Run(gcnew CppCLRWinFormsProject::MyForm());
  return 0;

}
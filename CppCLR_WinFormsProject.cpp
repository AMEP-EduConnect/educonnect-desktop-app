#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_CrearUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "Usuari.h"
#include "RegistreUsuari.h"
#include "IniciSessio.h"
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
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_EditarUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_CrearUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_ConsultarUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_AssignarUI());
  return 0;

}
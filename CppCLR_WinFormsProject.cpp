#include "pch.h"
#include "DatabaseConnector.h"
using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }



#include "DatabaseConnector.h"
#include "Proveidor.h"
#include "AltaProveidorUI.h"
using namespace System;
#include "InformacioPersonal_ConsultaUI.h"
#include "InformacioPersonal_ModificaUI.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::FirstPageUI());
  //Application::Run(gcnew CppCLRWinFormsProject::InformacioPersonal_ConsultaUI());
  //Application::Run(gcnew CppCLRWinFormsProject::IniciSessio());
  //Application::Run(gcnew CppCLRWinFormsProject::RegistreUsuari());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_EditarUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_CrearUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_ConsultarUI());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_AssignarUI());
  return 0;
}
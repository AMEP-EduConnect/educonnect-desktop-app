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
#include "CurrentSession.h"
#include "Usuari.h"
using namespace System::Windows::Forms;

[STAThread]
int main()
{
  CurrentSession::Instance = gcnew CurrentSession();
  Usuari^ testUsuari = gcnew Usuari(1LL, "pepe1234", "1234", "pepe@gmail.com","pepe");
  CurrentSession::Instance->LogNewUser(testUsuari);
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  //Application::Run(gcnew CppCLRWinFormsProject::MyForm());
  //Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_EditarUI());
  Application::Run(gcnew CppCLRWinFormsProject::GrupEstudiUI());
  return 0;
}
#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPageUI.h"
#include "FirstPageUI.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_CrearUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "Usuari.h"
#include "RegistreUsuariUI.h"
#include "IniciSessioUI.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CppCLRWinFormsProject;

#include "DatabaseConnector.h"
#include "Proveidor.h"
#include "AltaProveidorUI.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CppCLRWinFormsProject;
[STAThread]
int main()
{
  DatabaseConnector::Instance = gcnew DatabaseConnector();
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::AltaProveidorUI());
  return 0;

}
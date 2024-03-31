#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }
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
#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "MainPage.h"
#include "MyForm.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "InformacioPersonal_ModificaUI.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::InformacioPersonal_ConsultaUI());
  //Application::Run(gcnew CppCLRWinFormsProject::InformacioPersonal_ModificaUI());
  return 0;
}
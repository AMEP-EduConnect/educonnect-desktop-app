#include "pch.h"
#include "DatabaseConnector.h"
using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }
#include "AltaProveidorUI.h"
#include "MainPageUI.h"
#include "FirstPageUI.h"
#include "BaixaProveidorUI.h"
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
#include "BaixaUsuariUI.h"
#include "CaptchaUI.h"
#include "StartPageUI.h"
#include "AltaEspaisUI.h"
#include "InformacioPersonal_ConsultaUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	DatabaseConnector::Instance = gcnew DatabaseConnector();
	CurrentSession::Instance = gcnew CurrentSession();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CppCLRWinFormsProject::StartPageUI::Instance = gcnew CppCLRWinFormsProject::StartPageUI();
	
	Application::Run(CppCLRWinFormsProject::StartPageUI::Instance);
	return 0;
}
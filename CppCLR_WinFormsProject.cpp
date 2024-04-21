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
using namespace System;
#include "InformacioPersonal_ConsultaUI.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
	DatabaseConnector::Instance = gcnew DatabaseConnector();
	CurrentSession::Instance = gcnew CurrentSession();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinFormsProject::FirstPageUI());
	//Application::Run(gcnew CppCLRWinFormsProject::CaptchaUI());
	//Application::Run(gcnew CppCLRWinFormsProject::InformacioPersonal_ConsultaUI());
	//Application::Run(gcnew CppCLRWinFormsProject::IniciSessio());
	//Application::Run(gcnew CppCLRWinFormsProject::RegistreUsuari());
	//Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_EditarUI());
	//Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_CrearUI());
	//Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_ConsultarUI());
	//Application::Run(gcnew CppCLRWinFormsProject::GrupEstudi_AssignarUI());
	return 0;
}
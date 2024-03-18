#include "pch.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "Usuari.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include "InformacioPersonalService.h"

namespace CppCLRWinFormsProject {

	InformacioPersonal_ConsultaUI::InformacioPersonal_ConsultaUI(void)
	{
		InitializeComponent();
	}

	void InformacioPersonal_ConsultaUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
}

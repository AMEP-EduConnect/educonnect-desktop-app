#include "pch.h"
#include "InformacioPersonal_ModificaUI.h"
#include "Usuari.h"
#include "TxPerfilPersonal_Modifica.h"
#include "MessageManager.h"

namespace CppCLRWinFormsProject {

	InformacioPersonal_ModificaUI::InformacioPersonal_ModificaUI(void)
	{
		InitializeComponent();
	}

	void InformacioPersonal_ModificaUI::Cancelar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	void InformacioPersonal_ModificaUI::Acceptar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
}
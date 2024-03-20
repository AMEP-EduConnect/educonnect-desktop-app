#include "pch.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "Usuari.h"
#include "TxPerfilPersonal_Consulta.h"
#include "MessageManager.h"


namespace CppCLRWinFormsProject {

	InformacioPersonal_ConsultaUI::InformacioPersonal_ConsultaUI(void)
	{
		InitializeComponent();
		TxPerfilPersonal_Consulta^ tx = gcnew TxPerfilPersonal_Consulta();
		//Usuari^ u = tx->GetCurrentUser();
		/*String^ username = u->GetUsername();
		String^ password = u->GetPassword();
		String^ email = u->GetEmail();
		String^ name = u->GetName();*/
		textBox1->Text = "pepe";
		textBox2->Text = "#45Bebiuasbc";
		textBox3->Text = "pepe@gmail.com";
		textBox4->Text = "Pepe Rodriguez";
		
	}

	void InformacioPersonal_ConsultaUI::Tanca_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	void InformacioPersonal_ConsultaUI::Edita_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
}

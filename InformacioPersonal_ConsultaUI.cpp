#include "pch.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "InformacioPersonal_ModificaUI.h"
#include "Usuari.h"
#include "TxPerfilPersonal_Consulta.h"
#include "MessageManager.h"


namespace CppCLRWinFormsProject {

	InformacioPersonal_ConsultaUI::InformacioPersonal_ConsultaUI(void)
	{
		InitializeComponent();
		TxPerfilPersonal_Consulta^ tx = gcnew TxPerfilPersonal_Consulta();
		Usuari^ u = tx->GetCurrentUser();
		String^ username = u->GetUsername();
		String^ password = u->GetPassword();
		String^ email = u->GetEmail();
		String^ name = u->GetName();
		textBox1->Text = username;
		textBox2->Text = password;
		textBox3->Text = email;
		textBox4->Text = name;		
	}

	void InformacioPersonal_ConsultaUI::Tanca_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	void InformacioPersonal_ConsultaUI::Edita_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		InformacioPersonal_ModificaUI^ form = gcnew InformacioPersonal_ModificaUI();
		form->ShowDialog();
		this->Show();
		this->Close();
	}
}

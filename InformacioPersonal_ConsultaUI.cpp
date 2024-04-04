#include "pch.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "InformacioPersonal_ModificaUI.h"
#include "Usuari.h"
#include "PerfilPersonalConsultaService.h"
#include "MessageManager.h"
#include "MainPageUI.h"


namespace CppCLRWinFormsProject {

	InformacioPersonal_ConsultaUI::InformacioPersonal_ConsultaUI(void)
	{
		InitializeComponent();
		PerfilPersonalConsultaService^ txConsulta = gcnew PerfilPersonalConsultaService();
		Usuari^ u = txConsulta->GetCurrentUser();
		String^ username = u->GetUsername();
		String^ password = u->GetPassword();
		String^ email = u->GetEmail();
		String^ name = u->GetName();
		textBox1->Text = username;
		textBox2->Text = password;
		textBox3->Text = email;
		textBox4->Text = name;	
		this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	void InformacioPersonal_ConsultaUI::Tanca_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		MainPageUI^ form = gcnew MainPageUI();
		form->ShowDialog();
		this->Close();
	}

	void InformacioPersonal_ConsultaUI::Edita_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		InformacioPersonal_ModificaUI^ form = gcnew InformacioPersonal_ModificaUI();
		form->ShowDialog();
		this->Close();
	}
}

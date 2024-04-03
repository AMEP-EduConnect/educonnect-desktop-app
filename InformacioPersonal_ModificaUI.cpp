#include "pch.h"
#include "InformacioPersonal_ModificaUI.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "Usuari.h"
#include "MessageManager.h"
#include <iostream>
#include <string>


namespace CppCLRWinFormsProject {

	InformacioPersonal_ModificaUI::InformacioPersonal_ModificaUI(void)
	{
		InitializeComponent();
		this->txModifica = gcnew TxPerfilPersonal_Modifica();
		this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ModificaUI::Nickname_Validating);
		this->textBox2->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ModificaUI::Password_Validating);
		this->textBox3->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ModificaUI::Email_Validating);
	}

	void InformacioPersonal_ModificaUI::Cancelar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}

	void InformacioPersonal_ModificaUI::Acceptar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if(Repeat_Validating()) {
			this->txModifica->ModificaUsuari(textBox1->Text, textBox2->Text, textBox3->Text, textBox4->Text);
			this->Hide();
			InformacioPersonal_ConsultaUI^ form = gcnew InformacioPersonal_ConsultaUI();
			form->ShowDialog();
			this->Show();
			this->Close();
		}
	}

	Void InformacioPersonal_ModificaUI::Nickname_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (textBox->Text != "") {
			bool isnotValid = this->txModifica->CheckUsername(textBox->Text);
			if (isnotValid) {
				MessageBox::Show("El nom de l'usuari ja existeix o no és vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				textBox->Text = "";
				//e->Cancel = true;
			}
		}
	}

	Void InformacioPersonal_ModificaUI::Password_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (!IsPasswordStrong(textBox->Text) && textBox->Text != "") {
			MessageBox::Show("La contrasenya no és prou robusta.\nHa de contenir 8 o més caràcters, caràcters especials i números.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox->Text = "";
			//e->Cancel = true; // Previene que el foco cambie de control hasta que la entrada sea válida.
		}
		
	}

	Void InformacioPersonal_ModificaUI::Email_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (textBox->Text != "") {
			if (!IsValidEmail(textBox->Text) && textBox->Text != "") {
				MessageBox::Show("El correu electrònic no té un format vàlid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				//e->Cancel = true; // Esto previene que el foco cambie al siguiente control si la validación falla.
			}
			else {
				bool isnotValid = this->txModifica->CheckEmail(textBox->Text);
				if (isnotValid) {
					MessageBox::Show("El correu electrònic de l'usuari ja està registrat.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					textBox->Text = "";
					//e->Cancel = true;
				}
			}
		}
	}

	bool InformacioPersonal_ModificaUI::Repeat_Validating()
	{
		if (textBox2->Text != "") {
			if (textBox2->Text != textBox5->Text) {
				MessageBox::Show("La contrasenya no és la mateixa que l'anterior.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
		}
		return true;
	}

	bool InformacioPersonal_ModificaUI::IsValidEmail(String^ email) {
		String^ pattern = R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)";
		Regex^ regex = gcnew Regex(pattern);
		return regex->IsMatch(email);
	}

	bool InformacioPersonal_ModificaUI::IsPasswordStrong(String^ password) {
		if (password->Length < 8) return false;
		if (!Regex::IsMatch(password, R"([A-Z])")) return false;
		if (!Regex::IsMatch(password, R"([a-z])")) return false;
		if (!Regex::IsMatch(password, R"(\d)")) return false;
		if (!Regex::IsMatch(password, R"([\!\@\#\$\%\^\&\*\(\)\-\=\+\[\]\{\}\;\:\'\"\<\>\,\.\?\/\~\`\|\\])")) return false;
		return true;
	}
}
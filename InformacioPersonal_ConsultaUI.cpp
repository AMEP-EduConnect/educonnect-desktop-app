#include "pch.h"
#include "InformacioPersonal_ConsultaUI.h"


namespace CppCLRWinFormsProject {

	InformacioPersonal_ConsultaUI::InformacioPersonal_ConsultaUI(void)
	{
		InitializeComponent();
		txConsulta = gcnew PerfilPersonalConsultaService();
		txModifica = gcnew PerfilPersonalModificaService();
		credentialManagementService = gcnew CredentialManagementService();
		Usuari^ u = txConsulta->GetCurrentUser();
		username = u->GetUsername();
		password = u->GetPassword();
		email = u->GetEmail();
		name = u->GetName();
		textBox1->Text = username;
		textBox3->Text = email;
		textBox4->Text = name;

		this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ConsultaUI::Nickname_Validating);
		this->textBox2->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ConsultaUI::Password_Validating);
		this->textBox3->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ConsultaUI::Email_Validating);
		//this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	void InformacioPersonal_ConsultaUI::Edita_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if ((textBox1->Text == username or textBox1->Text == "") and (textBox3->Text == email or textBox3->Text == "") and textBox4->Text == name and textBox2->Text == "") {
			MessageBox::Show("Modifica almenys un camp per a actualitzar l'usuari!", "Actualitza usuari", MessageBoxButtons::OK);
		}
		else {
			if (Repeat_Validating()) {
				if(textBox2->Text != "") textBox2->Text = credentialManagementService->HashPassword(textBox2->Text);
				txModifica->ModificaUsuari(textBox1->Text, textBox2->Text, textBox3->Text, textBox4->Text);
				textBox2->Text = "";
				textBox5->Text = "";
				MessageBox::Show("L'usuari s'ha actualitzat correctament!", "Actualitza usuari", MessageBoxButtons::OK);
			}
		}
	}

	void InformacioPersonal_ConsultaUI::Elimina_Click(System::Object^ sender, System::EventArgs^ e)
	{
		BaixaUsuariUI^ PanelUI = gcnew BaixaUsuariUI();
		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);

		PanelUI->Show();
	}

	Void InformacioPersonal_ConsultaUI::Nickname_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (textBox->Text != "") {
			bool isnotValid = txModifica->CheckUsername(textBox->Text);
			if (isnotValid and textBox->Text != username) {
				MessageBox::Show("El nom de l'usuari ja existeix o no �s v�lid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				textBox->Text = "";
				//e->Cancel = true;
			}
		}
	}

	Void InformacioPersonal_ConsultaUI::Password_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (!IsPasswordStrong(textBox->Text) && textBox->Text != "") {
			MessageBox::Show("La contrasenya no �s prou robusta.\nHa de contenir 8 o m�s car�cters, car�cters especials i n�meros.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox->Text = "";
			//e->Cancel = true; // Previene que el foco cambie de control hasta que la entrada sea v�lida.
		}
		else if (credentialManagementService->VerifyPassword(textBox->Text, password) == true) {
			MessageBox::Show("La contrasenya no pot ser igual a l'actual", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			textBox->Text = "";
		}

	}

	Void InformacioPersonal_ConsultaUI::Email_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (textBox->Text != "") {
			if (!IsValidEmail(textBox->Text) && textBox->Text != "") {
				MessageBox::Show("El correu electr�nic no t� un format v�lid.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				textBox->Text = "";
				//e->Cancel = true; // Esto previene que el foco cambie al siguiente control si la validaci�n falla.
			}
			else {
				bool isnotValid = txModifica->CheckEmail(textBox->Text);
				if (isnotValid and textBox->Text != email) {
					MessageBox::Show("El correu electr�nic de l'usuari ja est� registrat.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					textBox->Text = "";
					//e->Cancel = true;
				}
			}
		}
	}

	bool InformacioPersonal_ConsultaUI::Repeat_Validating()
	{
		if (textBox2->Text != "") {
			if (textBox2->Text != textBox5->Text) {
				MessageBox::Show("La contrasenya no �s la mateixa que l'anterior.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
		}
		return true;
	}

	bool InformacioPersonal_ConsultaUI::IsValidEmail(String^ email) {
		String^ pattern = R"(^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$)";
		Regex^ regex = gcnew Regex(pattern);
		return regex->IsMatch(email);
	}

	bool InformacioPersonal_ConsultaUI::IsPasswordStrong(String^ password) {
		if (password->Length < 8) return false;
		if (!Regex::IsMatch(password, R"([A-Z])")) return false;
		if (!Regex::IsMatch(password, R"([a-z])")) return false;
		if (!Regex::IsMatch(password, R"(\d)")) return false;
		if (!Regex::IsMatch(password, R"([\!\@\#\$\%\^\&\*\(\)\-\=\+\[\]\{\}\;\:\'\"\<\>\,\.\?\/\~\`\|\\])")) return false;
		return true;
	}
}


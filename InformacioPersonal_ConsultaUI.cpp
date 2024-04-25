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
		
		this->BotoCancela->Visible = false;

		//ROLS
		Int64^ rol = CurrentSession::Instance->GetCurrentUserRol();
		if (*rol != 1LL) this->BotoElimina->Visible = true;
		else this->BotoElimina->Visible = false;

	}

	void InformacioPersonal_ConsultaUI::Edita_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (UserIsEditing) {
			if ((textBox1->Text == username or textBox1->Text == "") and (textBox3->Text == email or textBox3->Text == "") and textBox4->Text == name and textBox2->Text == "") {
				MessageManager::WarningMessage("Modifica almenys un camp per a actualitzar l'usuari!");
			}
			else {
				if (Repeat_Validating()) {
					UserIsEditing = false;

					txModifica->ModificaUsuari(textBox1->Text, textBox2->Text, textBox3->Text, textBox4->Text);
					if (textBox1->Text != "" or textBox1->Text != username) username = textBox1->Text;
					if (textBox2->Text != "" or textBox2->Text != password) password = textBox2->Text;
					if (textBox3->Text != "" or textBox3->Text != email) email = textBox3->Text;
					if (textBox4->Text != "" or textBox4->Text != name) name = textBox4->Text;
					textBox2->Text = "";
					textBox5->Text = "";
					MessageManager::InfoMessage("L'usuari s'ha actualitzat correctament!");
					textBox1->Enabled = false;
					textBox2->Enabled = false;
					textBox3->Enabled = false;
					textBox4->Enabled = false;
					textBox5->Enabled = false;
					
					this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));
					this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));
					this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));
					this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));
					this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));

					this->button1->Text = "Editar";
					this->BotoCancela->Visible = false;

				}
			}
		}

		else {
			UserIsEditing = true;

			textBox1->Enabled = true;
			textBox2->Enabled = true;
			textBox3->Enabled = true;
			textBox4->Enabled = true;
			textBox5->Enabled = true;

			this->textBox1->BackColor = SystemColors::Window;
			this->textBox2->BackColor = SystemColors::Window;
			this->textBox3->BackColor = SystemColors::Window;
			this->textBox4->BackColor = SystemColors::Window;
			this->textBox5->BackColor = SystemColors::Window;

			this->button1->Text = "Confirmar";
			this->BotoCancela->Visible = true;
		}
	}

	void InformacioPersonal_ConsultaUI::BotoElimina_Click(System::Object^ sender, System::EventArgs^ e)
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
				MessageManager::ErrorMessage("El nom de l'usuari ja existeix o no es valid");
				textBox->Text = "";
				//e->Cancel = true;
			}
		}
	}

	Void InformacioPersonal_ConsultaUI::Password_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (!IsPasswordStrong(textBox->Text) && textBox->Text != "") {
			MessageManager::WarningMessage("La contrasenya no es prou robusta.\nHa de contenir 8 o mes caracters, caracters especials i numeros");
			textBox->Text = "";
			//e->Cancel = true; // Previene que el foco cambie de control hasta que la entrada sea v�lida.
		}
		else if (credentialManagementService->VerifyPassword(textBox->Text, password) == true) {
			MessageManager::ErrorMessage("La contrasenya no pot ser igual a l'actual");
			textBox->Text = "";
		}

	}

	Void InformacioPersonal_ConsultaUI::Email_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (textBox->Text != "") {
			if (!IsValidEmail(textBox->Text) && textBox->Text != "") {
				MessageManager::ErrorMessage("El correu electronic no te un format valid");
				textBox->Text = "";
				//e->Cancel = true; // Esto previene que el foco cambie al siguiente control si la validaci�n falla.
			}
			else {
				bool isnotValid = txModifica->CheckEmail(textBox->Text);
				if (isnotValid and textBox->Text != email) {
					MessageManager::ErrorMessage("El correu electronic de l'usuari ja esta registrat");
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
				MessageManager::ErrorMessage("Les contrasenyes no coincideixen");
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

	Void InformacioPersonal_ConsultaUI::BotoCancela_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Enabled = false;
		textBox2->Enabled = false;
		textBox3->Enabled = false;
		textBox4->Enabled = false;
		textBox5->Enabled = false;

		textBox1->Text = username;
		textBox3->Text = email;
		textBox4->Text = name;
		textBox2->Text = "";
		textBox5->Text = "";

		this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(224)));
		this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
			static_cast<System::Int32>(static_cast<System::Byte>(224)));

		this->button1->Text = "Editar";
		this->BotoCancela->Visible = false;
		UserIsEditing = false;
	
	}

}


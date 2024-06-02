#include "pch.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "AcademicTag.h"
using namespace std;

using namespace System::Collections::Generic;

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
		if (*CurrentSession::Instance->GetCurrentUserRol() != 2LL) panel4->Visible = false;

		fill_flowlayoutpanelwithtags();

		this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ConsultaUI::Nickname_Validating);
		this->textBox2->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ConsultaUI::Password_Validating);
		this->textBox3->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &InformacioPersonal_ConsultaUI::Email_Validating);
		this->Icon = gcnew System::Drawing::Icon("app.ico");

		this->BotoCancela->Visible = false;
		this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
		this->pictureBox2->Image = Image::FromFile("resources/Icons/eye-crossed.png");

		Int64^ rol = CurrentSession::Instance->GetCurrentUserRol();
		if (*rol != 1LL and *rol != 3LL) this->BotoElimina->Visible = true;
		else this->BotoElimina->Visible = false;

	}

	void InformacioPersonal_ConsultaUI::Edita_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (UserIsEditing) {
			if ((textBox1->Text == username or textBox1->Text == "") and (textBox3->Text == email or textBox3->Text == "") and textBox4->Text == name and textBox2->Text == "") {
				MessageManager::WarningMessage("Modifica almenys un camp per a actualitzar l'usuari!");
				textBox5->Text = "";
			}
			else if (textBox2->Text != "" and textBox2->Text != password) {
				if (!IsPasswordStrong(textBox2->Text) && textBox2->Text != "") {
					MessageManager::WarningMessage("La contrasenya no es prou robusta.\nHa de contenir 8 o mes caracters, caracters especials i numeros");
					textBox2->Text = "";
					textBox5->Text = "";
				}
				else if (credentialManagementService->VerifyPassword(textBox2->Text, password) == true) {
					MessageManager::ErrorMessage("La contrasenya no pot ser igual a l'actual");
					textBox2->Text = "";
					textBox5->Text = "";
				}
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
					this->pictureBox1->Visible = false;
					this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));
					this->pictureBox2->Visible = false;
					this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
						static_cast<System::Int32>(static_cast<System::Byte>(224)));

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
			this->pictureBox1->Visible = true;
			this->pictureBox1->BackColor = SystemColors::Window;
			this->pictureBox2->Visible = true;
			this->pictureBox2->BackColor = SystemColors::Window;
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
			}
		}
	}

	Void InformacioPersonal_ConsultaUI::Password_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{


	}

	Void InformacioPersonal_ConsultaUI::Email_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e)
	{
		TextBox^ textBox = dynamic_cast<TextBox^>(sender);
		if (textBox->Text != "") {
			if (!IsValidEmail(textBox->Text) && textBox->Text != "") {
				MessageManager::ErrorMessage("El correu electronic no te un format valid");
				textBox->Text = "";
			}
			else {
				bool isnotValid = txModifica->CheckEmail(textBox->Text);
				if (isnotValid and textBox->Text != email) {
					MessageManager::ErrorMessage("El correu electronic de l'usuari ja esta registrat");
					textBox->Text = "";
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
		pictureBox1->Visible = false;
		pictureBox2->Visible = false;

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

	Void InformacioPersonal_ConsultaUI::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_visible1) {
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
			this->textBox2->PasswordChar = true;
			password_visible1 = false;
			this->textBox2->UseSystemPasswordChar = true;
		}
		else {
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye.png");
			this->textBox2->PasswordChar = false;
			password_visible1 = true;
			this->textBox2->UseSystemPasswordChar = false;
		}

	}




	Void InformacioPersonal_ConsultaUI::pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_visible2) {
			this->pictureBox2->Image = Image::FromFile("resources/Icons/eye-crossed.png");
			this->textBox5->PasswordChar = true;
			password_visible2 = false;
			this->textBox5->UseSystemPasswordChar = true;
		}
		else {
			this->pictureBox2->Image = Image::FromFile("resources/Icons/eye.png");
			this->textBox5->PasswordChar = false;
			password_visible2 = true;
			this->textBox5->UseSystemPasswordChar = false;
		}
	}

	System::Void InformacioPersonal_ConsultaUI::Checkbox_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::CheckBox^ checkbox = dynamic_cast<System::Windows::Forms::CheckBox^>(sender);
		AcademicTag^ tag = txConsulta->GetAcademicTagByName(checkbox->Text);

		if (checkbox->Checked) txModifica->addAcademicTag(tag->GetId());
		
		else txModifica->deleteAcademicTag(tag->GetId());
		
	}

	Void InformacioPersonal_ConsultaUI::fill_flowlayoutpanelwithtags()
	{
		List<AcademicTag^>^ all_tags = gcnew List<AcademicTag^>(0);
		List<AcademicTag^>^ user_tags = gcnew List<AcademicTag^>(0);

		all_tags = txConsulta->GetAllAcademicTags();
		user_tags = txConsulta->GetAcademicTagsByUserId(CurrentSession::Instance->GetCurrentUser()->GetUserId());

		System::Collections::Generic::IEnumerator<AcademicTag^>^ enumerator1 = all_tags->GetEnumerator();
		

		while (enumerator1->MoveNext())
		{
			System::Windows::Forms::CheckBox^ checkbox = gcnew System::Windows::Forms::CheckBox();
			checkbox->Text = enumerator1->Current->GetTagName();
			checkbox->AutoSize = true;
			checkbox->Font = gcnew System::Drawing::Font(L"Inter", 12.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));

			checkbox->Checked = false;

			System::Collections::Generic::IEnumerator<AcademicTag^>^ enumerator2 = user_tags->GetEnumerator();

			while(enumerator2->MoveNext())
			{
				if (*enumerator1->Current->GetId() == *enumerator2->Current->GetId()) 
				{
					checkbox->Checked = true;
					break;
				}

			}

			this->flowLayoutPanel1->Controls->Add(checkbox);
			checkbox->Click += gcnew System::EventHandler(this, &InformacioPersonal_ConsultaUI::Checkbox_Click);
		}

	}



}
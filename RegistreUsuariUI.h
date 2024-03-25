#pragma once
#include "RegistreService.h"
#include "FirstPageUI.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for RegistreUsuariUI
	/// </summary>
	public ref class RegistreUsuariUI : public System::Windows::Forms::Form
	{
	public:
		RegistreUsuariUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->registreService = gcnew RegistreService();
			this->NomUsuari_TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &RegistreUsuariUI::NomUsuari_TextBox_Validating);
			this->Email_TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &RegistreUsuariUI::Email_TextBox_Validating);
			this->Contrasenya_TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &RegistreUsuariUI::textBoxPassword_Validating);
			this->Icon = gcnew System::Drawing::Icon("app.ico");
		}
		Void NomUsuari_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		Void Email_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		Void textBoxPassword_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		bool IsValidEmail(String^ email);
		bool IsPasswordStrong(String^ password);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegistreUsuariUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Registre_Label;
	private: RegistreService^ registreService;

	private: System::Windows::Forms::Label^ NomUsuari_Label;
	private: System::Windows::Forms::TextBox^ NomUsuari_TextBox;
	private: System::Windows::Forms::Panel^ Main_Panel;
	private: System::Windows::Forms::Button^ Continuar_Button;
	private: System::Windows::Forms::TextBox^ Contrasenya_TextBox;


	private: System::Windows::Forms::TextBox^ Nom_TextBox;
	private: System::Windows::Forms::Label^ Contrasenya_Label;


	private: System::Windows::Forms::Label^ Email_Label;
	private: System::Windows::Forms::TextBox^ Email_TextBox;
	private: System::Windows::Forms::Label^ Nom_Label;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::Label^ EmplenaTotsError_Label;
	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::Label^ ContrasenyaTip_Email_Label;
	private: System::Windows::Forms::Label^ ContrasenyaTip_Label;
	private: System::Windows::Forms::Button^ GoBack_Button;









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Registre_Label = (gcnew System::Windows::Forms::Label());
			this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			this->NomUsuari_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Main_Panel = (gcnew System::Windows::Forms::Panel());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->ContrasenyaTip_Label = (gcnew System::Windows::Forms::Label());
			this->ContrasenyaTip_Email_Label = (gcnew System::Windows::Forms::Label());
			this->Continuar_Button = (gcnew System::Windows::Forms::Button());
			this->Contrasenya_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Nom_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Contrasenya_Label = (gcnew System::Windows::Forms::Label());
			this->Email_Label = (gcnew System::Windows::Forms::Label());
			this->Email_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Nom_Label = (gcnew System::Windows::Forms::Label());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->EmplenaTotsError_Label = (gcnew System::Windows::Forms::Label());
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->Main_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// Registre_Label
			// 
			this->Registre_Label->AutoSize = true;
			this->Registre_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Registre_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Registre_Label->Location = System::Drawing::Point(328, 34);
			this->Registre_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Registre_Label->Name = L"Registre_Label";
			this->Registre_Label->Size = System::Drawing::Size(133, 31);
			this->Registre_Label->TabIndex = 0;
			this->Registre_Label->Text = L"Registrat";
			// 
			// NomUsuari_Label
			// 
			this->NomUsuari_Label->AutoSize = true;
			this->NomUsuari_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomUsuari_Label->Location = System::Drawing::Point(28, 26);
			this->NomUsuari_Label->Name = L"NomUsuari_Label";
			this->NomUsuari_Label->Size = System::Drawing::Size(86, 16);
			this->NomUsuari_Label->TabIndex = 7;
			this->NomUsuari_Label->Text = L"Nom d\'usuari";
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_TextBox->Location = System::Drawing::Point(31, 45);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(197, 22);
			this->NomUsuari_TextBox->TabIndex = 8;
			// 
			// Main_Panel
			// 
			this->Main_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Main_Panel->Controls->Add(this->GoBack_Button);
			this->Main_Panel->Controls->Add(this->ContrasenyaTip_Label);
			this->Main_Panel->Controls->Add(this->ContrasenyaTip_Email_Label);
			this->Main_Panel->Controls->Add(this->Continuar_Button);
			this->Main_Panel->Controls->Add(this->Contrasenya_TextBox);
			this->Main_Panel->Controls->Add(this->Nom_TextBox);
			this->Main_Panel->Controls->Add(this->Contrasenya_Label);
			this->Main_Panel->Controls->Add(this->NomUsuari_Label);
			this->Main_Panel->Controls->Add(this->NomUsuari_TextBox);
			this->Main_Panel->Controls->Add(this->Email_Label);
			this->Main_Panel->Controls->Add(this->Email_TextBox);
			this->Main_Panel->Controls->Add(this->Nom_Label);
			this->Main_Panel->Location = System::Drawing::Point(334, 90);
			this->Main_Panel->Name = L"Main_Panel";
			this->Main_Panel->Size = System::Drawing::Size(259, 401);
			this->Main_Panel->TabIndex = 9;
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoBack_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GoBack_Button->Location = System::Drawing::Point(31, 358);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(197, 23);
			this->GoBack_Button->TabIndex = 21;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &RegistreUsuariUI::GoBackButton_Click);
			// 
			// ContrasenyaTip_Label
			// 
			this->ContrasenyaTip_Label->AutoSize = true;
			this->ContrasenyaTip_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ContrasenyaTip_Label->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ContrasenyaTip_Label->Location = System::Drawing::Point(28, 280);
			this->ContrasenyaTip_Label->Name = L"ContrasenyaTip_Label";
			this->ContrasenyaTip_Label->Size = System::Drawing::Size(198, 13);
			this->ContrasenyaTip_Label->TabIndex = 20;
			this->ContrasenyaTip_Label->Text = L"caràcters especials, números i maj. i min,";
			// 
			// ContrasenyaTip_Email_Label
			// 
			this->ContrasenyaTip_Email_Label->AutoSize = true;
			this->ContrasenyaTip_Email_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ContrasenyaTip_Email_Label->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ContrasenyaTip_Email_Label->Location = System::Drawing::Point(28, 267);
			this->ContrasenyaTip_Email_Label->Name = L"ContrasenyaTip_Email_Label";
			this->ContrasenyaTip_Email_Label->Size = System::Drawing::Size(164, 13);
			this->ContrasenyaTip_Email_Label->TabIndex = 19;
			this->ContrasenyaTip_Email_Label->Text = L"Ha de contenir 8 o més caràcters";
			// 
			// Continuar_Button
			// 
			this->Continuar_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Continuar_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Continuar_Button->Location = System::Drawing::Point(31, 317);
			this->Continuar_Button->Name = L"Continuar_Button";
			this->Continuar_Button->Size = System::Drawing::Size(197, 23);
			this->Continuar_Button->TabIndex = 18;
			this->Continuar_Button->Text = L"Continuar";
			this->Continuar_Button->UseVisualStyleBackColor = true;
			this->Continuar_Button->Click += gcnew System::EventHandler(this, &RegistreUsuariUI::ContinuarRegistreButton_Click);
			// 
			// Contrasenya_TextBox
			// 
			this->Contrasenya_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_TextBox->Location = System::Drawing::Point(31, 242);
			this->Contrasenya_TextBox->Name = L"Contrasenya_TextBox";
			this->Contrasenya_TextBox->PasswordChar = '*';
			this->Contrasenya_TextBox->Size = System::Drawing::Size(197, 22);
			this->Contrasenya_TextBox->TabIndex = 17;
			// 
			// Nom_TextBox
			// 
			this->Nom_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_TextBox->Location = System::Drawing::Point(31, 177);
			this->Nom_TextBox->Name = L"Nom_TextBox";
			this->Nom_TextBox->Size = System::Drawing::Size(197, 22);
			this->Nom_TextBox->TabIndex = 13;
			// 
			// Contrasenya_Label
			// 
			this->Contrasenya_Label->AutoSize = true;
			this->Contrasenya_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Contrasenya_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Contrasenya_Label->Location = System::Drawing::Point(28, 223);
			this->Contrasenya_Label->Name = L"Contrasenya_Label";
			this->Contrasenya_Label->Size = System::Drawing::Size(83, 16);
			this->Contrasenya_Label->TabIndex = 16;
			this->Contrasenya_Label->Text = L"Contrasenya";
			// 
			// Email_Label
			// 
			this->Email_Label->AutoSize = true;
			this->Email_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Email_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Email_Label->Location = System::Drawing::Point(28, 91);
			this->Email_Label->Name = L"Email_Label";
			this->Email_Label->Size = System::Drawing::Size(108, 16);
			this->Email_Label->TabIndex = 10;
			this->Email_Label->Text = L"Correu electrònic";
			// 
			// Email_TextBox
			// 
			this->Email_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_TextBox->Location = System::Drawing::Point(31, 110);
			this->Email_TextBox->Name = L"Email_TextBox";
			this->Email_TextBox->Size = System::Drawing::Size(197, 22);
			this->Email_TextBox->TabIndex = 11;
			// 
			// Nom_Label
			// 
			this->Nom_Label->AutoSize = true;
			this->Nom_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Nom_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Nom_Label->Location = System::Drawing::Point(28, 158);
			this->Nom_Label->Name = L"Nom_Label";
			this->Nom_Label->Size = System::Drawing::Size(36, 16);
			this->Nom_Label->TabIndex = 12;
			this->Nom_Label->Text = L"Nom";
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-3, 557);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(924, 265);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 12;
			this->Background_PictureBox->TabStop = false;
			this->Background_PictureBox->Image = Image::FromFile("background.png");
			// 
			// EmplenaTotsError_Label
			// 
			this->EmplenaTotsError_Label->AutoSize = true;
			this->EmplenaTotsError_Label->BackColor = System::Drawing::SystemColors::Control;
			this->EmplenaTotsError_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EmplenaTotsError_Label->ForeColor = System::Drawing::Color::Red;
			this->EmplenaTotsError_Label->Location = System::Drawing::Point(331, 510);
			this->EmplenaTotsError_Label->Name = L"EmplenaTotsError_Label";
			this->EmplenaTotsError_Label->Size = System::Drawing::Size(150, 16);
			this->EmplenaTotsError_Label->TabIndex = 19;
			this->EmplenaTotsError_Label->Text = L"Emplena tots els camps";
			this->EmplenaTotsError_Label->Visible = false;
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(332, 21);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(66, 13);
			this->EduConnect_Label->TabIndex = 20;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// RegistreUsuariUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(917, 657);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->EmplenaTotsError_Label);
			this->Controls->Add(this->Background_PictureBox);
			this->Controls->Add(this->Registre_Label);
			this->Controls->Add(this->Main_Panel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"RegistreUsuariUI";
			this->Text = L"EduConnect";
			this->Main_Panel->ResumeLayout(false);
			this->Main_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ContinuarRegistreButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void GoBackButton_Click(System::Object^ sender, System::EventArgs^ e);


	};
}

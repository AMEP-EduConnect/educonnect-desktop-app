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
		bool password_visible = false;
		RegistreUsuariUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
			this->registreService = gcnew RegistreService();
			this->NomUsuari_TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &RegistreUsuariUI::NomUsuari_TextBox_Validating);
			this->Email_TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &RegistreUsuariUI::Email_TextBox_Validating);
			this->Contrasenya_TextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &RegistreUsuariUI::textBoxPassword_Validating);
			this->Icon = gcnew System::Drawing::Icon("app.ico");
			this->EmplenaTots->Visible = false;

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
	private: System::Windows::Forms::Button^ GoBack_Button;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ IniciarSessio_Label;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ EmplenaTots;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel2;
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
			this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			this->NomUsuari_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Main_Panel = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->Contrasenya_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Nom_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Continuar_Button = (gcnew System::Windows::Forms::Button());
			this->Contrasenya_Label = (gcnew System::Windows::Forms::Label());
			this->Email_Label = (gcnew System::Windows::Forms::Label());
			this->Email_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Nom_Label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IniciarSessio_Label = (gcnew System::Windows::Forms::Label());
			this->EmplenaTots = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Main_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// NomUsuari_Label
			// 
			this->NomUsuari_Label->AutoSize = true;
			this->NomUsuari_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomUsuari_Label->Location = System::Drawing::Point(32, 24);
			this->NomUsuari_Label->Name = L"NomUsuari_Label";
			this->NomUsuari_Label->Size = System::Drawing::Size(109, 19);
			this->NomUsuari_Label->TabIndex = 7;
			this->NomUsuari_Label->Text = L"Nom d\'usuari";
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_TextBox->Location = System::Drawing::Point(35, 43);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(226, 27);
			this->NomUsuari_TextBox->TabIndex = 8;
			// 
			// Main_Panel
			// 
			this->Main_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Main_Panel->Controls->Add(this->label3);
			this->Main_Panel->Controls->Add(this->label2);
			this->Main_Panel->Controls->Add(this->pictureBox1);
			this->Main_Panel->Controls->Add(this->GoBack_Button);
			this->Main_Panel->Controls->Add(this->Contrasenya_TextBox);
			this->Main_Panel->Controls->Add(this->Nom_TextBox);
			this->Main_Panel->Controls->Add(this->Continuar_Button);
			this->Main_Panel->Controls->Add(this->Contrasenya_Label);
			this->Main_Panel->Controls->Add(this->NomUsuari_Label);
			this->Main_Panel->Controls->Add(this->NomUsuari_TextBox);
			this->Main_Panel->Controls->Add(this->Email_Label);
			this->Main_Panel->Controls->Add(this->Email_TextBox);
			this->Main_Panel->Controls->Add(this->Nom_Label);
			this->Main_Panel->Location = System::Drawing::Point(125, 78);
			this->Main_Panel->Name = L"Main_Panel";
			this->Main_Panel->Size = System::Drawing::Size(303, 410);
			this->Main_Panel->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Inter Italic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(32, 289);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(225, 19);
			this->label3->TabIndex = 25;
			this->label3->Text = L"caràcters especials i números.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter Italic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(32, 270);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(251, 19);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Ha de contenir 8 o més caràcters, ";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(234, 241);
			this->pictureBox1->MaximumSize = System::Drawing::Size(24, 24);
			this->pictureBox1->MinimumSize = System::Drawing::Size(24, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(24, 24);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 23;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &RegistreUsuariUI::pictureBox1_Click);
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoBack_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GoBack_Button->Location = System::Drawing::Point(35, 359);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(226, 35);
			this->GoBack_Button->TabIndex = 21;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &RegistreUsuariUI::GoBackButton_Click);
			// 
			// Contrasenya_TextBox
			// 
			this->Contrasenya_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_TextBox->Location = System::Drawing::Point(35, 240);
			this->Contrasenya_TextBox->Name = L"Contrasenya_TextBox";
			this->Contrasenya_TextBox->PasswordChar = '*';
			this->Contrasenya_TextBox->Size = System::Drawing::Size(226, 27);
			this->Contrasenya_TextBox->TabIndex = 17;
			this->Contrasenya_TextBox->UseSystemPasswordChar = true;
			// 
			// Nom_TextBox
			// 
			this->Nom_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_TextBox->Location = System::Drawing::Point(35, 175);
			this->Nom_TextBox->Name = L"Nom_TextBox";
			this->Nom_TextBox->Size = System::Drawing::Size(226, 27);
			this->Nom_TextBox->TabIndex = 13;
			// 
			// Continuar_Button
			// 
			this->Continuar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Continuar_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Continuar_Button->Location = System::Drawing::Point(35, 318);
			this->Continuar_Button->Name = L"Continuar_Button";
			this->Continuar_Button->Size = System::Drawing::Size(225, 35);
			this->Continuar_Button->TabIndex = 18;
			this->Continuar_Button->Text = L"Continuar";
			this->Continuar_Button->UseVisualStyleBackColor = true;
			this->Continuar_Button->Click += gcnew System::EventHandler(this, &RegistreUsuariUI::ContinuarRegistreButton_Click);
			// 
			// Contrasenya_Label
			// 
			this->Contrasenya_Label->AutoSize = true;
			this->Contrasenya_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Contrasenya_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Contrasenya_Label->Location = System::Drawing::Point(32, 221);
			this->Contrasenya_Label->Name = L"Contrasenya_Label";
			this->Contrasenya_Label->Size = System::Drawing::Size(105, 19);
			this->Contrasenya_Label->TabIndex = 16;
			this->Contrasenya_Label->Text = L"Contrasenya";
			// 
			// Email_Label
			// 
			this->Email_Label->AutoSize = true;
			this->Email_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Email_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Email_Label->Location = System::Drawing::Point(32, 89);
			this->Email_Label->Name = L"Email_Label";
			this->Email_Label->Size = System::Drawing::Size(141, 19);
			this->Email_Label->TabIndex = 10;
			this->Email_Label->Text = L"Correu electrònic";
			// 
			// Email_TextBox
			// 
			this->Email_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Email_TextBox->Location = System::Drawing::Point(35, 108);
			this->Email_TextBox->Name = L"Email_TextBox";
			this->Email_TextBox->Size = System::Drawing::Size(226, 27);
			this->Email_TextBox->TabIndex = 11;
			// 
			// Nom_Label
			// 
			this->Nom_Label->AutoSize = true;
			this->Nom_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Nom_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Nom_Label->Location = System::Drawing::Point(32, 156);
			this->Nom_Label->Name = L"Nom_Label";
			this->Nom_Label->Size = System::Drawing::Size(45, 19);
			this->Nom_Label->TabIndex = 12;
			this->Nom_Label->Text = L"Nom";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(122, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 19);
			this->label1->TabIndex = 22;
			this->label1->Text = L"EduConnect";
			// 
			// IniciarSessio_Label
			// 
			this->IniciarSessio_Label->AutoSize = true;
			this->IniciarSessio_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IniciarSessio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->IniciarSessio_Label->Location = System::Drawing::Point(119, 29);
			this->IniciarSessio_Label->Name = L"IniciarSessio_Label";
			this->IniciarSessio_Label->Size = System::Drawing::Size(135, 33);
			this->IniciarSessio_Label->TabIndex = 21;
			this->IniciarSessio_Label->Text = L"Registrat";
			// 
			// EmplenaTots
			// 
			this->EmplenaTots->AutoSize = true;
			this->EmplenaTots->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EmplenaTots->ForeColor = System::Drawing::Color::Red;
			this->EmplenaTots->Location = System::Drawing::Point(121, 494);
			this->EmplenaTots->Name = L"EmplenaTots";
			this->EmplenaTots->Size = System::Drawing::Size(194, 19);
			this->EmplenaTots->TabIndex = 25;
			this->EmplenaTots->Text = L"Emplena tots els camps.";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 1.867816F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90.94827F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.04023F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(933, 696);
			this->tableLayoutPanel1->TabIndex = 26;
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->Controls->Add(this->Main_Panel);
			this->panel2->Controls->Add(this->EmplenaTots);
			this->panel2->Controls->Add(this->IniciarSessio_Label);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(189, 16);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(553, 627);
			this->panel2->TabIndex = 18;
			// 
			// RegistreUsuariUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->ClientSize = System::Drawing::Size(933, 696);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MinimumSize = System::Drawing::Size(933, 696);
			this->Name = L"RegistreUsuariUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &RegistreUsuariUI::RegistreUsuariUI_Load);
			this->Main_Panel->ResumeLayout(false);
			this->Main_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void ContinuarRegistreButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GoBackButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void RegistreUsuariUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
	Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

};
}

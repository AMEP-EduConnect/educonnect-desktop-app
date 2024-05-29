#pragma once
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>
#include "IniciSessioService.h"
#include "FirstPageUI.h"
#include "ReportsService.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IniciSessioUI
	/// </summary>
	public ref class IniciSessioUI : public System::Windows::Forms::Form
	{
	public:
		bool password_visible = false;
		IniciSessioUI(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			this->Icon = gcnew System::Drawing::Icon("app.ico");
			reportService = gcnew ReportsService();
			//this->Background_PictureBox->Image = Image::FromFile("background.png");
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
			
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~IniciSessioUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ NomUsuari_TextBox;
	private: ReportsService^ reportService;
	private: System::Windows::Forms::TextBox^ Contrasenya_TextBox;
	private: System::Windows::Forms::Label^ IniciarSessio_Label;
	private: System::Windows::Forms::Button^ Continuar_Button;

	private: System::Windows::Forms::Label^ NomUsuari_Label;
	private: System::Windows::Forms::Label^ Contrasenya_Label;
	private: System::Windows::Forms::Panel^ Main_Panel;
	private: System::Windows::Forms::Label^ CredencialsIncorrectes_Label;

	private: System::Windows::Forms::Button^ GoBack_Button;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ CredencialsIncorrectes_Label2;
	private: System::Windows::Forms::Label^ Ban_label;



	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->NomUsuari_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Contrasenya_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->IniciarSessio_Label = (gcnew System::Windows::Forms::Label());
			this->Continuar_Button = (gcnew System::Windows::Forms::Button());
			this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			this->Contrasenya_Label = (gcnew System::Windows::Forms::Label());
			this->Main_Panel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->CredencialsIncorrectes_Label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CredencialsIncorrectes_Label2 = (gcnew System::Windows::Forms::Label());
			this->Ban_label = (gcnew System::Windows::Forms::Label());
			this->Main_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_TextBox->Location = System::Drawing::Point(26, 42);
			this->NomUsuari_TextBox->Margin = System::Windows::Forms::Padding(2);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(170, 27);
			this->NomUsuari_TextBox->TabIndex = 0;
			// 
			// Contrasenya_TextBox
			// 
			this->Contrasenya_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_TextBox->Location = System::Drawing::Point(26, 93);
			this->Contrasenya_TextBox->Margin = System::Windows::Forms::Padding(2);
			this->Contrasenya_TextBox->Name = L"Contrasenya_TextBox";
			this->Contrasenya_TextBox->PasswordChar = '*';
			this->Contrasenya_TextBox->Size = System::Drawing::Size(170, 27);
			this->Contrasenya_TextBox->TabIndex = 1;
			this->Contrasenya_TextBox->UseSystemPasswordChar = true;
			// 
			// IniciarSessio_Label
			// 
			this->IniciarSessio_Label->AutoSize = true;
			this->IniciarSessio_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IniciarSessio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->IniciarSessio_Label->Location = System::Drawing::Point(236, 76);
			this->IniciarSessio_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->IniciarSessio_Label->Name = L"IniciarSessio_Label";
			this->IniciarSessio_Label->Size = System::Drawing::Size(188, 33);
			this->IniciarSessio_Label->TabIndex = 4;
			this->IniciarSessio_Label->Text = L"Iniciar sessi�";
			// 
			// Continuar_Button
			// 
			this->Continuar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Continuar_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Continuar_Button->Location = System::Drawing::Point(26, 175);
			this->Continuar_Button->Margin = System::Windows::Forms::Padding(2);
			this->Continuar_Button->Name = L"Continuar_Button";
			this->Continuar_Button->Size = System::Drawing::Size(170, 27);
			this->Continuar_Button->TabIndex = 2;
			this->Continuar_Button->Text = L"Continuar";
			this->Continuar_Button->UseVisualStyleBackColor = true;
			this->Continuar_Button->Click += gcnew System::EventHandler(this, &IniciSessioUI::ContinuarIniciSessioButton_Click);
			// 
			// NomUsuari_Label
			// 
			this->NomUsuari_Label->AutoSize = true;
			this->NomUsuari_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomUsuari_Label->Location = System::Drawing::Point(23, 25);
			this->NomUsuari_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NomUsuari_Label->Name = L"NomUsuari_Label";
			this->NomUsuari_Label->Size = System::Drawing::Size(109, 19);
			this->NomUsuari_Label->TabIndex = 7;
			this->NomUsuari_Label->Text = L"Nom d\'usuari";
			// 
			// Contrasenya_Label
			// 
			this->Contrasenya_Label->AutoSize = true;
			this->Contrasenya_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Contrasenya_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Contrasenya_Label->Location = System::Drawing::Point(23, 76);
			this->Contrasenya_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Contrasenya_Label->Name = L"Contrasenya_Label";
			this->Contrasenya_Label->Size = System::Drawing::Size(99, 20);
			this->Contrasenya_Label->TabIndex = 8;
			this->Contrasenya_Label->Text = L"Contrasenya";
			// 
			// Main_Panel
			// 
			this->Main_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Main_Panel->Controls->Add(this->pictureBox1);
			this->Main_Panel->Controls->Add(this->GoBack_Button);
			this->Main_Panel->Controls->Add(this->Continuar_Button);
			this->Main_Panel->Controls->Add(this->NomUsuari_Label);
			this->Main_Panel->Controls->Add(this->Contrasenya_Label);
			this->Main_Panel->Controls->Add(this->Contrasenya_TextBox);
			this->Main_Panel->Controls->Add(this->NomUsuari_TextBox);
			this->Main_Panel->Location = System::Drawing::Point(238, 113);
			this->Main_Panel->Margin = System::Windows::Forms::Padding(2);
			this->Main_Panel->Name = L"Main_Panel";
			this->Main_Panel->Size = System::Drawing::Size(227, 245);
			this->Main_Panel->TabIndex = 9;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(176, 94);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->MaximumSize = System::Drawing::Size(18, 18);
			this->pictureBox1->MinimumSize = System::Drawing::Size(18, 18);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(18, 18);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &IniciSessioUI::pictureBox1_Click);
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoBack_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GoBack_Button->Location = System::Drawing::Point(26, 206);
			this->GoBack_Button->Margin = System::Windows::Forms::Padding(2);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(170, 27);
			this->GoBack_Button->TabIndex = 3;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &IniciSessioUI::GoBackButton_Click);
			// 
			// CredencialsIncorrectes_Label
			// 
			this->CredencialsIncorrectes_Label->AutoSize = true;
			this->CredencialsIncorrectes_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CredencialsIncorrectes_Label->ForeColor = System::Drawing::Color::Red;
			this->CredencialsIncorrectes_Label->Location = System::Drawing::Point(236, 366);
			this->CredencialsIncorrectes_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CredencialsIncorrectes_Label->Name = L"CredencialsIncorrectes_Label";
			this->CredencialsIncorrectes_Label->Size = System::Drawing::Size(192, 19);
			this->CredencialsIncorrectes_Label->TabIndex = 10;
			this->CredencialsIncorrectes_Label->Text = L"Credencials incorrectes.";
			this->CredencialsIncorrectes_Label->Visible = false;
			this->CredencialsIncorrectes_Label->Click += gcnew System::EventHandler(this, &IniciSessioUI::CredencialsIncorrectes_Label_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(237, 66);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 20);
			this->label1->TabIndex = 12;
			this->label1->Text = L"EduConnect";
			// 
			// CredencialsIncorrectes_Label2
			// 
			this->CredencialsIncorrectes_Label2->AutoSize = true;
			this->CredencialsIncorrectes_Label2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CredencialsIncorrectes_Label2->ForeColor = System::Drawing::Color::Red;
			this->CredencialsIncorrectes_Label2->Location = System::Drawing::Point(238, 385);
			this->CredencialsIncorrectes_Label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CredencialsIncorrectes_Label2->Name = L"CredencialsIncorrectes_Label2";
			this->CredencialsIncorrectes_Label2->Size = System::Drawing::Size(159, 19);
			this->CredencialsIncorrectes_Label2->TabIndex = 13;
			this->CredencialsIncorrectes_Label2->Text = L"Captcha incorrecte.";
			this->CredencialsIncorrectes_Label2->Visible = false;
			// 
			// Ban_label
			// 
			this->Ban_label->AutoSize = true;
			this->Ban_label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ban_label->ForeColor = System::Drawing::Color::Red;
			this->Ban_label->Location = System::Drawing::Point(237, 404);
			this->Ban_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Ban_label->Name = L"Ban_label";
			this->Ban_label->Size = System::Drawing::Size(204, 19);
			this->Ban_label->TabIndex = 14;
			this->Ban_label->Text = L"Estas ban en EduConnect";
			this->Ban_label->Visible = false;
			this->Ban_label->Click += gcnew System::EventHandler(this, &IniciSessioUI::label2_Click);
			// 
			// IniciSessioUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->ClientSize = System::Drawing::Size(700, 532);
			this->Controls->Add(this->Ban_label);
			this->Controls->Add(this->CredencialsIncorrectes_Label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CredencialsIncorrectes_Label);
			this->Controls->Add(this->IniciarSessio_Label);
			this->Controls->Add(this->Main_Panel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"IniciSessioUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &IniciSessioUI::IniciSessioUI_Load);
			this->Main_Panel->ResumeLayout(false);
			this->Main_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void GoBackButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ContinuarIniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void IniciSessioUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void CredencialsIncorrectes_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

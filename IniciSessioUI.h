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
			//TODO: agregar código de constructor aquí
			//
			this->Icon = gcnew System::Drawing::Icon("app.ico");
			reportService = gcnew ReportsService();
			//this->Background_PictureBox->Image = Image::FromFile("background.png");
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
			
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
	private: System::Windows::Forms::Label^ ban_label;
	private: System::Windows::Forms::Label^ descriptionBan_label;



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
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
			this->ban_label = (gcnew System::Windows::Forms::Label());
			this->descriptionBan_label = (gcnew System::Windows::Forms::Label());
			this->Main_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_TextBox->Location = System::Drawing::Point(35, 55);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(226, 27);
			this->NomUsuari_TextBox->TabIndex = 0;
			// 
			// Contrasenya_TextBox
			// 
			this->Contrasenya_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contrasenya_TextBox->Location = System::Drawing::Point(35, 122);
			this->Contrasenya_TextBox->Name = L"Contrasenya_TextBox";
			this->Contrasenya_TextBox->PasswordChar = '*';
			this->Contrasenya_TextBox->Size = System::Drawing::Size(226, 27);
			this->Contrasenya_TextBox->TabIndex = 1;
			this->Contrasenya_TextBox->UseSystemPasswordChar = true;
			// 
			// IniciarSessio_Label
			// 
			this->IniciarSessio_Label->AutoSize = true;
			this->IniciarSessio_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IniciarSessio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->IniciarSessio_Label->Location = System::Drawing::Point(314, 100);
			this->IniciarSessio_Label->Name = L"IniciarSessio_Label";
			this->IniciarSessio_Label->Size = System::Drawing::Size(188, 33);
			this->IniciarSessio_Label->TabIndex = 4;
			this->IniciarSessio_Label->Text = L"Iniciar sessió";
			// 
			// Continuar_Button
			// 
			this->Continuar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Continuar_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Continuar_Button->Location = System::Drawing::Point(35, 229);
			this->Continuar_Button->Name = L"Continuar_Button";
			this->Continuar_Button->Size = System::Drawing::Size(226, 35);
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
			this->NomUsuari_Label->Location = System::Drawing::Point(31, 33);
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
			this->Contrasenya_Label->Location = System::Drawing::Point(31, 99);
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
			this->Main_Panel->Location = System::Drawing::Point(318, 148);
			this->Main_Panel->Name = L"Main_Panel";
			this->Main_Panel->Size = System::Drawing::Size(303, 320);
			this->Main_Panel->TabIndex = 9;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Location = System::Drawing::Point(235, 123);
			this->pictureBox1->MaximumSize = System::Drawing::Size(24, 24);
			this->pictureBox1->MinimumSize = System::Drawing::Size(24, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(24, 24);
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
			this->GoBack_Button->Location = System::Drawing::Point(35, 270);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(226, 35);
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
			this->CredencialsIncorrectes_Label->Location = System::Drawing::Point(314, 479);
			this->CredencialsIncorrectes_Label->Name = L"CredencialsIncorrectes_Label";
			this->CredencialsIncorrectes_Label->Size = System::Drawing::Size(188, 19);
			this->CredencialsIncorrectes_Label->TabIndex = 10;
			this->CredencialsIncorrectes_Label->Text = L"Credencials incorrectes";
			this->CredencialsIncorrectes_Label->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(316, 86);
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
			this->CredencialsIncorrectes_Label2->Location = System::Drawing::Point(314, 500);
			this->CredencialsIncorrectes_Label2->Name = L"CredencialsIncorrectes_Label2";
			this->CredencialsIncorrectes_Label2->Size = System::Drawing::Size(159, 19);
			this->CredencialsIncorrectes_Label2->TabIndex = 13;
			this->CredencialsIncorrectes_Label2->Text = L"Captcha incorrecte.";
			this->CredencialsIncorrectes_Label2->Visible = false;
			// 
			// ban_label
			// 
			this->ban_label->AutoSize = true;
			this->ban_label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ban_label->ForeColor = System::Drawing::Color::Red;
			this->ban_label->Location = System::Drawing::Point(316, 479);
			this->ban_label->Name = L"ban_label";
			this->ban_label->Size = System::Drawing::Size(80, 19);
			this->ban_label->TabIndex = 14;
			this->ban_label->Text = L"ban_label";
			this->ban_label->Visible = false;
			// 
			// descriptionBan_label
			// 
			this->descriptionBan_label->AutoSize = true;
			this->descriptionBan_label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionBan_label->ForeColor = System::Drawing::Color::Red;
			this->descriptionBan_label->Location = System::Drawing::Point(316, 500);
			this->descriptionBan_label->Name = L"descriptionBan_label";
			this->descriptionBan_label->Size = System::Drawing::Size(55, 19);
			this->descriptionBan_label->TabIndex = 15;
			this->descriptionBan_label->Text = L"label2";
			this->descriptionBan_label->Visible = false;
			// 
			// IniciSessioUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->ClientSize = System::Drawing::Size(933, 696);
			this->Controls->Add(this->descriptionBan_label);
			this->Controls->Add(this->ban_label);
			this->Controls->Add(this->CredencialsIncorrectes_Label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CredencialsIncorrectes_Label);
			this->Controls->Add(this->IniciarSessio_Label);
			this->Controls->Add(this->Main_Panel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximumSize = System::Drawing::Size(933, 696);
			this->MinimumSize = System::Drawing::Size(933, 696);
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
};
}

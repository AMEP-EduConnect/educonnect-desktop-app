#pragma once
#include "Utils.h"
#include "DatabaseConnector.h"
#include <iostream>
#include <string>
#include "IniciSessioService.h"
#include "FirstPageUI.h"

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

		IniciSessioUI(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->Icon = gcnew System::Drawing::Icon("app.ico");
			this->Background_PictureBox->Image = Image::FromFile("background.png");

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

	private: System::Windows::Forms::TextBox^ Contrasenya_TextBox;
	private: System::Windows::Forms::Label^ IniciarSessio_Label;
	private: System::Windows::Forms::Button^ Continuar_Button;
	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::Label^ NomUsuari_Label;
	private: System::Windows::Forms::Label^ Contrasenya_Label;
	private: System::Windows::Forms::Panel^ Main_Panel;
	private: System::Windows::Forms::Label^ CredencialsIncorrectes_Label;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::Button^ GoBack_Button;

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
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			this->Contrasenya_Label = (gcnew System::Windows::Forms::Label());
			this->Main_Panel = (gcnew System::Windows::Forms::Panel());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->CredencialsIncorrectes_Label = (gcnew System::Windows::Forms::Label());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Main_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NomUsuari_TextBox->Location = System::Drawing::Point(29, 46);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(197, 22);
			this->NomUsuari_TextBox->TabIndex = 0;
			// 
			// Contrasenya_TextBox
			// 
			this->Contrasenya_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Contrasenya_TextBox->Location = System::Drawing::Point(29, 112);
			this->Contrasenya_TextBox->Name = L"Contrasenya_TextBox";
			this->Contrasenya_TextBox->PasswordChar = '*';
			this->Contrasenya_TextBox->Size = System::Drawing::Size(197, 22);
			this->Contrasenya_TextBox->TabIndex = 1;
			// 
			// IniciarSessio_Label
			// 
			this->IniciarSessio_Label->AutoSize = true;
			this->IniciarSessio_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->IniciarSessio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->IniciarSessio_Label->Location = System::Drawing::Point(322, 103);
			this->IniciarSessio_Label->Name = L"IniciarSessio_Label";
			this->IniciarSessio_Label->Size = System::Drawing::Size(186, 31);
			this->IniciarSessio_Label->TabIndex = 4;
			this->IniciarSessio_Label->Text = L"Iniciar sessió";
			// 
			// Continuar_Button
			// 
			this->Continuar_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Continuar_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Continuar_Button->Location = System::Drawing::Point(29, 180);
			this->Continuar_Button->Name = L"Continuar_Button";
			this->Continuar_Button->Size = System::Drawing::Size(197, 23);
			this->Continuar_Button->TabIndex = 2;
			this->Continuar_Button->Text = L"Continuar";
			this->Continuar_Button->UseVisualStyleBackColor = true;
			this->Continuar_Button->Click += gcnew System::EventHandler(this, &IniciSessioUI::ContinuarIniciSessioButton_Click);
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(325, 95);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(66, 13);
			this->EduConnect_Label->TabIndex = 6;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// NomUsuari_Label
			// 
			this->NomUsuari_Label->AutoSize = true;
			this->NomUsuari_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomUsuari_Label->Location = System::Drawing::Point(26, 27);
			this->NomUsuari_Label->Name = L"NomUsuari_Label";
			this->NomUsuari_Label->Size = System::Drawing::Size(86, 16);
			this->NomUsuari_Label->TabIndex = 7;
			this->NomUsuari_Label->Text = L"Nom d\'usuari";
			// 
			// Contrasenya_Label
			// 
			this->Contrasenya_Label->AutoSize = true;
			this->Contrasenya_Label->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Contrasenya_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Contrasenya_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Contrasenya_Label->Location = System::Drawing::Point(29, 93);
			this->Contrasenya_Label->Name = L"Contrasenya_Label";
			this->Contrasenya_Label->Size = System::Drawing::Size(83, 16);
			this->Contrasenya_Label->TabIndex = 8;
			this->Contrasenya_Label->Text = L"Contrasenya";
			// 
			// Main_Panel
			// 
			this->Main_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Main_Panel->Controls->Add(this->GoBack_Button);
			this->Main_Panel->Controls->Add(this->Continuar_Button);
			this->Main_Panel->Controls->Add(this->NomUsuari_Label);
			this->Main_Panel->Controls->Add(this->Contrasenya_Label);
			this->Main_Panel->Controls->Add(this->NomUsuari_TextBox);
			this->Main_Panel->Controls->Add(this->Contrasenya_TextBox);
			this->Main_Panel->Location = System::Drawing::Point(328, 165);
			this->Main_Panel->Name = L"Main_Panel";
			this->Main_Panel->Size = System::Drawing::Size(259, 265);
			this->Main_Panel->TabIndex = 9;
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoBack_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GoBack_Button->Location = System::Drawing::Point(29, 224);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(197, 23);
			this->GoBack_Button->TabIndex = 3;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &IniciSessioUI::GoBackButton_Click);
			// 
			// CredencialsIncorrectes_Label
			// 
			this->CredencialsIncorrectes_Label->AutoSize = true;
			this->CredencialsIncorrectes_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CredencialsIncorrectes_Label->ForeColor = System::Drawing::Color::Red;
			this->CredencialsIncorrectes_Label->Location = System::Drawing::Point(325, 447);
			this->CredencialsIncorrectes_Label->Name = L"CredencialsIncorrectes_Label";
			this->CredencialsIncorrectes_Label->Size = System::Drawing::Size(148, 16);
			this->CredencialsIncorrectes_Label->TabIndex = 10;
			this->CredencialsIncorrectes_Label->Text = L"Credencials incorrectes";
			this->CredencialsIncorrectes_Label->Visible = false;
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-5, 555);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(928, 265);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 11;
			this->Background_PictureBox->TabStop = false;
			// 
			// IniciSessioUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(917, 657);
			this->Controls->Add(this->Background_PictureBox);
			this->Controls->Add(this->CredencialsIncorrectes_Label);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->IniciarSessio_Label);
			this->Controls->Add(this->Main_Panel);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"IniciSessioUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &IniciSessioUI::IniciSessioUI_Load);
			this->Main_Panel->ResumeLayout(false);
			this->Main_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void GoBackButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ContinuarIniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void IniciSessioUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

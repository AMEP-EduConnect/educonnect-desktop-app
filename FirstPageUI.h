#pragma once
#include "CaptchaUI.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FirstPageUI
	/// </summary>
	public ref class FirstPageUI : public System::Windows::Forms::Form
	{
	public:
		FirstPageUI(void)
		{
			InitializeComponent();

			this->Icon = gcnew System::Drawing::Icon("app.ico");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~FirstPageUI()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ Benvingut_Label;
	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::Panel^ Main_Panel;

	private: System::Windows::Forms::Button^ IniciSessio_Button;
	private: System::Windows::Forms::Button^ Registrarse_Button;
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
			this->Benvingut_Label = (gcnew System::Windows::Forms::Label());
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->Main_Panel = (gcnew System::Windows::Forms::Panel());
			this->Registrarse_Button = (gcnew System::Windows::Forms::Button());
			this->IniciSessio_Button = (gcnew System::Windows::Forms::Button());
			this->Main_Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Benvingut_Label
			// 
			this->Benvingut_Label->AutoSize = true;
			this->Benvingut_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Benvingut_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Benvingut_Label->Location = System::Drawing::Point(263, 138);
			this->Benvingut_Label->Name = L"Benvingut_Label";
			this->Benvingut_Label->Size = System::Drawing::Size(385, 33);
			this->Benvingut_Label->TabIndex = 7;
			this->Benvingut_Label->Text = L"Benvingut/da a EduConnect";
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"SF Pro Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(267, 125);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(91, 19);
			this->EduConnect_Label->TabIndex = 8;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// Main_Panel
			// 
			this->Main_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Main_Panel->Controls->Add(this->Registrarse_Button);
			this->Main_Panel->Controls->Add(this->IniciSessio_Button);
			this->Main_Panel->Location = System::Drawing::Point(241, 192);
			this->Main_Panel->Name = L"Main_Panel";
			this->Main_Panel->Size = System::Drawing::Size(427, 265);
			this->Main_Panel->TabIndex = 10;
			// 
			// Registrarse_Button
			// 
			this->Registrarse_Button->Font = (gcnew System::Drawing::Font(L"Inter Light", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Registrarse_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Registrarse_Button->Location = System::Drawing::Point(28, 152);
			this->Registrarse_Button->Name = L"Registrarse_Button";
			this->Registrarse_Button->Size = System::Drawing::Size(371, 61);
			this->Registrarse_Button->TabIndex = 14;
			this->Registrarse_Button->Text = L"Registrat";
			this->Registrarse_Button->UseVisualStyleBackColor = true;
			this->Registrarse_Button->Click += gcnew System::EventHandler(this, &FirstPageUI::RegistrarseButton_Click);
			// 
			// IniciSessio_Button
			// 
			this->IniciSessio_Button->Font = (gcnew System::Drawing::Font(L"Inter Light", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IniciSessio_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->IniciSessio_Button->Location = System::Drawing::Point(28, 45);
			this->IniciSessio_Button->Name = L"IniciSessio_Button";
			this->IniciSessio_Button->Size = System::Drawing::Size(371, 61);
			this->IniciSessio_Button->TabIndex = 13;
			this->IniciSessio_Button->Text = L"Iniciar Sessi\u00F3";
			this->IniciSessio_Button->UseVisualStyleBackColor = true;
			this->IniciSessio_Button->Click += gcnew System::EventHandler(this, &FirstPageUI::IniciSessioButton_Click);
			// 
			// FirstPageUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->ClientSize = System::Drawing::Size(933, 696);
			this->Controls->Add(this->Main_Panel);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->Benvingut_Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximumSize = System::Drawing::Size(933, 696);
			this->MinimumSize = System::Drawing::Size(933, 696);
			this->Name = L"FirstPageUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EduConnect";
			this->Main_Panel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void IniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RegistrarseButton_Click(System::Object^ sender, System::EventArgs^ e);

};
}

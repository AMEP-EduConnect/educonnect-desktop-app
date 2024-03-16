#pragma once
#include "GrupEstudiService.h"
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudiUI
	/// </summary>
	public ref class GrupEstudiUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudiUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudiUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ pageTitle;
	private: System::Windows::Forms::Label^ eduConnectLabel;
	private: System::Windows::Forms::Button^ goBackButton;
	private: System::Windows::Forms::Label^ FormGrupNameLabel;
	private: System::Windows::Forms::TextBox^ FormGrupNameTextBox;
	private: System::Windows::Forms::ComboBox^ AcademicTagComboBox;
	private: System::Windows::Forms::Label^ AcademicTagLabel;
	private: System::Windows::Forms::TextBox^ FormGrupDescriptionTextBox;
	private: System::Windows::Forms::Label^ GrupDescriptionLabel;
	private: System::Windows::Forms::Button^ CreateGrupButton;
	private: System::Windows::Forms::Panel^ FormPanel;
	private: GrupEstudiService^ grupEstudiService;

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
			this->pageTitle = (gcnew System::Windows::Forms::Label());
			this->eduConnectLabel = (gcnew System::Windows::Forms::Label());
			this->goBackButton = (gcnew System::Windows::Forms::Button());
			this->FormGrupNameLabel = (gcnew System::Windows::Forms::Label());
			this->FormGrupNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AcademicTagComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AcademicTagLabel = (gcnew System::Windows::Forms::Label());
			this->FormGrupDescriptionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GrupDescriptionLabel = (gcnew System::Windows::Forms::Label());
			this->CreateGrupButton = (gcnew System::Windows::Forms::Button());
			this->FormPanel = (gcnew System::Windows::Forms::Panel());
			this->FormPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// pageTitle
			// 
			this->pageTitle->AutoSize = true;
			this->pageTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pageTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->pageTitle->Location = System::Drawing::Point(85, 76);
			this->pageTitle->Name = L"pageTitle";
			this->pageTitle->Size = System::Drawing::Size(262, 31);
			this->pageTitle->TabIndex = 0;
			this->pageTitle->Text = L"Crear grup d\'estudi";
			// 
			// eduConnectLabel
			// 
			this->eduConnectLabel->AutoSize = true;
			this->eduConnectLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eduConnectLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->eduConnectLabel->Location = System::Drawing::Point(91, 60);
			this->eduConnectLabel->Name = L"eduConnectLabel";
			this->eduConnectLabel->Size = System::Drawing::Size(95, 17);
			this->eduConnectLabel->TabIndex = 1;
			this->eduConnectLabel->Text = L"EduConnect";
			// 
			// goBackButton
			// 
			this->goBackButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)));
			this->goBackButton->Location = System::Drawing::Point(1044, 621);
			this->goBackButton->Name = L"goBackButton";
			this->goBackButton->Size = System::Drawing::Size(75, 23);
			this->goBackButton->TabIndex = 2;
			this->goBackButton->Text = L"Tornar";
			this->goBackButton->UseVisualStyleBackColor = true;
			this->goBackButton->Click += gcnew System::EventHandler(this, &GrupEstudiUI::goBackButton_Click);
			// 
			// FormGrupNameLabel
			// 
			this->FormGrupNameLabel->AutoSize = true;
			this->FormGrupNameLabel->Location = System::Drawing::Point(20, 22);
			this->FormGrupNameLabel->Name = L"FormGrupNameLabel";
			this->FormGrupNameLabel->Size = System::Drawing::Size(29, 13);
			this->FormGrupNameLabel->TabIndex = 3;
			this->FormGrupNameLabel->Text = L"Nom";
			// 
			// FormGrupNameTextBox
			// 
			this->FormGrupNameTextBox->Location = System::Drawing::Point(23, 49);
			this->FormGrupNameTextBox->Name = L"FormGrupNameTextBox";
			this->FormGrupNameTextBox->Size = System::Drawing::Size(408, 20);
			this->FormGrupNameTextBox->TabIndex = 4;
			this->FormGrupNameTextBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudiUI::FormGrupNameTextBox_TextChanged);
			// 
			// AcademicTagComboBox
			// 
			this->AcademicTagComboBox->FormattingEnabled = true;
			this->AcademicTagComboBox->Location = System::Drawing::Point(20, 125);
			this->AcademicTagComboBox->Name = L"AcademicTagComboBox";
			this->AcademicTagComboBox->Size = System::Drawing::Size(224, 21);
			this->AcademicTagComboBox->TabIndex = 5;
			// 
			// AcademicTagLabel
			// 
			this->AcademicTagLabel->AutoSize = true;
			this->AcademicTagLabel->Location = System::Drawing::Point(20, 97);
			this->AcademicTagLabel->Name = L"AcademicTagLabel";
			this->AcademicTagLabel->Size = System::Drawing::Size(42, 13);
			this->AcademicTagLabel->TabIndex = 6;
			this->AcademicTagLabel->Text = L"Materia";
			// 
			// FormGrupDescriptionTextBox
			// 
			this->FormGrupDescriptionTextBox->Location = System::Drawing::Point(23, 217);
			this->FormGrupDescriptionTextBox->Multiline = true;
			this->FormGrupDescriptionTextBox->Name = L"FormGrupDescriptionTextBox";
			this->FormGrupDescriptionTextBox->Size = System::Drawing::Size(408, 135);
			this->FormGrupDescriptionTextBox->TabIndex = 8;
			this->FormGrupDescriptionTextBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudiUI::FormGrupDescriptionTextBox_TextChanged);
			// 
			// GrupDescriptionLabel
			// 
			this->GrupDescriptionLabel->AutoSize = true;
			this->GrupDescriptionLabel->Location = System::Drawing::Point(20, 190);
			this->GrupDescriptionLabel->Name = L"GrupDescriptionLabel";
			this->GrupDescriptionLabel->Size = System::Drawing::Size(57, 13);
			this->GrupDescriptionLabel->TabIndex = 7;
			this->GrupDescriptionLabel->Text = L"Descripció";
			// 
			// CreateGrupButton
			// 
			this->CreateGrupButton->Location = System::Drawing::Point(356, 367);
			this->CreateGrupButton->Name = L"CreateGrupButton";
			this->CreateGrupButton->Size = System::Drawing::Size(75, 23);
			this->CreateGrupButton->TabIndex = 9;
			this->CreateGrupButton->Text = L"Crear grup";
			this->CreateGrupButton->UseVisualStyleBackColor = true;
			this->CreateGrupButton->Click += gcnew System::EventHandler(this, &GrupEstudiUI::CreateGrupButton_Click);
			// 
			// FormPanel
			// 
			this->FormPanel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->FormPanel->Controls->Add(this->CreateGrupButton);
			this->FormPanel->Controls->Add(this->FormGrupDescriptionTextBox);
			this->FormPanel->Controls->Add(this->FormGrupNameLabel);
			this->FormPanel->Controls->Add(this->GrupDescriptionLabel);
			this->FormPanel->Controls->Add(this->AcademicTagComboBox);
			this->FormPanel->Controls->Add(this->FormGrupNameTextBox);
			this->FormPanel->Controls->Add(this->AcademicTagLabel);
			this->FormPanel->Location = System::Drawing::Point(91, 155);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(454, 411);
			this->FormPanel->TabIndex = 10;
			// 
			// GrupEstudiUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1175, 680);
			this->Controls->Add(this->goBackButton);
			this->Controls->Add(this->eduConnectLabel);
			this->Controls->Add(this->pageTitle);
			this->Controls->Add(this->FormPanel);
			this->Name = L"GrupEstudiUI";
			this->Text = L"Crear grup d\'estudi  - EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudiUI::GrupEstudiUI_Load);
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void goBackButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CreateGrupButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupNameTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupDescriptionTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
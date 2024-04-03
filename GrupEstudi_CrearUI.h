#pragma once
#include "GrupEstudi.h"
#include "GrupEstudiService.h"
#include "AcademicTag.h"
#include "MessageManager.h"
using namespace System;

using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_CrearUI
	/// </summary>
	public ref class GrupEstudi_CrearUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_CrearUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudi_CrearUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ PageTitle_Label;
	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::Button^ GoBack_Button;
	private: System::Windows::Forms::Label^ FormGrupName_Label;
	private: System::Windows::Forms::TextBox^ FormGrupName_TextBox;
	private: System::Windows::Forms::ComboBox^ AcademicTag_ComboBox;
	private: System::Windows::Forms::Label^ AcademicTag_Label;
	private: System::Windows::Forms::TextBox^ FormGrupDescription_TextBox;
	private: System::Windows::Forms::Label^ GrupDescription_Label;
	private: System::Windows::Forms::Button^ CreateGrup_Button;
	private: System::Windows::Forms::Panel^ FormPanel;
	private: GrupEstudiService^ grupEstudiService;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;


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
			this->PageTitle_Label = (gcnew System::Windows::Forms::Label());
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->FormGrupName_Label = (gcnew System::Windows::Forms::Label());
			this->FormGrupName_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->AcademicTag_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->AcademicTag_Label = (gcnew System::Windows::Forms::Label());
			this->FormGrupDescription_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->GrupDescription_Label = (gcnew System::Windows::Forms::Label());
			this->CreateGrup_Button = (gcnew System::Windows::Forms::Button());
			this->FormPanel = (gcnew System::Windows::Forms::Panel());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->FormPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// PageTitle_Label
			// 
			this->PageTitle_Label->AutoSize = true;
			this->PageTitle_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PageTitle_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->PageTitle_Label->Location = System::Drawing::Point(218, 68);
			this->PageTitle_Label->Name = L"PageTitle_Label";
			this->PageTitle_Label->Size = System::Drawing::Size(262, 31);
			this->PageTitle_Label->TabIndex = 0;
			this->PageTitle_Label->Text = L"Crear grup d\'estudi";
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(224, 52);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(80, 16);
			this->EduConnect_Label->TabIndex = 1;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GoBack_Button->Location = System::Drawing::Point(776, 526);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(75, 23);
			this->GoBack_Button->TabIndex = 2;
			this->GoBack_Button->Text = L"Cancelar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::GoBack_Button_Click);
			// 
			// FormGrupName_Label
			// 
			this->FormGrupName_Label->AutoSize = true;
			this->FormGrupName_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->FormGrupName_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->FormGrupName_Label->Location = System::Drawing::Point(20, 22);
			this->FormGrupName_Label->Name = L"FormGrupName_Label";
			this->FormGrupName_Label->Size = System::Drawing::Size(36, 16);
			this->FormGrupName_Label->TabIndex = 3;
			this->FormGrupName_Label->Text = L"Nom";
			// 
			// FormGrupName_TextBox
			// 
			this->FormGrupName_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FormGrupName_TextBox->Location = System::Drawing::Point(23, 49);
			this->FormGrupName_TextBox->Name = L"FormGrupName_TextBox";
			this->FormGrupName_TextBox->Size = System::Drawing::Size(408, 20);
			this->FormGrupName_TextBox->TabIndex = 4;
			this->FormGrupName_TextBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::FormGrupName_TextBox_TextChanged);
			// 
			// AcademicTag_ComboBox
			// 
			this->AcademicTag_ComboBox->FormattingEnabled = true;
			this->AcademicTag_ComboBox->Location = System::Drawing::Point(20, 125);
			this->AcademicTag_ComboBox->Name = L"AcademicTag_ComboBox";
			this->AcademicTag_ComboBox->Size = System::Drawing::Size(224, 21);
			this->AcademicTag_ComboBox->TabIndex = 5;
			// 
			// AcademicTag_Label
			// 
			this->AcademicTag_Label->AutoSize = true;
			this->AcademicTag_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AcademicTag_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AcademicTag_Label->Location = System::Drawing::Point(20, 97);
			this->AcademicTag_Label->Name = L"AcademicTag_Label";
			this->AcademicTag_Label->Size = System::Drawing::Size(52, 16);
			this->AcademicTag_Label->TabIndex = 6;
			this->AcademicTag_Label->Text = L"Materia";
			// 
			// FormGrupDescription_TextBox
			// 
			this->FormGrupDescription_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FormGrupDescription_TextBox->Location = System::Drawing::Point(23, 217);
			this->FormGrupDescription_TextBox->Multiline = true;
			this->FormGrupDescription_TextBox->Name = L"FormGrupDescription_TextBox";
			this->FormGrupDescription_TextBox->Size = System::Drawing::Size(408, 135);
			this->FormGrupDescription_TextBox->TabIndex = 8;
			this->FormGrupDescription_TextBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::FormGrupDescription_TextBox_TextChanged);
			// 
			// GrupDescription_Label
			// 
			this->GrupDescription_Label->AutoSize = true;
			this->GrupDescription_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GrupDescription_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GrupDescription_Label->Location = System::Drawing::Point(20, 190);
			this->GrupDescription_Label->Name = L"GrupDescription_Label";
			this->GrupDescription_Label->Size = System::Drawing::Size(72, 16);
			this->GrupDescription_Label->TabIndex = 7;
			this->GrupDescription_Label->Text = L"Descripció";
			// 
			// CreateGrup_Button
			// 
			this->CreateGrup_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->CreateGrup_Button->Location = System::Drawing::Point(356, 367);
			this->CreateGrup_Button->Name = L"CreateGrup_Button";
			this->CreateGrup_Button->Size = System::Drawing::Size(75, 23);
			this->CreateGrup_Button->TabIndex = 9;
			this->CreateGrup_Button->Text = L"Crear grup";
			this->CreateGrup_Button->UseVisualStyleBackColor = true;
			this->CreateGrup_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::CreateGrup_Button_Click);
			// 
			// FormPanel
			// 
			this->FormPanel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->FormPanel->Controls->Add(this->CreateGrup_Button);
			this->FormPanel->Controls->Add(this->FormGrupDescription_TextBox);
			this->FormPanel->Controls->Add(this->FormGrupName_Label);
			this->FormPanel->Controls->Add(this->GrupDescription_Label);
			this->FormPanel->Controls->Add(this->AcademicTag_ComboBox);
			this->FormPanel->Controls->Add(this->FormGrupName_TextBox);
			this->FormPanel->Controls->Add(this->AcademicTag_Label);
			this->FormPanel->Location = System::Drawing::Point(224, 118);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(454, 411);
			this->FormPanel->TabIndex = 10;
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-5, 555);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(928, 265);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 16;
			this->Background_PictureBox->TabStop = false;
			// 
			// GrupEstudi_CrearUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 657);
			this->Controls->Add(this->Background_PictureBox);
			this->Controls->Add(this->GoBack_Button);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->PageTitle_Label);
			this->Controls->Add(this->FormPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"GrupEstudi_CrearUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::GrupEstudi_CrearUI_Load);
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudi_CrearUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CreateGrup_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupDescription_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
};
}
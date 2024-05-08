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
		GrupEstudi_CrearUI(bool isSourceIniciUI);

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

	private: GrupEstudiService^ grupEstudiService;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ FormPanel;
	private: System::Windows::Forms::Button^ CreateGrup_Button;
	private: System::Windows::Forms::TextBox^ FormGrupDescription_TextBox;
	private: System::Windows::Forms::Label^ FormGrupName_Label;
	private: System::Windows::Forms::Label^ GrupDescription_Label;
	private: System::Windows::Forms::ComboBox^ AcademicTag_ComboBox;
	private: System::Windows::Forms::TextBox^ FormGrupName_TextBox;
	private: System::Windows::Forms::Label^ AcademicTag_Label;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: bool isSourceIniciUI;

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
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->FormPanel = (gcnew System::Windows::Forms::Panel());
			this->CreateGrup_Button = (gcnew System::Windows::Forms::Button());
			this->FormGrupDescription_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->FormGrupName_Label = (gcnew System::Windows::Forms::Label());
			this->GrupDescription_Label = (gcnew System::Windows::Forms::Label());
			this->AcademicTag_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->FormGrupName_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->AcademicTag_Label = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->FormPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// PageTitle_Label
			// 
			this->PageTitle_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PageTitle_Label->AutoSize = true;
			this->PageTitle_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PageTitle_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->PageTitle_Label->Location = System::Drawing::Point(272, 21);
			this->PageTitle_Label->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->PageTitle_Label->Name = L"PageTitle_Label";
			this->PageTitle_Label->Size = System::Drawing::Size(268, 33);
			this->PageTitle_Label->TabIndex = 0;
			this->PageTitle_Label->Text = L"Crear grup d\'estudi";
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
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->FormPanel, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->PageTitle_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 85.71429F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 75)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 17;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_CrearUI::tableLayoutPanel1_Paint);
			// 
			// FormPanel
			// 
			this->FormPanel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FormPanel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->FormPanel->Controls->Add(this->CreateGrup_Button);
			this->FormPanel->Controls->Add(this->FormGrupDescription_TextBox);
			this->FormPanel->Controls->Add(this->FormGrupName_Label);
			this->FormPanel->Controls->Add(this->GrupDescription_Label);
			this->FormPanel->Controls->Add(this->AcademicTag_ComboBox);
			this->FormPanel->Controls->Add(this->FormGrupName_TextBox);
			this->FormPanel->Controls->Add(this->AcademicTag_Label);
			this->FormPanel->Location = System::Drawing::Point(172, 74);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(467, 378);
			this->FormPanel->TabIndex = 10;
			// 
			// CreateGrup_Button
			// 
			this->CreateGrup_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreateGrup_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->CreateGrup_Button->Location = System::Drawing::Point(320, 334);
			this->CreateGrup_Button->Name = L"CreateGrup_Button";
			this->CreateGrup_Button->Size = System::Drawing::Size(111, 35);
			this->CreateGrup_Button->TabIndex = 9;
			this->CreateGrup_Button->Text = L"Crear grup";
			this->CreateGrup_Button->UseVisualStyleBackColor = true;
			this->CreateGrup_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::CreateGrup_Button_Click);
			// 
			// FormGrupDescription_TextBox
			// 
			this->FormGrupDescription_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FormGrupDescription_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormGrupDescription_TextBox->Location = System::Drawing::Point(23, 190);
			this->FormGrupDescription_TextBox->Multiline = true;
			this->FormGrupDescription_TextBox->Name = L"FormGrupDescription_TextBox";
			this->FormGrupDescription_TextBox->Size = System::Drawing::Size(408, 135);
			this->FormGrupDescription_TextBox->TabIndex = 8;
			this->FormGrupDescription_TextBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::FormGrupDescription_TextBox_TextChanged);
			// 
			// FormGrupName_Label
			// 
			this->FormGrupName_Label->AutoSize = true;
			this->FormGrupName_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormGrupName_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->FormGrupName_Label->Location = System::Drawing::Point(20, 27);
			this->FormGrupName_Label->Name = L"FormGrupName_Label";
			this->FormGrupName_Label->Size = System::Drawing::Size(45, 19);
			this->FormGrupName_Label->TabIndex = 3;
			this->FormGrupName_Label->Text = L"Nom";
			// 
			// GrupDescription_Label
			// 
			this->GrupDescription_Label->AutoSize = true;
			this->GrupDescription_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GrupDescription_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GrupDescription_Label->Location = System::Drawing::Point(20, 168);
			this->GrupDescription_Label->Name = L"GrupDescription_Label";
			this->GrupDescription_Label->Size = System::Drawing::Size(135, 19);
			this->GrupDescription_Label->TabIndex = 7;
			this->GrupDescription_Label->Text = L"Descripci\u00F3";
			// 
			// AcademicTag_ComboBox
			// 
			this->AcademicTag_ComboBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AcademicTag_ComboBox->FormattingEnabled = true;
			this->AcademicTag_ComboBox->Location = System::Drawing::Point(24, 119);
			this->AcademicTag_ComboBox->Name = L"AcademicTag_ComboBox";
			this->AcademicTag_ComboBox->Size = System::Drawing::Size(224, 27);
			this->AcademicTag_ComboBox->TabIndex = 5;
			// 
			// FormGrupName_TextBox
			// 
			this->FormGrupName_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormGrupName_TextBox->Location = System::Drawing::Point(23, 49);
			this->FormGrupName_TextBox->Name = L"FormGrupName_TextBox";
			this->FormGrupName_TextBox->Size = System::Drawing::Size(408, 27);
			this->FormGrupName_TextBox->TabIndex = 4;
			this->FormGrupName_TextBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::FormGrupName_TextBox_TextChanged);
			// 
			// AcademicTag_Label
			// 
			this->AcademicTag_Label->AutoSize = true;
			this->AcademicTag_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AcademicTag_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AcademicTag_Label->Location = System::Drawing::Point(20, 97);
			this->AcademicTag_Label->Name = L"AcademicTag_Label";
			this->AcademicTag_Label->Size = System::Drawing::Size(66, 19);
			this->AcademicTag_Label->TabIndex = 6;
			this->AcademicTag_Label->Text = L"Materia";
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(687, 481);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(90, 35);
			this->Cancelar_Button->TabIndex = 11;
			this->Cancelar_Button->Text = L"Cancelar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::Cancelar_Button_Click);
			// 
			// GrupEstudi_CrearUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Background_PictureBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GrupEstudi_CrearUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_CrearUI::GrupEstudi_CrearUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void GrupEstudi_CrearUI_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void CreateGrup_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void FormGrupName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void FormGrupDescription_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);

};
}
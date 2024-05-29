#pragma once
#include "Reports_GestioUI.h"
#include "ReportsService.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include "IniciSessioService.h"
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
	public ref class Reports_GestioUI : public System::Windows::Forms::Form
	{
	public:
		Reports_GestioUI(Int64^ id_report);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Reports_GestioUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ PageTitle_Label;
	private: ReportsService^ reportService;
	private: IniciSessioService^ iniciSessioService;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ FormPanel;
	private: System::Windows::Forms::Button^ Sanciona_Button;
	private: System::Windows::Forms::TextBox^ Description_TextBox;



	private: System::Windows::Forms::Label^ GrupDescription_Label;
	private: System::Windows::Forms::ComboBox^ Sancio_ComboBox;


	private: System::Windows::Forms::Label^ sancio_Label;

	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: Int64^ report_id;
	private: System::Windows::Forms::Label^ de;
	private: System::Windows::Forms::Label^ nom_de;
	private: System::Windows::Forms::Label^ per;
	private: System::Windows::Forms::Label^ nom_per;


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
			this->nom_per = (gcnew System::Windows::Forms::Label());
			this->per = (gcnew System::Windows::Forms::Label());
			this->nom_de = (gcnew System::Windows::Forms::Label());
			this->de = (gcnew System::Windows::Forms::Label());
			this->Sanciona_Button = (gcnew System::Windows::Forms::Button());
			this->Description_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->GrupDescription_Label = (gcnew System::Windows::Forms::Label());
			this->Sancio_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->sancio_Label = (gcnew System::Windows::Forms::Label());
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
			this->PageTitle_Label->Location = System::Drawing::Point(291, 21);
			this->PageTitle_Label->Margin = System::Windows::Forms::Padding(3, 10, 3, 0);
			this->PageTitle_Label->Name = L"PageTitle_Label";
			this->PageTitle_Label->Size = System::Drawing::Size(230, 33);
			this->PageTitle_Label->TabIndex = 0;
			this->PageTitle_Label->Text = L"Gestiona Report";
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
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Reports_GestioUI::tableLayoutPanel1_Paint);
			// 
			// FormPanel
			// 
			this->FormPanel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FormPanel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->FormPanel->Controls->Add(this->nom_per);
			this->FormPanel->Controls->Add(this->per);
			this->FormPanel->Controls->Add(this->nom_de);
			this->FormPanel->Controls->Add(this->de);
			this->FormPanel->Controls->Add(this->Sanciona_Button);
			this->FormPanel->Controls->Add(this->Description_TextBox);
			this->FormPanel->Controls->Add(this->GrupDescription_Label);
			this->FormPanel->Controls->Add(this->Sancio_ComboBox);
			this->FormPanel->Controls->Add(this->sancio_Label);
			this->FormPanel->Location = System::Drawing::Point(172, 74);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(467, 378);
			this->FormPanel->TabIndex = 10;
			// 
			// nom_per
			// 
			this->nom_per->AutoSize = true;
			this->nom_per->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_per->ForeColor = System::Drawing::SystemColors::Desktop;
			this->nom_per->Location = System::Drawing::Point(253, 28);
			this->nom_per->Name = L"nom_per";
			this->nom_per->Size = System::Drawing::Size(47, 19);
			this->nom_per->TabIndex = 14;
			this->nom_per->Text = L"NOM";
			// 
			// per
			// 
			this->per->AutoSize = true;
			this->per->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->per->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->per->Location = System::Drawing::Point(211, 28);
			this->per->Name = L"per";
			this->per->Size = System::Drawing::Size(38, 19);
			this->per->TabIndex = 12;
			this->per->Text = L"Per:";
			// 
			// nom_de
			// 
			this->nom_de->AutoSize = true;
			this->nom_de->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_de->ForeColor = System::Drawing::SystemColors::Desktop;
			this->nom_de->Location = System::Drawing::Point(58, 28);
			this->nom_de->Name = L"nom_de";
			this->nom_de->Size = System::Drawing::Size(47, 19);
			this->nom_de->TabIndex = 13;
			this->nom_de->Text = L"NOM";
			// 
			// de
			// 
			this->de->AutoSize = true;
			this->de->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->de->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->de->Location = System::Drawing::Point(20, 28);
			this->de->Name = L"de";
			this->de->Size = System::Drawing::Size(34, 19);
			this->de->TabIndex = 11;
			this->de->Text = L"De:";
			// 
			// Sanciona_Button
			// 
			this->Sanciona_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sanciona_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Sanciona_Button->Location = System::Drawing::Point(320, 334);
			this->Sanciona_Button->Name = L"Sanciona_Button";
			this->Sanciona_Button->Size = System::Drawing::Size(111, 35);
			this->Sanciona_Button->TabIndex = 9;
			this->Sanciona_Button->Text = L"Sanciona";
			this->Sanciona_Button->UseVisualStyleBackColor = true;
			this->Sanciona_Button->Click += gcnew System::EventHandler(this, &Reports_GestioUI::Sanciona_Button_Click);
			// 
			// Description_TextBox
			// 
			this->Description_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Description_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Description_TextBox->Location = System::Drawing::Point(23, 190);
			this->Description_TextBox->Multiline = true;
			this->Description_TextBox->Name = L"Description_TextBox";
			this->Description_TextBox->Size = System::Drawing::Size(408, 135);
			this->Description_TextBox->TabIndex = 8;
			this->Description_TextBox->TextChanged += gcnew System::EventHandler(this, &Reports_GestioUI::FormGrupDescription_TextBox_TextChanged);
			// 
			// GrupDescription_Label
			// 
			this->GrupDescription_Label->AutoSize = true;
			this->GrupDescription_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GrupDescription_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GrupDescription_Label->Location = System::Drawing::Point(20, 168);
			this->GrupDescription_Label->Name = L"GrupDescription_Label";
			this->GrupDescription_Label->Size = System::Drawing::Size(90, 19);
			this->GrupDescription_Label->TabIndex = 7;
			this->GrupDescription_Label->Text = L"Descripció:";
			this->GrupDescription_Label->Click += gcnew System::EventHandler(this, &Reports_GestioUI::GrupDescription_Label_Click);
			// 
			// Sancio_ComboBox
			// 
			this->Sancio_ComboBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sancio_ComboBox->FormattingEnabled = true;
			this->Sancio_ComboBox->Location = System::Drawing::Point(24, 119);
			this->Sancio_ComboBox->Name = L"Sancio_ComboBox";
			this->Sancio_ComboBox->Size = System::Drawing::Size(224, 27);
			this->Sancio_ComboBox->TabIndex = 5;
			// 
			// sancio_Label
			// 
			this->sancio_Label->AutoSize = true;
			this->sancio_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sancio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->sancio_Label->Location = System::Drawing::Point(20, 97);
			this->sancio_Label->Name = L"sancio_Label";
			this->sancio_Label->Size = System::Drawing::Size(64, 19);
			this->sancio_Label->TabIndex = 6;
			this->sancio_Label->Text = L"Sanció:";
			this->sancio_Label->Click += gcnew System::EventHandler(this, &Reports_GestioUI::AcademicTag_Label_Click);
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
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &Reports_GestioUI::Cancelar_Button_Click);
			// 
			// Reports_GestioUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Background_PictureBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Reports_GestioUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &Reports_GestioUI::GrupEstudi_CrearUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GrupEstudi_CrearUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Sanciona_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupDescription_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void AcademicTag_Label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void GrupDescription_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
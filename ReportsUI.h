#pragma once
/*#include "GrupEstudi.h"
#include "SessionService.h"
#include "GrupSessionAttendantsService.h"
#include "ConsultaEspaisService.h"
#include "GrupEstudi.h"
#include "GrupEstudiService.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include <vector>
#include "Usuari.h"*/
#include "ReportsService.h"
#include "GrupEstudiService.h"

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
	public ref class ReportsUI : public System::Windows::Forms::Form
	{
	public:
		ReportsUI(String^ CurrentMembre, String^ CurrentGroup);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ReportsUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ PageTitle_Label;

	private: ReportsService^ reportService;
	private: GrupEstudiService^ grupService;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ FormPanel;
	private: System::Windows::Forms::Button^ CreateGrup_Button;
	private: System::Windows::Forms::TextBox^ FormDescription_TextBox;

	private: System::Windows::Forms::Label^ FormGrupName_Label;
	private: System::Windows::Forms::Label^ GrupDescription_Label;

	private: System::Windows::Forms::TextBox^ FormUserRep_TextBox;


	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: String^ MembreReport;
	private: String^ GrupActual;


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
			this->FormDescription_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->FormGrupName_Label = (gcnew System::Windows::Forms::Label());
			this->GrupDescription_Label = (gcnew System::Windows::Forms::Label());
			this->FormUserRep_TextBox = (gcnew System::Windows::Forms::TextBox());
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
			this->PageTitle_Label->Location = System::Drawing::Point(402, 26);
			this->PageTitle_Label->Margin = System::Windows::Forms::Padding(4, 12, 4, 0);
			this->PageTitle_Label->Name = L"PageTitle_Label";
			this->PageTitle_Label->Size = System::Drawing::Size(281, 41);
			this->PageTitle_Label->TabIndex = 0;
			this->PageTitle_Label->Text = L"Reportar Usuari";
			this->PageTitle_Label->Click += gcnew System::EventHandler(this, &ReportsUI::PageTitle_Label_Click);
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-7, 683);
			this->Background_PictureBox->Margin = System::Windows::Forms::Padding(4);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(1237, 326);
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
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 85.71429F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 92)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1085, 661);
			this->tableLayoutPanel1->TabIndex = 17;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ReportsUI::tableLayoutPanel1_Paint);
			// 
			// FormPanel
			// 
			this->FormPanel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->FormPanel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->FormPanel->Controls->Add(this->CreateGrup_Button);
			this->FormPanel->Controls->Add(this->FormDescription_TextBox);
			this->FormPanel->Controls->Add(this->FormGrupName_Label);
			this->FormPanel->Controls->Add(this->GrupDescription_Label);
			this->FormPanel->Controls->Add(this->FormUserRep_TextBox);
			this->FormPanel->Location = System::Drawing::Point(231, 92);
			this->FormPanel->Margin = System::Windows::Forms::Padding(4);
			this->FormPanel->Name = L"FormPanel";
			this->FormPanel->Size = System::Drawing::Size(623, 465);
			this->FormPanel->TabIndex = 10;
			// 
			// CreateGrup_Button
			// 
			this->CreateGrup_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CreateGrup_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->CreateGrup_Button->Location = System::Drawing::Point(427, 411);
			this->CreateGrup_Button->Margin = System::Windows::Forms::Padding(4);
			this->CreateGrup_Button->Name = L"CreateGrup_Button";
			this->CreateGrup_Button->Size = System::Drawing::Size(148, 43);
			this->CreateGrup_Button->TabIndex = 9;
			this->CreateGrup_Button->Text = L"Reportar";
			this->CreateGrup_Button->UseVisualStyleBackColor = true;
			this->CreateGrup_Button->Click += gcnew System::EventHandler(this, &ReportsUI::Reportar_Button_Click);
			// 
			// FormDescription_TextBox
			// 
			this->FormDescription_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FormDescription_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormDescription_TextBox->Location = System::Drawing::Point(31, 156);
			this->FormDescription_TextBox->Margin = System::Windows::Forms::Padding(4);
			this->FormDescription_TextBox->Multiline = true;
			this->FormDescription_TextBox->Name = L"FormDescription_TextBox";
			this->FormDescription_TextBox->Size = System::Drawing::Size(543, 244);
			this->FormDescription_TextBox->TabIndex = 8;
			this->FormDescription_TextBox->TextChanged += gcnew System::EventHandler(this, &ReportsUI::FormGrupDescription_TextBox_TextChanged);
			// 
			// FormGrupName_Label
			// 
			this->FormGrupName_Label->AutoSize = true;
			this->FormGrupName_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormGrupName_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->FormGrupName_Label->Location = System::Drawing::Point(27, 33);
			this->FormGrupName_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->FormGrupName_Label->Name = L"FormGrupName_Label";
			this->FormGrupName_Label->Size = System::Drawing::Size(175, 24);
			this->FormGrupName_Label->TabIndex = 3;
			this->FormGrupName_Label->Text = L"Usuari a reportar:";
			// 
			// GrupDescription_Label
			// 
			this->GrupDescription_Label->AutoSize = true;
			this->GrupDescription_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GrupDescription_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->GrupDescription_Label->Location = System::Drawing::Point(27, 128);
			this->GrupDescription_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->GrupDescription_Label->Name = L"GrupDescription_Label";
			this->GrupDescription_Label->Size = System::Drawing::Size(70, 24);
			this->GrupDescription_Label->TabIndex = 7;
			this->GrupDescription_Label->Text = L"Motiu:";
			this->GrupDescription_Label->Click += gcnew System::EventHandler(this, &ReportsUI::GrupDescription_Label_Click);
			// 
			// FormUserRep_TextBox
			// 
			this->FormUserRep_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->FormUserRep_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormUserRep_TextBox->Location = System::Drawing::Point(31, 60);
			this->FormUserRep_TextBox->Margin = System::Windows::Forms::Padding(4);
			this->FormUserRep_TextBox->Name = L"FormUserRep_TextBox";
			this->FormUserRep_TextBox->ReadOnly = true;
			this->FormUserRep_TextBox->Size = System::Drawing::Size(543, 32);
			this->FormUserRep_TextBox->TabIndex = 4;
			this->FormUserRep_TextBox->TextChanged += gcnew System::EventHandler(this, &ReportsUI::FormGrupName_TextBox_TextChanged);
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(916, 593);
			this->Cancelar_Button->Margin = System::Windows::Forms::Padding(4);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(120, 43);
			this->Cancelar_Button->TabIndex = 11;
			this->Cancelar_Button->Text = L"Cancelar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &ReportsUI::Cancelar_Button_Click);
			// 
			// ReportsUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 661);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Background_PictureBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ReportsUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &ReportsUI::Reports_CrearUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->FormPanel->ResumeLayout(false);
			this->FormPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Reports_CrearUI_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void Reportar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void FormGrupName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void FormGrupDescription_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PageTitle_Label_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void GrupDescription_Label_Click(System::Object^ sender, System::EventArgs^ e) {}
};
}


#pragma once
#include "GrupEstudiService.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembership.h"
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "Usuari.h"
#include "CurrentSession.h"
#include "GrupEstudi_EditarUI.h"
#include "MessageManager.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_Explorar
	/// </summary>
	public ref class GrupEstudi_Explorar : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_Explorar(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudi_Explorar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ ExplorarGrupEstudi_Label;

	private: System::Windows::Forms::Panel^ Actual_Panel;

	private: System::Windows::Forms::Button^ Membres_Button;






	private: System::Windows::Forms::ListBox^ Noms_ListBox;
	private: System::Windows::Forms::Label^ NomPertany_Label;

	private: System::Windows::Forms::ListBox^ Description_ListBox;


	private: GrupEstudiService^ grupEstudiService;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: array<GrupEstudi^>^ arrayIdGroupEstudisOfUserNoIn;
	private: System::Windows::Forms::Label^ Description_titulo;
	//private: System::Windows::Forms::Label^ num_mem;

	private: System::Windows::Forms::Label^ academicTag_titulo;
	private: System::Windows::Forms::Label^ Num_membres;
	//private: System::Windows::Forms::Label^ academic_tag;
	private: System::Windows::Forms::TextBox^ academictag;

	private: System::Windows::Forms::TextBox^ nummem;
	private: System::Windows::Forms::TextBox^ buscador_textBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ Unirse_Button;





		   //private: String^ Noms_ListBox;








	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ExplorarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			this->academictag = (gcnew System::Windows::Forms::TextBox());
			this->nummem = (gcnew System::Windows::Forms::TextBox());
			this->academicTag_titulo = (gcnew System::Windows::Forms::Label());
			this->Unirse_Button = (gcnew System::Windows::Forms::Button());
			this->Description_titulo = (gcnew System::Windows::Forms::Label());
			this->Membres_Button = (gcnew System::Windows::Forms::Button());
			this->Num_membres = (gcnew System::Windows::Forms::Label());
			this->Description_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->NomPertany_Label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->buscador_textBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->Actual_Panel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->ExplorarGrupEstudi_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.04651F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.07752F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 78.87597F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_Explorar::tableLayoutPanel1_Paint);
			// 
			// ExplorarGrupEstudi_Label
			// 
			this->ExplorarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ExplorarGrupEstudi_Label->AutoSize = true;
			this->ExplorarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExplorarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->ExplorarGrupEstudi_Label->Location = System::Drawing::Point(243, 12);
			this->ExplorarGrupEstudi_Label->Name = L"ExplorarGrupEstudi_Label";
			this->ExplorarGrupEstudi_Label->Size = System::Drawing::Size(326, 33);
			this->ExplorarGrupEstudi_Label->TabIndex = 3;
			this->ExplorarGrupEstudi_Label->Text = L"Explorar Grups d\'Estudi";
			// 
			// Actual_Panel
			// 
			this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Actual_Panel->Controls->Add(this->academictag);
			this->Actual_Panel->Controls->Add(this->nummem);
			this->Actual_Panel->Controls->Add(this->academicTag_titulo);
			this->Actual_Panel->Controls->Add(this->Unirse_Button);
			this->Actual_Panel->Controls->Add(this->Description_titulo);
			this->Actual_Panel->Controls->Add(this->Membres_Button);
			this->Actual_Panel->Controls->Add(this->Num_membres);
			this->Actual_Panel->Controls->Add(this->Description_ListBox);
			this->Actual_Panel->Controls->Add(this->Noms_ListBox);
			this->Actual_Panel->Controls->Add(this->NomPertany_Label);
			this->Actual_Panel->Location = System::Drawing::Point(185, 112);
			this->Actual_Panel->Name = L"Actual_Panel";
			this->Actual_Panel->Size = System::Drawing::Size(441, 401);
			this->Actual_Panel->TabIndex = 7;
			this->Actual_Panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_Explorar::Actual_Panel_Paint);
			// 
			// academictag
			// 
			this->academictag->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->academictag->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->academictag->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->academictag->Location = System::Drawing::Point(314, 308);
			this->academictag->Name = L"academictag";
			this->academictag->ReadOnly = true;
			this->academictag->Size = System::Drawing::Size(100, 20);
			this->academictag->TabIndex = 15;
			this->academictag->Visible = false;
			// 
			// nummem
			// 
			this->nummem->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->nummem->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nummem->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nummem->Location = System::Drawing::Point(25, 308);
			this->nummem->Name = L"nummem";
			this->nummem->ReadOnly = true;
			this->nummem->Size = System::Drawing::Size(100, 20);
			this->nummem->TabIndex = 8;
			this->nummem->Visible = false;
			// 
			// academicTag_titulo
			// 
			this->academicTag_titulo->AutoSize = true;
			this->academicTag_titulo->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->academicTag_titulo->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->academicTag_titulo->Location = System::Drawing::Point(310, 286);
			this->academicTag_titulo->Name = L"academicTag_titulo";
			this->academicTag_titulo->Size = System::Drawing::Size(98, 19);
			this->academicTag_titulo->TabIndex = 12;
			this->academicTag_titulo->Text = L"Assignatura";
			this->academicTag_titulo->Visible = false;
			// 
			// Unirse_Button
			// 
			this->Unirse_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Unirse_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Unirse_Button->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Unirse_Button->Location = System::Drawing::Point(265, 353);
			this->Unirse_Button->Name = L"Unirse_Button";
			this->Unirse_Button->Size = System::Drawing::Size(143, 35);
			this->Unirse_Button->TabIndex = 8;
			this->Unirse_Button->Text = L"Unir-se";
			this->Unirse_Button->UseVisualStyleBackColor = true;
			this->Unirse_Button->Visible = false;
			this->Unirse_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_Explorar::Unirse_Button_Click);
			// 
			// Description_titulo
			// 
			this->Description_titulo->AutoSize = true;
			this->Description_titulo->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Description_titulo->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Description_titulo->Location = System::Drawing::Point(21, 172);
			this->Description_titulo->Name = L"Description_titulo";
			this->Description_titulo->Size = System::Drawing::Size(93, 19);
			this->Description_titulo->TabIndex = 10;
			this->Description_titulo->Text = L"Descripció ";
			this->Description_titulo->Visible = false;
			// 
			// Membres_Button
			// 
			this->Membres_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Membres_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Membres_Button->Location = System::Drawing::Point(25, 353);
			this->Membres_Button->Margin = System::Windows::Forms::Padding(4);
			this->Membres_Button->Name = L"Membres_Button";
			this->Membres_Button->Size = System::Drawing::Size(143, 35);
			this->Membres_Button->TabIndex = 9;
			this->Membres_Button->Text = L"Veure membres";
			this->Membres_Button->UseVisualStyleBackColor = true;
			this->Membres_Button->Visible = false;
			this->Membres_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_Explorar::Membres_Button_Click);
			// 
			// Num_membres
			// 
			this->Num_membres->AutoSize = true;
			this->Num_membres->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Num_membres->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Num_membres->Location = System::Drawing::Point(21, 286);
			this->Num_membres->Name = L"Num_membres";
			this->Num_membres->Size = System::Drawing::Size(79, 19);
			this->Num_membres->TabIndex = 11;
			this->Num_membres->Text = L"Membres";
			this->Num_membres->Visible = false;
			// 
			// Description_ListBox
			// 
			this->Description_ListBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Description_ListBox->BackColor = System::Drawing::SystemColors::Window;
			this->Description_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Description_ListBox->FormattingEnabled = true;
			this->Description_ListBox->HorizontalScrollbar = true;
			this->Description_ListBox->ItemHeight = 19;
			this->Description_ListBox->Location = System::Drawing::Point(25, 194);
			this->Description_ListBox->Name = L"Description_ListBox";
			this->Description_ListBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->Description_ListBox->Size = System::Drawing::Size(383, 80);
			this->Description_ListBox->TabIndex = 9;
			this->Description_ListBox->Visible = false;
			// 
			// Noms_ListBox
			// 
			this->Noms_ListBox->BackColor = System::Drawing::SystemColors::Window;
			this->Noms_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Noms_ListBox->FormattingEnabled = true;
			this->Noms_ListBox->IntegralHeight = false;
			this->Noms_ListBox->ItemHeight = 19;
			this->Noms_ListBox->Location = System::Drawing::Point(25, 40);
			this->Noms_ListBox->Name = L"Noms_ListBox";
			this->Noms_ListBox->Size = System::Drawing::Size(383, 119);
			this->Noms_ListBox->TabIndex = 2;
			this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_Explorar::Noms_ListBox_SelectedIndexChanged);
			// 
			// NomPertany_Label
			// 
			this->NomPertany_Label->AutoSize = true;
			this->NomPertany_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomPertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomPertany_Label->Location = System::Drawing::Point(21, 18);
			this->NomPertany_Label->Name = L"NomPertany_Label";
			this->NomPertany_Label->Size = System::Drawing::Size(44, 19);
			this->NomPertany_Label->TabIndex = 1;
			this->NomPertany_Label->Text = L"Nom";
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->buscador_textBox);
			this->panel1->Location = System::Drawing::Point(186, 60);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(440, 46);
			this->panel1->TabIndex = 10;
			// 
			// buscador_textBox
			// 
			this->buscador_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->buscador_textBox->BackColor = System::Drawing::SystemColors::Window;
			this->buscador_textBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buscador_textBox->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->buscador_textBox->Location = System::Drawing::Point(24, 10);
			this->buscador_textBox->Margin = System::Windows::Forms::Padding(2);
			this->buscador_textBox->Name = L"buscador_textBox";
			this->buscador_textBox->Size = System::Drawing::Size(383, 27);
			this->buscador_textBox->TabIndex = 8;
			this->buscador_textBox->Text = L"Buscar Grup d\'Estudi...";
			this->buscador_textBox->Click += gcnew System::EventHandler(this, &GrupEstudi_Explorar::buscador_textBox_Click);
			this->buscador_textBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_Explorar::buscador_textBox_TextChanged);
			// 
			// GrupEstudi_Explorar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GrupEstudi_Explorar";
			this->Text = L"GrupEstudi_Explorar";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_Explorar::GrupEstudi_Explorar_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->Actual_Panel->ResumeLayout(false);
			this->Actual_Panel->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void Actual_Panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	private: System::Void Pertany_Label_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}

	private: System::Void Membres_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Unirse_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancela_Button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void GrupEstudi_Explorar_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void Description_ListBox_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numero_membres(System::Object^ sender, System::EventArgs^ e);
	private: System::Void academic_tag(System::Object^ sender, System::EventArgs^ e);

	//private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	//private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {}
	
	private: System::Void buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buscar_button_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
	array<GrupEstudi^>^ GrupEstudi_Explorar_Array();
	void GrupEstudi_Explorar_FormClosed();

};
};
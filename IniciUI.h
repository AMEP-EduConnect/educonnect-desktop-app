#pragma once
#include "GrupEstudi.h"
#include "IniciUI.h"
#include "CurrentSession.h"
#include "GrupEstudi.h"
#include <ctime>
#include <iostream>

#include "GrupEstudiService.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IniciUI
	/// </summary>
	public ref class IniciUI : public System::Windows::Forms::Form
	{
	public:
		IniciUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~IniciUI()
		{
			if (components)
			{
				delete components;
			}
		}
	//GrupEstudiService^ grupEstudiService;
	private: GrupEstudiService^ grupEstudiService;
	private:
	private: System::Windows::Forms::Label^ Benvinguda;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;




	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel5;























	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label7;









	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::TableLayoutPanel^ Grup1;
	private: System::Windows::Forms::Label^ Grup1label;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TableLayoutPanel^ Grup2;
	private: System::Windows::Forms::Label^ Grup2label;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TableLayoutPanel^ Grup3;
	private: System::Windows::Forms::Label^ Grup3label;

	private: System::Windows::Forms::PictureBox^ pictureBox1;







































	protected:

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
			this->Benvinguda = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Grup1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Grup1label = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->Grup2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Grup2label = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Grup3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Grup3label = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->Grup1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->Grup2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->Grup3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// Benvinguda
			// 
			this->Benvinguda->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Benvinguda->AutoSize = true;
			this->Benvinguda->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Benvinguda->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Benvinguda->Location = System::Drawing::Point(0, 16);
			this->Benvinguda->Name = L"Benvinguda";
			this->Benvinguda->Size = System::Drawing::Size(172, 33);
			this->Benvinguda->TabIndex = 0;
			this->Benvinguda->Text = L"Benvinguda";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				4.307974F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				95.69202F)));
			this->tableLayoutPanel1->Controls->Add(this->panel4, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.59404F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.40596F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->panel1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(38, 75);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(773, 459);
			this->panel4->TabIndex = 2;
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->Controls->Add(this->label2);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Location = System::Drawing::Point(0, 267);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(770, 190);
			this->panel5->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter Light", 14));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(2, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Notificacions";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Inter Light", 14));
			this->label3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Location = System::Drawing::Point(332, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(234, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Recomanacions de grups";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->flowLayoutPanel1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(0, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(770, 263);
			this->panel1->TabIndex = 4;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->Controls->Add(this->Grup1);
			this->flowLayoutPanel1->Controls->Add(this->Grup2);
			this->flowLayoutPanel1->Controls->Add(this->Grup3);
			this->flowLayoutPanel1->Controls->Add(this->tableLayoutPanel2);
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, 51);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(767, 187);
			this->flowLayoutPanel1->TabIndex = 4;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &IniciUI::flowLayoutPanel1_Paint_1);
			// 
			// Grup1
			// 
			this->Grup1->ColumnCount = 1;
			this->Grup1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup1->Controls->Add(this->Grup1label, 0, 1);
			this->Grup1->Controls->Add(this->pictureBox3, 0, 0);
			this->Grup1->Location = System::Drawing::Point(3, 3);
			this->Grup1->Margin = System::Windows::Forms::Padding(3, 3, 30, 3);
			this->Grup1->Name = L"Grup1";
			this->Grup1->RowCount = 2;
			this->Grup1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->Grup1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->Grup1->Size = System::Drawing::Size(132, 163);
			this->Grup1->TabIndex = 12;
			// 
			// Grup1label
			// 
			this->Grup1label->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Grup1label->AutoSize = true;
			this->Grup1label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Grup1label->Location = System::Drawing::Point(3, 138);
			this->Grup1label->Name = L"Grup1label";
			this->Grup1label->Size = System::Drawing::Size(86, 19);
			this->Grup1label->TabIndex = 4;
			this->Grup1label->Text = L"Nom Grup";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Location = System::Drawing::Point(3, 3);
			this->pictureBox3->MinimumSize = System::Drawing::Size(126, 126);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(126, 126);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
			// 
			// Grup2
			// 
			this->Grup2->ColumnCount = 1;
			this->Grup2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup2->Controls->Add(this->Grup2label, 0, 1);
			this->Grup2->Controls->Add(this->pictureBox2, 0, 0);
			this->Grup2->Location = System::Drawing::Point(168, 3);
			this->Grup2->Margin = System::Windows::Forms::Padding(3, 3, 30, 3);
			this->Grup2->Name = L"Grup2";
			this->Grup2->RowCount = 2;
			this->Grup2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->Grup2->Size = System::Drawing::Size(132, 163);
			this->Grup2->TabIndex = 14;
			// 
			// Grup2label
			// 
			this->Grup2label->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Grup2label->AutoSize = true;
			this->Grup2label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Grup2label->Location = System::Drawing::Point(3, 138);
			this->Grup2label->Name = L"Grup2label";
			this->Grup2label->Size = System::Drawing::Size(86, 19);
			this->Grup2label->TabIndex = 4;
			this->Grup2label->Text = L"Nom Grup";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(3, 3);
			this->pictureBox2->MinimumSize = System::Drawing::Size(126, 126);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(126, 126);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
			// 
			// Grup3
			// 
			this->Grup3->ColumnCount = 1;
			this->Grup3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup3->Controls->Add(this->Grup3label, 0, 1);
			this->Grup3->Controls->Add(this->pictureBox1, 0, 0);
			this->Grup3->Location = System::Drawing::Point(333, 3);
			this->Grup3->Margin = System::Windows::Forms::Padding(3, 3, 30, 3);
			this->Grup3->Name = L"Grup3";
			this->Grup3->RowCount = 2;
			this->Grup3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->Grup3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->Grup3->Size = System::Drawing::Size(132, 163);
			this->Grup3->TabIndex = 13;
			// 
			// Grup3label
			// 
			this->Grup3label->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Grup3label->AutoSize = true;
			this->Grup3label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Grup3label->Location = System::Drawing::Point(3, 138);
			this->Grup3label->Name = L"Grup3label";
			this->Grup3label->Size = System::Drawing::Size(86, 19);
			this->Grup3label->TabIndex = 4;
			this->Grup3label->Text = L"Nom Grup";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->MinimumSize = System::Drawing::Size(126, 126);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(126, 126);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->panel2, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(498, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(169, 184);
			this->tableLayoutPanel2->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(163, 178);
			this->panel2->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label7->Location = System::Drawing::Point(28, 50);
			this->label7->Margin = System::Windows::Forms::Padding(3, 0, 3, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(108, 19);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Crea un grup";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox4->Location = System::Drawing::Point(2, 47);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(78, 3, 3, 25);
			this->pictureBox4->MaximumSize = System::Drawing::Size(24, 24);
			this->pictureBox4->MinimumSize = System::Drawing::Size(24, 24);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(24, 24);
			this->pictureBox4->TabIndex = 9;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox4_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Inter Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label4->Location = System::Drawing::Point(0, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(196, 33);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Grups recents";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->Benvinguda);
			this->panel3->Location = System::Drawing::Point(38, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(455, 66);
			this->panel3->TabIndex = 2;
			// 
			// IniciUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(814, 537);
			this->Name = L"IniciUI";
			this->Text = L"IniciUI";
			this->Load += gcnew System::EventHandler(this, &IniciUI::IniciUI_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->Grup1->ResumeLayout(false);
			this->Grup1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->Grup2->ResumeLayout(false);
			this->Grup2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->Grup3->ResumeLayout(false);
			this->Grup3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void IniciUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	Void SetWelcomeMessage();
	Void SetRecentGroups();


private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void flowLayoutPanel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox_Click(System::Object^ sender, System::EventArgs^ e);
};
}

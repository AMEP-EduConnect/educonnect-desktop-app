#pragma once
#include "AltaEspaisService.h"
#include "AdministradorUI.h"
#include "Espai.h"
#include "ConsultaEspaisUI.h"
#include <iostream>
#include <string>
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class AltaEspaisUI : public System::Windows::Forms::Form
	{
	public:
		AltaEspaisUI(void) {
			InitializeComponent();
			altaEspaisService = gcnew AltaEspaisService();
			this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AltaEspaisUI::Capacitat_TextBox_Validating);

			this->Icon = gcnew System::Drawing::Icon("app.ico");
		}
		bool NomEspai_TextBox_Validating(String^ nom);
		bool IsValidCapacitat(String^ capacitat);
		Void Capacitat_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estn usando.
		/// </summary>
		~AltaEspaisUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;

	private: AltaEspaisService^ altaEspaisService;
	protected:

	private:
		/// <summary>
		/// Variable del diseador necesaria.

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Button^ Cancelar_Button;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel1;


	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Mtodo necesario para admitir el Diseador. No se puede modificar
		   /// el contenido de este mtodo con el editor de cdigo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->tableLayoutPanel3->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(128, 186);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(119, 35);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"Confirmar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &AltaEspaisUI::button1_Click);
			   // 
			   // label6
			   // 
			   this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(280, 23);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(252, 33);
			   this->label6->TabIndex = 13;
			   this->label6->Text = L"Donar d\'alta Espai";
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
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			   this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->label6, 1, 0);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 16;
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(688, 452);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(88, 35);
			   this->Cancelar_Button->TabIndex = 3;
			   this->Cancelar_Button->Text = L"Cancelar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &AltaEspaisUI::Cancelar_Button_Click);
			   // 
			   // tableLayoutPanel3
			   // 
			   this->tableLayoutPanel3->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->tableLayoutPanel3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->tableLayoutPanel3->ColumnCount = 1;
			   this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel3->Controls->Add(this->panel1, 0, 0);
			   this->tableLayoutPanel3->Controls->Add(this->button1, 0, 1);
			   this->tableLayoutPanel3->Location = System::Drawing::Point(218, 122);
			   this->tableLayoutPanel3->MinimumSize = System::Drawing::Size(376, 237);
			   this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			   this->tableLayoutPanel3->RowCount = 2;
			   this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 71.72996F)));
			   this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.27004F)));
			   this->tableLayoutPanel3->Size = System::Drawing::Size(376, 237);
			   this->tableLayoutPanel3->TabIndex = 18;
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->Controls->Add(this->textBox3);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->textBox1);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Location = System::Drawing::Point(3, 11);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(370, 148);
			   this->panel1->TabIndex = 1;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox3->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->textBox3->Location = System::Drawing::Point(165, 36);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(158, 27);
			   this->textBox3->TabIndex = 0;
			   // 
			   // label2
			   // 
			   this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(23, 40);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(122, 19);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Nom de l\'espai";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->textBox1->Location = System::Drawing::Point(165, 90);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(158, 27);
			   this->textBox1->TabIndex = 1;
			   // 
			   // label3
			   // 
			   this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(62, 94);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(83, 19);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Capacitat";
			   // 
			   // AltaEspaisUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MinimumSize = System::Drawing::Size(814, 537);
			   this->Name = L"AltaEspaisUI";
			   this->Text = L"EduConnect";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->tableLayoutPanel3->ResumeLayout(false);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

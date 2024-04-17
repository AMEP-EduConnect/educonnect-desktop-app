#pragma once
#include "AltaProveidorService.h"
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class AltaProveidorUI : public System::Windows::Forms::Form
	{
	public:
		AltaProveidorUI(void);


	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~AltaProveidorUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;

	private: AltaProveidorService^ altaProveidorService;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Label^ label6;



	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;






		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->tableLayoutPanel3->SuspendLayout();
			   this->tableLayoutPanel2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->button1->Location = System::Drawing::Point(104, 216);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(199, 22);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Confirma";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &AltaProveidorUI::button1_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox2->Location = System::Drawing::Point(171, 91);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(162, 20);
			   this->textBox2->TabIndex = 2;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox3->Location = System::Drawing::Point(171, 11);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(162, 20);
			   this->textBox3->TabIndex = 3;
			   // 
			   // textBox4
			   // 
			   this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox4->Location = System::Drawing::Point(171, 137);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(162, 20);
			   this->textBox4->TabIndex = 4;
			   // 
			   // textBox5
			   // 
			   this->textBox5->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox5->Location = System::Drawing::Point(171, 51);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(162, 20);
			   this->textBox5->TabIndex = 5;
			   this->textBox5->TextChanged += gcnew System::EventHandler(this, &AltaProveidorUI::textBox5_TextChanged);
			   // 
			   // label2
			   // 
			   this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(69, 13);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(89, 16);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Nom d\'usuari:";
			   // 
			   // label3
			   // 
			   this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(72, 53);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(86, 16);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Contrasenya:";
			   // 
			   // label4
			   // 
			   this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(114, 93);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(44, 16);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Email:";
			   // 
			   // label5
			   // 
			   this->label5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->label5->AutoSize = true;
			   this->label5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(68, 139);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(90, 16);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"Nom complet:";
			   // 
			   // label6
			   // 
			   this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(361, 70);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(331, 31);
			   this->label6->TabIndex = 13;
			   this->label6->Text = L"Donar d\'Alta a Proveidor";
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 3;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   19.00258F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   61.30696F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   19.60447F)));
			   this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->label6, 1, 0);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.78241F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 47.54099F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 26.82563F)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1062, 671);
			   this->tableLayoutPanel1->TabIndex = 16;
			   // 
			   // tableLayoutPanel3
			   // 
			   this->tableLayoutPanel3->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->tableLayoutPanel3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->tableLayoutPanel3->ColumnCount = 1;
			   this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel3->Controls->Add(this->button1, 0, 1);
			   this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel2, 0, 0);
			   this->tableLayoutPanel3->Location = System::Drawing::Point(323, 201);
			   this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			   this->tableLayoutPanel3->RowCount = 2;
			   this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75.13228F)));
			   this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.86773F)));
			   this->tableLayoutPanel3->Size = System::Drawing::Size(407, 260);
			   this->tableLayoutPanel3->TabIndex = 18;
			   // 
			   // tableLayoutPanel2
			   // 
			   this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->tableLayoutPanel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->tableLayoutPanel2->ColumnCount = 2;
			   this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   47.03557F)));
			   this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   52.96443F)));
			   this->tableLayoutPanel2->Controls->Add(this->label3, 0, 1);
			   this->tableLayoutPanel2->Controls->Add(this->label4, 0, 2);
			   this->tableLayoutPanel2->Controls->Add(this->label5, 0, 3);
			   this->tableLayoutPanel2->Controls->Add(this->textBox2, 1, 2);
			   this->tableLayoutPanel2->Controls->Add(this->textBox3, 1, 0);
			   this->tableLayoutPanel2->Controls->Add(this->label2, 0, 0);
			   this->tableLayoutPanel2->Controls->Add(this->textBox4, 1, 3);
			   this->tableLayoutPanel2->Controls->Add(this->textBox5, 1, 1);
			   this->tableLayoutPanel2->Location = System::Drawing::Point(31, 11);
			   this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			   this->tableLayoutPanel2->RowCount = 4;
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.85549F)));
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.54335F)));
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.27746F)));
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.3237F)));
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			   this->tableLayoutPanel2->Size = System::Drawing::Size(344, 173);
			   this->tableLayoutPanel2->TabIndex = 17;
			   // 
			   // AltaProveidorUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->ClientSize = System::Drawing::Size(1062, 671);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Name = L"AltaProveidorUI";
			   this->Text = L"EduConnect";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->tableLayoutPanel3->ResumeLayout(false);
			   this->tableLayoutPanel2->ResumeLayout(false);
			   this->tableLayoutPanel2->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		     System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

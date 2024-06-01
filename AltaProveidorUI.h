#pragma once
#include "AltaProveidorService.h"
#include "AdministradorUI.h"
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
	public ref class AltaProveidorUI : public System::Windows::Forms::Form
	{
	public:
		AltaProveidorUI(void);
		Void NomUsuari_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		Void Email_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		Void textBoxPassword_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		bool IsValidEmail(String^ email);
		bool IsPasswordStrong(String^ password);

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
	private: bool password_visible1 = false;
	private: bool password_visible2 = false;
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
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;


	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::Windows::Forms::Label^ PageTitleLabel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;



	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// 
		   /// 
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
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->PageTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->button1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(80, 330);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(135, 35);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Confirma";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &AltaProveidorUI::button1_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox2->Location = System::Drawing::Point(50, 231);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(196, 27);
			   this->textBox2->TabIndex = 2;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox3->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox3->Location = System::Drawing::Point(50, 34);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(196, 27);
			   this->textBox3->TabIndex = 0;
			   // 
			   // textBox4
			   // 
			   this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox4->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox4->Location = System::Drawing::Point(50, 292);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(196, 27);
			   this->textBox4->TabIndex = 3;
			   // 
			   // textBox5
			   // 
			   this->textBox5->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox5->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox5->Location = System::Drawing::Point(50, 99);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->PasswordChar = '*';
			   this->textBox5->Size = System::Drawing::Size(196, 27);
			   this->textBox5->TabIndex = 1;
			   this->textBox5->UseSystemPasswordChar = true;
			   // 
			   // label2
			   // 
			   this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(46, 12);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(109, 19);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Nom d\'usuari";
			   // 
			   // label3
			   // 
			   this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(46, 77);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(105, 19);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Contrasenya";
			   // 
			   // label4
			   // 
			   this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(46, 209);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(50, 19);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Email";
			   // 
			   // label5
			   // 
			   this->label5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			   this->label5->AutoSize = true;
			   this->label5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(46, 270);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(45, 19);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"Nom";
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
			   this->tableLayoutPanel1->Controls->Add(this->PageTitleLabel, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.40782F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 71.88082F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.52514F)));
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
			   this->Cancelar_Button->Location = System::Drawing::Point(688, 480);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(88, 34);
			   this->Cancelar_Button->TabIndex = 18;
			   this->Cancelar_Button->Text = L"Tornar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &AltaProveidorUI::Cancelar_Button_Click);
			   // 
			   // PageTitleLabel
			   // 
			   this->PageTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->PageTitleLabel->AutoSize = true;
			   this->PageTitleLabel->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PageTitleLabel->Location = System::Drawing::Point(251, 19);
			   this->PageTitleLabel->Name = L"PageTitleLabel";
			   this->PageTitleLabel->Size = System::Drawing::Size(309, 33);
			   this->PageTitleLabel->TabIndex = 19;
			   this->PageTitleLabel->Text = L"Donar d\'Alta Proveïdor";
			   this->PageTitleLabel->Click += gcnew System::EventHandler(this, &AltaProveidorUI::PageTitleLabel_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel1->Controls->Add(this->pictureBox2);
			   this->panel1->Controls->Add(this->pictureBox1);
			   this->panel1->Controls->Add(this->textBox1);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->textBox4);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->label5);
			   this->panel1->Controls->Add(this->textBox5);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->textBox2);
			   this->panel1->Controls->Add(this->label4);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->textBox3);
			   this->panel1->Location = System::Drawing::Point(258, 75);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(296, 380);
			   this->panel1->TabIndex = 20;
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			   this->pictureBox1->Location = System::Drawing::Point(222, 99);
			   this->pictureBox1->MaximumSize = System::Drawing::Size(24, 24);
			   this->pictureBox1->MinimumSize = System::Drawing::Size(24, 24);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(24, 24);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 27;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Click += gcnew System::EventHandler(this, &AltaProveidorUI::pictureBox1_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->textBox1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->textBox1->Location = System::Drawing::Point(50, 167);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->PasswordChar = '*';
			   this->textBox1->Size = System::Drawing::Size(196, 27);
			   this->textBox1->TabIndex = 26;
			   this->textBox1->UseSystemPasswordChar = true;
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::SystemColors::Window;
			   this->pictureBox2->Location = System::Drawing::Point(222, 167);
			   this->pictureBox2->MaximumSize = System::Drawing::Size(24, 24);
			   this->pictureBox2->MinimumSize = System::Drawing::Size(24, 24);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(24, 24);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 25;
			   this->pictureBox2->TabStop = false;
			   this->pictureBox2->Click += gcnew System::EventHandler(this, &AltaProveidorUI::pictureBox2_Click);
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(46, 145);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(173, 19);
			   this->label1->TabIndex = 11;
			   this->label1->Text = L"Repeteix contrasenya";
			   // 
			   // AltaProveidorUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MinimumSize = System::Drawing::Size(814, 537);
			   this->Name = L"AltaProveidorUI";
			   this->Text = L"EduConnect";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	   Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
	   Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void PageTitleLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}

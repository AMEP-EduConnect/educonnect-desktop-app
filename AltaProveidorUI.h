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
		/// Limpiar los recursos que se estén usando.
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
		/// Variable del diseñador necesaria.
		/// </summary>

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;






		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
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
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(266, 266);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(135, 23);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Confirma";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &AltaProveidorUI::button1_Click);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(313, 186);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(135, 20);
			   this->textBox2->TabIndex = 2;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(313, 108);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(135, 20);
			   this->textBox3->TabIndex = 3;
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(313, 146);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(135, 20);
			   this->textBox4->TabIndex = 4;
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(313, 226);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(135, 20);
			   this->textBox5->TabIndex = 5;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(218, 112);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(89, 16);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Nom d\'usuari:";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(221, 150);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(86, 16);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"Contrasenya:";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(263, 190);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(44, 16);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Email:";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(217, 230);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(90, 16);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"Nom complet:";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(149, 25);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(80, 16);
			   this->label1->TabIndex = 12;
			   this->label1->Text = L"EduConnect";
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(146, 41);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(331, 31);
			   this->label6->TabIndex = 13;
			   this->label6->Text = L"Donar d\'Alta a Proveïdor";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->pictureBox1->Location = System::Drawing::Point(152, 89);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(358, 214);
			   this->pictureBox1->TabIndex = 11;
			   this->pictureBox1->TabStop = false;
			   // 
			   // AltaProveidorUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(654, 350);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->textBox5);
			   this->Controls->Add(this->textBox4);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->pictureBox1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Name = L"AltaProveidorUI";
			   this->Text = L"MyForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	








	};
}
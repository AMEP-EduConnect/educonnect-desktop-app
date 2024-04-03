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
	private: System::Windows::Forms::TextBox^ textBox1;
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(12, 300);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(111, 23);
			   this->button1->TabIndex = 0;
			   this->button1->Text = L"Alta proveidor";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &AltaProveidorUI::button1_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(131, 54);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 20);
			   this->textBox1->TabIndex = 1;

			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(240, 54);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(100, 20);
			   this->textBox2->TabIndex = 2;
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(346, 54);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(100, 20);
			   this->textBox3->TabIndex = 3;
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(118, 120);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(100, 20);
			   this->textBox4->TabIndex = 4;
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(240, 120);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(100, 20);
			   this->textBox5->TabIndex = 5;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(149, 77);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(35, 13);
			   this->label1->TabIndex = 6;
			   this->label1->Text = L"id";

			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(272, 77);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(35, 13);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"username";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(393, 77);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(35, 13);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"password";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(149, 143);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(35, 13);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"email";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(272, 143);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(35, 13);
			   this->label5->TabIndex = 10;
			   this->label5->Text = L"surname";
			   // 
			   // AltaProveidorUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(545, 335);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->textBox5);
			   this->Controls->Add(this->textBox4);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->button1);
			   this->Name = L"AltaProveidorUI";
			   this->Text = L"MyForm";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AltaProveidorUI_Load(System::Object^ sender, System::EventArgs^ e);




	};
}

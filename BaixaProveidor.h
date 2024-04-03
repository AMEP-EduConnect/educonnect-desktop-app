#pragma once
#include "BaixaProveidorService.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BaixaProveidorUI
	/// </summary>
	public ref class BaixaProveidorUI : public System::Windows::Forms::Form
	{
	public:
		BaixaProveidorUI(void)
		{
			InitializeComponent();
			//
			//TODO: Agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BaixaProveidorUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: BaixaProveidorService^ baixaProveidorService;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Baixa Proveidor";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 302);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// BaixaProveidorUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Name = L"BaixaProveidorUI";
			this->Text = L"Baixa Proveidor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Aquí se implementará la lógica para dar de baja un proveedor.
	}
	};
}

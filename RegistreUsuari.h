#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegistreUsuari
	/// </summary>
	public ref class RegistreUsuari : public System::Windows::Forms::Form
	{
	public:
		RegistreUsuari(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegistreUsuari()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(366, 39);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(275, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Registrat en EduConnect";
			this->label1->Click += gcnew System::EventHandler(this, &RegistreUsuari::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(268, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nom";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(270, 232);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Cognoms";
			this->label3->Click += gcnew System::EventHandler(this, &RegistreUsuari::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(268, 283);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Data Naixement";
			this->label4->Click += gcnew System::EventHandler(this, &RegistreUsuari::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(268, 341);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"DNI";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(268, 397);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"E-mail";
			this->label6->Click += gcnew System::EventHandler(this, &RegistreUsuari::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(268, 460);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(99, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Contrasenya";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(268, 122);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(79, 20);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Nickname";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(402, 116);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(197, 26);
			this->textBox1->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(402, 338);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(197, 26);
			this->textBox2->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(402, 397);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(197, 26);
			this->textBox3->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(402, 460);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(197, 26);
			this->textBox4->TabIndex = 11;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(402, 280);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(197, 26);
			this->textBox5->TabIndex = 12;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(402, 226);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(197, 26);
			this->textBox6->TabIndex = 13;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(402, 166);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(197, 26);
			this->textBox7->TabIndex = 14;
			// 
			// RegistreUsuari
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(917, 657);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"RegistreUsuari";
			this->Text = L"RegistreUsuari";
			this->Load += gcnew System::EventHandler(this, &RegistreUsuari::RegistreUsuari_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void RegistreUsuari_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

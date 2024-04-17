#pragma once
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainPageUI
	/// </summary>
	public ref class MainPageUI : public System::Windows::Forms::Form
	{
	public:
		MainPageUI(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainPageUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(789, 43);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Perfil personal";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainPageUI::Perfil_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(981, 43);
			this->button2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 50);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Tancar sessió";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainPageUI::Tancar_Sessio_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(685, 274);
			this->button3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(184, 50);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Crear Grup d\'estudi";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainPageUI::Crea_Grup_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(685, 345);
			this->button4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(184, 50);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Consultar Grup d\'estudi";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainPageUI::Consulta_Grup_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(685, 416);
			this->button5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(184, 50);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Gestiona Grup d\'estudi";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainPageUI::Gestiona_Grup_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(359, 274);
			this->button7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(184, 50);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Alta Proveidor";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainPageUI::Alta_Proveidor_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(359, 345);
			this->button8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(184, 50);
			this->button8->TabIndex = 8;
			this->button8->Text = L"Baixa Proveidor";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MainPageUI::Baixa_Proveidor_Click);
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-7, 683);
			this->Background_PictureBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(1237, 326);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 12;
			this->Background_PictureBox->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(435, 171);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(330, 42);
			this->label1->TabIndex = 13;
			this->label1->Text = L"TEST MAIN PAGE";
			this->label1->Click += gcnew System::EventHandler(this, &MainPageUI::label1_Click);
			// 
			// MainPageUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 809);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Background_PictureBox);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MainPageUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &MainPageUI::MainPageUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		System::Void MainPageUI_Load(System::Object^ sender, System::EventArgs^ e);

		System::Void Tancar_Sessio_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Perfil_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Consulta_Grup_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Gestiona_Grup_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Crea_Grup_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Alta_Proveidor_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Baixa_Proveidor_Click(System::Object^ sender, System::EventArgs^ e);

		
		//TESTING METHOD, DELETE LATER
		//System::Void testQuery();
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
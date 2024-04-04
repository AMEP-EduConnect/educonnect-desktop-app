#pragma once
#include "BaixaProveidorService.h"
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
	public ref class BaixaProveidorUI : public System::Windows::Forms::Form
	{
	public:
		BaixaProveidorUI(void){
			InitializeComponent();
			baixaProveidorService = gcnew BaixaProveidorService();
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~BaixaProveidorUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ BaixaProveidorButton;

	private: BaixaProveidorService^ baixaProveidorService;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


	private: System::Windows::Forms::TextBox^ BaixaProveidorTextBox;



	private: System::Windows::Forms::Label^ BaixaProveidorLabel;




	private: System::Windows::Forms::Label^ EduConnectLabel;
	private: System::Windows::Forms::Label^ PageTitleLabel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;






		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->BaixaProveidorButton = (gcnew System::Windows::Forms::Button());
			   this->BaixaProveidorTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->BaixaProveidorLabel = (gcnew System::Windows::Forms::Label());
			   this->EduConnectLabel = (gcnew System::Windows::Forms::Label());
			   this->PageTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // BaixaProveidorButton
			   // 
			   this->BaixaProveidorButton->Location = System::Drawing::Point(379, 256);
			   this->BaixaProveidorButton->Name = L"BaixaProveidorButton";
			   this->BaixaProveidorButton->Size = System::Drawing::Size(135, 23);
			   this->BaixaProveidorButton->TabIndex = 0;
			   this->BaixaProveidorButton->Text = L"Confirma";
			   this->BaixaProveidorButton->UseVisualStyleBackColor = true;
			   this->BaixaProveidorButton->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::BaixaProveidorButton_Click);
			   // 
			   // BaixaProveidorTextBox
			   // 
			   this->BaixaProveidorTextBox->Location = System::Drawing::Point(411, 198);
			   this->BaixaProveidorTextBox->Name = L"BaixaProveidorTextBox";
			   this->BaixaProveidorTextBox->Size = System::Drawing::Size(135, 20);
			   this->BaixaProveidorTextBox->TabIndex = 3;
			   // 
			   // BaixaProveidorLabel
			   // 
			   this->BaixaProveidorLabel->AutoSize = true;
			   this->BaixaProveidorLabel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->BaixaProveidorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->BaixaProveidorLabel->Location = System::Drawing::Point(318, 199);
			   this->BaixaProveidorLabel->Name = L"BaixaProveidorLabel";
			   this->BaixaProveidorLabel->Size = System::Drawing::Size(89, 16);
			   this->BaixaProveidorLabel->TabIndex = 7;
			   this->BaixaProveidorLabel->Text = L"Nom d\'usuari:";
			   // 
			   // EduConnectLabel
			   // 
			   this->EduConnectLabel->AutoSize = true;
			   this->EduConnectLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->EduConnectLabel->Location = System::Drawing::Point(267, 53);
			   this->EduConnectLabel->Name = L"EduConnectLabel";
			   this->EduConnectLabel->Size = System::Drawing::Size(80, 16);
			   this->EduConnectLabel->TabIndex = 12;
			   this->EduConnectLabel->Text = L"EduConnect";
			   // 
			   // PageTitleLabel
			   // 
			   this->PageTitleLabel->AutoSize = true;
			   this->PageTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PageTitleLabel->Location = System::Drawing::Point(264, 69);
			   this->PageTitleLabel->Name = L"PageTitleLabel";
			   this->PageTitleLabel->Size = System::Drawing::Size(346, 31);
			   this->PageTitleLabel->TabIndex = 13;
			   this->PageTitleLabel->Text = L"Donar de Baixa Proveïdor";
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->pictureBox1->Location = System::Drawing::Point(270, 117);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(358, 214);
			   this->pictureBox1->TabIndex = 11;
			   this->pictureBox1->TabStop = false;
			   // 
			   // button1
			   // 
			   this->button1->ForeColor = System::Drawing::Color::Red;
			   this->button1->Location = System::Drawing::Point(675, 368);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(91, 26);
			   this->button1->TabIndex = 14;
			   this->button1->Text = L"Cancelar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::button1_Click);
			   // 
			   // BaixaProveidorUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(917, 657);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->PageTitleLabel);
			   this->Controls->Add(this->EduConnectLabel);
			   this->Controls->Add(this->BaixaProveidorLabel);
			   this->Controls->Add(this->BaixaProveidorTextBox);
			   this->Controls->Add(this->BaixaProveidorButton);
			   this->Controls->Add(this->pictureBox1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Name = L"BaixaProveidorUI";
			   this->Text = L"MyForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e);









	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
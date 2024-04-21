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
			//this->Background_PictureBox->Image = Image::FromFile("background.png");
			this->Icon = gcnew System::Drawing::Icon("app.ico");
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





	private: System::Windows::Forms::Label^ PageTitleLabel;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;








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
			   this->PageTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // BaixaProveidorButton
			   // 
			   this->BaixaProveidorButton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorButton->Location = System::Drawing::Point(88, 141);
			   this->BaixaProveidorButton->Name = L"BaixaProveidorButton";
			   this->BaixaProveidorButton->Size = System::Drawing::Size(135, 34);
			   this->BaixaProveidorButton->TabIndex = 0;
			   this->BaixaProveidorButton->Text = L"Confirma";
			   this->BaixaProveidorButton->UseVisualStyleBackColor = true;
			   this->BaixaProveidorButton->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::BaixaProveidorButton_Click);
			   // 
			   // BaixaProveidorTextBox
			   // 
			   this->BaixaProveidorTextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorTextBox->Location = System::Drawing::Point(154, 58);
			   this->BaixaProveidorTextBox->Name = L"BaixaProveidorTextBox";
			   this->BaixaProveidorTextBox->Size = System::Drawing::Size(135, 27);
			   this->BaixaProveidorTextBox->TabIndex = 3;
			   // 
			   // BaixaProveidorLabel
			   // 
			   this->BaixaProveidorLabel->AutoSize = true;
			   this->BaixaProveidorLabel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->BaixaProveidorLabel->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorLabel->Location = System::Drawing::Point(24, 61);
			   this->BaixaProveidorLabel->Name = L"BaixaProveidorLabel";
			   this->BaixaProveidorLabel->Size = System::Drawing::Size(113, 19);
			   this->BaixaProveidorLabel->TabIndex = 7;
			   this->BaixaProveidorLabel->Text = L"Nom d\'usuari:";
			   // 
			   // PageTitleLabel
			   // 
			   this->PageTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->PageTitleLabel->AutoSize = true;
			   this->PageTitleLabel->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PageTitleLabel->Location = System::Drawing::Point(232, 23);
			   this->PageTitleLabel->Name = L"PageTitleLabel";
			   this->PageTitleLabel->Size = System::Drawing::Size(347, 33);
			   this->PageTitleLabel->TabIndex = 13;
			   this->PageTitleLabel->Text = L"Donar de Baixa Proveïdor";
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
			   this->tableLayoutPanel1->Controls->Add(this->PageTitleLabel, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 14;
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel1->Controls->Add(this->BaixaProveidorLabel);
			   this->panel1->Controls->Add(this->BaixaProveidorTextBox);
			   this->panel1->Controls->Add(this->BaixaProveidorButton);
			   this->panel1->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel1->Location = System::Drawing::Point(245, 140);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(321, 201);
			   this->panel1->TabIndex = 15;
			   // 
			   // BaixaProveidorUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MinimumSize = System::Drawing::Size(814, 537);
			   this->Name = L"BaixaProveidorUI";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"EduConnect";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GoBackButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
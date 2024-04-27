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
	private: System::Windows::Forms::Button^ Cancelar_Button;








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
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // BaixaProveidorButton
			   // 
			   this->BaixaProveidorButton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorButton->Location = System::Drawing::Point(358, 80);
			   this->BaixaProveidorButton->Name = L"BaixaProveidorButton";
			   this->BaixaProveidorButton->Size = System::Drawing::Size(91, 34);
			   this->BaixaProveidorButton->TabIndex = 0;
			   this->BaixaProveidorButton->Text = L"Confirma";
			   this->BaixaProveidorButton->UseVisualStyleBackColor = true;
			   this->BaixaProveidorButton->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::BaixaProveidorButton_Click);
			   // 
			   // BaixaProveidorTextBox
			   // 
			   this->BaixaProveidorTextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorTextBox->Location = System::Drawing::Point(129, 48);
			   this->BaixaProveidorTextBox->Name = L"BaixaProveidorTextBox";
			   this->BaixaProveidorTextBox->Size = System::Drawing::Size(208, 27);
			   this->BaixaProveidorTextBox->TabIndex = 3;
			   // 
			   // BaixaProveidorLabel
			   // 
			   this->BaixaProveidorLabel->AutoSize = true;
			   this->BaixaProveidorLabel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->BaixaProveidorLabel->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorLabel->Location = System::Drawing::Point(14, 51);
			   this->BaixaProveidorLabel->Name = L"BaixaProveidorLabel";
			   this->BaixaProveidorLabel->Size = System::Drawing::Size(109, 19);
			   this->BaixaProveidorLabel->TabIndex = 7;
			   this->BaixaProveidorLabel->Text = L"Nom d\'usuari";
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
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			   this->tableLayoutPanel1->Controls->Add(this->PageTitleLabel, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.12104F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.98138F)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 14;
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel1->Controls->Add(this->BaixaProveidorButton);
			   this->panel1->Controls->Add(this->BaixaProveidorLabel);
			   this->panel1->Controls->Add(this->BaixaProveidorTextBox);
			   this->panel1->ForeColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel1->Location = System::Drawing::Point(175, 163);
			   this->panel1->MinimumSize = System::Drawing::Size(461, 128);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(461, 128);
			   this->panel1->TabIndex = 15;
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(688, 439);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(88, 34);
			   this->Cancelar_Button->TabIndex = 15;
			   this->Cancelar_Button->Text = L"Cancelar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::Cancelar_Button_Click);
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
    private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
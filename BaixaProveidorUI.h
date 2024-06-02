#pragma once
#include "BaixaProveidorService.h"
#include "BaixaProveidorUI.h"
#include "MessageManager.h"
#include "MainPageUI.h"
#include "AdministradorUI.h"
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
		BaixaProveidorUI(void) {
			InitializeComponent();
			baixaProveidorService = gcnew BaixaProveidorService();
			this->Load += gcnew System::EventHandler(this, &BaixaProveidorUI::LoadProvidersList);
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



	private: BaixaProveidorService^ baixaProveidorService;
	protected:
	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>

	private: System::Windows::Forms::Label^ PageTitleLabel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ Cancelar_Button;

	private: System::Windows::Forms::Button^ BaixaProveidorButton;



	private: System::Windows::Forms::TextBox^ buscador_textBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ BaixaProveidorLabel;
	internal: System::Windows::Forms::ListBox^ Llista_Proveidors;
	private: System::Windows::Forms::Panel^ panel2;
	internal:
	private:

	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->PageTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->BaixaProveidorButton = (gcnew System::Windows::Forms::Button());
			   this->buscador_textBox = (gcnew System::Windows::Forms::TextBox());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->BaixaProveidorLabel = (gcnew System::Windows::Forms::Label());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->Llista_Proveidors = (gcnew System::Windows::Forms::ListBox());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // PageTitleLabel
			   // 
			   this->PageTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->PageTitleLabel->AutoSize = true;
			   this->PageTitleLabel->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PageTitleLabel->Location = System::Drawing::Point(252, 10);
			   this->PageTitleLabel->Name = L"PageTitleLabel";
			   this->PageTitleLabel->Size = System::Drawing::Size(308, 33);
			   this->PageTitleLabel->TabIndex = 13;
			   this->PageTitleLabel->Text = L"Donar Baixa Proveïdor";
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
			   this->tableLayoutPanel1->Controls->Add(this->BaixaProveidorButton, 1, 3);
			   this->tableLayoutPanel1->Controls->Add(this->PageTitleLabel, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->buscador_textBox, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 3);
			   this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 2);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 4;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.02041F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.26531F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75.625F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 14;
			   // 
			   // BaixaProveidorButton
			   // 
			   this->BaixaProveidorButton->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->BaixaProveidorButton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorButton->Location = System::Drawing::Point(556, 496);
			   this->BaixaProveidorButton->Name = L"BaixaProveidorButton";
			   this->BaixaProveidorButton->Size = System::Drawing::Size(91, 35);
			   this->BaixaProveidorButton->TabIndex = 0;
			   this->BaixaProveidorButton->Text = L"Confirma";
			   this->BaixaProveidorButton->UseVisualStyleBackColor = true;
			   this->BaixaProveidorButton->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::BaixaProveidorButton_Click);
			   // 
			   // buscador_textBox
			   // 
			   this->buscador_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->buscador_textBox->BackColor = System::Drawing::SystemColors::Window;
			   this->buscador_textBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->buscador_textBox->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			   this->buscador_textBox->Location = System::Drawing::Point(241, 73);
			   this->buscador_textBox->Margin = System::Windows::Forms::Padding(2);
			   this->buscador_textBox->Name = L"buscador_textBox";
			   this->buscador_textBox->Size = System::Drawing::Size(329, 27);
			   this->buscador_textBox->TabIndex = 22;
			   this->buscador_textBox->Text = L"Buscar Proveïdor...";
			   this->buscador_textBox->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::buscador_textBox_Click);
			   this->buscador_textBox->TextChanged += gcnew System::EventHandler(this, &BaixaProveidorUI::buscador_textBox_TextChanged);
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(688, 496);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(88, 35);
			   this->Cancelar_Button->TabIndex = 1;
			   this->Cancelar_Button->Text = L"Tornar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::Cancelar_Button_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->BaixaProveidorLabel);
			   this->panel1->Controls->Add(this->panel2);
			   this->panel1->Location = System::Drawing::Point(165, 122);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(482, 365);
			   this->panel1->TabIndex = 18;
			   // 
			   // BaixaProveidorLabel
			   // 
			   this->BaixaProveidorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->BaixaProveidorLabel->AutoSize = true;
			   this->BaixaProveidorLabel->BackColor = System::Drawing::SystemColors::Control;
			   this->BaixaProveidorLabel->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorLabel->Location = System::Drawing::Point(-1, 11);
			   this->BaixaProveidorLabel->Name = L"BaixaProveidorLabel";
			   this->BaixaProveidorLabel->Size = System::Drawing::Size(480, 19);
			   this->BaixaProveidorLabel->TabIndex = 7;
			   this->BaixaProveidorLabel->Text = L"Selecciona el proveïdor que vols donar de baixa en el sistema";
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel2->Controls->Add(this->Llista_Proveidors);
			   this->panel2->Location = System::Drawing::Point(6, 33);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(461, 309);
			   this->panel2->TabIndex = 23;
			   // 
			   // Llista_Proveidors
			   // 
			   this->Llista_Proveidors->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Llista_Proveidors->BackColor = System::Drawing::SystemColors::Window;
			   this->Llista_Proveidors->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->Llista_Proveidors->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Llista_Proveidors->FormattingEnabled = true;
			   this->Llista_Proveidors->IntegralHeight = false;
			   this->Llista_Proveidors->ItemHeight = 19;
			   this->Llista_Proveidors->Location = System::Drawing::Point(19, 20);
			   this->Llista_Proveidors->Name = L"Llista_Proveidors";
			   this->Llista_Proveidors->Size = System::Drawing::Size(422, 270);
			   this->Llista_Proveidors->TabIndex = 17;
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
			   this->panel2->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void LoadProvidersList(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e);

};
}
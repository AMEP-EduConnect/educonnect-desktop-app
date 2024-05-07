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
	private: System::Windows::Forms::ListBox^ Llista_Proveidors;
	private: System::Windows::Forms::Button^ BaixaProveidorButton;
	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::Label^ BaixaProveidorLabel;
	private: System::Windows::Forms::Label^ Pertany_Label;

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
			   this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			   this->BaixaProveidorButton = (gcnew System::Windows::Forms::Button());
			   this->BaixaProveidorLabel = (gcnew System::Windows::Forms::Label());
			   this->Pertany_Label = (gcnew System::Windows::Forms::Label());
			   this->Llista_Proveidors = (gcnew System::Windows::Forms::ListBox());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->Actual_Panel->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // PageTitleLabel
			   // 
			   this->PageTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->PageTitleLabel->AutoSize = true;
			   this->PageTitleLabel->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PageTitleLabel->Location = System::Drawing::Point(207, 23);
			   this->PageTitleLabel->Name = L"PageTitleLabel";
			   this->PageTitleLabel->Size = System::Drawing::Size(398, 33);
			   this->PageTitleLabel->TabIndex = 13;
			   this->PageTitleLabel->Text = L"Donar Baixa Prove\u00EFdor";
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
			   this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
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
			   // Actual_Panel
			   // 
			   this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Actual_Panel->Controls->Add(this->BaixaProveidorButton);
			   this->Actual_Panel->Controls->Add(this->BaixaProveidorLabel);
			   this->Actual_Panel->Controls->Add(this->Pertany_Label);
			   this->Actual_Panel->Controls->Add(this->Llista_Proveidors);
			   this->Actual_Panel->Location = System::Drawing::Point(168, 83);
			   this->Actual_Panel->Name = L"Actual_Panel";
			   this->Actual_Panel->Size = System::Drawing::Size(475, 288);
			   this->Actual_Panel->TabIndex = 17;
			   // 
			   // BaixaProveidorButton
			   // 
			   this->BaixaProveidorButton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorButton->Location = System::Drawing::Point(339, 238);
			   this->BaixaProveidorButton->Name = L"BaixaProveidorButton";
			   this->BaixaProveidorButton->Size = System::Drawing::Size(91, 35);
			   this->BaixaProveidorButton->TabIndex = 0;
			   this->BaixaProveidorButton->Text = L"Confirma";
			   this->BaixaProveidorButton->UseVisualStyleBackColor = true;
			   this->BaixaProveidorButton->Click += gcnew System::EventHandler(this, &BaixaProveidorUI::BaixaProveidorButton_Click);
			   // 
			   // BaixaProveidorLabel
			   // 
			   this->BaixaProveidorLabel->AutoSize = true;
			   this->BaixaProveidorLabel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->BaixaProveidorLabel->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BaixaProveidorLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorLabel->Location = System::Drawing::Point(39, 39);
			   this->BaixaProveidorLabel->Name = L"BaixaProveidorLabel";
			   this->BaixaProveidorLabel->Size = System::Drawing::Size(139, 19);
			   this->BaixaProveidorLabel->TabIndex = 7;
			   this->BaixaProveidorLabel->Text = L"Prove\u00EFdors";
			   // 
			   // Pertany_Label
			   // 
			   this->Pertany_Label->AutoSize = true;
			   this->Pertany_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Pertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Pertany_Label->Location = System::Drawing::Point(40, 29);
			   this->Pertany_Label->Name = L"Pertany_Label";
			   this->Pertany_Label->Size = System::Drawing::Size(0, 16);
			   this->Pertany_Label->TabIndex = 0;
			   // 
			   // Llista_Proveidors
			   // 
			   this->Llista_Proveidors->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Llista_Proveidors->BackColor = System::Drawing::Color::Lavender;
			   this->Llista_Proveidors->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->Llista_Proveidors->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Llista_Proveidors->FormattingEnabled = true;
			   this->Llista_Proveidors->IntegralHeight = false;
			   this->Llista_Proveidors->ItemHeight = 19;
			   this->Llista_Proveidors->Location = System::Drawing::Point(43, 66);
			   this->Llista_Proveidors->Name = L"Llista_Proveidors";
			   this->Llista_Proveidors->Size = System::Drawing::Size(387, 156);
			   this->Llista_Proveidors->TabIndex = 17;
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(688, 438);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(88, 35);
			   this->Cancelar_Button->TabIndex = 1;
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
			   this->Actual_Panel->ResumeLayout(false);
			   this->Actual_Panel->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void LoadProvidersList(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BaixaProveidorButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
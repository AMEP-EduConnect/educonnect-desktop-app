#pragma once
#include "Usuari.h"
#include "CurrentSession.h"
#include "MessageManager.h"
#include "ReportsService.h"
#include "IniciSessioService.h"
#include "Reports.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Reports_InfoUI
	/// </summary>
	public ref class Reports_InfoUI : public System::Windows::Forms::Form
	{
	public:
		Reports_InfoUI(Int64^ id_report);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Reports_InfoUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ReportsService^ reportService;
	private: IniciSessioService^ iniciSessioService;
	private: Int64^ report_id;
	private: System::Windows::Forms::Label^ NumReports_Label;

	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::ListBox^ Noms_ListBox;
	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::Windows::Forms::Label^ GrupDescription_Label;
	private: System::Windows::Forms::Button^ denega_button;
	private: System::Windows::Forms::Button^ acepta_button;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->NumReports_Label = (gcnew System::Windows::Forms::Label());
			   this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			   this->denega_button = (gcnew System::Windows::Forms::Button());
			   this->acepta_button = (gcnew System::Windows::Forms::Button());
			   this->GrupDescription_Label = (gcnew System::Windows::Forms::Label());
			   this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->Actual_Panel->SuspendLayout();
			   this->tableLayoutPanel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // NumReports_Label
			   // 
			   this->NumReports_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->NumReports_Label->AutoSize = true;
			   this->NumReports_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->NumReports_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->NumReports_Label->Location = System::Drawing::Point(380, 21);
			   this->NumReports_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->NumReports_Label->Name = L"NumReports_Label";
			   this->NumReports_Label->Size = System::Drawing::Size(324, 41);
			   this->NumReports_Label->TabIndex = 2;
			   this->NumReports_Label->Text = L"Report Numero #X";
			   this->NumReports_Label->Click += gcnew System::EventHandler(this, &Reports_InfoUI::ConsultarReports_Label_Click);
			   // 
			   // Actual_Panel
			   // 
			   this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Actual_Panel->Controls->Add(this->denega_button);
			   this->Actual_Panel->Controls->Add(this->acepta_button);
			   this->Actual_Panel->Controls->Add(this->GrupDescription_Label);
			   this->Actual_Panel->Controls->Add(this->Noms_ListBox);
			   this->Actual_Panel->Location = System::Drawing::Point(221, 122);
			   this->Actual_Panel->Margin = System::Windows::Forms::Padding(4);
			   this->Actual_Panel->Name = L"Actual_Panel";
			   this->Actual_Panel->Size = System::Drawing::Size(643, 342);
			   this->Actual_Panel->TabIndex = 6;
			   // 
			   // denega_button
			   // 
			   this->denega_button->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->denega_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->denega_button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->denega_button->ForeColor = System::Drawing::Color::DarkRed;
			   this->denega_button->Location = System::Drawing::Point(477, 285);
			   this->denega_button->Margin = System::Windows::Forms::Padding(5);
			   this->denega_button->Name = L"denega_button";
			   this->denega_button->Size = System::Drawing::Size(139, 43);
			   this->denega_button->TabIndex = 9;
			   this->denega_button->Text = L"Denega";
			   this->denega_button->UseVisualStyleBackColor = true;
			   this->denega_button->Visible = false;
			   this->denega_button->Click += gcnew System::EventHandler(this, &Reports_InfoUI::denega_button_Click);
			   // 
			   // acepta_button
			   // 
			   this->acepta_button->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->acepta_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->acepta_button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->acepta_button->ForeColor = System::Drawing::Color::Green;
			   this->acepta_button->Location = System::Drawing::Point(27, 285);
			   this->acepta_button->Margin = System::Windows::Forms::Padding(5);
			   this->acepta_button->Name = L"acepta_button";
			   this->acepta_button->Size = System::Drawing::Size(139, 43);
			   this->acepta_button->TabIndex = 9;
			   this->acepta_button->Text = L"Accepta";
			   this->acepta_button->UseVisualStyleBackColor = true;
			   this->acepta_button->Visible = false;
			   this->acepta_button->Click += gcnew System::EventHandler(this, &Reports_InfoUI::acepta_button_Click);
			   // 
			   // GrupDescription_Label
			   // 
			   this->GrupDescription_Label->AutoSize = true;
			   this->GrupDescription_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->GrupDescription_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->GrupDescription_Label->Location = System::Drawing::Point(23, 25);
			   this->GrupDescription_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->GrupDescription_Label->Name = L"GrupDescription_Label";
			   this->GrupDescription_Label->Size = System::Drawing::Size(70, 24);
			   this->GrupDescription_Label->TabIndex = 8;
			   this->GrupDescription_Label->Text = L"Motiu:";
			   // 
			   // Noms_ListBox
			   // 
			   this->Noms_ListBox->BackColor = System::Drawing::SystemColors::Window;
			   this->Noms_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->Noms_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Noms_ListBox->FormattingEnabled = true;
			   this->Noms_ListBox->IntegralHeight = false;
			   this->Noms_ListBox->ItemHeight = 23;
			   this->Noms_ListBox->Location = System::Drawing::Point(27, 53);
			   this->Noms_ListBox->Margin = System::Windows::Forms::Padding(4);
			   this->Noms_ListBox->Name = L"Noms_ListBox";
			   this->Noms_ListBox->Size = System::Drawing::Size(589, 210);
			   this->Noms_ListBox->TabIndex = 2;
			   this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Reports_InfoUI::Noms_ListBox_SelectedIndexChanged);
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->Cancelar_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(724, 512);
			   this->Cancelar_Button->Margin = System::Windows::Forms::Padding(5);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(139, 43);
			   this->Cancelar_Button->TabIndex = 9;
			   this->Cancelar_Button->Text = L"Tornar";
			   this->Cancelar_Button->UseVisualStyleBackColor = true;
			   this->Cancelar_Button->Visible = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &Reports_InfoUI::Cancelar_Button_Click);
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
			   this->tableLayoutPanel1->Controls->Add(this->NumReports_Label, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 1, 2);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 4;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.8F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 83.2F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 62)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 95)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1085, 661);
			   this->tableLayoutPanel1->TabIndex = 7;
			   this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Reports_InfoUI::tableLayoutPanel1_Paint);
			   // 
			   // Reports_InfoUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1085, 661);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Reports_InfoUI";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"EduConnect";
			   this->Load += gcnew System::EventHandler(this, &Reports_InfoUI::Reports_ConsultarUI_Load);
			   this->Actual_Panel->ResumeLayout(false);
			   this->Actual_Panel->PerformLayout();
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void Reports_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: void Reports_ConsultarUIreload();
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void acepta_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void denega_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ConsultarReports_Label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}


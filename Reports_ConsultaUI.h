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
	/// Resumen de Reports_ConsultaUI
	/// </summary>
	public ref class Reports_ConsultaUI : public System::Windows::Forms::Form
	{
	public:
		Reports_ConsultaUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Reports_ConsultaUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ReportsService^ reportService;
	private: IniciSessioService^ iniciSessioService;
	private: Int64^ reportId;
	private: System::Windows::Forms::Label^ ConsultarReports_Label;
	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::ListBox^ Noms_ListBox;
	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ MoreInfo_Button;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->ConsultarReports_Label = (gcnew System::Windows::Forms::Label());
			   this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			   this->MoreInfo_Button = (gcnew System::Windows::Forms::Button());
			   this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->Actual_Panel->SuspendLayout();
			   this->tableLayoutPanel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // ConsultarReports_Label
			   // 
			   this->ConsultarReports_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->ConsultarReports_Label->AutoSize = true;
			   this->ConsultarReports_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ConsultarReports_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->ConsultarReports_Label->Location = System::Drawing::Point(360, 25);
			   this->ConsultarReports_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->ConsultarReports_Label->Name = L"ConsultarReports_Label";
			   this->ConsultarReports_Label->Size = System::Drawing::Size(314, 41);
			   this->ConsultarReports_Label->TabIndex = 2;
			   this->ConsultarReports_Label->Text = L"Reports d\'Usuaris";
			   // 
			   // Actual_Panel
			   // 
			   this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Actual_Panel->Controls->Add(this->MoreInfo_Button);
			   this->Actual_Panel->Controls->Add(this->Noms_ListBox);
			   this->Actual_Panel->Location = System::Drawing::Point(146, 114);
			   this->Actual_Panel->Margin = System::Windows::Forms::Padding(4);
			   this->Actual_Panel->Name = L"Actual_Panel";
			   this->Actual_Panel->Size = System::Drawing::Size(743, 411);
			   this->Actual_Panel->TabIndex = 6;
			   // 
			   // MoreInfo_Button
			   // 
			   this->MoreInfo_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->MoreInfo_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->MoreInfo_Button->Location = System::Drawing::Point(27, 350);
			   this->MoreInfo_Button->Margin = System::Windows::Forms::Padding(5);
			   this->MoreInfo_Button->Name = L"MoreInfo_Button";
			   this->MoreInfo_Button->Size = System::Drawing::Size(139, 43);
			   this->MoreInfo_Button->TabIndex = 9;
			   this->MoreInfo_Button->Text = L"Veure";
			   this->MoreInfo_Button->UseVisualStyleBackColor = true;
			   this->MoreInfo_Button->Visible = false;
			   this->MoreInfo_Button->Click += gcnew System::EventHandler(this, &Reports_ConsultaUI::MoreInfo_Button_Click);
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
			   this->Noms_ListBox->Location = System::Drawing::Point(27, 40);
			   this->Noms_ListBox->Margin = System::Windows::Forms::Padding(4);
			   this->Noms_ListBox->Name = L"Noms_ListBox";
			   this->Noms_ListBox->Size = System::Drawing::Size(693, 285);
			   this->Noms_ListBox->TabIndex = 2;
			   this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Reports_ConsultaUI::Noms_ListBox_SelectedIndexChanged);
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 3;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   13.08756F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   69.21659F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   17.69585F)));
			   this->tableLayoutPanel1->Controls->Add(this->ConsultarReports_Label, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 1, 2);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 4;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.8F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 83.2F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 33)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(1085, 661);
			   this->tableLayoutPanel1->TabIndex = 7;
			   this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Reports_ConsultaUI::tableLayoutPanel1_Paint);
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->Cancelar_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(749, 565);
			   this->Cancelar_Button->Margin = System::Windows::Forms::Padding(5);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(139, 43);
			   this->Cancelar_Button->TabIndex = 10;
			   this->Cancelar_Button->Text = L"Tornar";
			   this->Cancelar_Button->UseVisualStyleBackColor = true;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &Reports_ConsultaUI::Cancelar_Button_Click);
			   // 
			   // Reports_ConsultaUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1085, 661);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Reports_ConsultaUI";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"EduConnect";
			   this->Load += gcnew System::EventHandler(this, &Reports_ConsultaUI::Reports_ConsultarUI_Load);
			   this->Actual_Panel->ResumeLayout(false);
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
	private: System::Void MoreInfo_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

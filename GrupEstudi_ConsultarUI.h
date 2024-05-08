#pragma once
#include "GrupEstudiService.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembership.h"
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "Usuari.h"
#include "CurrentSession.h"
#include "GrupEstudi_EditarUI.h"
#include "MessageManager.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_ConsultarUI
	/// </summary>
	public ref class GrupEstudi_ConsultarUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_ConsultarUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~GrupEstudi_ConsultarUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ ConsultarGrupEstudi_Label;
	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::ListBox^ Noms_ListBox;
	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: System::Windows::Forms::Button^ abandonar_button;
	private: System::Windows::Forms::Button^ crearGrup_button;
	private: System::Windows::Forms::Button^ MoreInfo_GrupEstudi_Button;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ newGrup_button;
	private: GrupEstudiService^ grupEstudiService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ConsultarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			this->newGrup_button = (gcnew System::Windows::Forms::Button());
			this->abandonar_button = (gcnew System::Windows::Forms::Button());
			this->MoreInfo_GrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->Actual_Panel->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ConsultarGrupEstudi_Label
			// 
			this->ConsultarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsultarGrupEstudi_Label->AutoSize = true;
			this->ConsultarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConsultarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->ConsultarGrupEstudi_Label->Location = System::Drawing::Point(242, 25);
			this->ConsultarGrupEstudi_Label->Name = L"ConsultarGrupEstudi_Label";
			this->ConsultarGrupEstudi_Label->Size = System::Drawing::Size(328, 33);
			this->ConsultarGrupEstudi_Label->TabIndex = 2;
			this->ConsultarGrupEstudi_Label->Text = L"Els meus grups d\'Estudi";
			// 
			// Actual_Panel
			// 
			this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Actual_Panel->Controls->Add(this->newGrup_button);
			this->Actual_Panel->Controls->Add(this->abandonar_button);
			this->Actual_Panel->Controls->Add(this->MoreInfo_GrupEstudi_Button);
			this->Actual_Panel->Controls->Add(this->Noms_ListBox);
			this->Actual_Panel->Location = System::Drawing::Point(165, 121);
			this->Actual_Panel->Name = L"Actual_Panel";
			this->Actual_Panel->Size = System::Drawing::Size(482, 342);
			this->Actual_Panel->TabIndex = 6;
			// 
			// newGrup_button
			// 
			this->newGrup_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->newGrup_button->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			this->newGrup_button->Location = System::Drawing::Point(334, 18);
			this->newGrup_button->Name = L"newGrup_button";
			this->newGrup_button->Size = System::Drawing::Size(128, 39);
			this->newGrup_button->TabIndex = 11;
			this->newGrup_button->Text = L"Nou grup";
			this->newGrup_button->UseVisualStyleBackColor = true;
			this->newGrup_button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::CrearGrupEstudi_Click);
			// 
			// abandonar_button
			// 
			this->abandonar_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->abandonar_button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->abandonar_button->Location = System::Drawing::Point(358, 284);
			this->abandonar_button->Margin = System::Windows::Forms::Padding(4);
			this->abandonar_button->Name = L"abandonar_button";
			this->abandonar_button->Size = System::Drawing::Size(104, 35);
			this->abandonar_button->TabIndex = 10;
			this->abandonar_button->Text = L"Abandonar";
			this->abandonar_button->UseVisualStyleBackColor = true;
			this->abandonar_button->Visible = false;
			this->abandonar_button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::abandonar_button_Click);
			// 
			// MoreInfo_GrupEstudi_Button
			// 
			this->MoreInfo_GrupEstudi_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MoreInfo_GrupEstudi_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MoreInfo_GrupEstudi_Button->Location = System::Drawing::Point(20, 284);
			this->MoreInfo_GrupEstudi_Button->Margin = System::Windows::Forms::Padding(4);
			this->MoreInfo_GrupEstudi_Button->Name = L"MoreInfo_GrupEstudi_Button";
			this->MoreInfo_GrupEstudi_Button->Size = System::Drawing::Size(104, 35);
			this->MoreInfo_GrupEstudi_Button->TabIndex = 9;
			this->MoreInfo_GrupEstudi_Button->Text = L"Veure";
			this->MoreInfo_GrupEstudi_Button->UseVisualStyleBackColor = true;
			this->MoreInfo_GrupEstudi_Button->Visible = false;
			this->MoreInfo_GrupEstudi_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::MoreInfo_GrupEstudi_Button_Click);
			// 
			// Noms_ListBox
			// 
			this->Noms_ListBox->BackColor = System::Drawing::SystemColors::Window;
			this->Noms_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Noms_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Noms_ListBox->FormattingEnabled = true;
			this->Noms_ListBox->IntegralHeight = false;
			this->Noms_ListBox->ItemHeight = 19;
			this->Noms_ListBox->Location = System::Drawing::Point(20, 76);
			this->Noms_ListBox->Name = L"Noms_ListBox";
			this->Noms_ListBox->Size = System::Drawing::Size(442, 171);
			this->Noms_ListBox->TabIndex = 2;
			this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::Noms_ListBox_SelectedIndexChanged);
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
			this->tableLayoutPanel1->Controls->Add(this->ConsultarGrupEstudi_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.8F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 83.2F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 7;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_ConsultarUI::tableLayoutPanel1_Paint);
			// 
			// GrupEstudi_ConsultarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GrupEstudi_ConsultarUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load);
			this->Actual_Panel->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void abandonar_button_Click(System::Object^ sender, System::EventArgs^ e);
private: void GrupEstudi_ConsultarUIreload();
private: System::Void CrearGrupEstudi_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MoreInfo_GrupEstudi_Button_Click(System::Object^ sender, System::EventArgs^ e);
};
}

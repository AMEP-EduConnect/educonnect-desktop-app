#pragma once
#include "GrupEstudi.h"
#include "GrupEstudiService.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_InfoUI
	/// </summary>
	public ref class GrupEstudi_InfoUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_InfoUI(String^ CurrentGrup);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudi_InfoUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ InfoGrupEstudi_Label;
	private: System::Windows::Forms::Label^ DescGrupEstudi_Label;
	private: System::Windows::Forms::Label^ SessionsList_Label;
	private: System::Windows::Forms::ListBox^ Sessions_ListBox;
	private: System::Windows::Forms::Button^ ModifySession_Button;


	private: System::Windows::Forms::Label^ AcademicTagsInfo_Label;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ EspaiName_Label;
	private: System::Windows::Forms::Label^ DayMonthYear_label;
	private: System::Windows::Forms::Label^ SessionCapacity_Label1;

	private: System::Windows::Forms::Label^ EspaiCapacity_Label;
	private: System::Windows::Forms::Label^ StartEndDuration_Label;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ ConfirmAttent_Button;
	private: System::Windows::Forms::Button^ CancelAttend_Button;
	private: System::Windows::Forms::Button^ NewSession_Button;
	private: System::Windows::Forms::Button^ DeleteSession_Button;



	private: System::Windows::Forms::Button^ ViewSessionAttendants_Button;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ MembersGrupEstudi_Button;
	private: System::Windows::Forms::Button^ ModifyGrupEstudi_Button;
	private: System::Windows::Forms::Button^ DeleteGrupEstudi_Button;
	private: System::Windows::Forms::Button^ GoBack_Button;










	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		GrupEstudi^ CurrentGrupEntity;
		GrupEstudiService^ grupEstudiService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ConfirmAttent_Button = (gcnew System::Windows::Forms::Button());
			this->CancelAttend_Button = (gcnew System::Windows::Forms::Button());
			this->DeleteSession_Button = (gcnew System::Windows::Forms::Button());
			this->ModifySession_Button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->DescGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->AcademicTagsInfo_Label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ViewSessionAttendants_Button = (gcnew System::Windows::Forms::Button());
			this->SessionCapacity_Label1 = (gcnew System::Windows::Forms::Label());
			this->EspaiCapacity_Label = (gcnew System::Windows::Forms::Label());
			this->StartEndDuration_Label = (gcnew System::Windows::Forms::Label());
			this->DayMonthYear_label = (gcnew System::Windows::Forms::Label());
			this->EspaiName_Label = (gcnew System::Windows::Forms::Label());
			this->NewSession_Button = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->MembersGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->ModifyGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->DeleteGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->Sessions_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->SessionsList_Label = (gcnew System::Windows::Forms::Label());
			this->InfoGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			tableLayoutPanel1->ColumnCount = 3;
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 37.73585F)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 62.26415F)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 310)));
			tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 6);
			tableLayoutPanel1->Controls->Add(this->label1, 1, 4);
			tableLayoutPanel1->Controls->Add(this->DescGrupEstudi_Label, 1, 3);
			tableLayoutPanel1->Controls->Add(this->AcademicTagsInfo_Label, 1, 2);
			tableLayoutPanel1->Controls->Add(this->panel1, 1, 5);
			tableLayoutPanel1->Controls->Add(this->NewSession_Button, 0, 6);
			tableLayoutPanel1->Controls->Add(this->panel2, 2, 1);
			tableLayoutPanel1->Controls->Add(this->Sessions_ListBox, 0, 5);
			tableLayoutPanel1->Controls->Add(this->SessionsList_Label, 0, 4);
			tableLayoutPanel1->Controls->Add(this->InfoGrupEstudi_Label, 1, 1);
			tableLayoutPanel1->Controls->Add(this->GoBack_Button, 2, 6);
			tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			tableLayoutPanel1->Name = L"tableLayoutPanel1";
			tableLayoutPanel1->RowCount = 8;
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 78.18182F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.81818F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 66)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 218)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 100)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			tableLayoutPanel1->Size = System::Drawing::Size(1085, 661);
			tableLayoutPanel1->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->ConfirmAttent_Button);
			this->flowLayoutPanel1->Controls->Add(this->CancelAttend_Button);
			this->flowLayoutPanel1->Controls->Add(this->DeleteSession_Button);
			this->flowLayoutPanel1->Controls->Add(this->ModifySession_Button);
			this->flowLayoutPanel1->Location = System::Drawing::Point(296, 509);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(474, 92);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// ConfirmAttent_Button
			// 
			this->ConfirmAttent_Button->Location = System::Drawing::Point(4, 4);
			this->ConfirmAttent_Button->Margin = System::Windows::Forms::Padding(4);
			this->ConfirmAttent_Button->Name = L"ConfirmAttent_Button";
			this->ConfirmAttent_Button->Size = System::Drawing::Size(100, 28);
			this->ConfirmAttent_Button->TabIndex = 0;
			this->ConfirmAttent_Button->Text = L"Asistir";
			this->ConfirmAttent_Button->UseVisualStyleBackColor = true;
			// 
			// CancelAttend_Button
			// 
			this->CancelAttend_Button->Location = System::Drawing::Point(112, 4);
			this->CancelAttend_Button->Margin = System::Windows::Forms::Padding(4);
			this->CancelAttend_Button->Name = L"CancelAttend_Button";
			this->CancelAttend_Button->Size = System::Drawing::Size(193, 28);
			this->CancelAttend_Button->TabIndex = 1;
			this->CancelAttend_Button->Text = L"Cancel·lar assistencia";
			this->CancelAttend_Button->UseVisualStyleBackColor = true;
			this->CancelAttend_Button->Visible = false;
			// 
			// DeleteSession_Button
			// 
			this->DeleteSession_Button->Location = System::Drawing::Point(313, 4);
			this->DeleteSession_Button->Margin = System::Windows::Forms::Padding(4);
			this->DeleteSession_Button->Name = L"DeleteSession_Button";
			this->DeleteSession_Button->Size = System::Drawing::Size(100, 28);
			this->DeleteSession_Button->TabIndex = 8;
			this->DeleteSession_Button->Text = L"El·liminar";
			this->DeleteSession_Button->UseVisualStyleBackColor = true;
			this->DeleteSession_Button->Visible = false;
			// 
			// ModifySession_Button
			// 
			this->ModifySession_Button->Location = System::Drawing::Point(4, 40);
			this->ModifySession_Button->Margin = System::Windows::Forms::Padding(4);
			this->ModifySession_Button->Name = L"ModifySession_Button";
			this->ModifySession_Button->Size = System::Drawing::Size(172, 28);
			this->ModifySession_Button->TabIndex = 7;
			this->ModifySession_Button->Text = L"Modificar";
			this->ModifySession_Button->UseVisualStyleBackColor = true;
			this->ModifySession_Button->Visible = false;
			this->ModifySession_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(296, 248);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"...";
			this->label1->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label1_Click);
			// 
			// DescGrupEstudi_Label
			// 
			this->DescGrupEstudi_Label->AutoSize = true;
			this->DescGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DescGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->DescGrupEstudi_Label->Location = System::Drawing::Point(296, 182);
			this->DescGrupEstudi_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DescGrupEstudi_Label->Name = L"DescGrupEstudi_Label";
			this->DescGrupEstudi_Label->Size = System::Drawing::Size(21, 20);
			this->DescGrupEstudi_Label->TabIndex = 4;
			this->DescGrupEstudi_Label->Text = L"...";
			// 
			// AcademicTagsInfo_Label
			// 
			this->AcademicTagsInfo_Label->AutoSize = true;
			this->AcademicTagsInfo_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AcademicTagsInfo_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AcademicTagsInfo_Label->Location = System::Drawing::Point(296, 148);
			this->AcademicTagsInfo_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AcademicTagsInfo_Label->Name = L"AcademicTagsInfo_Label";
			this->AcademicTagsInfo_Label->Size = System::Drawing::Size(24, 20);
			this->AcademicTagsInfo_Label->TabIndex = 9;
			this->AcademicTagsInfo_Label->Text = L"...";
			this->AcademicTagsInfo_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::AcademicTagsInfo_Label_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->ViewSessionAttendants_Button);
			this->panel1->Controls->Add(this->SessionCapacity_Label1);
			this->panel1->Controls->Add(this->EspaiCapacity_Label);
			this->panel1->Controls->Add(this->StartEndDuration_Label);
			this->panel1->Controls->Add(this->DayMonthYear_label);
			this->panel1->Controls->Add(this->EspaiName_Label);
			this->panel1->Location = System::Drawing::Point(296, 291);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(474, 210);
			this->panel1->TabIndex = 10;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_InfoUI::panel1_Paint);
			// 
			// ViewSessionAttendants_Button
			// 
			this->ViewSessionAttendants_Button->Location = System::Drawing::Point(29, 130);
			this->ViewSessionAttendants_Button->Margin = System::Windows::Forms::Padding(4);
			this->ViewSessionAttendants_Button->Name = L"ViewSessionAttendants_Button";
			this->ViewSessionAttendants_Button->Size = System::Drawing::Size(188, 28);
			this->ViewSessionAttendants_Button->TabIndex = 5;
			this->ViewSessionAttendants_Button->Text = L"Consultar asistents";
			this->ViewSessionAttendants_Button->UseVisualStyleBackColor = true;
			this->ViewSessionAttendants_Button->Visible = false;
			this->ViewSessionAttendants_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::button1_Click_1);
			// 
			// SessionCapacity_Label1
			// 
			this->SessionCapacity_Label1->AutoSize = true;
			this->SessionCapacity_Label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SessionCapacity_Label1->Location = System::Drawing::Point(309, 137);
			this->SessionCapacity_Label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SessionCapacity_Label1->Name = L"SessionCapacity_Label1";
			this->SessionCapacity_Label1->Size = System::Drawing::Size(76, 17);
			this->SessionCapacity_Label1->TabIndex = 4;
			this->SessionCapacity_Label1->Text = L"Capacitat";
			this->SessionCapacity_Label1->Visible = false;
			// 
			// EspaiCapacity_Label
			// 
			this->EspaiCapacity_Label->AutoSize = true;
			this->EspaiCapacity_Label->Location = System::Drawing::Point(399, 137);
			this->EspaiCapacity_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EspaiCapacity_Label->Name = L"EspaiCapacity_Label";
			this->EspaiCapacity_Label->Size = System::Drawing::Size(39, 16);
			this->EspaiCapacity_Label->TabIndex = 3;
			this->EspaiCapacity_Label->Text = L"18/25";
			// 
			// StartEndDuration_Label
			// 
			this->StartEndDuration_Label->AutoSize = true;
			this->StartEndDuration_Label->Location = System::Drawing::Point(25, 89);
			this->StartEndDuration_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->StartEndDuration_Label->Name = L"StartEndDuration_Label";
			this->StartEndDuration_Label->Size = System::Drawing::Size(79, 16);
			this->StartEndDuration_Label->TabIndex = 2;
			this->StartEndDuration_Label->Text = L"18:00 - 19:00";
			// 
			// DayMonthYear_label
			// 
			this->DayMonthYear_label->AutoSize = true;
			this->DayMonthYear_label->Location = System::Drawing::Point(25, 55);
			this->DayMonthYear_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->DayMonthYear_label->Name = L"DayMonthYear_label";
			this->DayMonthYear_label->Size = System::Drawing::Size(79, 16);
			this->DayMonthYear_label->TabIndex = 1;
			this->DayMonthYear_label->Text = L"18 juny 2024";
			this->DayMonthYear_label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label2_Click_1);
			// 
			// EspaiName_Label
			// 
			this->EspaiName_Label->AutoSize = true;
			this->EspaiName_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EspaiName_Label->Location = System::Drawing::Point(25, 21);
			this->EspaiName_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EspaiName_Label->Name = L"EspaiName_Label";
			this->EspaiName_Label->Size = System::Drawing::Size(206, 17);
			this->EspaiName_Label->TabIndex = 0;
			this->EspaiName_Label->Text = L"Biblioteca vilanova - Sala 1";
			this->EspaiName_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label2_Click);
			// 
			// NewSession_Button
			// 
			this->NewSession_Button->Location = System::Drawing::Point(4, 509);
			this->NewSession_Button->Margin = System::Windows::Forms::Padding(4);
			this->NewSession_Button->Name = L"NewSession_Button";
			this->NewSession_Button->Size = System::Drawing::Size(267, 28);
			this->NewSession_Button->TabIndex = 11;
			this->NewSession_Button->Text = L"Nova sessió";
			this->NewSession_Button->UseVisualStyleBackColor = true;
			this->NewSession_Button->Visible = false;
			this->NewSession_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::NewSession_Button_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->MembersGrupEstudi_Button);
			this->panel2->Controls->Add(this->ModifyGrupEstudi_Button);
			this->panel2->Controls->Add(this->DeleteGrupEstudi_Button);
			this->panel2->Location = System::Drawing::Point(778, 29);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(299, 115);
			this->panel2->TabIndex = 15;
			// 
			// MembersGrupEstudi_Button
			// 
			this->MembersGrupEstudi_Button->Location = System::Drawing::Point(35, 15);
			this->MembersGrupEstudi_Button->Margin = System::Windows::Forms::Padding(4);
			this->MembersGrupEstudi_Button->Name = L"MembersGrupEstudi_Button";
			this->MembersGrupEstudi_Button->Size = System::Drawing::Size(235, 28);
			this->MembersGrupEstudi_Button->TabIndex = 14;
			this->MembersGrupEstudi_Button->Text = L"Consultar membres";
			this->MembersGrupEstudi_Button->UseVisualStyleBackColor = true;
			// 
			// ModifyGrupEstudi_Button
			// 
			this->ModifyGrupEstudi_Button->Location = System::Drawing::Point(35, 49);
			this->ModifyGrupEstudi_Button->Margin = System::Windows::Forms::Padding(4);
			this->ModifyGrupEstudi_Button->Name = L"ModifyGrupEstudi_Button";
			this->ModifyGrupEstudi_Button->Size = System::Drawing::Size(235, 28);
			this->ModifyGrupEstudi_Button->TabIndex = 12;
			this->ModifyGrupEstudi_Button->Text = L"Editar grup";
			this->ModifyGrupEstudi_Button->UseVisualStyleBackColor = true;
			this->ModifyGrupEstudi_Button->Visible = false;
			// 
			// DeleteGrupEstudi_Button
			// 
			this->DeleteGrupEstudi_Button->Location = System::Drawing::Point(35, 82);
			this->DeleteGrupEstudi_Button->Margin = System::Windows::Forms::Padding(4);
			this->DeleteGrupEstudi_Button->Name = L"DeleteGrupEstudi_Button";
			this->DeleteGrupEstudi_Button->Size = System::Drawing::Size(235, 28);
			this->DeleteGrupEstudi_Button->TabIndex = 13;
			this->DeleteGrupEstudi_Button->Text = L"El·liminar grup";
			this->DeleteGrupEstudi_Button->UseVisualStyleBackColor = true;
			this->DeleteGrupEstudi_Button->Visible = false;
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GoBack_Button->Location = System::Drawing::Point(879, 541);
			this->GoBack_Button->Margin = System::Windows::Forms::Padding(4);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(100, 28);
			this->GoBack_Button->TabIndex = 16;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::GoBack_Button_Click);
			// 
			// Sessions_ListBox
			// 
			this->Sessions_ListBox->BackColor = System::Drawing::Color::Lavender;
			this->Sessions_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sessions_ListBox->FormattingEnabled = true;
			this->Sessions_ListBox->IntegralHeight = false;
			this->Sessions_ListBox->ItemHeight = 16;
			this->Sessions_ListBox->Location = System::Drawing::Point(4, 291);
			this->Sessions_ListBox->Margin = System::Windows::Forms::Padding(4);
			this->Sessions_ListBox->Name = L"Sessions_ListBox";
			this->Sessions_ListBox->Size = System::Drawing::Size(266, 210);
			this->Sessions_ListBox->TabIndex = 6;
			this->Sessions_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::Sessions_ListBox_SelectedIndexChanged);
			// 
			// SessionsList_Label
			// 
			this->SessionsList_Label->AutoSize = true;
			this->SessionsList_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SessionsList_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->SessionsList_Label->Location = System::Drawing::Point(4, 248);
			this->SessionsList_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->SessionsList_Label->Name = L"SessionsList_Label";
			this->SessionsList_Label->Size = System::Drawing::Size(159, 20);
			this->SessionsList_Label->TabIndex = 5;
			this->SessionsList_Label->Text = L"Sessions actuals:";
			this->SessionsList_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::SessionsList_Label_Click_1);
			// 
			// InfoGrupEstudi_Label
			// 
			this->InfoGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InfoGrupEstudi_Label->AutoSize = true;
			this->InfoGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->InfoGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->InfoGrupEstudi_Label->Location = System::Drawing::Point(509, 67);
			this->InfoGrupEstudi_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->InfoGrupEstudi_Label->Name = L"InfoGrupEstudi_Label";
			this->InfoGrupEstudi_Label->Size = System::Drawing::Size(47, 39);
			this->InfoGrupEstudi_Label->TabIndex = 3;
			this->InfoGrupEstudi_Label->Text = L"...";
			this->InfoGrupEstudi_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::InfoGrupEstudi_Label_Click);
			// 
			// GrupEstudi_InfoUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 661);
			this->Controls->Add(tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GrupEstudi_InfoUI";
			this->Text = L"GrupEstudi_InfoUI";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::GrupEstudi_InfoUI_Load);
			tableLayoutPanel1->ResumeLayout(false);
			tableLayoutPanel1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void SessionsList_Label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void DescGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SessionsList_Label_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Sessions_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AcademicTagsInfo_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GrupEstudi_InfoUI_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void SelectLastSessionOrPlaceholder();
private: System::Void ActivateButtonsIfOwner();
private: System::Void InfoGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void NewSession_Button_Click(System::Object^ sender, System::EventArgs^ e);
};
}

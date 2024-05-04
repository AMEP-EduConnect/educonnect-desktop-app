#pragma once
#include "GrupEstudi.h"
#include "GrupEstudiService.h"
#include "SessionService.h"
#include "GrupSessionAttendantsService.h"

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
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~GrupEstudi_InfoUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ InfoGrupEstudi_Label;

	private: System::Windows::Forms::Label^ SessionsList_Label;
	private: System::Windows::Forms::ListBox^ Sessions_ListBox;
	private: System::Windows::Forms::Button^ ModifySession_Button;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ EspaiName_Label;
	private: System::Windows::Forms::Label^ DayMonthYear_label;
	private: System::Windows::Forms::Label^ SessionCapacity_Label1;

	private: System::Windows::Forms::Label^ EspaiCapacity_Label;
	private: System::Windows::Forms::Label^ StartEndDuration_Label;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ Confirm_Cancel_Attent_Button;


	private: System::Windows::Forms::Button^ NewSession_Button;
	private: System::Windows::Forms::Button^ DeleteSession_Button;



	private: System::Windows::Forms::Button^ ViewSessionAttendants_Button;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ MembersGrupEstudi_Button;
	private: System::Windows::Forms::Button^ ModifyGrupEstudi_Button;
	private: System::Windows::Forms::Button^ DeleteGrupEstudi_Button;
	private: System::Windows::Forms::Button^ GoBack_Button;
	private: List<Session^>^ SessionsList;







	protected:

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		GrupEstudi^ CurrentGrupEntity;

	private: System::Windows::Forms::Label^ AcademicTagsInfo_Label;

	private: System::Windows::Forms::Label^ DescGrupEstudi_Label;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ Chat_Button;



	private: GrupEstudiService^ grupEstudiService;
	private: GrupSessionAttendantsService^ grupSessionAttendantsService;
	private: SessionService^ sessionService;
	private: System::Windows::Forms::Label^ capacity;
	private: System::Windows::Forms::Label^ session_name;

	private: Session^ CurrentSessionEntity;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AcademicTagsInfo_Label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DescGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->DeleteGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->MembersGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->ModifyGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->InfoGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ModifySession_Button = (gcnew System::Windows::Forms::Button());
			this->DeleteSession_Button = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->capacity = (gcnew System::Windows::Forms::Label());
			this->Confirm_Cancel_Attent_Button = (gcnew System::Windows::Forms::Button());
			this->ViewSessionAttendants_Button = (gcnew System::Windows::Forms::Button());
			this->SessionCapacity_Label1 = (gcnew System::Windows::Forms::Label());
			this->EspaiCapacity_Label = (gcnew System::Windows::Forms::Label());
			this->StartEndDuration_Label = (gcnew System::Windows::Forms::Label());
			this->DayMonthYear_label = (gcnew System::Windows::Forms::Label());
			this->EspaiName_Label = (gcnew System::Windows::Forms::Label());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->SessionsList_Label = (gcnew System::Windows::Forms::Label());
			this->Sessions_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->NewSession_Button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Chat_Button = (gcnew System::Windows::Forms::Button());
			this->session_name = (gcnew System::Windows::Forms::Label());
			tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			tableLayoutPanel1->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			tableLayoutPanel1->ColumnCount = 3;
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 27.18447F)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 48.54369F)));
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 24.27184F)));
			tableLayoutPanel1->Controls->Add(this->panel6, 1, 1);
			tableLayoutPanel1->Controls->Add(this->panel2, 2, 1);
			tableLayoutPanel1->Controls->Add(this->InfoGrupEstudi_Label, 1, 0);
			tableLayoutPanel1->Controls->Add(this->panel5, 1, 2);
			tableLayoutPanel1->Controls->Add(this->GoBack_Button, 2, 3);
			tableLayoutPanel1->Controls->Add(this->panel4, 0, 2);
			tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 2, 2);
			tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			tableLayoutPanel1->MinimumSize = System::Drawing::Size(814, 537);
			tableLayoutPanel1->Name = L"tableLayoutPanel1";
			tableLayoutPanel1->RowCount = 4;
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.05587F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 28.86406F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.76909F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.090909F)));
			tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			tableLayoutPanel1->TabIndex = 0;
			// 
			// panel6
			// 
			this->panel6->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->panel6->Controls->Add(this->label1);
			this->panel6->Controls->Add(this->AcademicTagsInfo_Label);
			this->panel6->Controls->Add(this->label2);
			this->panel6->Controls->Add(this->DescGrupEstudi_Label);
			this->panel6->Location = System::Drawing::Point(224, 57);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(389, 147);
			this->panel6->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(3, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 19);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Etiquetes";
			// 
			// AcademicTagsInfo_Label
			// 
			this->AcademicTagsInfo_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AcademicTagsInfo_Label->AutoSize = true;
			this->AcademicTagsInfo_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AcademicTagsInfo_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AcademicTagsInfo_Label->Location = System::Drawing::Point(3, 108);
			this->AcademicTagsInfo_Label->Name = L"AcademicTagsInfo_Label";
			this->AcademicTagsInfo_Label->Size = System::Drawing::Size(89, 19);
			this->AcademicTagsInfo_Label->TabIndex = 9;
			this->AcademicTagsInfo_Label->Text = L"Group Tags";
			this->AcademicTagsInfo_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::AcademicTagsInfo_Label_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(3, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 19);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Descripci�";
			// 
			// DescGrupEstudi_Label
			// 
			this->DescGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DescGrupEstudi_Label->AutoSize = true;
			this->DescGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DescGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->DescGrupEstudi_Label->Location = System::Drawing::Point(3, 27);
			this->DescGrupEstudi_Label->Name = L"DescGrupEstudi_Label";
			this->DescGrupEstudi_Label->Size = System::Drawing::Size(135, 19);
			this->DescGrupEstudi_Label->TabIndex = 4;
			this->DescGrupEstudi_Label->Text = L"Group Description";
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->panel2->Controls->Add(this->DeleteGrupEstudi_Button);
			this->panel2->Controls->Add(this->MembersGrupEstudi_Button);
			this->panel2->Controls->Add(this->ModifyGrupEstudi_Button);
			this->panel2->Location = System::Drawing::Point(619, 57);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(192, 147);
			this->panel2->TabIndex = 15;
			// 
			// DeleteGrupEstudi_Button
			// 
			this->DeleteGrupEstudi_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DeleteGrupEstudi_Button->Location = System::Drawing::Point(8, 89);
			this->DeleteGrupEstudi_Button->Name = L"DeleteGrupEstudi_Button";
			this->DeleteGrupEstudi_Button->Size = System::Drawing::Size(176, 35);
			this->DeleteGrupEstudi_Button->TabIndex = 13;
			this->DeleteGrupEstudi_Button->Text = L"El�liminar grup";
			this->DeleteGrupEstudi_Button->UseVisualStyleBackColor = true;
			this->DeleteGrupEstudi_Button->Visible = false;
			// 
			// MembersGrupEstudi_Button
			// 
			this->MembersGrupEstudi_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MembersGrupEstudi_Button->Location = System::Drawing::Point(8, 8);
			this->MembersGrupEstudi_Button->Name = L"MembersGrupEstudi_Button";
			this->MembersGrupEstudi_Button->Size = System::Drawing::Size(176, 35);
			this->MembersGrupEstudi_Button->TabIndex = 14;
			this->MembersGrupEstudi_Button->Text = L"Consultar membres";
			this->MembersGrupEstudi_Button->UseVisualStyleBackColor = true;
			// 
			// ModifyGrupEstudi_Button
			// 
			this->ModifyGrupEstudi_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ModifyGrupEstudi_Button->Location = System::Drawing::Point(8, 48);
			this->ModifyGrupEstudi_Button->Name = L"ModifyGrupEstudi_Button";
			this->ModifyGrupEstudi_Button->Size = System::Drawing::Size(176, 35);
			this->ModifyGrupEstudi_Button->TabIndex = 12;
			this->ModifyGrupEstudi_Button->Text = L"Editar grup";
			this->ModifyGrupEstudi_Button->UseVisualStyleBackColor = true;
			this->ModifyGrupEstudi_Button->Visible = false;
			// 
			// InfoGrupEstudi_Label
			// 
			this->InfoGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InfoGrupEstudi_Label->AutoSize = true;
			this->InfoGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InfoGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->InfoGrupEstudi_Label->Location = System::Drawing::Point(344, 10);
			this->InfoGrupEstudi_Label->Name = L"InfoGrupEstudi_Label";
			this->InfoGrupEstudi_Label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->InfoGrupEstudi_Label->Size = System::Drawing::Size(149, 33);
			this->InfoGrupEstudi_Label->TabIndex = 3;
			this->InfoGrupEstudi_Label->Text = L"Nom Grup";
			this->InfoGrupEstudi_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::InfoGrupEstudi_Label_Click);
			// 
			// panel5
			// 
			this->panel5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel5->Controls->Add(this->flowLayoutPanel1);
			this->panel5->Controls->Add(this->panel1);
			this->panel5->Location = System::Drawing::Point(224, 215);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(389, 265);
			this->panel5->TabIndex = 20;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->flowLayoutPanel1->Controls->Add(this->ModifySession_Button);
			this->flowLayoutPanel1->Controls->Add(this->DeleteSession_Button);
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 214);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(236, 43);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// ModifySession_Button
			// 
			this->ModifySession_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ModifySession_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ModifySession_Button->Location = System::Drawing::Point(3, 3);
			this->ModifySession_Button->Name = L"ModifySession_Button";
			this->ModifySession_Button->Size = System::Drawing::Size(112, 35);
			this->ModifySession_Button->TabIndex = 7;
			this->ModifySession_Button->Text = L"Modificar";
			this->ModifySession_Button->UseVisualStyleBackColor = true;
			this->ModifySession_Button->Visible = false;
			this->ModifySession_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::ModifySession_Click);
			// 
			// DeleteSession_Button
			// 
			this->DeleteSession_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DeleteSession_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteSession_Button->Location = System::Drawing::Point(121, 3);
			this->DeleteSession_Button->Name = L"DeleteSession_Button";
			this->DeleteSession_Button->Size = System::Drawing::Size(112, 35);
			this->DeleteSession_Button->TabIndex = 8;
			this->DeleteSession_Button->Text = L"El�liminar";
			this->DeleteSession_Button->UseVisualStyleBackColor = true;
			this->DeleteSession_Button->Visible = false;
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->session_name);
			this->panel1->Controls->Add(this->capacity);
			this->panel1->Controls->Add(this->Confirm_Cancel_Attent_Button);
			this->panel1->Controls->Add(this->ViewSessionAttendants_Button);
			this->panel1->Controls->Add(this->SessionCapacity_Label1);
			this->panel1->Controls->Add(this->EspaiCapacity_Label);
			this->panel1->Controls->Add(this->StartEndDuration_Label);
			this->panel1->Controls->Add(this->DayMonthYear_label);
			this->panel1->Controls->Add(this->EspaiName_Label);
			this->panel1->Location = System::Drawing::Point(7, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(375, 205);
			this->panel1->TabIndex = 10;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_InfoUI::panel1_Paint);
			// 
			// capacity
			// 
			this->capacity->AutoSize = true;
			this->capacity->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->capacity->Location = System::Drawing::Point(289, 168);
			this->capacity->Name = L"capacity";
			this->capacity->Size = System::Drawing::Size(26, 19);
			this->capacity->TabIndex = 11;
			this->capacity->Text = L"18";
			this->capacity->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label4_Click);
			// 
			// Confirm_Cancel_Attent_Button
			// 
			this->Confirm_Cancel_Attent_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Confirm_Cancel_Attent_Button->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Confirm_Cancel_Attent_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Confirm_Cancel_Attent_Button->Location = System::Drawing::Point(258, 17);
			this->Confirm_Cancel_Attent_Button->Name = L"Confirm_Cancel_Attent_Button";
			this->Confirm_Cancel_Attent_Button->Size = System::Drawing::Size(100, 52);
			this->Confirm_Cancel_Attent_Button->TabIndex = 0;
			this->Confirm_Cancel_Attent_Button->Text = L"Asistir";
			this->Confirm_Cancel_Attent_Button->UseVisualStyleBackColor = true;
			this->Confirm_Cancel_Attent_Button->Visible = false;
			this->Confirm_Cancel_Attent_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::Confirm_Cancel_Attent_Button_Click);
			// 
			// ViewSessionAttendants_Button
			// 
			this->ViewSessionAttendants_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ViewSessionAttendants_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ViewSessionAttendants_Button->Location = System::Drawing::Point(23, 149);
			this->ViewSessionAttendants_Button->Name = L"ViewSessionAttendants_Button";
			this->ViewSessionAttendants_Button->Size = System::Drawing::Size(181, 35);
			this->ViewSessionAttendants_Button->TabIndex = 5;
			this->ViewSessionAttendants_Button->Text = L"Consultar asistents";
			this->ViewSessionAttendants_Button->UseVisualStyleBackColor = true;
			this->ViewSessionAttendants_Button->Visible = false;
			this->ViewSessionAttendants_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::button1_Click_1);
			// 
			// SessionCapacity_Label1
			// 
			this->SessionCapacity_Label1->AutoSize = true;
			this->SessionCapacity_Label1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SessionCapacity_Label1->Location = System::Drawing::Point(275, 149);
			this->SessionCapacity_Label1->Name = L"SessionCapacity_Label1";
			this->SessionCapacity_Label1->Size = System::Drawing::Size(83, 19);
			this->SessionCapacity_Label1->TabIndex = 4;
			this->SessionCapacity_Label1->Text = L"Capacitat";
			this->SessionCapacity_Label1->Visible = false;
			// 
			// EspaiCapacity_Label
			// 
			this->EspaiCapacity_Label->AutoSize = true;
			this->EspaiCapacity_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EspaiCapacity_Label->Location = System::Drawing::Point(312, 168);
			this->EspaiCapacity_Label->Name = L"EspaiCapacity_Label";
			this->EspaiCapacity_Label->Size = System::Drawing::Size(40, 19);
			this->EspaiCapacity_Label->TabIndex = 3;
			this->EspaiCapacity_Label->Text = L"/ 25";
			this->EspaiCapacity_Label->Visible = false;
			// 
			// StartEndDuration_Label
			// 
			this->StartEndDuration_Label->AutoSize = true;
			this->StartEndDuration_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartEndDuration_Label->Location = System::Drawing::Point(18, 106);
			this->StartEndDuration_Label->Name = L"StartEndDuration_Label";
			this->StartEndDuration_Label->Size = System::Drawing::Size(108, 19);
			this->StartEndDuration_Label->TabIndex = 2;
			this->StartEndDuration_Label->Text = L"18:00 - 19:00";
			this->StartEndDuration_Label->Visible = false;
			// 
			// DayMonthYear_label
			// 
			this->DayMonthYear_label->AutoSize = true;
			this->DayMonthYear_label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DayMonthYear_label->Location = System::Drawing::Point(19, 76);
			this->DayMonthYear_label->Name = L"DayMonthYear_label";
			this->DayMonthYear_label->Size = System::Drawing::Size(107, 19);
			this->DayMonthYear_label->TabIndex = 1;
			this->DayMonthYear_label->Text = L"18 juny 2024";
			this->DayMonthYear_label->Visible = false;
			this->DayMonthYear_label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label2_Click_1);
			// 
			// EspaiName_Label
			// 
			this->EspaiName_Label->AutoSize = true;
			this->EspaiName_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EspaiName_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EspaiName_Label->Location = System::Drawing::Point(19, 17);
			this->EspaiName_Label->Name = L"EspaiName_Label";
			this->EspaiName_Label->Size = System::Drawing::Size(217, 19);
			this->EspaiName_Label->TabIndex = 0;
			this->EspaiName_Label->Text = L"Biblioteca Vilanova - Sala 1";
			this->EspaiName_Label->Visible = false;
			this->EspaiName_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label2_Click);
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GoBack_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoBack_Button->ForeColor = System::Drawing::Color::Red;
			this->GoBack_Button->Location = System::Drawing::Point(677, 494);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(75, 35);
			this->GoBack_Button->TabIndex = 16;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::GoBack_Button_Click);
			// 
			// panel4
			// 
			this->panel4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel4->Controls->Add(this->SessionsList_Label);
			this->panel4->Controls->Add(this->Sessions_ListBox);
			this->panel4->Controls->Add(this->NewSession_Button);
			this->panel4->Location = System::Drawing::Point(12, 221);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(197, 253);
			this->panel4->TabIndex = 18;
			// 
			// SessionsList_Label
			// 
			this->SessionsList_Label->AutoSize = true;
			this->SessionsList_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SessionsList_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->SessionsList_Label->Location = System::Drawing::Point(28, 7);
			this->SessionsList_Label->Name = L"SessionsList_Label";
			this->SessionsList_Label->Size = System::Drawing::Size(140, 19);
			this->SessionsList_Label->TabIndex = 5;
			this->SessionsList_Label->Text = L"Sessions actuals";
			this->SessionsList_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::SessionsList_Label_Click_1);
			// 
			// Sessions_ListBox
			// 
			this->Sessions_ListBox->BackColor = System::Drawing::Color::Lavender;
			this->Sessions_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sessions_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sessions_ListBox->FormattingEnabled = true;
			this->Sessions_ListBox->IntegralHeight = false;
			this->Sessions_ListBox->ItemHeight = 19;
			this->Sessions_ListBox->Location = System::Drawing::Point(12, 31);
			this->Sessions_ListBox->Name = L"Sessions_ListBox";
			this->Sessions_ListBox->Size = System::Drawing::Size(176, 171);
			this->Sessions_ListBox->TabIndex = 6;
			this->Sessions_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::SelectLastSessionOrPlaceholder);
			// 
			// NewSession_Button
			// 
			this->NewSession_Button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NewSession_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NewSession_Button->Location = System::Drawing::Point(12, 208);
			this->NewSession_Button->Name = L"NewSession_Button";
			this->NewSession_Button->Size = System::Drawing::Size(176, 35);
			this->NewSession_Button->TabIndex = 11;
			this->NewSession_Button->Text = L"Nova sessi�";
			this->NewSession_Button->UseVisualStyleBackColor = true;
			this->NewSession_Button->Visible = false;
			this->NewSession_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::NewSession_Button_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->Chat_Button, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(619, 212);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 57)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(192, 272);
			this->tableLayoutPanel2->TabIndex = 22;
			// 
			// Chat_Button
			// 
			this->Chat_Button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->Chat_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Chat_Button->Location = System::Drawing::Point(8, 3);
			this->Chat_Button->Name = L"Chat_Button";
			this->Chat_Button->Size = System::Drawing::Size(176, 35);
			this->Chat_Button->TabIndex = 15;
			this->Chat_Button->Text = L"Chat";
			this->Chat_Button->UseVisualStyleBackColor = true;
			this->Chat_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::Chat_Button_Click);
			// 
			// session_name
			// 
			this->session_name->AutoSize = true;
			this->session_name->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->session_name->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->session_name->Location = System::Drawing::Point(19, 50);
			this->session_name->Name = L"session_name";
			this->session_name->Size = System::Drawing::Size(50, 19);
			this->session_name->TabIndex = 12;
			this->session_name->Text = L"name";
			this->session_name->Visible = false;
			// 
			// GrupEstudi_InfoUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(814, 537);
			this->Name = L"GrupEstudi_InfoUI";
			this->Text = L"GrupEstudi_InfoUI";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::GrupEstudi_InfoUI_Load);
			tableLayoutPanel1->ResumeLayout(false);
			tableLayoutPanel1->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void SessionsList_Label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void DescGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SessionsList_Label_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SelectLastSessionOrPlaceholder(System::Object^ sender, System::EventArgs^ e);
private: System::Void ModifySession_Click(System::Object^ sender, System::EventArgs^ e);
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
//private: System::Void SelectLastSessionOrPlaceholder();
private: System::Void ActivateButtonsIfOwner();
private: System::Void InfoGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void NewSession_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Chat_Button_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Sessions_Actuals_Load();
private: System::Void Confirm_Cancel_Attent_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

#pragma once

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
		GrupEstudi_InfoUI(void);

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
			this->InfoGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->SessionsList_Label = (gcnew System::Windows::Forms::Label());
			this->Sessions_ListBox = (gcnew System::Windows::Forms::ListBox());
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
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->DeleteGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->ModifyGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->MembersGrupEstudi_Button = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 230)));
			tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 6);
			tableLayoutPanel1->Controls->Add(this->label1, 1, 4);
			tableLayoutPanel1->Controls->Add(this->DescGrupEstudi_Label, 1, 3);
			tableLayoutPanel1->Controls->Add(this->AcademicTagsInfo_Label, 1, 2);
			tableLayoutPanel1->Controls->Add(this->panel1, 1, 5);
			tableLayoutPanel1->Controls->Add(this->NewSession_Button, 0, 6);
			tableLayoutPanel1->Controls->Add(this->panel2, 2, 1);
			tableLayoutPanel1->Controls->Add(this->GoBack_Button, 2, 6);
			tableLayoutPanel1->Controls->Add(this->Sessions_ListBox, 0, 5);
			tableLayoutPanel1->Controls->Add(this->SessionsList_Label, 0, 4);
			tableLayoutPanel1->Controls->Add(this->InfoGrupEstudi_Label, 1, 1);
			tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			tableLayoutPanel1->Name = L"tableLayoutPanel1";
			tableLayoutPanel1->RowCount = 8;
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 78.18182F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 21.81818F)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 177)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
			tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			tableLayoutPanel1->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->ConfirmAttent_Button);
			this->flowLayoutPanel1->Controls->Add(this->CancelAttend_Button);
			this->flowLayoutPanel1->Controls->Add(this->DeleteSession_Button);
			this->flowLayoutPanel1->Controls->Add(this->ModifySession_Button);
			this->flowLayoutPanel1->Location = System::Drawing::Point(223, 413);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(357, 75);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// ConfirmAttent_Button
			// 
			this->ConfirmAttent_Button->Location = System::Drawing::Point(3, 3);
			this->ConfirmAttent_Button->Name = L"ConfirmAttent_Button";
			this->ConfirmAttent_Button->Size = System::Drawing::Size(75, 23);
			this->ConfirmAttent_Button->TabIndex = 0;
			this->ConfirmAttent_Button->Text = L"Asistir";
			this->ConfirmAttent_Button->UseVisualStyleBackColor = true;
			// 
			// CancelAttend_Button
			// 
			this->CancelAttend_Button->Location = System::Drawing::Point(84, 3);
			this->CancelAttend_Button->Name = L"CancelAttend_Button";
			this->CancelAttend_Button->Size = System::Drawing::Size(145, 23);
			this->CancelAttend_Button->TabIndex = 1;
			this->CancelAttend_Button->Text = L"Cancel·lar assistencia";
			this->CancelAttend_Button->UseVisualStyleBackColor = true;
			// 
			// DeleteSession_Button
			// 
			this->DeleteSession_Button->Location = System::Drawing::Point(235, 3);
			this->DeleteSession_Button->Name = L"DeleteSession_Button";
			this->DeleteSession_Button->Size = System::Drawing::Size(75, 23);
			this->DeleteSession_Button->TabIndex = 8;
			this->DeleteSession_Button->Text = L"El·liminar";
			this->DeleteSession_Button->UseVisualStyleBackColor = true;
			// 
			// ModifySession_Button
			// 
			this->ModifySession_Button->Location = System::Drawing::Point(3, 32);
			this->ModifySession_Button->Name = L"ModifySession_Button";
			this->ModifySession_Button->Size = System::Drawing::Size(129, 23);
			this->ModifySession_Button->TabIndex = 7;
			this->ModifySession_Button->Text = L"Modificar";
			this->ModifySession_Button->UseVisualStyleBackColor = true;
			this->ModifySession_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::button1_Click);
			// 
			// InfoGrupEstudi_Label
			// 
			this->InfoGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InfoGrupEstudi_Label->AutoSize = true;
			this->InfoGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->InfoGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->InfoGrupEstudi_Label->Location = System::Drawing::Point(270, 54);
			this->InfoGrupEstudi_Label->Name = L"InfoGrupEstudi_Label";
			this->InfoGrupEstudi_Label->Size = System::Drawing::Size(262, 31);
			this->InfoGrupEstudi_Label->TabIndex = 3;
			this->InfoGrupEstudi_Label->Text = L"Grupo roleplay +18";
			// 
			// SessionsList_Label
			// 
			this->SessionsList_Label->AutoSize = true;
			this->SessionsList_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SessionsList_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->SessionsList_Label->Location = System::Drawing::Point(3, 201);
			this->SessionsList_Label->Name = L"SessionsList_Label";
			this->SessionsList_Label->Size = System::Drawing::Size(129, 16);
			this->SessionsList_Label->TabIndex = 5;
			this->SessionsList_Label->Text = L"Sessions actuals:";
			this->SessionsList_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::SessionsList_Label_Click_1);
			// 
			// Sessions_ListBox
			// 
			this->Sessions_ListBox->BackColor = System::Drawing::Color::Lavender;
			this->Sessions_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Sessions_ListBox->FormattingEnabled = true;
			this->Sessions_ListBox->IntegralHeight = false;
			this->Sessions_ListBox->Location = System::Drawing::Point(3, 236);
			this->Sessions_ListBox->Name = L"Sessions_ListBox";
			this->Sessions_ListBox->Size = System::Drawing::Size(200, 171);
			this->Sessions_ListBox->TabIndex = 6;
			this->Sessions_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::Sessions_ListBox_SelectedIndexChanged);
			// 
			// DescGrupEstudi_Label
			// 
			this->DescGrupEstudi_Label->AutoSize = true;
			this->DescGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DescGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->DescGrupEstudi_Label->Location = System::Drawing::Point(223, 147);
			this->DescGrupEstudi_Label->Name = L"DescGrupEstudi_Label";
			this->DescGrupEstudi_Label->Size = System::Drawing::Size(267, 16);
			this->DescGrupEstudi_Label->TabIndex = 4;
			this->DescGrupEstudi_Label->Text = L"Grupo de roleplay +18 de la que se avecina";
			// 
			// AcademicTagsInfo_Label
			// 
			this->AcademicTagsInfo_Label->AutoSize = true;
			this->AcademicTagsInfo_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AcademicTagsInfo_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AcademicTagsInfo_Label->Location = System::Drawing::Point(223, 120);
			this->AcademicTagsInfo_Label->Name = L"AcademicTagsInfo_Label";
			this->AcademicTagsInfo_Label->Size = System::Drawing::Size(42, 16);
			this->AcademicTagsInfo_Label->TabIndex = 9;
			this->AcademicTagsInfo_Label->Text = L"INEP";
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
			this->panel1->Location = System::Drawing::Point(223, 236);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(357, 171);
			this->panel1->TabIndex = 10;
			// 
			// ViewSessionAttendants_Button
			// 
			this->ViewSessionAttendants_Button->Location = System::Drawing::Point(22, 106);
			this->ViewSessionAttendants_Button->Name = L"ViewSessionAttendants_Button";
			this->ViewSessionAttendants_Button->Size = System::Drawing::Size(141, 23);
			this->ViewSessionAttendants_Button->TabIndex = 5;
			this->ViewSessionAttendants_Button->Text = L"Consultar asistents";
			this->ViewSessionAttendants_Button->UseVisualStyleBackColor = true;
			this->ViewSessionAttendants_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::button1_Click_1);
			// 
			// SessionCapacity_Label1
			// 
			this->SessionCapacity_Label1->AutoSize = true;
			this->SessionCapacity_Label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SessionCapacity_Label1->Location = System::Drawing::Point(232, 111);
			this->SessionCapacity_Label1->Name = L"SessionCapacity_Label1";
			this->SessionCapacity_Label1->Size = System::Drawing::Size(61, 13);
			this->SessionCapacity_Label1->TabIndex = 4;
			this->SessionCapacity_Label1->Text = L"Capacitat";
			// 
			// EspaiCapacity_Label
			// 
			this->EspaiCapacity_Label->AutoSize = true;
			this->EspaiCapacity_Label->Location = System::Drawing::Point(299, 111);
			this->EspaiCapacity_Label->Name = L"EspaiCapacity_Label";
			this->EspaiCapacity_Label->Size = System::Drawing::Size(36, 13);
			this->EspaiCapacity_Label->TabIndex = 3;
			this->EspaiCapacity_Label->Text = L"18/25";
			// 
			// StartEndDuration_Label
			// 
			this->StartEndDuration_Label->AutoSize = true;
			this->StartEndDuration_Label->Location = System::Drawing::Point(19, 72);
			this->StartEndDuration_Label->Name = L"StartEndDuration_Label";
			this->StartEndDuration_Label->Size = System::Drawing::Size(70, 13);
			this->StartEndDuration_Label->TabIndex = 2;
			this->StartEndDuration_Label->Text = L"18:00 - 19:00";
			// 
			// DayMonthYear_label
			// 
			this->DayMonthYear_label->AutoSize = true;
			this->DayMonthYear_label->Location = System::Drawing::Point(19, 45);
			this->DayMonthYear_label->Name = L"DayMonthYear_label";
			this->DayMonthYear_label->Size = System::Drawing::Size(71, 13);
			this->DayMonthYear_label->TabIndex = 1;
			this->DayMonthYear_label->Text = L"16 Juny 2024";
			this->DayMonthYear_label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label2_Click_1);
			// 
			// EspaiName_Label
			// 
			this->EspaiName_Label->AutoSize = true;
			this->EspaiName_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EspaiName_Label->Location = System::Drawing::Point(19, 17);
			this->EspaiName_Label->Name = L"EspaiName_Label";
			this->EspaiName_Label->Size = System::Drawing::Size(144, 13);
			this->EspaiName_Label->TabIndex = 0;
			this->EspaiName_Label->Text = L"Biblioteca Cunit - Sala 1";
			this->EspaiName_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label2_Click);
			// 
			// NewSession_Button
			// 
			this->NewSession_Button->Location = System::Drawing::Point(3, 413);
			this->NewSession_Button->Name = L"NewSession_Button";
			this->NewSession_Button->Size = System::Drawing::Size(200, 23);
			this->NewSession_Button->TabIndex = 11;
			this->NewSession_Button->Text = L"Nova sessió";
			this->NewSession_Button->UseVisualStyleBackColor = true;
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GoBack_Button->Location = System::Drawing::Point(661, 439);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(75, 23);
			this->GoBack_Button->TabIndex = 16;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::GoBack_Button_Click);
			// 
			// DeleteGrupEstudi_Button
			// 
			this->DeleteGrupEstudi_Button->Location = System::Drawing::Point(26, 67);
			this->DeleteGrupEstudi_Button->Name = L"DeleteGrupEstudi_Button";
			this->DeleteGrupEstudi_Button->Size = System::Drawing::Size(176, 23);
			this->DeleteGrupEstudi_Button->TabIndex = 13;
			this->DeleteGrupEstudi_Button->Text = L"El·liminar grup";
			this->DeleteGrupEstudi_Button->UseVisualStyleBackColor = true;
			// 
			// ModifyGrupEstudi_Button
			// 
			this->ModifyGrupEstudi_Button->Location = System::Drawing::Point(26, 40);
			this->ModifyGrupEstudi_Button->Name = L"ModifyGrupEstudi_Button";
			this->ModifyGrupEstudi_Button->Size = System::Drawing::Size(176, 23);
			this->ModifyGrupEstudi_Button->TabIndex = 12;
			this->ModifyGrupEstudi_Button->Text = L"Editar grup";
			this->ModifyGrupEstudi_Button->UseVisualStyleBackColor = true;
			// 
			// MembersGrupEstudi_Button
			// 
			this->MembersGrupEstudi_Button->Location = System::Drawing::Point(26, 12);
			this->MembersGrupEstudi_Button->Name = L"MembersGrupEstudi_Button";
			this->MembersGrupEstudi_Button->Size = System::Drawing::Size(176, 23);
			this->MembersGrupEstudi_Button->TabIndex = 14;
			this->MembersGrupEstudi_Button->Text = L"Consultar membres";
			this->MembersGrupEstudi_Button->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->MembersGrupEstudi_Button);
			this->panel2->Controls->Add(this->ModifyGrupEstudi_Button);
			this->panel2->Controls->Add(this->DeleteGrupEstudi_Button);
			this->panel2->Location = System::Drawing::Point(586, 23);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(224, 94);
			this->panel2->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(223, 201);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 16);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Repaso de INEP";
			this->label1->Click += gcnew System::EventHandler(this, &GrupEstudi_InfoUI::label1_Click);
			// 
			// GrupEstudi_InfoUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GrupEstudi_InfoUI";
			this->Text = L"GrupEstudi_InfoUI";
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
};
}

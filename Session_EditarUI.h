#pragma once
#include "SessionService.h"
#include "Session.h"
#include "BaixaProveidorService.h"
#include "IniciSessioService.h"
#include "GrupEstudi.h"
#include "ConsultaEspaisService.h"
#include "GrupEstudiService.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Session_EditarUI
	/// </summary>
	public ref class Session_EditarUI : public System::Windows::Forms::Form
	{
	public:
		Session_EditarUI(GrupEstudi^ CurrentGrupEntity, Int64^ sessionId);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Session_EditarUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ EditaSession_Label;
	private: System::Windows::Forms::Label^ SessionName_Label;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ GoBack_Button;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ TimeHour_ComboBox;
	private: System::Windows::Forms::Label^ Espai_Label;
	private: System::Windows::Forms::Label^ Proveidor_Label;
	private: System::Windows::Forms::ComboBox^ Espai_ComboBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ SessionName_TextBox;
	private: System::Windows::Forms::MonthCalendar^ DayMonth_Calendar;
	private: System::Windows::Forms::ListBox^ Proveidor_ListBox;
	private: System::Windows::Forms::Button^ EditarTemps_Button;



	private: System::Windows::Forms::Button^ EditarEspai_Button;

	private: System::Windows::Forms::Button^ EditarProveidor_Button;
	private: System::Windows::Forms::Button^ EditarNom_Button;


	private: GrupEstudi^ CurrentGrupEntity;
	private: GrupEstudiService^ grupEstudiService;
	private: Session^ CurrentSessionEntity;
	private: SessionService^ sessionService;
	private: BaixaProveidorService^ baixaProveidorService;
	private: ConsultaEspaisService^ consultaEspaisService;
	private: IniciSessioService^ iniciSessioService;

	private: DateTime^ FullyFormatedSessionDate;
	private: bool IsLoaded;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->EditaSession_Label = (gcnew System::Windows::Forms::Label());
			this->SessionName_Label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->EditarTemps_Button = (gcnew System::Windows::Forms::Button());
			this->EditarEspai_Button = (gcnew System::Windows::Forms::Button());
			this->EditarProveidor_Button = (gcnew System::Windows::Forms::Button());
			this->EditarNom_Button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TimeHour_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Espai_Label = (gcnew System::Windows::Forms::Label());
			this->Proveidor_Label = (gcnew System::Windows::Forms::Label());
			this->Espai_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SessionName_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->DayMonth_Calendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->Proveidor_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				7.152682F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				92.84732F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				90)));
			this->tableLayoutPanel1->Controls->Add(this->EditaSession_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->SessionName_Label, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->GoBack_Button, 2, 3);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 53.15315F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.84685F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 352)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 60)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 26)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// EditaSession_Label
			// 
			this->EditaSession_Label->AutoSize = true;
			this->EditaSession_Label->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->EditaSession_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditaSession_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EditaSession_Label->Location = System::Drawing::Point(54, 19);
			this->EditaSession_Label->Name = L"EditaSession_Label";
			this->EditaSession_Label->Size = System::Drawing::Size(666, 33);
			this->EditaSession_Label->TabIndex = 0;
			this->EditaSession_Label->Text = L"Editar sessi\u00F3";
			this->EditaSession_Label->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// SessionName_Label
			// 
			this->SessionName_Label->AutoSize = true;
			this->SessionName_Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SessionName_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SessionName_Label->Location = System::Drawing::Point(54, 52);
			this->SessionName_Label->Name = L"SessionName_Label";
			this->SessionName_Label->Size = System::Drawing::Size(666, 46);
			this->SessionName_Label->TabIndex = 1;
			this->SessionName_Label->Text = L"...";
			this->SessionName_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->EditarTemps_Button);
			this->panel1->Controls->Add(this->EditarEspai_Button);
			this->panel1->Controls->Add(this->EditarProveidor_Button);
			this->panel1->Controls->Add(this->EditarNom_Button);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->TimeHour_ComboBox);
			this->panel1->Controls->Add(this->Espai_Label);
			this->panel1->Controls->Add(this->Proveidor_Label);
			this->panel1->Controls->Add(this->Espai_ComboBox);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->SessionName_TextBox);
			this->panel1->Controls->Add(this->DayMonth_Calendar);
			this->panel1->Controls->Add(this->Proveidor_ListBox);
			this->panel1->Location = System::Drawing::Point(54, 101);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(666, 346);
			this->panel1->TabIndex = 2;
			// 
			// EditarTemps_Button
			// 
			this->EditarTemps_Button->Enabled = false;
			this->EditarTemps_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarTemps_Button->Location = System::Drawing::Point(505, 292);
			this->EditarTemps_Button->Name = L"EditarTemps_Button";
			this->EditarTemps_Button->Size = System::Drawing::Size(104, 35);
			this->EditarTemps_Button->TabIndex = 23;
			this->EditarTemps_Button->Text = L"Confirmar";
			this->EditarTemps_Button->UseVisualStyleBackColor = true;
			this->EditarTemps_Button->Click += gcnew System::EventHandler(this, &Session_EditarUI::EditarTemps_Button_Click);
			// 
			// EditarEspai_Button
			// 
			this->EditarEspai_Button->Enabled = false;
			this->EditarEspai_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarEspai_Button->Location = System::Drawing::Point(219, 247);
			this->EditarEspai_Button->Name = L"EditarEspai_Button";
			this->EditarEspai_Button->Size = System::Drawing::Size(103, 35);
			this->EditarEspai_Button->TabIndex = 21;
			this->EditarEspai_Button->Text = L"Confirmar";
			this->EditarEspai_Button->UseVisualStyleBackColor = true;
			this->EditarEspai_Button->Click += gcnew System::EventHandler(this, &Session_EditarUI::EditarEspai_Button_Click);
			// 
			// EditarProveidor_Button
			// 
			this->EditarProveidor_Button->Enabled = false;
			this->EditarProveidor_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarProveidor_Button->Location = System::Drawing::Point(218, 147);
			this->EditarProveidor_Button->Name = L"EditarProveidor_Button";
			this->EditarProveidor_Button->Size = System::Drawing::Size(104, 35);
			this->EditarProveidor_Button->TabIndex = 20;
			this->EditarProveidor_Button->Text = L"Confirmar";
			this->EditarProveidor_Button->UseVisualStyleBackColor = true;
			this->EditarProveidor_Button->Click += gcnew System::EventHandler(this, &Session_EditarUI::EditarProveidor_Button_Click);
			// 
			// EditarNom_Button
			// 
			this->EditarNom_Button->Enabled = false;
			this->EditarNom_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarNom_Button->Location = System::Drawing::Point(218, 42);
			this->EditarNom_Button->Name = L"EditarNom_Button";
			this->EditarNom_Button->Size = System::Drawing::Size(104, 35);
			this->EditarNom_Button->TabIndex = 19;
			this->EditarNom_Button->Text = L"Confirmar";
			this->EditarNom_Button->UseVisualStyleBackColor = true;
			this->EditarNom_Button->Click += gcnew System::EventHandler(this, &Session_EditarUI::EditarNom_Button_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(413, 211);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 19);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Temps";
			// 
			// TimeHour_ComboBox
			// 
			this->TimeHour_ComboBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeHour_ComboBox->FormattingEnabled = true;
			this->TimeHour_ComboBox->Location = System::Drawing::Point(417, 232);
			this->TimeHour_ComboBox->Margin = System::Windows::Forms::Padding(2);
			this->TimeHour_ComboBox->Name = L"TimeHour_ComboBox";
			this->TimeHour_ComboBox->Size = System::Drawing::Size(192, 27);
			this->TimeHour_ComboBox->TabIndex = 17;
			this->TimeHour_ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Session_EditarUI::TimeHour_ComboBox_SelectedIndexChanged);
			// 
			// Espai_Label
			// 
			this->Espai_Label->AutoSize = true;
			this->Espai_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Espai_Label->Location = System::Drawing::Point(23, 226);
			this->Espai_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Espai_Label->Name = L"Espai_Label";
			this->Espai_Label->Size = System::Drawing::Size(50, 19);
			this->Espai_Label->TabIndex = 16;
			this->Espai_Label->Text = L"Espai";
			// 
			// Proveidor_Label
			// 
			this->Proveidor_Label->AutoSize = true;
			this->Proveidor_Label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Proveidor_Label->Location = System::Drawing::Point(23, 126);
			this->Proveidor_Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Proveidor_Label->Name = L"Proveidor_Label";
			this->Proveidor_Label->Size = System::Drawing::Size(206, 19);
			this->Proveidor_Label->TabIndex = 15;
			this->Proveidor_Label->Text = L"Prove\u00EFdor de espais";
			// 
			// Espai_ComboBox
			// 
			this->Espai_ComboBox->Enabled = false;
			this->Espai_ComboBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Espai_ComboBox->FormattingEnabled = true;
			this->Espai_ComboBox->Location = System::Drawing::Point(26, 247);
			this->Espai_ComboBox->Margin = System::Windows::Forms::Padding(2);
			this->Espai_ComboBox->Name = L"Espai_ComboBox";
			this->Espai_ComboBox->Size = System::Drawing::Size(186, 27);
			this->Espai_ComboBox->TabIndex = 14;
			this->Espai_ComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Session_EditarUI::Espai_ComboBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(23, 20);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 19);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Nom de la sessi\u00F3";
			// 
			// SessionName_TextBox
			// 
			this->SessionName_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SessionName_TextBox->Location = System::Drawing::Point(26, 42);
			this->SessionName_TextBox->Margin = System::Windows::Forms::Padding(2);
			this->SessionName_TextBox->Name = L"SessionName_TextBox";
			this->SessionName_TextBox->Size = System::Drawing::Size(186, 27);
			this->SessionName_TextBox->TabIndex = 12;
			this->SessionName_TextBox->TextChanged += gcnew System::EventHandler(this, &Session_EditarUI::SessionName_TextBox_TextChanged);
			// 
			// DayMonth_Calendar
			// 
			this->DayMonth_Calendar->Font = (gcnew System::Drawing::Font(L"Inter", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DayMonth_Calendar->Location = System::Drawing::Point(417, 42);
			this->DayMonth_Calendar->Margin = System::Windows::Forms::Padding(7);
			this->DayMonth_Calendar->Name = L"DayMonth_Calendar";
			this->DayMonth_Calendar->TabIndex = 11;
			this->DayMonth_Calendar->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Session_EditarUI::DayMonth_Calendar_DateChanged);
			// 
			// Proveidor_ListBox
			// 
			this->Proveidor_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Proveidor_ListBox->FormattingEnabled = true;
			this->Proveidor_ListBox->ItemHeight = 19;
			this->Proveidor_ListBox->Location = System::Drawing::Point(26, 147);
			this->Proveidor_ListBox->Margin = System::Windows::Forms::Padding(2);
			this->Proveidor_ListBox->Name = L"Proveidor_ListBox";
			this->Proveidor_ListBox->Size = System::Drawing::Size(186, 61);
			this->Proveidor_ListBox->TabIndex = 10;
			this->Proveidor_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Session_EditarUI::Proveidor_ListBox_SelectedIndexChanged);
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GoBack_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->GoBack_Button->ForeColor = System::Drawing::Color::Red;
			this->GoBack_Button->Location = System::Drawing::Point(731, 462);
			this->GoBack_Button->Margin = System::Windows::Forms::Padding(1, 10, 1, 10);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(75, 35);
			this->GoBack_Button->TabIndex = 3;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &Session_EditarUI::GoBack_Button_Click);
			// 
			// Session_EditarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Session_EditarUI";
			this->Text = L"Session_EditarUI";
			this->Load += gcnew System::EventHandler(this, &Session_EditarUI::Session_EditarUI_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Session_EditarUI_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void SessionName_TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void Proveidor_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void TimeHour_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void DayMonth_Calendar_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e);
private: System::Void GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Espai_ComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditarNom_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditarProveidor_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditarEspai_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void EditarTemps_Button_Click(System::Object^ sender, System::EventArgs^ e);
	   DateTime FormatTimeStringIntoDateTime(String^ espaiString);
private:
	void LoadEspaiTimeStampsOfCurrentDay();
	void LoadEspaisFromSelectedProveidor();
	void LoadProveidorsOnList();
	void OnCalendarDateChanged();
	bool FieldsNotEmpty();
};
}

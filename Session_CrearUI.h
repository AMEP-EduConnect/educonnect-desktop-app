#pragma once
#include "GrupEstudi.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Session_CrearUI
	/// </summary>
	public ref class Session_CrearUI : public System::Windows::Forms::Form
	{
	public:
		Session_CrearUI(GrupEstudi^ CurrentGrupEntity);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Session_CrearUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ NewSession_Label;
	private: System::Windows::Forms::Label^ CurrentGrupName_Label;

	private: System::Windows::Forms::Panel^ NewSessionInput_Panel;
	private: System::Windows::Forms::TextBox^ SessionName_TextBox;
	private: System::Windows::Forms::MonthCalendar^ DayMonth_Calendar;




	private: System::Windows::Forms::ListBox^ Proveidor_ListBox;

	private: System::Windows::Forms::Label^ SessionName_Label;
	private: System::Windows::Forms::ComboBox^ TimeHour_ComboBox;

	private: System::Windows::Forms::Label^ Espai_Label;
	private: System::Windows::Forms::Label^ Proveidor_Label;
	private: System::Windows::Forms::ComboBox^ Espai_ComboBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ CreateSession_Button;
	private: System::Windows::Forms::Button^ GoBack_Button;




		   GrupEstudi^ CurrentGrupEntity;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->NewSession_Label = (gcnew System::Windows::Forms::Label());
			this->CurrentGrupName_Label = (gcnew System::Windows::Forms::Label());
			this->NewSessionInput_Panel = (gcnew System::Windows::Forms::Panel());
			this->CreateSession_Button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TimeHour_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Espai_Label = (gcnew System::Windows::Forms::Label());
			this->Proveidor_Label = (gcnew System::Windows::Forms::Label());
			this->Espai_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SessionName_Label = (gcnew System::Windows::Forms::Label());
			this->SessionName_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->DayMonth_Calendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->Proveidor_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->GoBack_Button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->NewSessionInput_Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				23.85321F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				76.14679F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				213)));
			this->tableLayoutPanel1->Controls->Add(this->NewSession_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->CurrentGrupName_Label, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->NewSessionInput_Panel, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->GoBack_Button, 2, 3);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.68085F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.31915F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 436)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 110)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1085, 661);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// NewSession_Label
			// 
			this->NewSession_Label->AutoSize = true;
			this->NewSession_Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NewSession_Label->Location = System::Drawing::Point(211, 0);
			this->NewSession_Label->Name = L"NewSession_Label";
			this->NewSession_Label->Size = System::Drawing::Size(658, 42);
			this->NewSession_Label->TabIndex = 0;
			this->NewSession_Label->Text = L"Nova sessió en ";
			this->NewSession_Label->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// CurrentGrupName_Label
			// 
			this->CurrentGrupName_Label->AutoSize = true;
			this->CurrentGrupName_Label->Dock = System::Windows::Forms::DockStyle::Fill;
			this->CurrentGrupName_Label->Location = System::Drawing::Point(211, 42);
			this->CurrentGrupName_Label->Name = L"CurrentGrupName_Label";
			this->CurrentGrupName_Label->Size = System::Drawing::Size(658, 52);
			this->CurrentGrupName_Label->TabIndex = 1;
			this->CurrentGrupName_Label->Text = L"...";
			this->CurrentGrupName_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// NewSessionInput_Panel
			// 
			this->NewSessionInput_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->NewSessionInput_Panel->Controls->Add(this->CreateSession_Button);
			this->NewSessionInput_Panel->Controls->Add(this->label2);
			this->NewSessionInput_Panel->Controls->Add(this->TimeHour_ComboBox);
			this->NewSessionInput_Panel->Controls->Add(this->Espai_Label);
			this->NewSessionInput_Panel->Controls->Add(this->Proveidor_Label);
			this->NewSessionInput_Panel->Controls->Add(this->Espai_ComboBox);
			this->NewSessionInput_Panel->Controls->Add(this->SessionName_Label);
			this->NewSessionInput_Panel->Controls->Add(this->SessionName_TextBox);
			this->NewSessionInput_Panel->Controls->Add(this->DayMonth_Calendar);
			this->NewSessionInput_Panel->Controls->Add(this->Proveidor_ListBox);
			this->NewSessionInput_Panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NewSessionInput_Panel->Location = System::Drawing::Point(211, 97);
			this->NewSessionInput_Panel->Name = L"NewSessionInput_Panel";
			this->NewSessionInput_Panel->Size = System::Drawing::Size(658, 430);
			this->NewSessionInput_Panel->TabIndex = 2;
			// 
			// CreateSession_Button
			// 
			this->CreateSession_Button->Location = System::Drawing::Point(462, 385);
			this->CreateSession_Button->Name = L"CreateSession_Button";
			this->CreateSession_Button->Size = System::Drawing::Size(125, 23);
			this->CreateSession_Button->TabIndex = 10;
			this->CreateSession_Button->Text = L"Crear sessió";
			this->CreateSession_Button->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(364, 290);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 16);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Temps";
			// 
			// TimeHour_ComboBox
			// 
			this->TimeHour_ComboBox->FormattingEnabled = true;
			this->TimeHour_ComboBox->Location = System::Drawing::Point(367, 318);
			this->TimeHour_ComboBox->Name = L"TimeHour_ComboBox";
			this->TimeHour_ComboBox->Size = System::Drawing::Size(220, 24);
			this->TimeHour_ComboBox->TabIndex = 8;
			// 
			// Espai_Label
			// 
			this->Espai_Label->AutoSize = true;
			this->Espai_Label->Location = System::Drawing::Point(45, 290);
			this->Espai_Label->Name = L"Espai_Label";
			this->Espai_Label->Size = System::Drawing::Size(42, 16);
			this->Espai_Label->TabIndex = 7;
			this->Espai_Label->Text = L"Espai";
			// 
			// Proveidor_Label
			// 
			this->Proveidor_Label->AutoSize = true;
			this->Proveidor_Label->Location = System::Drawing::Point(45, 152);
			this->Proveidor_Label->Name = L"Proveidor_Label";
			this->Proveidor_Label->Size = System::Drawing::Size(129, 16);
			this->Proveidor_Label->TabIndex = 6;
			this->Proveidor_Label->Text = L"Proveïdor de espais";
			// 
			// Espai_ComboBox
			// 
			this->Espai_ComboBox->Enabled = false;
			this->Espai_ComboBox->FormattingEnabled = true;
			this->Espai_ComboBox->Location = System::Drawing::Point(48, 318);
			this->Espai_ComboBox->Name = L"Espai_ComboBox";
			this->Espai_ComboBox->Size = System::Drawing::Size(246, 24);
			this->Espai_ComboBox->TabIndex = 5;
			// 
			// SessionName_Label
			// 
			this->SessionName_Label->AutoSize = true;
			this->SessionName_Label->Location = System::Drawing::Point(45, 60);
			this->SessionName_Label->Name = L"SessionName_Label";
			this->SessionName_Label->Size = System::Drawing::Size(112, 16);
			this->SessionName_Label->TabIndex = 4;
			this->SessionName_Label->Text = L"Nom de la sessió";
			this->SessionName_Label->Click += gcnew System::EventHandler(this, &Session_CrearUI::label2_Click);
			// 
			// SessionName_TextBox
			// 
			this->SessionName_TextBox->Location = System::Drawing::Point(48, 95);
			this->SessionName_TextBox->Name = L"SessionName_TextBox";
			this->SessionName_TextBox->Size = System::Drawing::Size(246, 22);
			this->SessionName_TextBox->TabIndex = 3;
			// 
			// DayMonth_Calendar
			// 
			this->DayMonth_Calendar->Location = System::Drawing::Point(367, 60);
			this->DayMonth_Calendar->Name = L"DayMonth_Calendar";
			this->DayMonth_Calendar->TabIndex = 2;
			// 
			// Proveidor_ListBox
			// 
			this->Proveidor_ListBox->FormattingEnabled = true;
			this->Proveidor_ListBox->ItemHeight = 16;
			this->Proveidor_ListBox->Location = System::Drawing::Point(48, 183);
			this->Proveidor_ListBox->Name = L"Proveidor_ListBox";
			this->Proveidor_ListBox->Size = System::Drawing::Size(246, 84);
			this->Proveidor_ListBox->TabIndex = 0;
			// 
			// GoBack_Button
			// 
			this->GoBack_Button->Location = System::Drawing::Point(942, 570);
			this->GoBack_Button->Margin = System::Windows::Forms::Padding(70, 40, 10, 30);
			this->GoBack_Button->Name = L"GoBack_Button";
			this->GoBack_Button->Size = System::Drawing::Size(75, 23);
			this->GoBack_Button->TabIndex = 3;
			this->GoBack_Button->Text = L"Tornar";
			this->GoBack_Button->UseVisualStyleBackColor = true;
			this->GoBack_Button->Click += gcnew System::EventHandler(this, &Session_CrearUI::GoBack_Button_Click);
			// 
			// Session_CrearUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1085, 661);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Session_CrearUI";
			this->Text = L"Session_CrearUI";
			this->Load += gcnew System::EventHandler(this, &Session_CrearUI::Session_CrearUI_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->NewSessionInput_Panel->ResumeLayout(false);
			this->NewSessionInput_Panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Session_CrearUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e);
};
}

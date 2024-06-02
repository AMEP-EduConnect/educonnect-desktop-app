#pragma once
#include "GrupEstudi.h"
#include "GrupEstudiService.h"
#include "SessionService.h"
#include "GrupSessionAttendantsService.h"
#include "ConsultaEspaisService.h"
#include "CurrentSession.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Session_CalendariUI
	/// </summary>
	public ref class Session_CalendariUI : public System::Windows::Forms::Form
	{
	public:
		Session_CalendariUI(void);

		Void ChangeSessionCardVisibility(bool isSessionCardAvailable);

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Session_CalendariUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: List<Session^>^ SessionsList;
		   List<Session^>^ sessionsdia;
		   int i;
	private: bool isSessionLoaded;
	public: System::Collections::Generic::IEnumerator<Session^>^ enumerator;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
		GrupEstudi^ CurrentGrupEntity;
		ConsultaEspaisService^ consultaEspaisService;







	private: GrupEstudiService^ grupEstudiService;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: GrupSessionAttendantsService^ grupSessionAttendantsService;
	private: SessionService^ sessionService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ Anterior_Button;


	private: System::Windows::Forms::Button^ Seguent_Button;
	private: System::Windows::Forms::Label^ Contador;
	private: System::Windows::Forms::Label^ Separator_Label;


	private: System::Windows::Forms::Label^ DaySessions;
	private: System::Windows::Forms::Label^ NomSessió;

	private: System::Windows::Forms::Label^ Capacity;
	private: System::Windows::Forms::Label^ Attendants;
	private: System::Windows::Forms::Label^ SeparatorAsistents_Label;

	private: System::Windows::Forms::Label^ Horari;
	private: System::Windows::Forms::Label^ NomEspai;
	private: System::Windows::Forms::Label^ NomGrup;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ Data;
	private: System::Windows::Forms::Label^ label3;
	private: bool isSessionCardAvailable;




	private: Session^ CurrentSessionEntity;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->DaySessions = (gcnew System::Windows::Forms::Label());
			   this->Contador = (gcnew System::Windows::Forms::Label());
			   this->Separator_Label = (gcnew System::Windows::Forms::Label());
			   this->Anterior_Button = (gcnew System::Windows::Forms::Button());
			   this->Seguent_Button = (gcnew System::Windows::Forms::Button());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->Data = (gcnew System::Windows::Forms::Label());
			   this->NomGrup = (gcnew System::Windows::Forms::Label());
			   this->Horari = (gcnew System::Windows::Forms::Label());
			   this->NomEspai = (gcnew System::Windows::Forms::Label());
			   this->NomSessió = (gcnew System::Windows::Forms::Label());
			   this->Capacity = (gcnew System::Windows::Forms::Label());
			   this->Attendants = (gcnew System::Windows::Forms::Label());
			   this->SeparatorAsistents_Label = (gcnew System::Windows::Forms::Label());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->panel3->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 3;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   27.18447F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   63.26781F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   9.58231F)));
			   this->tableLayoutPanel1->Controls->Add(this->monthCalendar1, 0, 1);
			   this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 0);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->MinimumSize = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.74046F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 69.46565F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.79389F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 0;
			   this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Session_CalendariUI::tableLayoutPanel1_Paint);
			   // 
			   // monthCalendar1
			   // 
			   this->monthCalendar1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->monthCalendar1->Font = (gcnew System::Drawing::Font(L"Inter", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->monthCalendar1->Location = System::Drawing::Point(14, 178);
			   this->monthCalendar1->Name = L"monthCalendar1";
			   this->monthCalendar1->TabIndex = 1;
			   this->monthCalendar1->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &Session_CalendariUI::monthCalendar1_DateChanged);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel1->Controls->Add(this->DaySessions);
			   this->panel1->Controls->Add(this->Contador);
			   this->panel1->Controls->Add(this->Separator_Label);
			   this->panel1->Controls->Add(this->Anterior_Button);
			   this->panel1->Controls->Add(this->Seguent_Button);
			   this->panel1->Controls->Add(this->panel2);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel1->Location = System::Drawing::Point(224, 76);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(508, 367);
			   this->panel1->TabIndex = 13;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Session_CalendariUI::panel1_Paint_1);
			   // 
			   // DaySessions
			   // 
			   this->DaySessions->AutoSize = true;
			   this->DaySessions->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->DaySessions->Location = System::Drawing::Point(257, 325);
			   this->DaySessions->Name = L"DaySessions";
			   this->DaySessions->Size = System::Drawing::Size(19, 19);
			   this->DaySessions->TabIndex = 28;
			   this->DaySessions->Text = L"0";
			   this->DaySessions->Visible = false;
			   // 
			   // Contador
			   // 
			   this->Contador->AutoSize = true;
			   this->Contador->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->Contador->Location = System::Drawing::Point(220, 325);
			   this->Contador->Name = L"Contador";
			   this->Contador->Size = System::Drawing::Size(19, 19);
			   this->Contador->TabIndex = 27;
			   this->Contador->Text = L"0";
			   this->Contador->Visible = false;
			   // 
			   // Separator_Label
			   // 
			   this->Separator_Label->AutoSize = true;
			   this->Separator_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->Separator_Label->Location = System::Drawing::Point(239, 325);
			   this->Separator_Label->Name = L"Separator_Label";
			   this->Separator_Label->Size = System::Drawing::Size(15, 19);
			   this->Separator_Label->TabIndex = 26;
			   this->Separator_Label->Text = L"/";
			   this->Separator_Label->Visible = false;
			   // 
			   // Anterior_Button
			   // 
			   this->Anterior_Button->Enabled = false;
			   this->Anterior_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->Anterior_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Anterior_Button->Location = System::Drawing::Point(48, 317);
			   this->Anterior_Button->Name = L"Anterior_Button";
			   this->Anterior_Button->Size = System::Drawing::Size(104, 35);
			   this->Anterior_Button->TabIndex = 25;
			   this->Anterior_Button->Text = L"Anterior";
			   this->Anterior_Button->UseVisualStyleBackColor = true;
			   this->Anterior_Button->Visible = false;
			   this->Anterior_Button->Click += gcnew System::EventHandler(this, &Session_CalendariUI::AnteriorButton_Click);
			   // 
			   // Seguent_Button
			   // 
			   this->Seguent_Button->Enabled = false;
			   this->Seguent_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->Seguent_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Seguent_Button->Location = System::Drawing::Point(356, 317);
			   this->Seguent_Button->Name = L"Seguent_Button";
			   this->Seguent_Button->Size = System::Drawing::Size(104, 35);
			   this->Seguent_Button->TabIndex = 24;
			   this->Seguent_Button->Text = L"Següent";
			   this->Seguent_Button->UseVisualStyleBackColor = true;
			   this->Seguent_Button->Visible = false;
			   this->Seguent_Button->Click += gcnew System::EventHandler(this, &Session_CalendariUI::SeguentButton_Click);
			   // 
			   // panel2
			   // 
			   this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->panel2->Controls->Add(this->label3);
			   this->panel2->Controls->Add(this->Data);
			   this->panel2->Controls->Add(this->NomGrup);
			   this->panel2->Controls->Add(this->Horari);
			   this->panel2->Controls->Add(this->NomEspai);
			   this->panel2->Controls->Add(this->NomSessió);
			   this->panel2->Controls->Add(this->Capacity);
			   this->panel2->Controls->Add(this->Attendants);
			   this->panel2->Controls->Add(this->SeparatorAsistents_Label);
			   this->panel2->Location = System::Drawing::Point(48, 40);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(412, 271);
			   this->panel2->TabIndex = 14;
			   this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Session_CalendariUI::panel2_Paint);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Inter", 12));
			   this->label3->Location = System::Drawing::Point(18, 205);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(78, 19);
			   this->label3->TabIndex = 37;
			   this->label3->Text = L"Asistents";
			   this->label3->Visible = false;
			   // 
			   // Data
			   // 
			   this->Data->AutoSize = true;
			   this->Data->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Data->Location = System::Drawing::Point(271, 83);
			   this->Data->Name = L"Data";
			   this->Data->Size = System::Drawing::Size(0, 19);
			   this->Data->TabIndex = 36;
			   // 
			   // NomGrup
			   // 
			   this->NomGrup->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->NomGrup->AutoSize = true;
			   this->NomGrup->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->NomGrup->Location = System::Drawing::Point(18, 25);
			   this->NomGrup->Name = L"NomGrup";
			   this->NomGrup->Size = System::Drawing::Size(240, 19);
			   this->NomGrup->TabIndex = 35;
			   this->NomGrup->Text = L"No hi ha sessions disponibles";
			   this->NomGrup->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // Horari
			   // 
			   this->Horari->AutoSize = true;
			   this->Horari->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Horari->Location = System::Drawing::Point(270, 117);
			   this->Horari->Name = L"Horari";
			   this->Horari->Size = System::Drawing::Size(0, 19);
			   this->Horari->TabIndex = 34;
			   // 
			   // NomEspai
			   // 
			   this->NomEspai->AutoSize = true;
			   this->NomEspai->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->NomEspai->Location = System::Drawing::Point(18, 83);
			   this->NomEspai->Name = L"NomEspai";
			   this->NomEspai->Size = System::Drawing::Size(90, 19);
			   this->NomEspai->TabIndex = 33;
			   this->NomEspai->Text = L"Nom espai";
			   this->NomEspai->Visible = false;
			   // 
			   // NomSessió
			   // 
			   this->NomSessió->AutoSize = true;
			   this->NomSessió->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->NomSessió->Location = System::Drawing::Point(18, 117);
			   this->NomSessió->Name = L"NomSessió";
			   this->NomSessió->Size = System::Drawing::Size(97, 19);
			   this->NomSessió->TabIndex = 32;
			   this->NomSessió->Text = L"Nom sessió";
			   this->NomSessió->Visible = false;
			   // 
			   // Capacity
			   // 
			   this->Capacity->AutoSize = true;
			   this->Capacity->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Capacity->Location = System::Drawing::Point(354, 200);
			   this->Capacity->Name = L"Capacity";
			   this->Capacity->Size = System::Drawing::Size(19, 19);
			   this->Capacity->TabIndex = 31;
			   this->Capacity->Text = L"0";
			   this->Capacity->Visible = false;
			   // 
			   // Attendants
			   // 
			   this->Attendants->AutoSize = true;
			   this->Attendants->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Attendants->Location = System::Drawing::Point(317, 200);
			   this->Attendants->Name = L"Attendants";
			   this->Attendants->Size = System::Drawing::Size(19, 19);
			   this->Attendants->TabIndex = 30;
			   this->Attendants->Text = L"0";
			   this->Attendants->Visible = false;
			   // 
			   // SeparatorAsistents_Label
			   // 
			   this->SeparatorAsistents_Label->AutoSize = true;
			   this->SeparatorAsistents_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->SeparatorAsistents_Label->Location = System::Drawing::Point(336, 200);
			   this->SeparatorAsistents_Label->Name = L"SeparatorAsistents_Label";
			   this->SeparatorAsistents_Label->Size = System::Drawing::Size(15, 19);
			   this->SeparatorAsistents_Label->TabIndex = 29;
			   this->SeparatorAsistents_Label->Text = L"/";
			   this->SeparatorAsistents_Label->Visible = false;
			   // 
			   // panel3
			   // 
			   this->panel3->BackColor = System::Drawing::SystemColors::ButtonFace;
			   this->panel3->Controls->Add(this->label7);
			   this->panel3->Controls->Add(this->label1);
			   this->panel3->Controls->Add(this->label8);
			   this->panel3->Controls->Add(this->label9);
			   this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel3->Location = System::Drawing::Point(224, 3);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(508, 67);
			   this->panel3->TabIndex = 35;
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(292, 230);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(13, 13);
			   this->label7->TabIndex = 31;
			   this->label7->Text = L"5";
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->label1->Location = System::Drawing::Point(57, 15);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(268, 33);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Calendari Sessions";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(255, 230);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(13, 13);
			   this->label8->TabIndex = 30;
			   this->label8->Text = L"1";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(274, 230);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(12, 13);
			   this->label9->TabIndex = 29;
			   this->label9->Text = L"/";
			   // 
			   // Session_CalendariUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MinimumSize = System::Drawing::Size(814, 537);
			   this->Name = L"Session_CalendariUI";
			   this->Text = L"Session_CalendariUI";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Session_CalendariUI_ReLoad();
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void monthCalendar1_DateChanged(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e);
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void SeguentButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AnteriorButton_Click(System::Object^ sender, System::EventArgs^ e);

	};
}

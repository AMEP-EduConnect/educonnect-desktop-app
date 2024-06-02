#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AdministradorUI
	/// </summary>
	public ref class AdministradorUI : public System::Windows::Forms::Form
	{

	public:
		AdministradorUI(void);
		

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AdministradorUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
		
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ BotoReports;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ BotoBaixa;

	private: System::Windows::Forms::Button^ BotoAlta;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button_elim_usuari;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ Benvinguda;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel4;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_elim_usuari = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->BotoReports = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BotoBaixa = (gcnew System::Windows::Forms::Button());
			this->BotoAlta = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Benvinguda = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				3.931204F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				96.06879F)));
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.03538F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.96461F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AdministradorUI::tableLayoutPanel1_Paint);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(35, 73);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(776, 461);
			this->panel2->TabIndex = 1;
			// 
			// button_elim_usuari
			// 
			this->button_elim_usuari->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_elim_usuari->BackColor = System::Drawing::SystemColors::Control;
			this->button_elim_usuari->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_elim_usuari->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_elim_usuari->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_elim_usuari->Location = System::Drawing::Point(40, 53);
			this->button_elim_usuari->Name = L"button_elim_usuari";
			this->button_elim_usuari->Size = System::Drawing::Size(243, 41);
			this->button_elim_usuari->TabIndex = 23;
			this->button_elim_usuari->Text = L"Donar de baixa usuari";
			this->button_elim_usuari->UseVisualStyleBackColor = false;
			this->button_elim_usuari->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoBaixaUser_Click);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Inter Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label6->Location = System::Drawing::Point(232, 23);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(298, 33);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Panell d\'Administrador";
			// 
			// BotoReports
			// 
			this->BotoReports->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoReports->BackColor = System::Drawing::SystemColors::Control;
			this->BotoReports->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoReports->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoReports->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoReports->Location = System::Drawing::Point(40, 114);
			this->BotoReports->Name = L"BotoReports";
			this->BotoReports->Size = System::Drawing::Size(243, 41);
			this->BotoReports->TabIndex = 22;
			this->BotoReports->Text = L"Reports";
			this->BotoReports->UseVisualStyleBackColor = false;
			this->BotoReports->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoReports_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(128, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 19);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Usuaris";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(114, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 19);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Proveïdors";
			// 
			// BotoBaixa
			// 
			this->BotoBaixa->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoBaixa->BackColor = System::Drawing::SystemColors::Control;
			this->BotoBaixa->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoBaixa->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoBaixa->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoBaixa->Location = System::Drawing::Point(38, 114);
			this->BotoBaixa->Name = L"BotoBaixa";
			this->BotoBaixa->Size = System::Drawing::Size(243, 41);
			this->BotoBaixa->TabIndex = 19;
			this->BotoBaixa->Text = L"Donar de baixa proveïdor";
			this->BotoBaixa->UseVisualStyleBackColor = false;
			this->BotoBaixa->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoBaixa_Click);
			// 
			// BotoAlta
			// 
			this->BotoAlta->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoAlta->BackColor = System::Drawing::SystemColors::Control;
			this->BotoAlta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoAlta->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoAlta->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoAlta->Location = System::Drawing::Point(38, 53);
			this->BotoAlta->Name = L"BotoAlta";
			this->BotoAlta->Size = System::Drawing::Size(243, 41);
			this->BotoAlta->TabIndex = 17;
			this->BotoAlta->Text = L"Donar d\'alta proveïdor";
			this->BotoAlta->UseVisualStyleBackColor = false;
			this->BotoAlta->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoAltaProveidor_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->Benvinguda);
			this->panel3->Location = System::Drawing::Point(35, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(455, 64);
			this->panel3->TabIndex = 3;
			// 
			// Benvinguda
			// 
			this->Benvinguda->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Benvinguda->AutoSize = true;
			this->Benvinguda->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Benvinguda->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Benvinguda->Location = System::Drawing::Point(0, 15);
			this->Benvinguda->Name = L"Benvinguda";
			this->Benvinguda->Size = System::Drawing::Size(172, 33);
			this->Benvinguda->TabIndex = 0;
			this->Benvinguda->Text = L"Benvinguda";
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->button_elim_usuari);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->BotoReports);
			this->panel1->Location = System::Drawing::Point(394, 116);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(329, 182);
			this->panel1->TabIndex = 24;
			// 
			// panel4
			// 
			this->panel4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel4->Controls->Add(this->BotoAlta);
			this->panel4->Controls->Add(this->BotoBaixa);
			this->panel4->Controls->Add(this->label1);
			this->panel4->Location = System::Drawing::Point(30, 116);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(329, 182);
			this->panel4->TabIndex = 25;
			// 
			// AdministradorUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(814, 537);
			this->Name = L"AdministradorUI";
			this->Text = L"AdministradorUI";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void BotoAltaProveidor_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BotoBaixa_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BotoBaixaUser_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BotoReports_Click(System::Object^ sender, System::EventArgs^ e);
	   Void SetWelcomeMessage();
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}

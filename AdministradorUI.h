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












	protected:

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_elim_usuari = (gcnew System::Windows::Forms::Button());
			this->BotoReports = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BotoBaixa = (gcnew System::Windows::Forms::Button());
			this->BotoAlta = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				2.948403F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				97.0516F)));
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label6, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.03538F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.96461F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button_elim_usuari);
			this->panel2->Controls->Add(this->BotoReports);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->BotoBaixa);
			this->panel2->Controls->Add(this->BotoAlta);
			this->panel2->Location = System::Drawing::Point(27, 73);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(561, 334);
			this->panel2->TabIndex = 1;
			// 
			// button_elim_usuari
			// 
			this->button_elim_usuari->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_elim_usuari->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button_elim_usuari->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_elim_usuari->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_elim_usuari->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_elim_usuari->Location = System::Drawing::Point(7, 219);
			this->button_elim_usuari->Name = L"button_elim_usuari";
			this->button_elim_usuari->Size = System::Drawing::Size(243, 41);
			this->button_elim_usuari->TabIndex = 23;
			this->button_elim_usuari->Text = L"Donar de baixa usuari";
			this->button_elim_usuari->UseVisualStyleBackColor = false;
			this->button_elim_usuari->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoBaixaUser_Click);
			// 
			// BotoReports
			// 
			this->BotoReports->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoReports->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BotoReports->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoReports->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoReports->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoReports->Location = System::Drawing::Point(7, 172);
			this->BotoReports->Name = L"BotoReports";
			this->BotoReports->Size = System::Drawing::Size(243, 41);
			this->BotoReports->TabIndex = 22;
			this->BotoReports->Text = L"Reports";
			this->BotoReports->UseVisualStyleBackColor = false;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(3, 150);
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
			this->label1->Location = System::Drawing::Point(3, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 19);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Proveidors";
			// 
			// BotoBaixa
			// 
			this->BotoBaixa->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoBaixa->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BotoBaixa->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoBaixa->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoBaixa->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoBaixa->Location = System::Drawing::Point(7, 81);
			this->BotoBaixa->Name = L"BotoBaixa";
			this->BotoBaixa->Size = System::Drawing::Size(243, 41);
			this->BotoBaixa->TabIndex = 19;
			this->BotoBaixa->Text = L"Donar de baixa prove\u00EFdor";
			this->BotoBaixa->UseVisualStyleBackColor = false;
			this->BotoBaixa->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoBaixa_Click);
			// 
			// BotoAlta
			// 
			this->BotoAlta->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoAlta->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BotoAlta->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoAlta->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoAlta->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoAlta->Location = System::Drawing::Point(7, 34);
			this->BotoAlta->Name = L"BotoAlta";
			this->BotoAlta->Size = System::Drawing::Size(243, 41);
			this->BotoAlta->TabIndex = 17;
			this->BotoAlta->Text = L"Donar d\'alta prove\u00EFdor";
			this->BotoAlta->UseVisualStyleBackColor = false;
			this->BotoAlta->Click += gcnew System::EventHandler(this, &AdministradorUI::BotoAltaProveidor_Click);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label6->Location = System::Drawing::Point(264, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(310, 33);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Panell d\'administrador";
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
			this->tableLayoutPanel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void BotoAltaProveidor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BotoBaixa_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BotoBaixaUser_Click(System::Object^ sender, System::EventArgs^ e);
};
}

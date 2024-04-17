#pragma once
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainPageUI
	/// </summary>
	public ref class MainPageUI : public System::Windows::Forms::Form
	{
	public:
		MainPageUI(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainPageUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BotoPersonal;
	private: System::Windows::Forms::Button^ BotoLogout;
	protected:

	protected:

	protected:














	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ label1;






	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ BotoInici;
	private: System::Windows::Forms::Button^ BotoExplorar;







	private: System::Windows::Forms::Panel^ panel4;


	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ BotoSessions;

	private: System::Windows::Forms::Button^ BotoElsMeus;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ BotoAdmin;


	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ BotoEspais;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->BotoPersonal = (gcnew System::Windows::Forms::Button());
			this->BotoLogout = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->BotoInici = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->BotoExplorar = (gcnew System::Windows::Forms::Button());
			this->BotoElsMeus = (gcnew System::Windows::Forms::Button());
			this->BotoSessions = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->BotoEspais = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->BotoAdmin = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// BotoPersonal
			// 
			this->BotoPersonal->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoPersonal->FlatAppearance->BorderSize = 0;
			this->BotoPersonal->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BotoPersonal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoPersonal->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoPersonal->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoPersonal->Location = System::Drawing::Point(3, 3);
			this->BotoPersonal->Name = L"BotoPersonal";
			this->BotoPersonal->Size = System::Drawing::Size(158, 41);
			this->BotoPersonal->TabIndex = 1;
			this->BotoPersonal->Text = L"Perfil personal";
			this->BotoPersonal->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BotoPersonal->UseVisualStyleBackColor = true;
			this->BotoPersonal->Click += gcnew System::EventHandler(this, &MainPageUI::Perfil_Click);
			// 
			// BotoLogout
			// 
			this->BotoLogout->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->BotoLogout->FlatAppearance->BorderSize = 0;
			this->BotoLogout->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BotoLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoLogout->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoLogout->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoLogout->Location = System::Drawing::Point(167, 3);
			this->BotoLogout->Name = L"BotoLogout";
			this->BotoLogout->Size = System::Drawing::Size(146, 41);
			this->BotoLogout->TabIndex = 2;
			this->BotoLogout->Text = L"Tancar sessió";
			this->BotoLogout->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BotoLogout->UseVisualStyleBackColor = true;
			this->BotoLogout->Click += gcnew System::EventHandler(this, &MainPageUI::Tancar_Sessio_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				74.17583F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				361)));
			this->tableLayoutPanel3->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1271, 74);
			this->tableLayoutPanel3->TabIndex = 16;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->flowLayoutPanel1->Controls->Add(this->BotoPersonal);
			this->flowLayoutPanel1->Controls->Add(this->BotoLogout);
			this->flowLayoutPanel1->Location = System::Drawing::Point(931, 11);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(317, 52);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Inter ExtraBold", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(29, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"EduConnect";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(141)),
				static_cast<System::Int32>(static_cast<System::Byte>(211)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(217, 68);
			this->tableLayoutPanel2->TabIndex = 17;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel3->Controls->Add(this->BotoAdmin);
			this->panel3->Controls->Add(this->panel6);
			this->panel3->Controls->Add(this->BotoEspais);
			this->panel3->Controls->Add(this->panel5);
			this->panel3->Controls->Add(this->BotoSessions);
			this->panel3->Controls->Add(this->BotoElsMeus);
			this->panel3->Controls->Add(this->BotoExplorar);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->BotoInici);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 74);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(220, 605);
			this->panel3->TabIndex = 24;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->tableLayoutPanel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1271, 74);
			this->panel2->TabIndex = 19;
			// 
			// BotoInici
			// 
			this->BotoInici->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoInici->FlatAppearance->BorderSize = 0;
			this->BotoInici->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoInici->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoInici->Location = System::Drawing::Point(0, 0);
			this->BotoInici->Margin = System::Windows::Forms::Padding(3, 3, 3, 100);
			this->BotoInici->Name = L"BotoInici";
			this->BotoInici->Size = System::Drawing::Size(220, 40);
			this->BotoInici->TabIndex = 25;
			this->BotoInici->Text = L"Inici";
			this->BotoInici->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoInici->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 40);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(220, 44);
			this->panel4->TabIndex = 26;
			// 
			// BotoExplorar
			// 
			this->BotoExplorar->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoExplorar->FlatAppearance->BorderSize = 0;
			this->BotoExplorar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoExplorar->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoExplorar->Location = System::Drawing::Point(0, 84);
			this->BotoExplorar->Margin = System::Windows::Forms::Padding(3, 3, 3, 100);
			this->BotoExplorar->Name = L"BotoExplorar";
			this->BotoExplorar->Size = System::Drawing::Size(220, 40);
			this->BotoExplorar->TabIndex = 27;
			this->BotoExplorar->Text = L"Explorar Grups";
			this->BotoExplorar->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoExplorar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoExplorar->UseVisualStyleBackColor = true;
			// 
			// BotoElsMeus
			// 
			this->BotoElsMeus->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoElsMeus->FlatAppearance->BorderSize = 0;
			this->BotoElsMeus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoElsMeus->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoElsMeus->Location = System::Drawing::Point(0, 124);
			this->BotoElsMeus->Margin = System::Windows::Forms::Padding(3, 3, 3, 100);
			this->BotoElsMeus->Name = L"BotoElsMeus";
			this->BotoElsMeus->Size = System::Drawing::Size(220, 40);
			this->BotoElsMeus->TabIndex = 28;
			this->BotoElsMeus->Text = L"Els meus grups";
			this->BotoElsMeus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoElsMeus->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoElsMeus->UseVisualStyleBackColor = true;
			// 
			// BotoSessions
			// 
			this->BotoSessions->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoSessions->FlatAppearance->BorderSize = 0;
			this->BotoSessions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoSessions->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoSessions->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoSessions->Location = System::Drawing::Point(0, 164);
			this->BotoSessions->Margin = System::Windows::Forms::Padding(3, 3, 3, 100);
			this->BotoSessions->Name = L"BotoSessions";
			this->BotoSessions->Size = System::Drawing::Size(220, 40);
			this->BotoSessions->TabIndex = 29;
			this->BotoSessions->Text = L"Sessions";
			this->BotoSessions->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoSessions->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoSessions->UseVisualStyleBackColor = true;
			// 
			// panel5
			// 
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(0, 204);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(220, 44);
			this->panel5->TabIndex = 30;
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(220, 74);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1051, 605);
			this->panel1->TabIndex = 14;
			// 
			// BotoEspais
			// 
			this->BotoEspais->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoEspais->FlatAppearance->BorderSize = 0;
			this->BotoEspais->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoEspais->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoEspais->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoEspais->Location = System::Drawing::Point(0, 248);
			this->BotoEspais->Margin = System::Windows::Forms::Padding(3, 3, 3, 100);
			this->BotoEspais->Name = L"BotoEspais";
			this->BotoEspais->Size = System::Drawing::Size(220, 40);
			this->BotoEspais->TabIndex = 31;
			this->BotoEspais->Text = L"Espais";
			this->BotoEspais->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoEspais->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoEspais->UseVisualStyleBackColor = true;
			// 
			// panel6
			// 
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(0, 288);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(220, 44);
			this->panel6->TabIndex = 32;
			// 
			// BotoAdmin
			// 
			this->BotoAdmin->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoAdmin->FlatAppearance->BorderSize = 0;
			this->BotoAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoAdmin->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoAdmin->Location = System::Drawing::Point(0, 332);
			this->BotoAdmin->Margin = System::Windows::Forms::Padding(3, 3, 3, 100);
			this->BotoAdmin->Name = L"BotoAdmin";
			this->BotoAdmin->Size = System::Drawing::Size(220, 40);
			this->BotoAdmin->TabIndex = 33;
			this->BotoAdmin->Text = L"Administrador";
			this->BotoAdmin->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoAdmin->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoAdmin->UseVisualStyleBackColor = true;
			// 
			// MainPageUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1271, 679);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Name = L"MainPageUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Load += gcnew System::EventHandler(this, &MainPageUI::MainPageUI_Load);
			this->Resize += gcnew System::EventHandler(this, &MainPageUI::panelContenedor_Resize);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:

		System::Void MainPageUI_Load(System::Object^ sender, System::EventArgs^ e);

		System::Void Tancar_Sessio_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Perfil_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Consulta_Grup_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Edita_Grup_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Gestiona_Grup_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Crea_Grup_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void Alta_Proveidor_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Baixa_Proveidor_Click(System::Object^ sender, System::EventArgs^ e);
		void panelContenedor_Resize(Object^ sender, EventArgs^ e);

		
		//TESTING METHOD, DELETE LATER
		//System::Void testQuery();
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
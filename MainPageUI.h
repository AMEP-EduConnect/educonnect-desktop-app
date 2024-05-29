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
		static MainPageUI^ Instance;
		MainPageUI(void);


		//protected:
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

	public:
		System::Windows::Forms::Panel^ screen;

	private:

		System::Windows::Forms::Button^ BotoPersonal;
		System::Windows::Forms::Button^ BotoLogout;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
		System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
		System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Panel^ panel3;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::Button^ BotoInici;
		System::Windows::Forms::Button^ BotoExplorar;
		System::Windows::Forms::Panel^ panel4;

		System::Windows::Forms::Button^ BotoSessions;
		System::Windows::Forms::Button^ BotoElsMeus;


		System::Windows::Forms::Button^ BotoEspais;
		System::Windows::Forms::Panel^ panel7;
		System::Windows::Forms::Button^ BotoNotificacions;
		System::Windows::Forms::Button^ BotoAdmin;
		System::Windows::Forms::Panel^ panel6;


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
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->BotoAdmin = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->BotoNotificacions = (gcnew System::Windows::Forms::Button());
			this->BotoEspais = (gcnew System::Windows::Forms::Button());
			this->BotoSessions = (gcnew System::Windows::Forms::Button());
			this->BotoElsMeus = (gcnew System::Windows::Forms::Button());
			this->BotoExplorar = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->BotoInici = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->screen = (gcnew System::Windows::Forms::Panel());
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
			this->BotoPersonal->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoPersonal->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoPersonal->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoPersonal->Location = System::Drawing::Point(4, 4);
			this->BotoPersonal->Margin = System::Windows::Forms::Padding(4);
			this->BotoPersonal->Name = L"BotoPersonal";
			this->BotoPersonal->Size = System::Drawing::Size(211, 50);
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
			this->BotoLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoLogout->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoLogout->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoLogout->Location = System::Drawing::Point(223, 4);
			this->BotoLogout->Margin = System::Windows::Forms::Padding(4);
			this->BotoLogout->Name = L"BotoLogout";
			this->BotoLogout->Size = System::Drawing::Size(195, 50);
			this->BotoLogout->TabIndex = 2;
			this->BotoLogout->Text = L"Tancar sessió";
			this->BotoLogout->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BotoLogout->UseVisualStyleBackColor = true;
			this->BotoLogout->Click += gcnew System::EventHandler(this, &MainPageUI::Tancar_Sessio_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				74.17583F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				483)));
			this->tableLayoutPanel3->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(1379, 90);
			this->tableLayoutPanel3->TabIndex = 16;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->flowLayoutPanel1->Controls->Add(this->BotoPersonal);
			this->flowLayoutPanel1->Controls->Add(this->BotoLogout);
			this->flowLayoutPanel1->Location = System::Drawing::Point(926, 13);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(423, 64);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(243)));
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(4, 4);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(289, 82);
			this->tableLayoutPanel2->TabIndex = 17;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Location = System::Drawing::Point(32, 20);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"EduConnect";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->panel3->Controls->Add(this->BotoAdmin);
			this->panel3->Controls->Add(this->panel6);
			this->panel3->Controls->Add(this->BotoNotificacions);
			this->panel3->Controls->Add(this->BotoEspais);
			this->panel3->Controls->Add(this->BotoSessions);
			this->panel3->Controls->Add(this->BotoElsMeus);
			this->panel3->Controls->Add(this->BotoExplorar);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Controls->Add(this->BotoInici);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 91);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(293, 659);
			this->panel3->TabIndex = 24;
			// 
			// BotoAdmin
			// 
			this->BotoAdmin->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoAdmin->FlatAppearance->BorderSize = 0;
			this->BotoAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoAdmin->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoAdmin->Location = System::Drawing::Point(0, 402);
			this->BotoAdmin->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoAdmin->Name = L"BotoAdmin";
			this->BotoAdmin->Size = System::Drawing::Size(293, 49);
			this->BotoAdmin->TabIndex = 36;
			this->BotoAdmin->Text = L"  Administrador";
			this->BotoAdmin->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoAdmin->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoAdmin->UseVisualStyleBackColor = true;
			// 
			// panel6
			// 
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(0, 348);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(293, 54);
			this->panel6->TabIndex = 35;
			// 
			// BotoNotificacions
			// 
			this->BotoNotificacions->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoNotificacions->FlatAppearance->BorderSize = 0;
			this->BotoNotificacions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoNotificacions->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoNotificacions->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoNotificacions->Location = System::Drawing::Point(0, 299);
			this->BotoNotificacions->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoNotificacions->Name = L"BotoNotificacions";
			this->BotoNotificacions->Size = System::Drawing::Size(293, 49);
			this->BotoNotificacions->TabIndex = 34;
			this->BotoNotificacions->Text = L"  Notificacions";
			this->BotoNotificacions->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoNotificacions->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoNotificacions->UseVisualStyleBackColor = true;
			this->BotoNotificacions->Click += gcnew System::EventHandler(this, &MainPageUI::BotoNotificacions_Click);
			// 
			// BotoEspais
			// 
			this->BotoEspais->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoEspais->FlatAppearance->BorderSize = 0;
			this->BotoEspais->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoEspais->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoEspais->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoEspais->Location = System::Drawing::Point(0, 250);
			this->BotoEspais->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoEspais->Name = L"BotoEspais";
			this->BotoEspais->Size = System::Drawing::Size(293, 49);
			this->BotoEspais->TabIndex = 31;
			this->BotoEspais->Text = L"  Espais";
			this->BotoEspais->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoEspais->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoEspais->UseVisualStyleBackColor = true;
			this->BotoEspais->Click += gcnew System::EventHandler(this, &MainPageUI::BotoEspais_Click);
			// 
			// BotoSessions
			// 
			this->BotoSessions->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoSessions->FlatAppearance->BorderSize = 0;
			this->BotoSessions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoSessions->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoSessions->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoSessions->Location = System::Drawing::Point(0, 201);
			this->BotoSessions->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoSessions->Name = L"BotoSessions";
			this->BotoSessions->Size = System::Drawing::Size(293, 49);
			this->BotoSessions->TabIndex = 29;
			this->BotoSessions->Text = L"  Sessions";
			this->BotoSessions->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoSessions->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoSessions->UseVisualStyleBackColor = true;
			// 
			// BotoElsMeus
			// 
			this->BotoElsMeus->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoElsMeus->FlatAppearance->BorderSize = 0;
			this->BotoElsMeus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoElsMeus->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoElsMeus->Location = System::Drawing::Point(0, 152);
			this->BotoElsMeus->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoElsMeus->Name = L"BotoElsMeus";
			this->BotoElsMeus->Size = System::Drawing::Size(293, 49);
			this->BotoElsMeus->TabIndex = 28;
			this->BotoElsMeus->Text = L"  Els meus grups";
			this->BotoElsMeus->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoElsMeus->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoElsMeus->UseVisualStyleBackColor = true;
			this->BotoElsMeus->Click += gcnew System::EventHandler(this, &MainPageUI::ElsMeus_Click);
			// 
			// BotoExplorar
			// 
			this->BotoExplorar->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoExplorar->FlatAppearance->BorderSize = 0;
			this->BotoExplorar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoExplorar->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoExplorar->Location = System::Drawing::Point(0, 103);
			this->BotoExplorar->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoExplorar->Name = L"BotoExplorar";
			this->BotoExplorar->Size = System::Drawing::Size(293, 49);
			this->BotoExplorar->TabIndex = 27;
			this->BotoExplorar->Text = L"  Explorar grups";
			this->BotoExplorar->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoExplorar->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoExplorar->UseVisualStyleBackColor = true;
			this->BotoExplorar->Click += gcnew System::EventHandler(this, &MainPageUI::BotoExplorar_Click);
			// 
			// panel4
			// 
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 49);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(293, 54);
			this->panel4->TabIndex = 26;
			// 
			// BotoInici
			// 
			this->BotoInici->Dock = System::Windows::Forms::DockStyle::Top;
			this->BotoInici->FlatAppearance->BorderSize = 0;
			this->BotoInici->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BotoInici->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->BotoInici->Location = System::Drawing::Point(0, 0);
			this->BotoInici->Margin = System::Windows::Forms::Padding(4, 4, 4, 123);
			this->BotoInici->Name = L"BotoInici";
			this->BotoInici->Size = System::Drawing::Size(293, 49);
			this->BotoInici->TabIndex = 25;
			this->BotoInici->Text = L"Inici";
			this->BotoInici->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->BotoInici->UseVisualStyleBackColor = true;
			this->BotoInici->Click += gcnew System::EventHandler(this, &MainPageUI::BotoInici_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->Controls->Add(this->tableLayoutPanel3);
			this->panel2->Controls->Add(this->panel7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1379, 91);
			this->panel2->TabIndex = 19;
			// 
			// panel7
			// 
			this->panel7->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel7->Location = System::Drawing::Point(0, 90);
			this->panel7->Margin = System::Windows::Forms::Padding(0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1379, 1);
			this->panel7->TabIndex = 0;
			// 
			// screen
			// 
			this->screen->BackColor = System::Drawing::SystemColors::Control;
			this->screen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->screen->Location = System::Drawing::Point(293, 91);
			this->screen->Margin = System::Windows::Forms::Padding(4);
			this->screen->Name = L"screen";
			this->screen->Size = System::Drawing::Size(1086, 659);
			this->screen->TabIndex = 14;
			// 
			// MainPageUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1379, 750);
			this->Controls->Add(this->screen);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(1394, 787);
			this->Name = L"MainPageUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Load += gcnew System::EventHandler(this, &MainPageUI::MainPageUI_Load);
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

		System::Void BotoInici_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Admin_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void ElsMeus_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BotoExplorar_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BotoEspais_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void BotoNotificacions_Click(System::Object^ sender, System::EventArgs^ e);
	};
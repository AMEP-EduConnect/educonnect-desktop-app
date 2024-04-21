#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CppCLRWinFormsProject {

	/// <summary>
	/// Resumen de GrupUC
	/// </summary>
	public ref class GrupUC : public System::Windows::Forms::UserControl
	{
	public:
		GrupUC(void);

	
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupUC()
		{
			if (components)
			{
				delete components;
			}
		}
	 System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	 System::Windows::Forms::PictureBox^ pictureBox1;
	 System::Windows::Forms::Button^ button1;
	 System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	
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
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->button1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->MinimumSize = System::Drawing::Size(163, 185);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 81.34715F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.65285F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(166, 185);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(3, 153);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Grup";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->Location = System::Drawing::Point(4, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(157, 120);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// GrupUC
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tableLayoutPanel2);
			this->MinimumSize = System::Drawing::Size(163, 185);
			this->Name = L"GrupUC";
			this->Size = System::Drawing::Size(163, 185);
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

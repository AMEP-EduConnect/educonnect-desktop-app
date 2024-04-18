#pragma once
#include "BaixaUsuariService.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de BaixaUsuari
	/// </summary>
	public ref class BaixaUsuariUI : public System::Windows::Forms::Form
	{
	public:
		BaixaUsuariUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~BaixaUsuariUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: BaixaUsuariService^ baixaUsuariService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(367, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"hOLA";
			this->label1->Click += gcnew System::EventHandler(this, &BaixaUsuariUI::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(177, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(208, 26);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->button1->Location = System::Drawing::Point(337, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 34);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Confirma";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BaixaUsuariUI::button1_Click);
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(434, 74);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(88, 34);
			this->Cancelar_Button->TabIndex = 16;
			this->Cancelar_Button->Text = L"Cancelar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &BaixaUsuariUI::Cancelar_Button_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				3.522012F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				96.47799F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				54)));
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 1, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 31.14754F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.85246F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 201)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 174)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 17;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BaixaUsuariUI::tableLayoutPanel1_Paint);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->Cancelar_Button);
			this->panel1->Location = System::Drawing::Point(53, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(561, 128);
			this->panel1->TabIndex = 18;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &BaixaUsuariUI::panel1_Paint);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(303, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(179, 31);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Baixa Usuari";
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Location = System::Drawing::Point(67, 176);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(651, 171);
			this->panel2->TabIndex = 20;
			// 
			// BaixaUsuariUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"BaixaUsuariUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BaixaUsuari";
			this->Load += gcnew System::EventHandler(this, &BaixaUsuariUI::BaixaUsuariUI_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
			 System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void BaixaUsuariUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}

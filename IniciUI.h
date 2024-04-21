#pragma once
#include "GrupUC.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IniciUI
	/// </summary>
	public ref class IniciUI : public System::Windows::Forms::Form
	{
	public:
		IniciUI(void)
		{
			InitializeComponent();
			SetWelcomeMessage();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~IniciUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Benvinguda;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;




	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;





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
			this->Benvinguda = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// Benvinguda
			// 
			this->Benvinguda->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Benvinguda->AutoSize = true;
			this->Benvinguda->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Benvinguda->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Benvinguda->Location = System::Drawing::Point(0, 7);
			this->Benvinguda->Name = L"Benvinguda";
			this->Benvinguda->Size = System::Drawing::Size(172, 33);
			this->Benvinguda->TabIndex = 0;
			this->Benvinguda->Text = L"Benvinguda";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				4.307974F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				95.69202F)));
			this->tableLayoutPanel1->Controls->Add(this->panel4, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.24209F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 89.75791F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->panel1);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(38, 58);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(773, 476);
			this->panel4->TabIndex = 2;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &IniciUI::panel4_Paint);
			// 
			// panel5
			// 
			this->panel5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel5->Controls->Add(this->label2);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Location = System::Drawing::Point(0, 272);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(770, 207);
			this->panel5->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Inter Light", 14));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(3, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Notificacions";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Inter Light", 14));
			this->label3->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label3->Location = System::Drawing::Point(355, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(234, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Recomanacions de grups";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->Controls->Add(this->flowLayoutPanel1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(0, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(770, 263);
			this->panel1->TabIndex = 4;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, 51);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(767, 187);
			this->flowLayoutPanel1->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Inter Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label4->Location = System::Drawing::Point(0, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(208, 33);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Els meus grups";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->Benvinguda);
			this->panel3->Location = System::Drawing::Point(38, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(455, 49);
			this->panel3->TabIndex = 2;
			// 
			// IniciUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MinimumSize = System::Drawing::Size(814, 537);
			this->Name = L"IniciUI";
			this->Text = L"IniciUI";
			this->Load += gcnew System::EventHandler(this, &IniciUI::IniciUI_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void IniciUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void SetWelcomeMessage();


private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}

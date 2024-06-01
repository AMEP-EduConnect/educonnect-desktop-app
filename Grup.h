#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace CppCLRWinFormsProject {

	/// <summary>
	/// Resumen de Grup
	/// </summary>
	public ref class Grup : public System::Windows::Forms::UserControl
	{
	public:
		Grup(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Grup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ Grup1;
	protected:
	private: System::Windows::Forms::Label^ Grup1label;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

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
			this->Grup1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Grup1label = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->Grup1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// Grup1
			// 
			this->Grup1->ColumnCount = 1;
			this->Grup1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup1->Controls->Add(this->Grup1label, 0, 1);
			this->Grup1->Controls->Add(this->pictureBox3, 0, 0);
			this->Grup1->Location = System::Drawing::Point(23, 9);
			this->Grup1->Margin = System::Windows::Forms::Padding(3, 3, 30, 3);
			this->Grup1->Name = L"Grup1";
			this->Grup1->RowCount = 2;
			this->Grup1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->Grup1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
			this->Grup1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->Grup1->Size = System::Drawing::Size(132, 163);
			this->Grup1->TabIndex = 13;
			// 
			// Grup1label
			// 
			this->Grup1label->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Grup1label->AutoSize = true;
			this->Grup1label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Grup1label->Location = System::Drawing::Point(3, 138);
			this->Grup1label->Name = L"Grup1label";
			this->Grup1label->Size = System::Drawing::Size(86, 19);
			this->Grup1label->TabIndex = 4;
			this->Grup1label->Text = L"Nom Grup";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Location = System::Drawing::Point(3, 3);
			this->pictureBox3->MinimumSize = System::Drawing::Size(126, 126);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(126, 126);
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// Grup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->Grup1);
			this->Name = L"Grup";
			this->Size = System::Drawing::Size(179, 181);
			this->Grup1->ResumeLayout(false);
			this->Grup1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

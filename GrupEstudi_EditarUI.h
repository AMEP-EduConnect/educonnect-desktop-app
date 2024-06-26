#pragma once
#include "GrupEstudiService.h"
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"
#include "GrupEstudi.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_EditarUI
	/// </summary>
	public ref class GrupEstudi_EditarUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_EditarUI(String^ NomGrup);
		//bool UserIsEditing = false;

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~GrupEstudi_EditarUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ EditarGrupEstudi_Label;
	private: System::Windows::Forms::TextBox^ NomActual_TextBox;
	protected:




	private: System::Windows::Forms::Label^ Nom_Label;
	private: System::Windows::Forms::Panel^ Editar_Panel;
	private: System::Windows::Forms::TextBox^ EditarDescripcio_TextBox;
	private: System::Windows::Forms::Label^ Descripcio_Label;
	private: System::Windows::Forms::Button^ Edita_Button;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: GrupEstudiService^ grupEstudiService;

	private: String^ nomActual;
	private: System::Windows::Forms::Button^ noModificarButton;
	private: bool noModifica = false;

	private: String^ descripcioActual;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EditarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->NomActual_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Nom_Label = (gcnew System::Windows::Forms::Label());
			this->Editar_Panel = (gcnew System::Windows::Forms::Panel());
			this->noModificarButton = (gcnew System::Windows::Forms::Button());
			this->Edita_Button = (gcnew System::Windows::Forms::Button());
			this->EditarDescripcio_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Descripcio_Label = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Editar_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// EditarGrupEstudi_Label
			// 
			this->EditarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EditarGrupEstudi_Label->AutoSize = true;
			this->EditarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EditarGrupEstudi_Label->Location = System::Drawing::Point(273, 34);
			this->EditarGrupEstudi_Label->Name = L"EditarGrupEstudi_Label";
			this->EditarGrupEstudi_Label->Size = System::Drawing::Size(266, 33);
			this->EditarGrupEstudi_Label->TabIndex = 0;
			this->EditarGrupEstudi_Label->Text = L"Edita Grup d\'Estudi";
			this->EditarGrupEstudi_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::EditarGrupEstudi_Label_Click);
			// 
			// NomActual_TextBox
			// 
			this->NomActual_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomActual_TextBox->Location = System::Drawing::Point(31, 46);
			this->NomActual_TextBox->MaxLength = 22;
			this->NomActual_TextBox->Name = L"NomActual_TextBox";
			this->NomActual_TextBox->Size = System::Drawing::Size(392, 27);
			this->NomActual_TextBox->TabIndex = 2;
			// 
			// Nom_Label
			// 
			this->Nom_Label->AutoSize = true;
			this->Nom_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Nom_Label->Location = System::Drawing::Point(27, 24);
			this->Nom_Label->Name = L"Nom_Label";
			this->Nom_Label->Size = System::Drawing::Size(113, 19);
			this->Nom_Label->TabIndex = 3;
			this->Nom_Label->Text = L"Nom del grup";
			this->Nom_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::Nom_Label_Click);
			// 
			// Editar_Panel
			// 
			this->Editar_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Editar_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Editar_Panel->Controls->Add(this->noModificarButton);
			this->Editar_Panel->Controls->Add(this->Edita_Button);
			this->Editar_Panel->Controls->Add(this->EditarDescripcio_TextBox);
			this->Editar_Panel->Controls->Add(this->Descripcio_Label);
			this->Editar_Panel->Controls->Add(this->Nom_Label);
			this->Editar_Panel->Controls->Add(this->NomActual_TextBox);
			this->Editar_Panel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Editar_Panel->Location = System::Drawing::Point(179, 122);
			this->Editar_Panel->Name = L"Editar_Panel";
			this->Editar_Panel->Size = System::Drawing::Size(454, 324);
			this->Editar_Panel->TabIndex = 4;
			// 
			// noModificarButton
			// 
			this->noModificarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->noModificarButton->BackColor = System::Drawing::Color::Transparent;
			this->noModificarButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->noModificarButton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->noModificarButton->ForeColor = System::Drawing::Color::Red;
			this->noModificarButton->Location = System::Drawing::Point(30, 253);
			this->noModificarButton->Name = L"noModificarButton";
			this->noModificarButton->Size = System::Drawing::Size(98, 35);
			this->noModificarButton->TabIndex = 6;
			this->noModificarButton->Text = L"Cancel�la";
			this->noModificarButton->UseVisualStyleBackColor = true;
			this->noModificarButton->Visible = false;
			this->noModificarButton->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::noModificarButton_Click);
			// 
			// Edita_Button
			// 
			this->Edita_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Edita_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Edita_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Edita_Button->Location = System::Drawing::Point(324, 253);
			this->Edita_Button->Name = L"Edita_Button";
			this->Edita_Button->Size = System::Drawing::Size(99, 35);
			this->Edita_Button->TabIndex = 7;
			this->Edita_Button->Text = L"Modifica";
			this->Edita_Button->UseVisualStyleBackColor = true;
			this->Edita_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::testEdita_Button);
			// 
			// EditarDescripcio_TextBox
			// 
			this->EditarDescripcio_TextBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarDescripcio_TextBox->Location = System::Drawing::Point(31, 120);
			this->EditarDescripcio_TextBox->MaxLength = 111;
			this->EditarDescripcio_TextBox->Multiline = true;
			this->EditarDescripcio_TextBox->Name = L"EditarDescripcio_TextBox";
			this->EditarDescripcio_TextBox->Size = System::Drawing::Size(392, 93);
			this->EditarDescripcio_TextBox->TabIndex = 5;
			// 
			// Descripcio_Label
			// 
			this->Descripcio_Label->AutoSize = true;
			this->Descripcio_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Descripcio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Descripcio_Label->Location = System::Drawing::Point(27, 98);
			this->Descripcio_Label->Name = L"Descripcio_Label";
			this->Descripcio_Label->Size = System::Drawing::Size(158, 19);
			this->Descripcio_Label->TabIndex = 4;
			this->Descripcio_Label->Text = L"Descripci� del grup";
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(687, 485);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(89, 35);
			this->Cancelar_Button->TabIndex = 6;
			this->Cancelar_Button->Text = L"Tornar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::CancelarButton_Click);
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-5, 555);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(928, 265);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 15;
			this->Background_PictureBox->TabStop = false;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->EditarGrupEstudi_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->Editar_Panel, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.80819F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.34264F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.7045F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 16;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_EditarUI::tableLayoutPanel1_Paint);
			// 
			// GrupEstudi_EditarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Background_PictureBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GrupEstudi_EditarUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::GrupEstudi_EditarUI_Load);
			this->Editar_Panel->ResumeLayout(false);
			this->Editar_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void CancelarButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void testEdita_Button(System::Object^ sender, System::EventArgs^ e);
private: System::Void noModificarButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GrupEstudi_EditarUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EduConnect_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void EditarGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void Nom_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

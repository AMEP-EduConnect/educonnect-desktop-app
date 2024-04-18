#pragma once
#include "GrupEstudi.h"
#include "GrupEstudiMembership.h"
#include "GrupEstudiMembershipService.h"
#include "GrupEstudiService.h"
#include <vector>
#include "Usuari.h"
#include "CurrentSession.h"
#include "MessageManager.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_AssignarUI
	/// </summary>
	public ref class GrupEstudi_AssignarUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_AssignarUI(String^ nomsListBox);

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~GrupEstudi_AssignarUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ AssignarGrupEstudi_Label;
	private: System::Windows::Forms::TextBox^ NomUsuari_TextBox;
	private: System::Windows::Forms::Label^ NomUsuari_Label;
	private: System::Windows::Forms::Panel^ Assignar_Panel;
	private: System::Windows::Forms::TextBox^ NomGrup_TextBox;
	private: System::Windows::Forms::Label^ NomGrup_Label;
	private: System::Windows::Forms::Button^ Assigna_Button;

	private: System::Windows::Forms::Button^ Cancelar_Button;


	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: GrupEstudiService^ grupEstudiService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: String^ Noms_ListBox;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AssignarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->NomUsuari_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			this->Assignar_Panel = (gcnew System::Windows::Forms::Panel());
			this->Assigna_Button = (gcnew System::Windows::Forms::Button());
			this->NomGrup_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NomGrup_Label = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Assignar_Panel->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// AssignarGrupEstudi_Label
			// 
			this->AssignarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AssignarGrupEstudi_Label->AutoSize = true;
			this->AssignarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AssignarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AssignarGrupEstudi_Label->Location = System::Drawing::Point(148, 44);
			this->AssignarGrupEstudi_Label->Name = L"AssignarGrupEstudi_Label";
			this->AssignarGrupEstudi_Label->Size = System::Drawing::Size(429, 31);
			this->AssignarGrupEstudi_Label->TabIndex = 2;
			this->AssignarGrupEstudi_Label->Text = L"Assigna Membres Grup d\'Estudi";
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NomUsuari_TextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->NomUsuari_TextBox->Location = System::Drawing::Point(38, 110);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(195, 20);
			this->NomUsuari_TextBox->TabIndex = 3;
			// 
			// NomUsuari_Label
			// 
			this->NomUsuari_Label->AutoSize = true;
			this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomUsuari_Label->Location = System::Drawing::Point(35, 91);
			this->NomUsuari_Label->Name = L"NomUsuari_Label";
			this->NomUsuari_Label->Size = System::Drawing::Size(118, 16);
			this->NomUsuari_Label->TabIndex = 1;
			this->NomUsuari_Label->Text = L"Nom del estudiant:";
			// 
			// Assignar_Panel
			// 
			this->Assignar_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Assignar_Panel->Controls->Add(this->Assigna_Button);
			this->Assignar_Panel->Controls->Add(this->NomGrup_TextBox);
			this->Assignar_Panel->Controls->Add(this->NomGrup_Label);
			this->Assignar_Panel->Controls->Add(this->NomUsuari_TextBox);
			this->Assignar_Panel->Controls->Add(this->NomUsuari_Label);
			this->Assignar_Panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Assignar_Panel->Location = System::Drawing::Point(138, 123);
			this->Assignar_Panel->Name = L"Assignar_Panel";
			this->Assignar_Panel->Size = System::Drawing::Size(449, 206);
			this->Assignar_Panel->TabIndex = 6;
			// 
			// Assigna_Button
			// 
			this->Assigna_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Assigna_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Assigna_Button->Location = System::Drawing::Point(38, 158);
			this->Assigna_Button->Name = L"Assigna_Button";
			this->Assigna_Button->Size = System::Drawing::Size(75, 23);
			this->Assigna_Button->TabIndex = 8;
			this->Assigna_Button->Text = L"Assignar";
			this->Assigna_Button->UseVisualStyleBackColor = true;
			this->Assigna_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::AssignaButton_Click);
			// 
			// NomGrup_TextBox
			// 
			this->NomGrup_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NomGrup_TextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->NomGrup_TextBox->Location = System::Drawing::Point(38, 41);
			this->NomGrup_TextBox->Name = L"NomGrup_TextBox";
			this->NomGrup_TextBox->ReadOnly = true;
			this->NomGrup_TextBox->Size = System::Drawing::Size(195, 20);
			this->NomGrup_TextBox->TabIndex = 5;
			// 
			// NomGrup_Label
			// 
			this->NomGrup_Label->AutoSize = true;
			this->NomGrup_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomGrup_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomGrup_Label->Location = System::Drawing::Point(35, 22);
			this->NomGrup_Label->Name = L"NomGrup_Label";
			this->NomGrup_Label->Size = System::Drawing::Size(91, 16);
			this->NomGrup_Label->TabIndex = 4;
			this->NomGrup_Label->Text = L"Nom del grup:";
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(656, 403);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(75, 23);
			this->Cancelar_Button->TabIndex = 7;
			this->Cancelar_Button->Text = L"Cancelar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::CancelarButton_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				22.90862F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				77.09138F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				207)));
			this->tableLayoutPanel1->Controls->Add(this->Assignar_Panel, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->AssignarGrupEstudi_Label, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 36.12566F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 63.87434F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 165)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(798, 498);
			this->tableLayoutPanel1->TabIndex = 8;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_AssignarUI::tableLayoutPanel1_Paint);
			// 
			// GrupEstudi_AssignarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(798, 498);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"GrupEstudi_AssignarUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::GrupEstudi_AssignarUI_Load);
			this->Assignar_Panel->ResumeLayout(false);
			this->Assignar_Panel->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void CancelarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AssignaButton_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void GrupEstudi_AssignarUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}

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

	private: System::Windows::Forms::Label^ NomUsuari_Label;
	private: System::Windows::Forms::Panel^ Assignar_Panel;


	private: System::Windows::Forms::Button^ Assigna_Button;

	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: String^ Username;
	private: String^ groupName;

	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: GrupEstudiService^ grupEstudiService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::TextBox^ buscador_textBox;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ListBox^ Noms_ListBox;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->AssignarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			   this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			   this->Assignar_Panel = (gcnew System::Windows::Forms::Panel());
			   this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			   this->Assigna_Button = (gcnew System::Windows::Forms::Button());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->buscador_textBox = (gcnew System::Windows::Forms::TextBox());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->Assignar_Panel->SuspendLayout();
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // AssignarGrupEstudi_Label
			   // 
			   this->AssignarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->AssignarGrupEstudi_Label->AutoSize = true;
			   this->AssignarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->AssignarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->AssignarGrupEstudi_Label->Location = System::Drawing::Point(247, 20);
			   this->AssignarGrupEstudi_Label->Name = L"AssignarGrupEstudi_Label";
			   this->AssignarGrupEstudi_Label->Size = System::Drawing::Size(301, 33);
			   this->AssignarGrupEstudi_Label->TabIndex = 2;
			   this->AssignarGrupEstudi_Label->Text = L"Convidar Membre a \"\"";
			   this->AssignarGrupEstudi_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   // 
			   // NomUsuari_Label
			   // 
			   this->NomUsuari_Label->AutoSize = true;
			   this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->NomUsuari_Label->Location = System::Drawing::Point(58, 13);
			   this->NomUsuari_Label->Name = L"NomUsuari_Label";
			   this->NomUsuari_Label->Size = System::Drawing::Size(350, 19);
			   this->NomUsuari_Label->TabIndex = 1;
			   this->NomUsuari_Label->Text = L"Selecciona l\'estudiant que vols afegir al grup";
			   // 
			   // Assignar_Panel
			   // 
			   this->Assignar_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Assignar_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Assignar_Panel->Controls->Add(this->Noms_ListBox);
			   this->Assignar_Panel->Location = System::Drawing::Point(11, 44);
			   this->Assignar_Panel->Name = L"Assignar_Panel";
			   this->Assignar_Panel->Size = System::Drawing::Size(450, 258);
			   this->Assignar_Panel->TabIndex = 6;
			   // 
			   // Noms_ListBox
			   // 
			   this->Noms_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Noms_ListBox->FormattingEnabled = true;
			   this->Noms_ListBox->ItemHeight = 19;
			   this->Noms_ListBox->Location = System::Drawing::Point(12, 13);
			   this->Noms_ListBox->Name = L"Noms_ListBox";
			   this->Noms_ListBox->Size = System::Drawing::Size(424, 232);
			   this->Noms_ListBox->TabIndex = 23;
			   this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::listBox_SelectedIndexChanged);
			   // 
			   // Assigna_Button
			   // 
			   this->Assigna_Button->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->Assigna_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Assigna_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Assigna_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Assigna_Button->Location = System::Drawing::Point(549, 456);
			   this->Assigna_Button->Name = L"Assigna_Button";
			   this->Assigna_Button->Size = System::Drawing::Size(85, 35);
			   this->Assigna_Button->TabIndex = 8;
			   this->Assigna_Button->Text = L"Assignar";
			   this->Assigna_Button->UseVisualStyleBackColor = true;
			   this->Assigna_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::AssignaButton_Click);
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(674, 456);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(87, 35);
			   this->Cancelar_Button->TabIndex = 7;
			   this->Cancelar_Button->Text = L"Cancelar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::CancelarButton_Click);
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
			   this->tableLayoutPanel1->Controls->Add(this->AssignarGrupEstudi_Label, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->buscador_textBox, 1, 1);
			   this->tableLayoutPanel1->Controls->Add(this->panel1, 1, 2);
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 3);
			   this->tableLayoutPanel1->Controls->Add(this->Assigna_Button, 1, 3);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 4;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.85944F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.04016F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 65.26105F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.638555F)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(798, 498);
			   this->tableLayoutPanel1->TabIndex = 8;
			   this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_AssignarUI::tableLayoutPanel1_Paint);
			   // 
			   // buscador_textBox
			   // 
			   this->buscador_textBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->buscador_textBox->BackColor = System::Drawing::SystemColors::Window;
			   this->buscador_textBox->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->buscador_textBox->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			   this->buscador_textBox->Location = System::Drawing::Point(206, 85);
			   this->buscador_textBox->Margin = System::Windows::Forms::Padding(2);
			   this->buscador_textBox->Name = L"buscador_textBox";
			   this->buscador_textBox->Size = System::Drawing::Size(383, 27);
			   this->buscador_textBox->TabIndex = 22;
			   this->buscador_textBox->Text = L"Buscar Usuari...";
			   this->buscador_textBox->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::buscador_textBox_Click);
			   this->buscador_textBox->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::buscador_textBox_TextChanged);
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->Controls->Add(this->NomUsuari_Label);
			   this->panel1->Controls->Add(this->Assignar_Panel);
			   this->panel1->Location = System::Drawing::Point(162, 129);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(472, 314);
			   this->panel1->TabIndex = 9;
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
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void CancelarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AssignaButton_Click(System::Object^ sender, System::EventArgs^ e);

		   Void buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e);

		   Void GEstudiAssignarAdminUI_Load(System::Object^ sender, System::EventArgs^ e);

		   Void buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e);

		   Void listBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);


	private: System::Void GrupEstudi_AssignarUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	};
}

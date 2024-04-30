#pragma once
#include "GrupEstudiService.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembership.h"
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "Usuari.h"
#include "CurrentSession.h"
#include "GrupEstudi_EditarUI.h"
#include "MessageManager.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de GrupEstudi_ConsultarUI
	/// </summary>
	public ref class GrupEstudi_ConsultarUI : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_ConsultarUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~GrupEstudi_ConsultarUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ ConsultarGrupEstudi_Label;
	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::Label^ NomPertany_Label;


	private: System::Windows::Forms::Label^ Pertany_Label;
	private: System::Windows::Forms::ListBox^ Noms_ListBox;



	private: System::Windows::Forms::Button^ Eliminar_Button;
	private: System::Windows::Forms::Button^ Editar_Button;



	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ consulta_membres;
	private: System::Windows::Forms::Button^ abandonar_button;






	private: GrupEstudiService^ grupEstudiService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ConsultarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			this->abandonar_button = (gcnew System::Windows::Forms::Button());
			this->consulta_membres = (gcnew System::Windows::Forms::Button());
			this->Eliminar_Button = (gcnew System::Windows::Forms::Button());
			this->Editar_Button = (gcnew System::Windows::Forms::Button());
			this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->NomPertany_Label = (gcnew System::Windows::Forms::Label());
			this->Pertany_Label = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Actual_Panel->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ConsultarGrupEstudi_Label
			// 
			this->ConsultarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsultarGrupEstudi_Label->AutoSize = true;
			this->ConsultarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConsultarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->ConsultarGrupEstudi_Label->Location = System::Drawing::Point(242, 37);
			this->ConsultarGrupEstudi_Label->Name = L"ConsultarGrupEstudi_Label";
			this->ConsultarGrupEstudi_Label->Size = System::Drawing::Size(328, 33);
			this->ConsultarGrupEstudi_Label->TabIndex = 2;
			this->ConsultarGrupEstudi_Label->Text = L"Els meus grups d\'Estudi";
			// 
			// Actual_Panel
			// 
			this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Actual_Panel->Controls->Add(this->abandonar_button);
			this->Actual_Panel->Controls->Add(this->consulta_membres);
			this->Actual_Panel->Controls->Add(this->Eliminar_Button);
			this->Actual_Panel->Controls->Add(this->Editar_Button);
			this->Actual_Panel->Controls->Add(this->Noms_ListBox);
			this->Actual_Panel->Controls->Add(this->NomPertany_Label);
			this->Actual_Panel->Controls->Add(this->Pertany_Label);
			this->Actual_Panel->Location = System::Drawing::Point(165, 111);
			this->Actual_Panel->Name = L"Actual_Panel";
			this->Actual_Panel->Size = System::Drawing::Size(482, 319);
			this->Actual_Panel->TabIndex = 6;
			// 
			// abandonar_button
			// 
			this->abandonar_button->Location = System::Drawing::Point(146, 273);
			this->abandonar_button->Margin = System::Windows::Forms::Padding(4);
			this->abandonar_button->Name = L"abandonar_button";
			this->abandonar_button->Size = System::Drawing::Size(75, 23);
			this->abandonar_button->TabIndex = 10;
			this->abandonar_button->Text = L"Abandonar";
			this->abandonar_button->UseVisualStyleBackColor = true;
			this->abandonar_button->Visible = false;
			this->abandonar_button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::abandonar_button_Click);
			// 
			// consulta_membres
			// 
			this->consulta_membres->Location = System::Drawing::Point(63, 273);
			this->consulta_membres->Margin = System::Windows::Forms::Padding(4);
			this->consulta_membres->Name = L"consulta_membres";
			this->consulta_membres->Size = System::Drawing::Size(75, 23);
			this->consulta_membres->TabIndex = 9;
			this->consulta_membres->Text = L"Membres";
			this->consulta_membres->UseVisualStyleBackColor = true;
			this->consulta_membres->Visible = false;
			this->consulta_membres->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::consulta_membres_Click);
			// 
			// Eliminar_Button
			// 
			this->Eliminar_Button->Location = System::Drawing::Point(257, 273);
			this->Eliminar_Button->Name = L"Eliminar_Button";
			this->Eliminar_Button->Size = System::Drawing::Size(75, 23);
			this->Eliminar_Button->TabIndex = 9;
			this->Eliminar_Button->Text = L"Elimina";
			this->Eliminar_Button->UseVisualStyleBackColor = true;
			this->Eliminar_Button->Visible = false;
			this->Eliminar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::EliminarButton_Click);
			// 
			// Editar_Button
			// 
			this->Editar_Button->Location = System::Drawing::Point(338, 273);
			this->Editar_Button->Name = L"Editar_Button";
			this->Editar_Button->Size = System::Drawing::Size(75, 23);
			this->Editar_Button->TabIndex = 8;
			this->Editar_Button->Text = L"Edita";
			this->Editar_Button->UseVisualStyleBackColor = true;
			this->Editar_Button->Visible = false;
			this->Editar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::EditarButton_Click);
			// 
			// Noms_ListBox
			// 
			this->Noms_ListBox->BackColor = System::Drawing::SystemColors::Window;
			this->Noms_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Noms_ListBox->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Noms_ListBox->FormattingEnabled = true;
			this->Noms_ListBox->IntegralHeight = false;
			this->Noms_ListBox->ItemHeight = 19;
			this->Noms_ListBox->Location = System::Drawing::Point(63, 83);
			this->Noms_ListBox->Name = L"Noms_ListBox";
			this->Noms_ListBox->Size = System::Drawing::Size(350, 171);
			this->Noms_ListBox->TabIndex = 2;
			this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::Noms_ListBox_SelectedIndexChanged);
			// 
			// NomPertany_Label
			// 
			this->NomPertany_Label->AutoSize = true;
			this->NomPertany_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomPertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomPertany_Label->Location = System::Drawing::Point(59, 60);
			this->NomPertany_Label->Name = L"NomPertany_Label";
			this->NomPertany_Label->Size = System::Drawing::Size(45, 19);
			this->NomPertany_Label->TabIndex = 1;
			this->NomPertany_Label->Text = L"Nom";
			// 
			// Pertany_Label
			// 
			this->Pertany_Label->AutoSize = true;
			this->Pertany_Label->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Pertany_Label->Location = System::Drawing::Point(59, 23);
			this->Pertany_Label->Name = L"Pertany_Label";
			this->Pertany_Label->Size = System::Drawing::Size(232, 19);
			this->Pertany_Label->TabIndex = 0;
			this->Pertany_Label->Text = L"Grups d\'Estudi que pertanys";
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
			this->tableLayoutPanel1->Controls->Add(this->ConsultarGrupEstudi_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 103)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			this->tableLayoutPanel1->TabIndex = 7;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_ConsultarUI::tableLayoutPanel1_Paint);
			// 
			// GrupEstudi_ConsultarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 537);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GrupEstudi_ConsultarUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load);
			this->Actual_Panel->ResumeLayout(false);
			this->Actual_Panel->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EliminarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditarButton_Click(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void consulta_membres_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void abandonar_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: void GrupEstudi_ConsultarUIreload();
	private: System::Void CrearGrupEstudi_Click(System::Object^ sender, System::EventArgs^ e);

};
}

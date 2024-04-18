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
	/// Resumen de GrupEstudi_Membres
	/// </summary>
	public ref class GrupEstudi_Membres : public System::Windows::Forms::Form
	{
	public:
		GrupEstudi_Membres(String^ nomsListBox);

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~GrupEstudi_Membres()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ ConsultarGrupEstudi_Label;
	private: System::Windows::Forms::Panel^ Panel_Membres;
	private: System::Windows::Forms::Button^ Assignar_Button;
	private: System::Windows::Forms::Button^ Expulsar_Button;




	private: System::Windows::Forms::ListBox^ Membres_Box;

	private: System::Windows::Forms::Label^ Membres_GE2;

	private: System::Windows::Forms::Label^ Membres_GE;

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ Cancelar_Button;

	private: GrupEstudiService^ grupEstudiService;
	private: String^ Noms_ListBox;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->ConsultarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			   this->Panel_Membres = (gcnew System::Windows::Forms::Panel());
			   this->Assignar_Button = (gcnew System::Windows::Forms::Button());
			   this->Expulsar_Button = (gcnew System::Windows::Forms::Button());
			   this->Membres_Box = (gcnew System::Windows::Forms::ListBox());
			   this->Membres_GE2 = (gcnew System::Windows::Forms::Label());
			   this->Membres_GE = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->Panel_Membres->SuspendLayout();
			   this->tableLayoutPanel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // ConsultarGrupEstudi_Label
			   // 
			   this->ConsultarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->ConsultarGrupEstudi_Label->AutoSize = true;
			   this->ConsultarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ConsultarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->ConsultarGrupEstudi_Label->Location = System::Drawing::Point(159, 36);
			   this->ConsultarGrupEstudi_Label->Name = L"ConsultarGrupEstudi_Label";
			   this->ConsultarGrupEstudi_Label->Size = System::Drawing::Size(451, 31);
			   this->ConsultarGrupEstudi_Label->TabIndex = 5;
			   this->ConsultarGrupEstudi_Label->Text = L"Consultar Membres Grup d\'Estudi";
			   this->ConsultarGrupEstudi_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::ConsultarGrupEstudi_Label_Click);
			   // 
			   // Panel_Membres
			   // 
			   this->Panel_Membres->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Panel_Membres->Controls->Add(this->Assignar_Button);
			   this->Panel_Membres->Controls->Add(this->Expulsar_Button);
			   this->Panel_Membres->Controls->Add(this->Membres_Box);
			   this->Panel_Membres->Controls->Add(this->Membres_GE2);
			   this->Panel_Membres->Controls->Add(this->Membres_GE);
			   this->Panel_Membres->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->Panel_Membres->Location = System::Drawing::Point(141, 106);
			   this->Panel_Membres->Name = L"Panel_Membres";
			   this->Panel_Membres->Size = System::Drawing::Size(487, 316);
			   this->Panel_Membres->TabIndex = 7;
			   // 
			   // Assignar_Button
			   // 
			   this->Assignar_Button->Location = System::Drawing::Point(63, 273);
			   this->Assignar_Button->Name = L"Assignar_Button";
			   this->Assignar_Button->Size = System::Drawing::Size(75, 23);
			   this->Assignar_Button->TabIndex = 9;
			   this->Assignar_Button->Text = L"Assignar";
			   this->Assignar_Button->UseVisualStyleBackColor = true;
			   this->Assignar_Button->Visible = false;
			   this->Assignar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::Assignar_Button_Click);
			   // 
			   // Expulsar_Button
			   // 
			   this->Expulsar_Button->Location = System::Drawing::Point(338, 273);
			   this->Expulsar_Button->Name = L"Expulsar_Button";
			   this->Expulsar_Button->Size = System::Drawing::Size(75, 23);
			   this->Expulsar_Button->TabIndex = 8;
			   this->Expulsar_Button->Text = L"Expulsar";
			   this->Expulsar_Button->UseVisualStyleBackColor = true;
			   this->Expulsar_Button->Visible = false;
			   this->Expulsar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::Expulsar_Button_Click);
			   // 
			   // Membres_Box
			   // 
			   this->Membres_Box->BackColor = System::Drawing::Color::Lavender;
			   this->Membres_Box->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->Membres_Box->FormattingEnabled = true;
			   this->Membres_Box->IntegralHeight = false;
			   this->Membres_Box->Location = System::Drawing::Point(63, 83);
			   this->Membres_Box->Name = L"Membres_Box";
			   this->Membres_Box->Size = System::Drawing::Size(350, 171);
			   this->Membres_Box->TabIndex = 2;
			   this->Membres_Box->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_Membres::Membres_Box_SelectedIndexChanged);
			   // 
			   // Membres_GE2
			   // 
			   this->Membres_GE2->AutoSize = true;
			   this->Membres_GE2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Membres_GE2->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Membres_GE2->Location = System::Drawing::Point(60, 55);
			   this->Membres_GE2->Name = L"Membres_GE2";
			   this->Membres_GE2->Size = System::Drawing::Size(129, 16);
			   this->Membres_GE2->TabIndex = 1;
			   this->Membres_GE2->Text = L"Nom dels integrants:";
			   // 
			   // Membres_GE
			   // 
			   this->Membres_GE->AutoSize = true;
			   this->Membres_GE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Membres_GE->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Membres_GE->Location = System::Drawing::Point(40, 29);
			   this->Membres_GE->Name = L"Membres_GE";
			   this->Membres_GE->Size = System::Drawing::Size(308, 16);
			   this->Membres_GE->TabIndex = 0;
			   this->Membres_GE->Text = L"Membres del Grups d\'Estudis que pertanys:";
			   this->Membres_GE->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::Pertany_Label_Click);
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 3;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   21.92429F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   78.07571F)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				   182)));
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			   this->tableLayoutPanel1->Controls->Add(this->ConsultarGrupEstudi_Label, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->Panel_Membres, 1, 1);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.23529F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75.76471F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 111)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 8;
			   this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_Membres::tableLayoutPanel1_Paint);
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(635, 429);
			   this->Cancelar_Button->Margin = System::Windows::Forms::Padding(4);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(100, 28);
			   this->Cancelar_Button->TabIndex = 7;
			   this->Cancelar_Button->Text = L"Cancelar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::CancelButton_Click);
			   // 
			   // GrupEstudi_Membres
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"GrupEstudi_Membres";
			   this->Text = L"GrupEstudi_Membres";
			   this->Load += gcnew System::EventHandler(this, &GrupEstudi_Membres::GrupEstudi_Membres_Load);
			   this->Panel_Membres->ResumeLayout(false);
			   this->Panel_Membres->PerformLayout();
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void ConsultarGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void Pertany_Label_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void GrupEstudi_Membres_Load(System::Object^ sender, System::EventArgs^ e);
	private: void GrupEstudi_Membresreload();
	private: System::Void Membres_Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Assignar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Expulsar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e);



	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
};
}

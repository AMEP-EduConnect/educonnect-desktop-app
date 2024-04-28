#pragma once

#include "Espais.h"
#include "CurrentSession.h"
#include "ConsultaEspaisService.h"
#include "MessageManager.h"
#include "MainPageUI.h"
#include "AdministradorUI.h"
//#include "ModificarEspaiUI.h"
#include "AltaEspaisUI.h"
#include "EliminarEspaisService.h"
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class ConsultaEspaisUI : public System::Windows::Forms::Form
	{
	public:
		ConsultaEspaisUI(void) {
			InitializeComponent();
			consultaEspaisService = gcnew ConsultaEspaisService();
			eliminarEspaisService = gcnew EliminarEspaisService();
			this->Load += gcnew System::EventHandler(this, &ConsultaEspaisUI::LoadEspaisList);
			this->Icon = gcnew System::Drawing::Icon("app.ico");
		}




	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~ConsultaEspaisUI()
		{
			if (components)
			{
				delete components;
			}
		}



	private: ConsultaEspaisService^ consultaEspaisService;
	private: EliminarEspaisService^ eliminarEspaisService;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>

	private: System::Windows::Forms::Label^ PageTitleLabel;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::Windows::Forms::ListBox^ Llista_Espais;
	private: System::Windows::Forms::Button^ GestioEspaiButton;


	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::Label^ BaixaProveidorLabel;
	private: System::Windows::Forms::Label^ Pertany_Label;
	private: System::Windows::Forms::Button^ ButtonEliminar;


		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->PageTitleLabel = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			   this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			   this->GestioEspaiButton = (gcnew System::Windows::Forms::Button());
			   this->BaixaProveidorLabel = (gcnew System::Windows::Forms::Label());
			   this->Pertany_Label = (gcnew System::Windows::Forms::Label());
			   this->Llista_Espais = (gcnew System::Windows::Forms::ListBox());
			   this->ButtonEliminar = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->Actual_Panel->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // PageTitleLabel
			   // 
			   this->PageTitleLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->PageTitleLabel->AutoSize = true;
			   this->PageTitleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PageTitleLabel->Location = System::Drawing::Point(293, 24);
			   this->PageTitleLabel->Name = L"PageTitleLabel";
			   this->PageTitleLabel->Size = System::Drawing::Size(226, 31);
			   this->PageTitleLabel->TabIndex = 13;
			   this->PageTitleLabel->Text = L"Consulta Espais";
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
			   this->tableLayoutPanel1->Controls->Add(this->Cancelar_Button, 2, 2);
			   this->tableLayoutPanel1->Controls->Add(this->PageTitleLabel, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			   this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 3;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.12104F)));
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 29.98138F)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel1->TabIndex = 14;
			   // 
			   // Cancelar_Button
			   // 
			   this->Cancelar_Button->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			   this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Cancelar_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			   this->Cancelar_Button->Location = System::Drawing::Point(688, 439);
			   this->Cancelar_Button->Name = L"Cancelar_Button";
			   this->Cancelar_Button->Size = System::Drawing::Size(88, 34);
			   this->Cancelar_Button->TabIndex = 15;
			   this->Cancelar_Button->Text = L"Cancelar";
			   this->Cancelar_Button->UseVisualStyleBackColor = false;
			   this->Cancelar_Button->Click += gcnew System::EventHandler(this, &ConsultaEspaisUI::Cancelar_Button_Click);
			   // 
			   // Actual_Panel
			   // 
			   this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Actual_Panel->Controls->Add(this->ButtonEliminar);
			   this->Actual_Panel->Controls->Add(this->GestioEspaiButton);
			   this->Actual_Panel->Controls->Add(this->BaixaProveidorLabel);
			   this->Actual_Panel->Controls->Add(this->Pertany_Label);
			   this->Actual_Panel->Controls->Add(this->Llista_Espais);
			   this->Actual_Panel->Location = System::Drawing::Point(168, 83);
			   this->Actual_Panel->Name = L"Actual_Panel";
			   this->Actual_Panel->Size = System::Drawing::Size(475, 288);
			   this->Actual_Panel->TabIndex = 17;
			   // 
			   // GestioEspaiButton
			   // 
			   this->GestioEspaiButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->GestioEspaiButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->GestioEspaiButton->Location = System::Drawing::Point(356, 239);
			   this->GestioEspaiButton->Name = L"GestioEspaiButton";
			   this->GestioEspaiButton->Size = System::Drawing::Size(91, 34);
			   this->GestioEspaiButton->TabIndex = 0;
			   this->GestioEspaiButton->Text = L"Gestionar";
			   this->GestioEspaiButton->UseVisualStyleBackColor = true;
			   this->GestioEspaiButton->Click += gcnew System::EventHandler(this, &ConsultaEspaisUI::ButtonGestio_Click);
			   // 
			   // BaixaProveidorLabel
			   // 
			   this->BaixaProveidorLabel->AutoSize = true;
			   this->BaixaProveidorLabel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->BaixaProveidorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->BaixaProveidorLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->BaixaProveidorLabel->Location = System::Drawing::Point(39, 39);
			   this->BaixaProveidorLabel->Name = L"BaixaProveidorLabel";
			   this->BaixaProveidorLabel->Size = System::Drawing::Size(102, 20);
			   this->BaixaProveidorLabel->TabIndex = 7;
			   this->BaixaProveidorLabel->Text = L"Llista Espais:";
			   // 
			   // Pertany_Label
			   // 
			   this->Pertany_Label->AutoSize = true;
			   this->Pertany_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Pertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Pertany_Label->Location = System::Drawing::Point(40, 29);
			   this->Pertany_Label->Name = L"Pertany_Label";
			   this->Pertany_Label->Size = System::Drawing::Size(0, 16);
			   this->Pertany_Label->TabIndex = 0;
			   // 
			   // Llista_Espais
			   // 
			   this->Llista_Espais->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Llista_Espais->BackColor = System::Drawing::Color::Lavender;
			   this->Llista_Espais->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->Llista_Espais->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Llista_Espais->FormattingEnabled = true;
			   this->Llista_Espais->IntegralHeight = false;
			   this->Llista_Espais->ItemHeight = 16;
			   this->Llista_Espais->Location = System::Drawing::Point(43, 66);
			   this->Llista_Espais->Name = L"Llista_Espais";
			   this->Llista_Espais->Size = System::Drawing::Size(390, 156);
			   this->Llista_Espais->TabIndex = 17;
			   // 
			   // ButtonEliminar
			   // 
			   this->ButtonEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ButtonEliminar->ForeColor = System::Drawing::Color::Red;
			   this->ButtonEliminar->Location = System::Drawing::Point(247, 239);
			   this->ButtonEliminar->Name = L"ButtonEliminar";
			   this->ButtonEliminar->Size = System::Drawing::Size(91, 34);
			   this->ButtonEliminar->TabIndex = 18;
			   this->ButtonEliminar->Text = L"Eliminar";
			   this->ButtonEliminar->UseVisualStyleBackColor = true;
			   this->ButtonEliminar->Click += gcnew System::EventHandler(this, &ConsultaEspaisUI::ButtonEliminar_Click);
			   // 
			   // ConsultaEspaisUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel1);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MinimumSize = System::Drawing::Size(814, 537);
			   this->Name = L"ConsultaEspaisUI";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"EduConnect";
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->tableLayoutPanel1->PerformLayout();
			   this->Actual_Panel->ResumeLayout(false);
			   this->Actual_Panel->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void LoadEspaisList(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonGestio_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonEliminar_Click(System::Object^ sender, System::EventArgs^ e);
};
}
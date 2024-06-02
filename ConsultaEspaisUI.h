#pragma once

#include "Espai.h"
#include "CurrentSession.h"
#include "ConsultaEspaisService.h"
#include "MessageManager.h"
#include "MainPageUI.h"
#include "AdministradorUI.h"
#include "ModificaEspaisUI.h"
#include "IniciUI.h"
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
			SetWelcomeMessage();
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




	private: System::Windows::Forms::ListBox^ Llista_Espais;
	private: System::Windows::Forms::Button^ GestioEspaiButton;


	private: System::Windows::Forms::Panel^ Actual_Panel;

	private: System::Windows::Forms::Label^ Pertany_Label;
	private: System::Windows::Forms::Button^ ButtonEliminar;
	private: System::Windows::Forms::Button^ ButtonAltaEspais;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ Benvinguda;


		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// M�todo necesario para admitir el Dise�ador. No se puede modificar
		   /// el contenido de este m�todo con el editor de c�digo.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			   this->ButtonAltaEspais = (gcnew System::Windows::Forms::Button());
			   this->ButtonEliminar = (gcnew System::Windows::Forms::Button());
			   this->Pertany_Label = (gcnew System::Windows::Forms::Label());
			   this->Llista_Espais = (gcnew System::Windows::Forms::ListBox());
			   this->GestioEspaiButton = (gcnew System::Windows::Forms::Button());
			   this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->Benvinguda = (gcnew System::Windows::Forms::Label());
			   this->Actual_Panel->SuspendLayout();
			   this->tableLayoutPanel2->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->panel3->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // Actual_Panel
			   // 
			   this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->Actual_Panel->Controls->Add(this->ButtonAltaEspais);
			   this->Actual_Panel->Controls->Add(this->ButtonEliminar);
			   this->Actual_Panel->Controls->Add(this->Pertany_Label);
			   this->Actual_Panel->Controls->Add(this->Llista_Espais);
			   this->Actual_Panel->Controls->Add(this->GestioEspaiButton);
			   this->Actual_Panel->Location = System::Drawing::Point(101, 86);
			   this->Actual_Panel->Name = L"Actual_Panel";
			   this->Actual_Panel->Size = System::Drawing::Size(541, 314);
			   this->Actual_Panel->TabIndex = 17;
			   // 
			   // ButtonAltaEspais
			   // 
			   this->ButtonAltaEspais->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ButtonAltaEspais->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->ButtonAltaEspais->Location = System::Drawing::Point(14, 269);
			   this->ButtonAltaEspais->Name = L"ButtonAltaEspais";
			   this->ButtonAltaEspais->Size = System::Drawing::Size(91, 34);
			   this->ButtonAltaEspais->TabIndex = 19;
			   this->ButtonAltaEspais->Text = L"Crear";
			   this->ButtonAltaEspais->UseVisualStyleBackColor = true;
			   this->ButtonAltaEspais->Click += gcnew System::EventHandler(this, &ConsultaEspaisUI::ButtonAlta_Click);
			   // 
			   // ButtonEliminar
			   // 
			   this->ButtonEliminar->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ButtonEliminar->ForeColor = System::Drawing::Color::Red;
			   this->ButtonEliminar->Location = System::Drawing::Point(436, 269);
			   this->ButtonEliminar->Name = L"ButtonEliminar";
			   this->ButtonEliminar->Size = System::Drawing::Size(91, 34);
			   this->ButtonEliminar->TabIndex = 18;
			   this->ButtonEliminar->Text = L"Eliminar";
			   this->ButtonEliminar->UseVisualStyleBackColor = true;
			   this->ButtonEliminar->Click += gcnew System::EventHandler(this, &ConsultaEspaisUI::ButtonEliminar_Click);
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
			   this->Llista_Espais->BackColor = System::Drawing::SystemColors::Window;
			   this->Llista_Espais->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Llista_Espais->FormattingEnabled = true;
			   this->Llista_Espais->IntegralHeight = false;
			   this->Llista_Espais->ItemHeight = 19;
			   this->Llista_Espais->Location = System::Drawing::Point(14, 10);
			   this->Llista_Espais->Name = L"Llista_Espais";
			   this->Llista_Espais->Size = System::Drawing::Size(511, 251);
			   this->Llista_Espais->TabIndex = 17;
			   // 
			   // GestioEspaiButton
			   // 
			   this->GestioEspaiButton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->GestioEspaiButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->GestioEspaiButton->Location = System::Drawing::Point(339, 269);
			   this->GestioEspaiButton->Name = L"GestioEspaiButton";
			   this->GestioEspaiButton->Size = System::Drawing::Size(91, 34);
			   this->GestioEspaiButton->TabIndex = 0;
			   this->GestioEspaiButton->Text = L"Gestionar";
			   this->GestioEspaiButton->UseVisualStyleBackColor = true;
			   this->GestioEspaiButton->Click += gcnew System::EventHandler(this, &ConsultaEspaisUI::ButtonGestio_Click);
			   // 
			   // tableLayoutPanel2
			   // 
			   this->tableLayoutPanel2->ColumnCount = 2;
			   this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   3.931204F)));
			   this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   96.06879F)));
			   this->tableLayoutPanel2->Controls->Add(this->panel2, 1, 1);
			   this->tableLayoutPanel2->Controls->Add(this->panel3, 1, 0);
			   this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			   this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			   this->tableLayoutPanel2->RowCount = 2;
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.03538F)));
			   this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.96461F)));
			   this->tableLayoutPanel2->Size = System::Drawing::Size(814, 537);
			   this->tableLayoutPanel2->TabIndex = 15;
			   // 
			   // panel2
			   // 
			   this->panel2->Controls->Add(this->label6);
			   this->panel2->Controls->Add(this->Actual_Panel);
			   this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->panel2->Location = System::Drawing::Point(35, 73);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(776, 461);
			   this->panel2->TabIndex = 1;
			   // 
			   // label6
			   // 
			   this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Inter Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->label6->Location = System::Drawing::Point(262, 24);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(217, 33);
			   this->label6->TabIndex = 14;
			   this->label6->Text = L"Els meus espais";
			   // 
			   // panel3
			   // 
			   this->panel3->Controls->Add(this->Benvinguda);
			   this->panel3->Location = System::Drawing::Point(35, 3);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(455, 64);
			   this->panel3->TabIndex = 3;
			   // 
			   // Benvinguda
			   // 
			   this->Benvinguda->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->Benvinguda->AutoSize = true;
			   this->Benvinguda->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Benvinguda->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->Benvinguda->Location = System::Drawing::Point(0, 15);
			   this->Benvinguda->Name = L"Benvinguda";
			   this->Benvinguda->Size = System::Drawing::Size(172, 33);
			   this->Benvinguda->TabIndex = 0;
			   this->Benvinguda->Text = L"Benvinguda";
			   // 
			   // ConsultaEspaisUI
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(814, 537);
			   this->Controls->Add(this->tableLayoutPanel2);
			   this->ForeColor = System::Drawing::SystemColors::HotTrack;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->MinimumSize = System::Drawing::Size(814, 537);
			   this->Name = L"ConsultaEspaisUI";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			   this->Text = L"EduConnect";
			   this->Actual_Panel->ResumeLayout(false);
			   this->Actual_Panel->PerformLayout();
			   this->tableLayoutPanel2->ResumeLayout(false);
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void LoadEspaisList(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonGestio_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonEliminar_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ButtonAlta_Click(System::Object^ sender, System::EventArgs^ e);
		   Void SetWelcomeMessage();
};
}
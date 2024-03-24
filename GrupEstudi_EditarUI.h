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
		GrupEstudi_EditarUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudi_EditarUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Editar_Grup_Estudi_TITULO;
	protected:

	private: System::Windows::Forms::Label^ EduConnect_TITULO;
	private: System::Windows::Forms::TextBox^ textBox_NomEditar;

	private: System::Windows::Forms::Label^ Nom_TITULO;
	private: System::Windows::Forms::Panel^ panel_Editar;
	private: System::Windows::Forms::TextBox^ textBox_DescripcioEditar;


	private: System::Windows::Forms::Label^ Despcripción_TITULO;
	private: System::Windows::Forms::Label^ editar_TITULO;
	private: System::Windows::Forms::Panel^ panel_ACTUAL;


	private: System::Windows::Forms::Label^ actual_TITULO;
	private: System::Windows::Forms::Label^ nom_Actual;



	private: System::Windows::Forms::TextBox^ textBox_NomActual;
	private: System::Windows::Forms::Button^ button_Edita;
	private: System::Windows::Forms::Button^ button_Cancelar;
	private: GrupEstudiService^ grupEstudiService;




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
			this->Editar_Grup_Estudi_TITULO = (gcnew System::Windows::Forms::Label());
			this->EduConnect_TITULO = (gcnew System::Windows::Forms::Label());
			this->textBox_NomEditar = (gcnew System::Windows::Forms::TextBox());
			this->Nom_TITULO = (gcnew System::Windows::Forms::Label());
			this->panel_Editar = (gcnew System::Windows::Forms::Panel());
			this->button_Edita = (gcnew System::Windows::Forms::Button());
			this->editar_TITULO = (gcnew System::Windows::Forms::Label());
			this->textBox_DescripcioEditar = (gcnew System::Windows::Forms::TextBox());
			this->Despcripción_TITULO = (gcnew System::Windows::Forms::Label());
			this->panel_ACTUAL = (gcnew System::Windows::Forms::Panel());
			this->textBox_NomActual = (gcnew System::Windows::Forms::TextBox());
			this->nom_Actual = (gcnew System::Windows::Forms::Label());
			this->actual_TITULO = (gcnew System::Windows::Forms::Label());
			this->button_Cancelar = (gcnew System::Windows::Forms::Button());
			this->panel_Editar->SuspendLayout();
			this->panel_ACTUAL->SuspendLayout();
			this->SuspendLayout();
			// 
			// Editar_Grup_Estudi_TITULO
			// 
			this->Editar_Grup_Estudi_TITULO->AutoSize = true;
			this->Editar_Grup_Estudi_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Editar_Grup_Estudi_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Editar_Grup_Estudi_TITULO->Location = System::Drawing::Point(40, 74);
			this->Editar_Grup_Estudi_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Editar_Grup_Estudi_TITULO->Name = L"Editar_Grup_Estudi_TITULO";
			this->Editar_Grup_Estudi_TITULO->Size = System::Drawing::Size(339, 39);
			this->Editar_Grup_Estudi_TITULO->TabIndex = 0;
			this->Editar_Grup_Estudi_TITULO->Text = L"Editar Grup d\'Estudi";
			this->Editar_Grup_Estudi_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::label1_Click);
			// 
			// EduConnect_TITULO
			// 
			this->EduConnect_TITULO->AutoSize = true;
			this->EduConnect_TITULO->BackColor = System::Drawing::SystemColors::Control;
			this->EduConnect_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_TITULO->Location = System::Drawing::Point(44, 58);
			this->EduConnect_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_TITULO->Name = L"EduConnect_TITULO";
			this->EduConnect_TITULO->Size = System::Drawing::Size(100, 20);
			this->EduConnect_TITULO->TabIndex = 1;
			this->EduConnect_TITULO->Text = L"EduConnect";
			this->EduConnect_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::label2_Click);
			// 
			// textBox_NomEditar
			// 
			this->textBox_NomEditar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_NomEditar->Location = System::Drawing::Point(57, 113);
			this->textBox_NomEditar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_NomEditar->Name = L"textBox_NomEditar";
			this->textBox_NomEditar->Size = System::Drawing::Size(263, 22);
			this->textBox_NomEditar->TabIndex = 2;
			// 
			// Nom_TITULO
			// 
			this->Nom_TITULO->AutoSize = true;
			this->Nom_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Nom_TITULO->Location = System::Drawing::Point(53, 90);
			this->Nom_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Nom_TITULO->Name = L"Nom_TITULO";
			this->Nom_TITULO->Size = System::Drawing::Size(146, 20);
			this->Nom_TITULO->TabIndex = 3;
			this->Nom_TITULO->Text = L"Nou nom del grup:";
			// 
			// panel_Editar
			// 
			this->panel_Editar->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel_Editar->Controls->Add(this->button_Edita);
			this->panel_Editar->Controls->Add(this->editar_TITULO);
			this->panel_Editar->Controls->Add(this->textBox_DescripcioEditar);
			this->panel_Editar->Controls->Add(this->Despcripción_TITULO);
			this->panel_Editar->Controls->Add(this->Nom_TITULO);
			this->panel_Editar->Controls->Add(this->textBox_NomEditar);
			this->panel_Editar->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->panel_Editar->Location = System::Drawing::Point(91, 332);
			this->panel_Editar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel_Editar->Name = L"panel_Editar";
			this->panel_Editar->Size = System::Drawing::Size(536, 310);
			this->panel_Editar->TabIndex = 4;
			this->panel_Editar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GrupEstudi_EditarUI::panel1_Paint);
			// 
			// button_Edita
			// 
			this->button_Edita->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Edita->Location = System::Drawing::Point(405, 265);
			this->button_Edita->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button_Edita->Name = L"button_Edita";
			this->button_Edita->Size = System::Drawing::Size(100, 28);
			this->button_Edita->TabIndex = 7;
			this->button_Edita->Text = L"Modifica";
			this->button_Edita->UseVisualStyleBackColor = true;
			this->button_Edita->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::testbutton_Edita);
			// 
			// editar_TITULO
			// 
			this->editar_TITULO->AutoSize = true;
			this->editar_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editar_TITULO->Location = System::Drawing::Point(53, 36);
			this->editar_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->editar_TITULO->Name = L"editar_TITULO";
			this->editar_TITULO->Size = System::Drawing::Size(152, 20);
			this->editar_TITULO->TabIndex = 6;
			this->editar_TITULO->Text = L"GRUP A EDITAR";
			this->editar_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::label1_Click_1);
			// 
			// textBox_DescripcioEditar
			// 
			this->textBox_DescripcioEditar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_DescripcioEditar->Location = System::Drawing::Point(57, 206);
			this->textBox_DescripcioEditar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_DescripcioEditar->Multiline = true;
			this->textBox_DescripcioEditar->Name = L"textBox_DescripcioEditar";
			this->textBox_DescripcioEditar->Size = System::Drawing::Size(403, 24);
			this->textBox_DescripcioEditar->TabIndex = 5;
			// 
			// Despcripción_TITULO
			// 
			this->Despcripción_TITULO->AutoSize = true;
			this->Despcripción_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Despcripción_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Despcripción_TITULO->Location = System::Drawing::Point(57, 181);
			this->Despcripción_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Despcripción_TITULO->Name = L"Despcripción_TITULO";
			this->Despcripción_TITULO->Size = System::Drawing::Size(199, 20);
			this->Despcripción_TITULO->TabIndex = 4;
			this->Despcripción_TITULO->Text = L"Nova descripció del grup:";
			// 
			// panel_ACTUAL
			// 
			this->panel_ACTUAL->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel_ACTUAL->Controls->Add(this->textBox_NomActual);
			this->panel_ACTUAL->Controls->Add(this->nom_Actual);
			this->panel_ACTUAL->Controls->Add(this->actual_TITULO);
			this->panel_ACTUAL->Location = System::Drawing::Point(91, 134);
			this->panel_ACTUAL->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel_ACTUAL->Name = L"panel_ACTUAL";
			this->panel_ACTUAL->Size = System::Drawing::Size(536, 176);
			this->panel_ACTUAL->TabIndex = 5;
			// 
			// textBox_NomActual
			// 
			this->textBox_NomActual->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_NomActual->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox_NomActual->Location = System::Drawing::Point(61, 113);
			this->textBox_NomActual->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox_NomActual->Name = L"textBox_NomActual";
			this->textBox_NomActual->Size = System::Drawing::Size(259, 22);
			this->textBox_NomActual->TabIndex = 3;
			this->textBox_NomActual->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::textBox_NomActual_TextChanged);
			// 
			// nom_Actual
			// 
			this->nom_Actual->AutoSize = true;
			this->nom_Actual->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_Actual->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->nom_Actual->Location = System::Drawing::Point(53, 90);
			this->nom_Actual->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nom_Actual->Name = L"nom_Actual";
			this->nom_Actual->Size = System::Drawing::Size(164, 20);
			this->nom_Actual->TabIndex = 1;
			this->nom_Actual->Text = L"Nom del grup actual:";
			this->nom_Actual->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::label1_Click_2);
			// 
			// actual_TITULO
			// 
			this->actual_TITULO->AutoSize = true;
			this->actual_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->actual_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->actual_TITULO->Location = System::Drawing::Point(53, 36);
			this->actual_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->actual_TITULO->Name = L"actual_TITULO";
			this->actual_TITULO->Size = System::Drawing::Size(139, 20);
			this->actual_TITULO->TabIndex = 0;
			this->actual_TITULO->Text = L"GRUP ACTUAL";
			this->actual_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::actual_TITULO_Click);
			// 
			// button_Cancelar
			// 
			this->button_Cancelar->BackColor = System::Drawing::Color::Transparent;
			this->button_Cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Cancelar->ForeColor = System::Drawing::Color::Red;
			this->button_Cancelar->Location = System::Drawing::Point(1021, 614);
			this->button_Cancelar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button_Cancelar->Name = L"button_Cancelar";
			this->button_Cancelar->Size = System::Drawing::Size(100, 28);
			this->button_Cancelar->TabIndex = 6;
			this->button_Cancelar->Text = L"Cancelar";
			this->button_Cancelar->UseVisualStyleBackColor = false;
			this->button_Cancelar->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::testbutton_Cancelar);
			// 
			// GrupEstudi_EditarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1167, 673);
			this->Controls->Add(this->button_Cancelar);
			this->Controls->Add(this->panel_ACTUAL);
			this->Controls->Add(this->panel_Editar);
			this->Controls->Add(this->EduConnect_TITULO);
			this->Controls->Add(this->Editar_Grup_Estudi_TITULO);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"GrupEstudi_EditarUI";
			this->Text = L"Editar Grup Estudi - EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::GrupEstudi_EditarUI_Load);
			this->panel_Editar->ResumeLayout(false);
			this->panel_Editar->PerformLayout();
			this->panel_ACTUAL->ResumeLayout(false);
			this->panel_ACTUAL->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudi_EditarUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_2(System::Object^ sender, System::EventArgs^ e) {
	}

	//
	private: System::Void testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e);
	private: System::Void testbutton_Edita(System::Object^ sender, System::EventArgs^ e);
	//
private: System::Void textBox_NomActual_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void actual_TITULO_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

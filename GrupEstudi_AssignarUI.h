#pragma once
#include "GrupEstudiService.h"
#include "GrupEstudiMembershipService.h"


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
		GrupEstudi_AssignarUI(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudi_AssignarUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ EduConnect_TITULO;
	private: System::Windows::Forms::Label^ Assignar_Grup_Estudi_TITULO;
	private: System::Windows::Forms::TextBox^ textBox_NomUsuari;
	private: System::Windows::Forms::Label^ nom_Usuari;
	private: System::Windows::Forms::Panel^ panel_Assignar;
	private: System::Windows::Forms::TextBox^ boxNom_Grup;
	private: System::Windows::Forms::Label^ nom_Grup;
	private: System::Windows::Forms::Button^ button_Assigna;

	private: System::Windows::Forms::Button^ button_Cancelar;
	private: GrupEstudiService^ grupEstudiService;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::Button^ button_Expulsa;









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
			this->EduConnect_TITULO = (gcnew System::Windows::Forms::Label());
			this->Assignar_Grup_Estudi_TITULO = (gcnew System::Windows::Forms::Label());
			this->textBox_NomUsuari = (gcnew System::Windows::Forms::TextBox());
			this->nom_Usuari = (gcnew System::Windows::Forms::Label());
			this->panel_Assignar = (gcnew System::Windows::Forms::Panel());
			this->button_Expulsa = (gcnew System::Windows::Forms::Button());
			this->button_Assigna = (gcnew System::Windows::Forms::Button());
			this->boxNom_Grup = (gcnew System::Windows::Forms::TextBox());
			this->nom_Grup = (gcnew System::Windows::Forms::Label());
			this->button_Cancelar = (gcnew System::Windows::Forms::Button());
			this->panel_Assignar->SuspendLayout();
			this->SuspendLayout();
			// 
			// EduConnect_TITULO
			// 
			this->EduConnect_TITULO->AutoSize = true;
			this->EduConnect_TITULO->BackColor = System::Drawing::SystemColors::Control;
			this->EduConnect_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_TITULO->Location = System::Drawing::Point(40, 44);
			this->EduConnect_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_TITULO->Name = L"EduConnect_TITULO";
			this->EduConnect_TITULO->Size = System::Drawing::Size(100, 20);
			this->EduConnect_TITULO->TabIndex = 3;
			this->EduConnect_TITULO->Text = L"EduConnect";
			this->EduConnect_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::EduConnect_TITULO_Click);
			// 
			// Assignar_Grup_Estudi_TITULO
			// 
			this->Assignar_Grup_Estudi_TITULO->AutoSize = true;
			this->Assignar_Grup_Estudi_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Assignar_Grup_Estudi_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Assignar_Grup_Estudi_TITULO->Location = System::Drawing::Point(36, 60);
			this->Assignar_Grup_Estudi_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Assignar_Grup_Estudi_TITULO->Name = L"Assignar_Grup_Estudi_TITULO";
			this->Assignar_Grup_Estudi_TITULO->Size = System::Drawing::Size(546, 39);
			this->Assignar_Grup_Estudi_TITULO->TabIndex = 2;
			this->Assignar_Grup_Estudi_TITULO->Text = L"Gestiona Membres Grup d\'Estudi";
			this->Assignar_Grup_Estudi_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::Editar_Grup_Estudi_TITULO_Click);
			// 
			// textBox_NomUsuari
			// 
			this->textBox_NomUsuari->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox_NomUsuari->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox_NomUsuari->Location = System::Drawing::Point(51, 51);
			this->textBox_NomUsuari->Margin = System::Windows::Forms::Padding(4);
			this->textBox_NomUsuari->Name = L"textBox_NomUsuari";
			this->textBox_NomUsuari->Size = System::Drawing::Size(259, 22);
			this->textBox_NomUsuari->TabIndex = 3;
			this->textBox_NomUsuari->TextChanged += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::textBox_NomActual_TextChanged);
			// 
			// nom_Usuari
			// 
			this->nom_Usuari->AutoSize = true;
			this->nom_Usuari->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_Usuari->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->nom_Usuari->Location = System::Drawing::Point(43, 28);
			this->nom_Usuari->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nom_Usuari->Name = L"nom_Usuari";
			this->nom_Usuari->Size = System::Drawing::Size(149, 20);
			this->nom_Usuari->TabIndex = 1;
			this->nom_Usuari->Text = L"Nom del estudiant:";
			this->nom_Usuari->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::nom_Actual_Click);
			// 
			// panel_Assignar
			// 
			this->panel_Assignar->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel_Assignar->Controls->Add(this->button_Expulsa);
			this->panel_Assignar->Controls->Add(this->button_Assigna);
			this->panel_Assignar->Controls->Add(this->boxNom_Grup);
			this->panel_Assignar->Controls->Add(this->nom_Grup);
			this->panel_Assignar->Controls->Add(this->textBox_NomUsuari);
			this->panel_Assignar->Controls->Add(this->nom_Usuari);
			this->panel_Assignar->Location = System::Drawing::Point(73, 128);
			this->panel_Assignar->Margin = System::Windows::Forms::Padding(4);
			this->panel_Assignar->Name = L"panel_Assignar";
			this->panel_Assignar->Size = System::Drawing::Size(536, 245);
			this->panel_Assignar->TabIndex = 6;
			// 
			// button_Expulsa
			// 
			this->button_Expulsa->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Expulsa->ForeColor = System::Drawing::Color::DarkRed;
			this->button_Expulsa->Location = System::Drawing::Point(409, 194);
			this->button_Expulsa->Margin = System::Windows::Forms::Padding(4);
			this->button_Expulsa->Name = L"button_Expulsa";
			this->button_Expulsa->Size = System::Drawing::Size(100, 28);
			this->button_Expulsa->TabIndex = 9;
			this->button_Expulsa->Text = L"Expulsa";
			this->button_Expulsa->UseVisualStyleBackColor = true;
			this->button_Expulsa->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::testbutton_Expulsar);
			// 
			// button_Assigna
			// 
			this->button_Assigna->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Assigna->ForeColor = System::Drawing::Color::ForestGreen;
			this->button_Assigna->Location = System::Drawing::Point(301, 194);
			this->button_Assigna->Margin = System::Windows::Forms::Padding(4);
			this->button_Assigna->Name = L"button_Assigna";
			this->button_Assigna->Size = System::Drawing::Size(100, 28);
			this->button_Assigna->TabIndex = 8;
			this->button_Assigna->Text = L"Assigna";
			this->button_Assigna->UseVisualStyleBackColor = true;
			this->button_Assigna->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::testbutton_Assignar);
			// 
			// boxNom_Grup
			// 
			this->boxNom_Grup->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->boxNom_Grup->Cursor = System::Windows::Forms::Cursors::Default;
			this->boxNom_Grup->Location = System::Drawing::Point(55, 135);
			this->boxNom_Grup->Margin = System::Windows::Forms::Padding(4);
			this->boxNom_Grup->Name = L"boxNom_Grup";
			this->boxNom_Grup->Size = System::Drawing::Size(259, 22);
			this->boxNom_Grup->TabIndex = 5;
			// 
			// nom_Grup
			// 
			this->nom_Grup->AutoSize = true;
			this->nom_Grup->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_Grup->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->nom_Grup->Location = System::Drawing::Point(47, 112);
			this->nom_Grup->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nom_Grup->Name = L"nom_Grup";
			this->nom_Grup->Size = System::Drawing::Size(114, 20);
			this->nom_Grup->TabIndex = 4;
			this->nom_Grup->Text = L"Nom del grup:";
			// 
			// button_Cancelar
			// 
			this->button_Cancelar->BackColor = System::Drawing::Color::Transparent;
			this->button_Cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Cancelar->ForeColor = System::Drawing::Color::Red;
			this->button_Cancelar->Location = System::Drawing::Point(917, 556);
			this->button_Cancelar->Margin = System::Windows::Forms::Padding(4);
			this->button_Cancelar->Name = L"button_Cancelar";
			this->button_Cancelar->Size = System::Drawing::Size(100, 28);
			this->button_Cancelar->TabIndex = 7;
			this->button_Cancelar->Text = L"Cancelar";
			this->button_Cancelar->UseVisualStyleBackColor = false;
			this->button_Cancelar->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::testbutton_Cancelar);
			// 
			// GrupEstudi_AssignarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1081, 622);
			this->Controls->Add(this->button_Cancelar);
			this->Controls->Add(this->panel_Assignar);
			this->Controls->Add(this->EduConnect_TITULO);
			this->Controls->Add(this->Assignar_Grup_Estudi_TITULO);
			this->Name = L"GrupEstudi_AssignarUI";
			this->Text = L"GrupEstudi_AssignarUI";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::GrupEstudi_AssignarUI_Load);
			this->panel_Assignar->ResumeLayout(false);
			this->panel_Assignar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudi_AssignarUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Editar_Grup_Estudi_TITULO_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EduConnect_TITULO_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void nom_Actual_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox_NomActual_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e);
	private: System::Void testbutton_Assignar(System::Object^ sender, System::EventArgs^ e);
	private: System::Void testbutton_Expulsar(System::Object^ sender, System::EventArgs^ e);


};
}

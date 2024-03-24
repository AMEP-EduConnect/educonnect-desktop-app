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
	private: System::Windows::Forms::Label^ EduConnect_TITULO;
	private: System::Windows::Forms::Label^ Consultar_Grup_Estudi_TITULO;
	private: System::Windows::Forms::Panel^ panel_ACTUAL;
	private: System::Windows::Forms::Label^ nom_petany;


	private: System::Windows::Forms::Label^ pertany_TITULO;
	private: System::Windows::Forms::ListBox^ listaNoms;



	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: GrupEstudiService^ grupEstudiService;
	private: System::Windows::Forms::Button^ button_Cancelar;
	private: System::Windows::Forms::Button^ EliminarButton;
	private: System::Windows::Forms::Button^ EditarButton;



	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EduConnect_TITULO = (gcnew System::Windows::Forms::Label());
			this->Consultar_Grup_Estudi_TITULO = (gcnew System::Windows::Forms::Label());
			this->panel_ACTUAL = (gcnew System::Windows::Forms::Panel());
			this->EliminarButton = (gcnew System::Windows::Forms::Button());
			this->EditarButton = (gcnew System::Windows::Forms::Button());
			this->listaNoms = (gcnew System::Windows::Forms::ListBox());
			this->nom_petany = (gcnew System::Windows::Forms::Label());
			this->pertany_TITULO = (gcnew System::Windows::Forms::Label());
			this->button_Cancelar = (gcnew System::Windows::Forms::Button());
			this->panel_ACTUAL->SuspendLayout();
			this->SuspendLayout();
			// 
			// EduConnect_TITULO
			// 
			this->EduConnect_TITULO->AutoSize = true;
			this->EduConnect_TITULO->BackColor = System::Drawing::SystemColors::Control;
			this->EduConnect_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_TITULO->Location = System::Drawing::Point(25, 41);
			this->EduConnect_TITULO->Name = L"EduConnect_TITULO";
			this->EduConnect_TITULO->Size = System::Drawing::Size(80, 16);
			this->EduConnect_TITULO->TabIndex = 3;
			this->EduConnect_TITULO->Text = L"EduConnect";
			// 
			// Consultar_Grup_Estudi_TITULO
			// 
			this->Consultar_Grup_Estudi_TITULO->AutoSize = true;
			this->Consultar_Grup_Estudi_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Consultar_Grup_Estudi_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Consultar_Grup_Estudi_TITULO->Location = System::Drawing::Point(22, 57);
			this->Consultar_Grup_Estudi_TITULO->Name = L"Consultar_Grup_Estudi_TITULO";
			this->Consultar_Grup_Estudi_TITULO->Size = System::Drawing::Size(324, 31);
			this->Consultar_Grup_Estudi_TITULO->TabIndex = 2;
			this->Consultar_Grup_Estudi_TITULO->Text = L"Consultar Grup d\'Estudi";
			// 
			// panel_ACTUAL
			// 
			this->panel_ACTUAL->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel_ACTUAL->Controls->Add(this->EliminarButton);
			this->panel_ACTUAL->Controls->Add(this->EditarButton);
			this->panel_ACTUAL->Controls->Add(this->listaNoms);
			this->panel_ACTUAL->Controls->Add(this->nom_petany);
			this->panel_ACTUAL->Controls->Add(this->pertany_TITULO);
			this->panel_ACTUAL->Location = System::Drawing::Point(62, 111);
			this->panel_ACTUAL->Name = L"panel_ACTUAL";
			this->panel_ACTUAL->Size = System::Drawing::Size(475, 309);
			this->panel_ACTUAL->TabIndex = 6;
			// 
			// EliminarButton
			// 
			this->EliminarButton->Location = System::Drawing::Point(257, 273);
			this->EliminarButton->Name = L"EliminarButton";
			this->EliminarButton->Size = System::Drawing::Size(75, 23);
			this->EliminarButton->TabIndex = 9;
			this->EliminarButton->Text = L"Elimina";
			this->EliminarButton->UseVisualStyleBackColor = true;
			this->EliminarButton->Visible = false;
			this->EliminarButton->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::EliminarButton_Click);
			// 
			// EditarButton
			// 
			this->EditarButton->Location = System::Drawing::Point(338, 273);
			this->EditarButton->Name = L"EditarButton";
			this->EditarButton->Size = System::Drawing::Size(75, 23);
			this->EditarButton->TabIndex = 8;
			this->EditarButton->Text = L"Edita";
			this->EditarButton->UseVisualStyleBackColor = true;
			this->EditarButton->Visible = false;
			this->EditarButton->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::EditarButton_Click);
			// 
			// listaNoms
			// 
			this->listaNoms->BackColor = System::Drawing::Color::Lavender;
			this->listaNoms->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listaNoms->FormattingEnabled = true;
			this->listaNoms->IntegralHeight = false;
			this->listaNoms->Location = System::Drawing::Point(63, 83);
			this->listaNoms->Name = L"listaNoms";
			this->listaNoms->Size = System::Drawing::Size(350, 171);
			this->listaNoms->TabIndex = 2;
			this->listaNoms->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::listaNoms_SelectedIndexChanged);
			// 
			// nom_petany
			// 
			this->nom_petany->AutoSize = true;
			this->nom_petany->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_petany->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->nom_petany->Location = System::Drawing::Point(60, 55);
			this->nom_petany->Name = L"nom_petany";
			this->nom_petany->Size = System::Drawing::Size(105, 16);
			this->nom_petany->TabIndex = 1;
			this->nom_petany->Text = L"Nom dels grups:";
			this->nom_petany->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::nom_Actual_Click);
			// 
			// pertany_TITULO
			// 
			this->pertany_TITULO->AutoSize = true;
			this->pertany_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pertany_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->pertany_TITULO->Location = System::Drawing::Point(40, 29);
			this->pertany_TITULO->Name = L"pertany_TITULO";
			this->pertany_TITULO->Size = System::Drawing::Size(214, 16);
			this->pertany_TITULO->TabIndex = 0;
			this->pertany_TITULO->Text = L"Grups d\'Estudis que pertanys:";
			this->pertany_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::actual_TITULO_Click);
			// 
			// button_Cancelar
			// 
			this->button_Cancelar->BackColor = System::Drawing::Color::Transparent;
			this->button_Cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Cancelar->ForeColor = System::Drawing::Color::Red;
			this->button_Cancelar->Location = System::Drawing::Point(709, 487);
			this->button_Cancelar->Name = L"button_Cancelar";
			this->button_Cancelar->Size = System::Drawing::Size(75, 23);
			this->button_Cancelar->TabIndex = 7;
			this->button_Cancelar->Text = L"Cancelar";
			this->button_Cancelar->UseVisualStyleBackColor = false;
			this->button_Cancelar->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::button_Cancel);
			// 
			// GrupEstudi_ConsultarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 529);
			this->Controls->Add(this->button_Cancelar);
			this->Controls->Add(this->panel_ACTUAL);
			this->Controls->Add(this->EduConnect_TITULO);
			this->Controls->Add(this->Consultar_Grup_Estudi_TITULO);
			this->Name = L"GrupEstudi_ConsultarUI";
			this->Text = L"GrupEstudi_ConsultarUI";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load);
			this->panel_ACTUAL->ResumeLayout(false);
			this->panel_ACTUAL->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void actual_TITULO_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EliminarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Cancel(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listaNoms_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nom_Actual_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e) {
}
};
}

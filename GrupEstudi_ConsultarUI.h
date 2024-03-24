#pragma once
#include "GrupEstudiMembershipService.h"

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
	private: System::Windows::Forms::Button^ button_Consulta;


	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::Button^ button_Cancelar;



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
			this->button_Consulta = (gcnew System::Windows::Forms::Button());
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
			this->EduConnect_TITULO->Location = System::Drawing::Point(33, 50);
			this->EduConnect_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_TITULO->Name = L"EduConnect_TITULO";
			this->EduConnect_TITULO->Size = System::Drawing::Size(100, 20);
			this->EduConnect_TITULO->TabIndex = 3;
			this->EduConnect_TITULO->Text = L"EduConnect";
			// 
			// Consultar_Grup_Estudi_TITULO
			// 
			this->Consultar_Grup_Estudi_TITULO->AutoSize = true;
			this->Consultar_Grup_Estudi_TITULO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Consultar_Grup_Estudi_TITULO->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Consultar_Grup_Estudi_TITULO->Location = System::Drawing::Point(29, 70);
			this->Consultar_Grup_Estudi_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Consultar_Grup_Estudi_TITULO->Name = L"Consultar_Grup_Estudi_TITULO";
			this->Consultar_Grup_Estudi_TITULO->Size = System::Drawing::Size(399, 39);
			this->Consultar_Grup_Estudi_TITULO->TabIndex = 2;
			this->Consultar_Grup_Estudi_TITULO->Text = L"Consultar Grup d\'Estudi";
			// 
			// panel_ACTUAL
			// 
			this->panel_ACTUAL->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->panel_ACTUAL->Controls->Add(this->button_Consulta);
			this->panel_ACTUAL->Controls->Add(this->listaNoms);
			this->panel_ACTUAL->Controls->Add(this->nom_petany);
			this->panel_ACTUAL->Controls->Add(this->pertany_TITULO);
			this->panel_ACTUAL->Location = System::Drawing::Point(83, 137);
			this->panel_ACTUAL->Margin = System::Windows::Forms::Padding(4);
			this->panel_ACTUAL->Name = L"panel_ACTUAL";
			this->panel_ACTUAL->Size = System::Drawing::Size(633, 380);
			this->panel_ACTUAL->TabIndex = 6;
			// 
			// button_Consulta
			// 
			this->button_Consulta->BackColor = System::Drawing::Color::Transparent;
			this->button_Consulta->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Consulta->ForeColor = System::Drawing::Color::Black;
			this->button_Consulta->Location = System::Drawing::Point(450, 333);
			this->button_Consulta->Margin = System::Windows::Forms::Padding(4);
			this->button_Consulta->Name = L"button_Consulta";
			this->button_Consulta->Size = System::Drawing::Size(100, 28);
			this->button_Consulta->TabIndex = 7;
			this->button_Consulta->Text = L"Consulta";
			this->button_Consulta->UseVisualStyleBackColor = false;
			this->button_Consulta->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::button_Consultar);
			// 
			// listaNoms
			// 
			this->listaNoms->BackColor = System::Drawing::Color::Lavender;
			this->listaNoms->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listaNoms->FormattingEnabled = true;
			this->listaNoms->IntegralHeight = false;
			this->listaNoms->ItemHeight = 16;
			this->listaNoms->Location = System::Drawing::Point(84, 102);
			this->listaNoms->Margin = System::Windows::Forms::Padding(4);
			this->listaNoms->Name = L"listaNoms";
			this->listaNoms->Size = System::Drawing::Size(466, 210);
			this->listaNoms->TabIndex = 2;
			this->listaNoms->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::listBox1_SelectedIndexChanged_1);
			// 
			// nom_petany
			// 
			this->nom_petany->AutoSize = true;
			this->nom_petany->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nom_petany->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->nom_petany->Location = System::Drawing::Point(80, 68);
			this->nom_petany->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->nom_petany->Name = L"nom_petany";
			this->nom_petany->Size = System::Drawing::Size(132, 20);
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
			this->pertany_TITULO->Location = System::Drawing::Point(53, 36);
			this->pertany_TITULO->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->pertany_TITULO->Name = L"pertany_TITULO";
			this->pertany_TITULO->Size = System::Drawing::Size(264, 20);
			this->pertany_TITULO->TabIndex = 0;
			this->pertany_TITULO->Text = L"Grups d\'Estudis que pertanys:";
			this->pertany_TITULO->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::actual_TITULO_Click);
			// 
			// button_Cancelar
			// 
			this->button_Cancelar->BackColor = System::Drawing::Color::Transparent;
			this->button_Cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Cancelar->ForeColor = System::Drawing::Color::Red;
			this->button_Cancelar->Location = System::Drawing::Point(945, 599);
			this->button_Cancelar->Margin = System::Windows::Forms::Padding(4);
			this->button_Cancelar->Name = L"button_Cancelar";
			this->button_Cancelar->Size = System::Drawing::Size(100, 28);
			this->button_Cancelar->TabIndex = 7;
			this->button_Cancelar->Text = L"Cancelar";
			this->button_Cancelar->UseVisualStyleBackColor = false;
			this->button_Cancelar->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::button_Cancel);

			// 
			// GrupEstudi_ConsultarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 651);
			this->Controls->Add(this->button_Cancelar);
			this->Controls->Add(this->panel_ACTUAL);
			this->Controls->Add(this->EduConnect_TITULO);
			this->Controls->Add(this->Consultar_Grup_Estudi_TITULO);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GrupEstudi_ConsultarUI";
			this->Text = L"GrupEstudi_ConsultarUI";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load);
			this->panel_ACTUAL->ResumeLayout(false);
			this->panel_ACTUAL->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void actual_TITULO_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_Consultar(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_Cancel(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nom_Actual_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e) {
}
};
}

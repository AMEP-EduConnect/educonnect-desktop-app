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
		GrupEstudi_Membres(void);

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrupEstudi_Membres()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ EduConnect_Label;
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
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: GrupEstudiService^ grupEstudiService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->ConsultarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->Panel_Membres = (gcnew System::Windows::Forms::Panel());
			this->Assignar_Button = (gcnew System::Windows::Forms::Button());
			this->Expulsar_Button = (gcnew System::Windows::Forms::Button());
			this->Membres_Box = (gcnew System::Windows::Forms::ListBox());
			this->Membres_GE2 = (gcnew System::Windows::Forms::Label());
			this->Membres_GE = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->Panel_Membres->SuspendLayout();
			this->SuspendLayout();
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->BackColor = System::Drawing::SystemColors::Control;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(248, 93);
			this->EduConnect_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(100, 20);
			this->EduConnect_Label->TabIndex = 4;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// ConsultarGrupEstudi_Label
			// 
			this->ConsultarGrupEstudi_Label->AutoSize = true;
			this->ConsultarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ConsultarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->ConsultarGrupEstudi_Label->Location = System::Drawing::Point(245, 113);
			this->ConsultarGrupEstudi_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ConsultarGrupEstudi_Label->Name = L"ConsultarGrupEstudi_Label";
			this->ConsultarGrupEstudi_Label->Size = System::Drawing::Size(557, 39);
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
			this->Panel_Membres->Location = System::Drawing::Point(252, 172);
			this->Panel_Membres->Margin = System::Windows::Forms::Padding(4);
			this->Panel_Membres->Name = L"Panel_Membres";
			this->Panel_Membres->Size = System::Drawing::Size(633, 380);
			this->Panel_Membres->TabIndex = 7;
			// 
			// Assignar_Button
			// 
			this->Assignar_Button->Location = System::Drawing::Point(343, 336);
			this->Assignar_Button->Margin = System::Windows::Forms::Padding(4);
			this->Assignar_Button->Name = L"Assignar_Button";
			this->Assignar_Button->Size = System::Drawing::Size(100, 28);
			this->Assignar_Button->TabIndex = 9;
			this->Assignar_Button->Text = L"Assignar";
			this->Assignar_Button->UseVisualStyleBackColor = true;
			this->Assignar_Button->Visible = false;
			this->Assignar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::Assignar_Button_Click);
			// 
			// Expulsar_Button
			// 
			this->Expulsar_Button->Location = System::Drawing::Point(451, 336);
			this->Expulsar_Button->Margin = System::Windows::Forms::Padding(4);
			this->Expulsar_Button->Name = L"Expulsar_Button";
			this->Expulsar_Button->Size = System::Drawing::Size(100, 28);
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
			this->Membres_Box->ItemHeight = 16;
			this->Membres_Box->Location = System::Drawing::Point(84, 102);
			this->Membres_Box->Margin = System::Windows::Forms::Padding(4);
			this->Membres_Box->Name = L"Membres_Box";
			this->Membres_Box->Size = System::Drawing::Size(466, 210);
			this->Membres_Box->TabIndex = 2;
			// 
			// Membres_GE2
			// 
			this->Membres_GE2->AutoSize = true;
			this->Membres_GE2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Membres_GE2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Membres_GE2->Location = System::Drawing::Point(80, 68);
			this->Membres_GE2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Membres_GE2->Name = L"Membres_GE2";
			this->Membres_GE2->Size = System::Drawing::Size(164, 20);
			this->Membres_GE2->TabIndex = 1;
			this->Membres_GE2->Text = L"Nom dels integrants:";
			// 
			// Membres_GE
			// 
			this->Membres_GE->AutoSize = true;
			this->Membres_GE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Membres_GE->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Membres_GE->Location = System::Drawing::Point(53, 36);
			this->Membres_GE->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Membres_GE->Name = L"Membres_GE";
			this->Membres_GE->Size = System::Drawing::Size(378, 20);
			this->Membres_GE->TabIndex = 0;
			this->Membres_GE->Text = L"Membres del Grups d\'Estudis que pertanys:";
			this->Membres_GE->Click += gcnew System::EventHandler(this, &GrupEstudi_Membres::Pertany_Label_Click);
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(1067, 634);
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
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 809);
			this->Controls->Add(this->Cancelar_Button);
			this->Controls->Add(this->Panel_Membres);
			this->Controls->Add(this->ConsultarGrupEstudi_Label);
			this->Controls->Add(this->EduConnect_Label);
			this->Name = L"GrupEstudi_Membres";
			this->Text = L"GrupEstudi_Membres";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_Membres::GrupEstudi_Membres_Load);
			this->Panel_Membres->ResumeLayout(false);
			this->Panel_Membres->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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

		   

};
}

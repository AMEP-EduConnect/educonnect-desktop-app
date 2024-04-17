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
	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::Label^ AssignarGrupEstudi_Label;
	private: System::Windows::Forms::TextBox^ NomUsuari_TextBox;
	private: System::Windows::Forms::Label^ NomUsuari_Label;
	private: System::Windows::Forms::Panel^ Assignar_Panel;
	private: System::Windows::Forms::TextBox^ NomGrup_TextBox;
	private: System::Windows::Forms::Label^ NomGrup_Label;
	private: System::Windows::Forms::Button^ Assigna_Button;

	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::Windows::Forms::Button^ Expulsa_Button;

	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: GrupEstudiService^ grupEstudiService;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->AssignarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->NomUsuari_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NomUsuari_Label = (gcnew System::Windows::Forms::Label());
			this->Assignar_Panel = (gcnew System::Windows::Forms::Panel());
			this->Expulsa_Button = (gcnew System::Windows::Forms::Button());
			this->Assigna_Button = (gcnew System::Windows::Forms::Button());
			this->NomGrup_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NomGrup_Label = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Assignar_Panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->BackColor = System::Drawing::SystemColors::Control;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(329, 145);
			this->EduConnect_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(100, 20);
			this->EduConnect_Label->TabIndex = 3;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// AssignarGrupEstudi_Label
			// 
			this->AssignarGrupEstudi_Label->AutoSize = true;
			this->AssignarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AssignarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->AssignarGrupEstudi_Label->Location = System::Drawing::Point(325, 161);
			this->AssignarGrupEstudi_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->AssignarGrupEstudi_Label->Name = L"AssignarGrupEstudi_Label";
			this->AssignarGrupEstudi_Label->Size = System::Drawing::Size(546, 39);
			this->AssignarGrupEstudi_Label->TabIndex = 2;
			this->AssignarGrupEstudi_Label->Text = L"Gestiona Membres Grup d\'Estudi";
			this->AssignarGrupEstudi_Label->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::AssignarGrupEstudi_Label_Click);
			// 
			// NomUsuari_TextBox
			// 
			this->NomUsuari_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NomUsuari_TextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->NomUsuari_TextBox->Location = System::Drawing::Point(51, 50);
			this->NomUsuari_TextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->NomUsuari_TextBox->Name = L"NomUsuari_TextBox";
			this->NomUsuari_TextBox->Size = System::Drawing::Size(259, 22);
			this->NomUsuari_TextBox->TabIndex = 3;
			// 
			// NomUsuari_Label
			// 
			this->NomUsuari_Label->AutoSize = true;
			this->NomUsuari_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomUsuari_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomUsuari_Label->Location = System::Drawing::Point(47, 27);
			this->NomUsuari_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NomUsuari_Label->Name = L"NomUsuari_Label";
			this->NomUsuari_Label->Size = System::Drawing::Size(149, 20);
			this->NomUsuari_Label->TabIndex = 1;
			this->NomUsuari_Label->Text = L"Nom del estudiant:";
			// 
			// Assignar_Panel
			// 
			this->Assignar_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Assignar_Panel->Controls->Add(this->Expulsa_Button);
			this->Assignar_Panel->Controls->Add(this->Assigna_Button);
			this->Assignar_Panel->Controls->Add(this->NomGrup_TextBox);
			this->Assignar_Panel->Controls->Add(this->NomGrup_Label);
			this->Assignar_Panel->Controls->Add(this->NomUsuari_TextBox);
			this->Assignar_Panel->Controls->Add(this->NomUsuari_Label);
			this->Assignar_Panel->Location = System::Drawing::Point(333, 234);
			this->Assignar_Panel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Assignar_Panel->Name = L"Assignar_Panel";
			this->Assignar_Panel->Size = System::Drawing::Size(536, 245);
			this->Assignar_Panel->TabIndex = 6;
			// 
			// Expulsa_Button
			// 
			this->Expulsa_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Expulsa_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Expulsa_Button->Location = System::Drawing::Point(392, 194);
			this->Expulsa_Button->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Expulsa_Button->Name = L"Expulsa_Button";
			this->Expulsa_Button->Size = System::Drawing::Size(100, 28);
			this->Expulsa_Button->TabIndex = 9;
			this->Expulsa_Button->Text = L"Expulsa";
			this->Expulsa_Button->UseVisualStyleBackColor = true;
			this->Expulsa_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::ExpulsaButton_Click);
			// 
			// Assigna_Button
			// 
			this->Assigna_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Assigna_Button->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Assigna_Button->Location = System::Drawing::Point(51, 194);
			this->Assigna_Button->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Assigna_Button->Name = L"Assigna_Button";
			this->Assigna_Button->Size = System::Drawing::Size(100, 28);
			this->Assigna_Button->TabIndex = 8;
			this->Assigna_Button->Text = L"Assigna";
			this->Assigna_Button->UseVisualStyleBackColor = true;
			this->Assigna_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::AssignaButton_Click);
			// 
			// NomGrup_TextBox
			// 
			this->NomGrup_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NomGrup_TextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->NomGrup_TextBox->Location = System::Drawing::Point(51, 135);
			this->NomGrup_TextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->NomGrup_TextBox->Name = L"NomGrup_TextBox";
			this->NomGrup_TextBox->Size = System::Drawing::Size(259, 22);
			this->NomGrup_TextBox->TabIndex = 5;
			// 
			// NomGrup_Label
			// 
			this->NomGrup_Label->AutoSize = true;
			this->NomGrup_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomGrup_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomGrup_Label->Location = System::Drawing::Point(47, 112);
			this->NomGrup_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NomGrup_Label->Name = L"NomGrup_Label";
			this->NomGrup_Label->Size = System::Drawing::Size(114, 20);
			this->NomGrup_Label->TabIndex = 4;
			this->NomGrup_Label->Text = L"Nom del grup:";
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(1067, 634);
			this->Cancelar_Button->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(100, 28);
			this->Cancelar_Button->TabIndex = 7;
			this->Cancelar_Button->Text = L"Cancelar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::CancelarButton_Click);
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-7, 683);
			this->Background_PictureBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(1237, 326);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 13;
			this->Background_PictureBox->TabStop = false;
			// 
			// GrupEstudi_AssignarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 809);
			this->Controls->Add(this->Background_PictureBox);
			this->Controls->Add(this->Cancelar_Button);
			this->Controls->Add(this->Assignar_Panel);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->AssignarGrupEstudi_Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"GrupEstudi_AssignarUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::GrupEstudi_AssignarUI_Load);
			this->Assignar_Panel->ResumeLayout(false);
			this->Assignar_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void CancelarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AssignaButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ExpulsaButton_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void GrupEstudi_AssignarUI_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void AssignarGrupEstudi_Label_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

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
	private: System::Windows::Forms::Label^ EditarGrupEstudi_Label;
	protected:

	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::TextBox^ EditarNom_TextBox;

	private: System::Windows::Forms::Label^ Nom_Label;
	private: System::Windows::Forms::Panel^ Editar_Panel;
	private: System::Windows::Forms::TextBox^ EditarDescripcio_TextBox;


	private: System::Windows::Forms::Label^ Descripcio_Label;
	private: System::Windows::Forms::Label^ Edita_Label;
	private: System::Windows::Forms::Panel^ Actual_Panel;


	private: System::Windows::Forms::Label^ Actual_Label;
	private: System::Windows::Forms::Label^ NomActual_Label;



	private: System::Windows::Forms::TextBox^ NomActual_TextBox;
	private: System::Windows::Forms::Button^ Edita_Button;
	private: System::Windows::Forms::Button^ Cancelar_Button;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: GrupEstudiService^ grupEstudiService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EditarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->EditarNom_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Nom_Label = (gcnew System::Windows::Forms::Label());
			this->Editar_Panel = (gcnew System::Windows::Forms::Panel());
			this->Edita_Button = (gcnew System::Windows::Forms::Button());
			this->Edita_Label = (gcnew System::Windows::Forms::Label());
			this->EditarDescripcio_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->Descripcio_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			this->NomActual_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NomActual_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Label = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->Editar_Panel->SuspendLayout();
			this->Actual_Panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// EditarGrupEstudi_Label
			// 
			this->EditarGrupEstudi_Label->AutoSize = true;
			this->EditarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EditarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EditarGrupEstudi_Label->Location = System::Drawing::Point(40, 74);
			this->EditarGrupEstudi_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EditarGrupEstudi_Label->Name = L"EditarGrupEstudi_Label";
			this->EditarGrupEstudi_Label->Size = System::Drawing::Size(339, 39);
			this->EditarGrupEstudi_Label->TabIndex = 0;
			this->EditarGrupEstudi_Label->Text = L"Editar Grup d\'Estudi";
			// 
			// EduConnect_Label
			// 
			this->EduConnect_Label->AutoSize = true;
			this->EduConnect_Label->BackColor = System::Drawing::SystemColors::Control;
			this->EduConnect_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->EduConnect_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EduConnect_Label->Location = System::Drawing::Point(44, 58);
			this->EduConnect_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(100, 20);
			this->EduConnect_Label->TabIndex = 1;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// EditarNom_TextBox
			// 
			this->EditarNom_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EditarNom_TextBox->Location = System::Drawing::Point(57, 113);
			this->EditarNom_TextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->EditarNom_TextBox->Name = L"EditarNom_TextBox";
			this->EditarNom_TextBox->Size = System::Drawing::Size(263, 22);
			this->EditarNom_TextBox->TabIndex = 2;
			// 
			// Nom_Label
			// 
			this->Nom_Label->AutoSize = true;
			this->Nom_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nom_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Nom_Label->Location = System::Drawing::Point(53, 90);
			this->Nom_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Nom_Label->Name = L"Nom_Label";
			this->Nom_Label->Size = System::Drawing::Size(146, 20);
			this->Nom_Label->TabIndex = 3;
			this->Nom_Label->Text = L"Nou nom del grup:";
			// 
			// Editar_Panel
			// 
			this->Editar_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Editar_Panel->Controls->Add(this->Edita_Button);
			this->Editar_Panel->Controls->Add(this->Edita_Label);
			this->Editar_Panel->Controls->Add(this->EditarDescripcio_TextBox);
			this->Editar_Panel->Controls->Add(this->Descripcio_Label);
			this->Editar_Panel->Controls->Add(this->Nom_Label);
			this->Editar_Panel->Controls->Add(this->EditarNom_TextBox);
			this->Editar_Panel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Editar_Panel->Location = System::Drawing::Point(91, 332);
			this->Editar_Panel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Editar_Panel->Name = L"Editar_Panel";
			this->Editar_Panel->Size = System::Drawing::Size(536, 310);
			this->Editar_Panel->TabIndex = 4;
			// 
			// Edita_Button
			// 
			this->Edita_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Edita_Button->Location = System::Drawing::Point(405, 265);
			this->Edita_Button->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Edita_Button->Name = L"Edita_Button";
			this->Edita_Button->Size = System::Drawing::Size(100, 28);
			this->Edita_Button->TabIndex = 7;
			this->Edita_Button->Text = L"Modifica";
			this->Edita_Button->UseVisualStyleBackColor = true;
			this->Edita_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::testEdita_Button);
			// 
			// Edita_Label
			// 
			this->Edita_Label->AutoSize = true;
			this->Edita_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Edita_Label->Location = System::Drawing::Point(53, 36);
			this->Edita_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Edita_Label->Name = L"Edita_Label";
			this->Edita_Label->Size = System::Drawing::Size(152, 20);
			this->Edita_Label->TabIndex = 6;
			this->Edita_Label->Text = L"GRUP A EDITAR";
			// 
			// EditarDescripcio_TextBox
			// 
			this->EditarDescripcio_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EditarDescripcio_TextBox->Location = System::Drawing::Point(57, 206);
			this->EditarDescripcio_TextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->EditarDescripcio_TextBox->Multiline = true;
			this->EditarDescripcio_TextBox->Name = L"EditarDescripcio_TextBox";
			this->EditarDescripcio_TextBox->Size = System::Drawing::Size(403, 24);
			this->EditarDescripcio_TextBox->TabIndex = 5;
			// 
			// Descripcio_Label
			// 
			this->Descripcio_Label->AutoSize = true;
			this->Descripcio_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Descripcio_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Descripcio_Label->Location = System::Drawing::Point(57, 181);
			this->Descripcio_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Descripcio_Label->Name = L"Descripcio_Label";
			this->Descripcio_Label->Size = System::Drawing::Size(199, 20);
			this->Descripcio_Label->TabIndex = 4;
			this->Descripcio_Label->Text = L"Nova descripció del grup:";
			// 
			// Actual_Panel
			// 
			this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Actual_Panel->Controls->Add(this->NomActual_TextBox);
			this->Actual_Panel->Controls->Add(this->NomActual_Label);
			this->Actual_Panel->Controls->Add(this->Actual_Label);
			this->Actual_Panel->Location = System::Drawing::Point(91, 134);
			this->Actual_Panel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Actual_Panel->Name = L"Actual_Panel";
			this->Actual_Panel->Size = System::Drawing::Size(536, 176);
			this->Actual_Panel->TabIndex = 5;
			// 
			// NomActual_TextBox
			// 
			this->NomActual_TextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NomActual_TextBox->Cursor = System::Windows::Forms::Cursors::Default;
			this->NomActual_TextBox->Location = System::Drawing::Point(61, 113);
			this->NomActual_TextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->NomActual_TextBox->Name = L"NomActual_TextBox";
			this->NomActual_TextBox->Size = System::Drawing::Size(259, 22);
			this->NomActual_TextBox->TabIndex = 3;
			// 
			// NomActual_Label
			// 
			this->NomActual_Label->AutoSize = true;
			this->NomActual_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NomActual_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomActual_Label->Location = System::Drawing::Point(53, 90);
			this->NomActual_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NomActual_Label->Name = L"NomActual_Label";
			this->NomActual_Label->Size = System::Drawing::Size(164, 20);
			this->NomActual_Label->TabIndex = 1;
			this->NomActual_Label->Text = L"Nom del grup actual:";
			// 
			// Actual_Label
			// 
			this->Actual_Label->AutoSize = true;
			this->Actual_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Actual_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Actual_Label->Location = System::Drawing::Point(53, 36);
			this->Actual_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Actual_Label->Name = L"Actual_Label";
			this->Actual_Label->Size = System::Drawing::Size(139, 20);
			this->Actual_Label->TabIndex = 0;
			this->Actual_Label->Text = L"GRUP ACTUAL";
			// 
			// Cancelar_Button
			// 
			this->Cancelar_Button->BackColor = System::Drawing::Color::Transparent;
			this->Cancelar_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancelar_Button->ForeColor = System::Drawing::Color::Red;
			this->Cancelar_Button->Location = System::Drawing::Point(1021, 614);
			this->Cancelar_Button->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Cancelar_Button->Name = L"Cancelar_Button";
			this->Cancelar_Button->Size = System::Drawing::Size(100, 28);
			this->Cancelar_Button->TabIndex = 6;
			this->Cancelar_Button->Text = L"Cancelar";
			this->Cancelar_Button->UseVisualStyleBackColor = false;
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_EditarUI::CancelarButton_Click);
			// 
			// GrupEstudi_EditarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1167, 673);
			this->Controls->Add(this->Cancelar_Button);
			this->Controls->Add(this->Actual_Panel);
			this->Controls->Add(this->Editar_Panel);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->EditarGrupEstudi_Label);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"GrupEstudi_EditarUI";
			this->Text = L"Editar Grup Estudi - EduConnect";
			this->Editar_Panel->ResumeLayout(false);
			this->Editar_Panel->PerformLayout();
			this->Actual_Panel->ResumeLayout(false);
			this->Actual_Panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CancelarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void testEdita_Button(System::Object^ sender, System::EventArgs^ e);
	};
}

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
	private: System::Windows::Forms::Label^ EduConnect_Label;
	private: System::Windows::Forms::Label^ ConsultarGrupEstudi_Label;
	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::Label^ NomPertany_Label;


	private: System::Windows::Forms::Label^ Pertany_Label;
	private: System::Windows::Forms::ListBox^ Noms_ListBox;


	private: System::Windows::Forms::Button^ Cancelar_Button;
	private: System::Windows::Forms::Button^ Eliminar_Button;
	private: System::Windows::Forms::Button^ Editar_Button;



	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: System::Windows::Forms::PictureBox^ Background_PictureBox;
	private: System::Windows::Forms::Button^ consulta_membres;
	private: GrupEstudiService^ grupEstudiService;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GrupEstudi_ConsultarUI::typeid));
			this->EduConnect_Label = (gcnew System::Windows::Forms::Label());
			this->ConsultarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			this->consulta_membres = (gcnew System::Windows::Forms::Button());
			this->Eliminar_Button = (gcnew System::Windows::Forms::Button());
			this->Editar_Button = (gcnew System::Windows::Forms::Button());
			this->Noms_ListBox = (gcnew System::Windows::Forms::ListBox());
			this->NomPertany_Label = (gcnew System::Windows::Forms::Label());
			this->Pertany_Label = (gcnew System::Windows::Forms::Label());
			this->Cancelar_Button = (gcnew System::Windows::Forms::Button());
			this->Background_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Actual_Panel->SuspendLayout();
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
			this->EduConnect_Label->Location = System::Drawing::Point(264, 101);
			this->EduConnect_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EduConnect_Label->Name = L"EduConnect_Label";
			this->EduConnect_Label->Size = System::Drawing::Size(100, 20);
			this->EduConnect_Label->TabIndex = 3;
			this->EduConnect_Label->Text = L"EduConnect";
			// 
			// ConsultarGrupEstudi_Label
			// 
			this->ConsultarGrupEstudi_Label->AutoSize = true;
			this->ConsultarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ConsultarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->ConsultarGrupEstudi_Label->Location = System::Drawing::Point(260, 121);
			this->ConsultarGrupEstudi_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ConsultarGrupEstudi_Label->Name = L"ConsultarGrupEstudi_Label";
			this->ConsultarGrupEstudi_Label->Size = System::Drawing::Size(399, 39);
			this->ConsultarGrupEstudi_Label->TabIndex = 2;
			this->ConsultarGrupEstudi_Label->Text = L"Consultar Grup d\'Estudi";
			// 
			// Actual_Panel
			// 
			this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Actual_Panel->Controls->Add(this->consulta_membres);
			this->Actual_Panel->Controls->Add(this->Eliminar_Button);
			this->Actual_Panel->Controls->Add(this->Editar_Button);
			this->Actual_Panel->Controls->Add(this->Noms_ListBox);
			this->Actual_Panel->Controls->Add(this->NomPertany_Label);
			this->Actual_Panel->Controls->Add(this->Pertany_Label);
			this->Actual_Panel->Location = System::Drawing::Point(268, 183);
			this->Actual_Panel->Margin = System::Windows::Forms::Padding(4);
			this->Actual_Panel->Name = L"Actual_Panel";
			this->Actual_Panel->Size = System::Drawing::Size(633, 380);
			this->Actual_Panel->TabIndex = 6;
			// 
			// consulta_membres
			// 
			this->consulta_membres->Location = System::Drawing::Point(84, 336);
			this->consulta_membres->Margin = System::Windows::Forms::Padding(4);
			this->consulta_membres->Name = L"consulta_membres";
			this->consulta_membres->Size = System::Drawing::Size(100, 28);
			this->consulta_membres->TabIndex = 10;
			this->consulta_membres->Text = L"Membres";
			this->consulta_membres->UseVisualStyleBackColor = true;
			this->consulta_membres->Visible = false;
			this->consulta_membres->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::consulta_membres_Click);
			// 
			// Eliminar_Button
			// 
			this->Eliminar_Button->Location = System::Drawing::Point(343, 336);
			this->Eliminar_Button->Margin = System::Windows::Forms::Padding(4);
			this->Eliminar_Button->Name = L"Eliminar_Button";
			this->Eliminar_Button->Size = System::Drawing::Size(100, 28);
			this->Eliminar_Button->TabIndex = 9;
			this->Eliminar_Button->Text = L"Elimina";
			this->Eliminar_Button->UseVisualStyleBackColor = true;
			this->Eliminar_Button->Visible = false;
			this->Eliminar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::EliminarButton_Click);
			// 
			// Editar_Button
			// 
			this->Editar_Button->Location = System::Drawing::Point(451, 336);
			this->Editar_Button->Margin = System::Windows::Forms::Padding(4);
			this->Editar_Button->Name = L"Editar_Button";
			this->Editar_Button->Size = System::Drawing::Size(100, 28);
			this->Editar_Button->TabIndex = 8;
			this->Editar_Button->Text = L"Edita";
			this->Editar_Button->UseVisualStyleBackColor = true;
			this->Editar_Button->Visible = false;
			this->Editar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::EditarButton_Click);
			// 
			// Noms_ListBox
			// 
			this->Noms_ListBox->BackColor = System::Drawing::Color::Lavender;
			this->Noms_ListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Noms_ListBox->FormattingEnabled = true;
			this->Noms_ListBox->IntegralHeight = false;
			this->Noms_ListBox->ItemHeight = 16;
			this->Noms_ListBox->Location = System::Drawing::Point(84, 102);
			this->Noms_ListBox->Margin = System::Windows::Forms::Padding(4);
			this->Noms_ListBox->Name = L"Noms_ListBox";
			this->Noms_ListBox->Size = System::Drawing::Size(466, 210);
			this->Noms_ListBox->TabIndex = 2;
			this->Noms_ListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::Noms_ListBox_SelectedIndexChanged);
			// 
			// NomPertany_Label
			// 
			this->NomPertany_Label->AutoSize = true;
			this->NomPertany_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->NomPertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NomPertany_Label->Location = System::Drawing::Point(80, 68);
			this->NomPertany_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NomPertany_Label->Name = L"NomPertany_Label";
			this->NomPertany_Label->Size = System::Drawing::Size(132, 20);
			this->NomPertany_Label->TabIndex = 1;
			this->NomPertany_Label->Text = L"Nom dels grups:";
			// 
			// Pertany_Label
			// 
			this->Pertany_Label->AutoSize = true;
			this->Pertany_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pertany_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Pertany_Label->Location = System::Drawing::Point(53, 36);
			this->Pertany_Label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Pertany_Label->Name = L"Pertany_Label";
			this->Pertany_Label->Size = System::Drawing::Size(264, 20);
			this->Pertany_Label->TabIndex = 0;
			this->Pertany_Label->Text = L"Grups d\'Estudis que pertanys:";
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
			this->Cancelar_Button->Click += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::CancelButton_Click);
			// 
			// Background_PictureBox
			// 
			this->Background_PictureBox->Location = System::Drawing::Point(-7, 683);
			this->Background_PictureBox->Margin = System::Windows::Forms::Padding(4);
			this->Background_PictureBox->Name = L"Background_PictureBox";
			this->Background_PictureBox->Size = System::Drawing::Size(1237, 326);
			this->Background_PictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Background_PictureBox->TabIndex = 17;
			this->Background_PictureBox->TabStop = false;
			// 
			// GrupEstudi_ConsultarUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 809);
			this->Controls->Add(this->Background_PictureBox);
			this->Controls->Add(this->Cancelar_Button);
			this->Controls->Add(this->Actual_Panel);
			this->Controls->Add(this->EduConnect_Label);
			this->Controls->Add(this->ConsultarGrupEstudi_Label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			//this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GrupEstudi_ConsultarUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EduConnect";
			this->Load += gcnew System::EventHandler(this, &GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load);
			this->Actual_Panel->ResumeLayout(false);
			this->Actual_Panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background_PictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EliminarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditarButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CancelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void consulta_membres_Click(System::Object^ sender, System::EventArgs^ e);
	private: void GrupEstudi_ConsultarUIreload();
	};
}

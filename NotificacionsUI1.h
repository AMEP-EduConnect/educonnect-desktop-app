#pragma once
#include "NotificacioService.h"
#include "pch.h"
#include "GrupEstudiMembershipService.h"
#include "GrupEstudiService.h"
#include "Notificacio.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "GrupEstudi.h"
#include "BaixaUsuariService.h"
#include "CurrentSession.h"
#include "MessageManager.h"
#include "NotificacioService.h"
#include "IniciSessioService.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de NotificacionsUI
	/// </summary>
	public ref class NotificacionsUI : public System::Windows::Forms::Form
	{
	public:
		NotificacionsUI(void);


	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~NotificacionsUI()
		{
			if (components)
			{
				delete components;
			}
		}

		
	private:Int64^ selectedId;
	private:String^ selectedIdString;

	private: IniciSessioService^ iniciSessioService;
	private: GrupEstudiMembershipService^ grupEstudiMembershipService;
	private: GrupEstudiService^ grupEstudiService;

	private: NotificacioService^ notificacioService;

	private: UsuariRepository^ usuariRepository;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

	private: System::Windows::Forms::Label^ EditarGrupEstudi_Label;
	private: System::Windows::Forms::Panel^ Actual_Panel;
	private: System::Windows::Forms::ListBox^ Llista_Notificacions;
	private: System::Windows::Forms::Button^ Rebutjarbutton;

	private: System::Windows::Forms::Label^ NotificacionsLabel;

	private: System::Windows::Forms::Label^ Pertany_Label;
	private: System::Windows::Forms::Button^ Acceptarbutton;

	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->EditarGrupEstudi_Label = (gcnew System::Windows::Forms::Label());
			this->Actual_Panel = (gcnew System::Windows::Forms::Panel());
			this->Acceptarbutton = (gcnew System::Windows::Forms::Button());
			this->Llista_Notificacions = (gcnew System::Windows::Forms::ListBox());
			this->Rebutjarbutton = (gcnew System::Windows::Forms::Button());
			this->NotificacionsLabel = (gcnew System::Windows::Forms::Label());
			this->Pertany_Label = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->Actual_Panel->SuspendLayout();
			this->SuspendLayout();
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
			this->tableLayoutPanel1->Controls->Add(this->EditarGrupEstudi_Label, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->Actual_Panel, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 72.83763F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.29135F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(772, 535);
			this->tableLayoutPanel1->TabIndex = 17;
			// 
			// EditarGrupEstudi_Label
			// 
			this->EditarGrupEstudi_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EditarGrupEstudi_Label->AutoSize = true;
			this->EditarGrupEstudi_Label->Font = (gcnew System::Drawing::Font(L"Inter", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditarGrupEstudi_Label->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->EditarGrupEstudi_Label->Location = System::Drawing::Point(290, 23);
			this->EditarGrupEstudi_Label->Name = L"EditarGrupEstudi_Label";
			this->EditarGrupEstudi_Label->Size = System::Drawing::Size(190, 33);
			this->EditarGrupEstudi_Label->TabIndex = 4;
			this->EditarGrupEstudi_Label->Text = L"Notificacions";
			// 
			// Actual_Panel
			// 
			this->Actual_Panel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Actual_Panel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->Actual_Panel->Controls->Add(this->Acceptarbutton);
			this->Actual_Panel->Controls->Add(this->Llista_Notificacions);
			this->Actual_Panel->Controls->Add(this->Rebutjarbutton);
			this->Actual_Panel->Controls->Add(this->NotificacionsLabel);
			this->Actual_Panel->Controls->Add(this->Pertany_Label);
			this->Actual_Panel->Location = System::Drawing::Point(161, 93);
			this->Actual_Panel->Name = L"Actual_Panel";
			this->Actual_Panel->Size = System::Drawing::Size(448, 363);
			this->Actual_Panel->TabIndex = 18;
			// 
			// Acceptarbutton
			// 
			this->Acceptarbutton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Acceptarbutton->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Acceptarbutton->Location = System::Drawing::Point(73, 310);
			this->Acceptarbutton->Name = L"Acceptarbutton";
			this->Acceptarbutton->Size = System::Drawing::Size(91, 34);
			this->Acceptarbutton->TabIndex = 18;
			this->Acceptarbutton->Text = L"Acceptar";
			this->Acceptarbutton->UseVisualStyleBackColor = true;
			this->Acceptarbutton->Click += gcnew System::EventHandler(this, &NotificacionsUI::Acceptarbutton_Click);
			// 
			// Llista_Notificacions
			// 
			this->Llista_Notificacions->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Llista_Notificacions->BackColor = System::Drawing::SystemColors::Window;
			this->Llista_Notificacions->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Llista_Notificacions->Font = (gcnew System::Drawing::Font(L"Inter", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Llista_Notificacions->FormattingEnabled = true;
			this->Llista_Notificacions->IntegralHeight = false;
			this->Llista_Notificacions->ItemHeight = 19;
			this->Llista_Notificacions->Location = System::Drawing::Point(29, 49);
			this->Llista_Notificacions->Name = L"Llista_Notificacions";
			this->Llista_Notificacions->Size = System::Drawing::Size(390, 256);
			this->Llista_Notificacions->TabIndex = 17;
			this->Llista_Notificacions->SelectedIndexChanged += gcnew System::EventHandler(this, &NotificacionsUI::Llista_Notificacions_SelectedIndexChanged);
			// 
			// Rebutjarbutton
			// 
			this->Rebutjarbutton->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rebutjarbutton->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->Rebutjarbutton->Location = System::Drawing::Point(285, 310);
			this->Rebutjarbutton->Name = L"Rebutjarbutton";
			this->Rebutjarbutton->Size = System::Drawing::Size(91, 34);
			this->Rebutjarbutton->TabIndex = 0;
			this->Rebutjarbutton->Text = L"Rebutjar";
			this->Rebutjarbutton->UseVisualStyleBackColor = true;
			this->Rebutjarbutton->Click += gcnew System::EventHandler(this, &NotificacionsUI::Rebutjarbutton_Click);
			// 
			// NotificacionsLabel
			// 
			this->NotificacionsLabel->AutoSize = true;
			this->NotificacionsLabel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->NotificacionsLabel->Font = (gcnew System::Drawing::Font(L"Inter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NotificacionsLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->NotificacionsLabel->Location = System::Drawing::Point(40, 10);
			this->NotificacionsLabel->Name = L"NotificacionsLabel";
			this->NotificacionsLabel->Size = System::Drawing::Size(149, 19);
			this->NotificacionsLabel->TabIndex = 7;
			this->NotificacionsLabel->Text = L"LlistaNotificacions";
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
			// NotificacionsUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 535);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"NotificacionsUI";
			this->Text = L"NotificacionsUI";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->Actual_Panel->ResumeLayout(false);
			this->Actual_Panel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LoadNotificacionsList(System::Object^ sender, System::EventArgs^ e);
	private: String^ GetIdFromString(String^ input);

	private: System::Void Acceptarbutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Rebutjarbutton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Llista_Notificacions_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}

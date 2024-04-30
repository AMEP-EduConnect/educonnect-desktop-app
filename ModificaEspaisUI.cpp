#include "pch.h"
#include "ModificaEspaisUI.h"
#include "Espai.h"
#include <string>
using namespace System;
using namespace MySql::Data::MySqlClient;
namespace CppCLRWinFormsProject {

	ModificaEspaisUI::ModificaEspaisUI(String^ selectedEspais)
	{
		InitializeComponent();
		modificaEspaisService = gcnew ModificaEspaisService();
		Espai^ espai = this->modificaEspaisService->GetEspaiByName(selectedEspais);
		String^ name = espai->GetName();  
        String^ capacity = espai->GetCapacity()->ToString();
		textBox3->Text = name;
		textBox1->Text = capacity;
		
		
		this->textBox3->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &ModificaEspaisUI::NomEspai_TextBox_Validating);
        this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &ModificaEspaisUI::Capacitat_TextBox_Validating);
		//this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");

		this->Cancelar_Button->Visible = false;
		
		//ROLS
		

	}

    Void ModificaEspaisUI::NomEspai_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (textBox != nullptr) {
            bool isnotValid = this->modificaEspaisService->CheckNameEspai(textBox->Text);
            if (isnotValid) {
                MessageManager::WarningMessage("El nom de l'espai ja existeix.");
                textBox->Text = "";
                e->Cancel = true;
            }

        }
    }

    bool ModificaEspaisUI::IsValidCapacitat(String^ capacitat) {
        // Esta expresión regular coincide solo con cadenas que son números enteros no negativos.
        String^ pattern = "^[0-9]+$";
        System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(pattern);
        return regex->IsMatch(capacitat);
    }


    Void ModificaEspaisUI::Capacitat_TextBox_Validating(Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
        TextBox^ textBox = dynamic_cast<TextBox^>(sender);
        if (textBox != nullptr) {
            if ((!IsValidCapacitat(textBox->Text) and textBox->Text != "") or (textBox->Text == "0")) {
                MessageManager::WarningMessage("La capacitat ha de ser un número enter major a 0.");
                this->textBox1->Text = "";

            }


        }
    }

    void ModificaEspaisUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        
        String^ nom = textBox3->Text;
        String^ capacitatText = textBox1->Text;
        Int64^ capacitat;

        if (!String::IsNullOrWhiteSpace(nom) && !String::IsNullOrWhiteSpace(capacitatText)) {

            Int64^ capacitat = Int64::Parse(capacitatText);

            this->modificaEspaisService->UpdateEspai(nom);
            MessageManager::InfoMessage("Espai modificat!");
            this->textBox3->Text = nom;
            this->textBox1->Text = capacitatText;
        }

        else {
            MessageBox::Show("Falta informació de l'espai.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

    }

    Void ModificaEspaisUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        ConsultaEspaisUI^ PanelUI = gcnew ConsultaEspaisUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();

    }


}


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
		espai = this->modificaEspaisService->GetEspaiByName(selectedEspais);
        
		String^ name = espai->GetName();  
        this->label6->Text = L"Informació de " + name;
        String^ capacity = espai->GetCapacity()->ToString();
		textBox3->Text = name;
		textBox1->Text = capacity;
		id_espai = espai->GetEspaiId();
		
        
		//this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");

		this->Cancelar_Button->Visible = true;
		
		//ROLS
		

	}

    bool ModificaEspaisUI::NomEspai_TextBox_Validating(String^ nom) {
    
        if (nom != nullptr) {
            bool isnotValid = this->modificaEspaisService->CheckNameEspai(nom);
            if (isnotValid) {
                MessageManager::WarningMessage("El nom de l'espai ja existeix.");
                this->textBox3->Text = "";
                
            }

        }
    }

    bool ModificaEspaisUI::IsValidCapacitat(String^ capacitat) {
        // Esta expresión regular coincide solo con cadenas que son números enteros no negativos.
        String^ pattern = "^[0-9]+$";
        System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(pattern);
        return regex->IsMatch(capacitat);
    }


    bool ModificaEspaisUI::Capacitat_TextBox_Validating(String^ capacitat) {

        if ((capacitat != "") && (capacitat != nullptr)) {

            if (IsValidCapacitat(capacitat) == false) {
                MessageManager::WarningMessage("La capacitat ha de ser un número enter major o igual a 4.");
                this->textBox1->Text = "";
                return false;
            }
            else {
                Int64^ cap = Int64::Parse(capacitat);
                if (*cap >= 4LL)return true;
                else return false;
            }


        }
        else return false;
    }
    void ModificaEspaisUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if(this->button1->Text == L"Confirmar")
        {
            this->label6->Text = L"Informació de " + espai->GetName();
            String^ nom = textBox3->Text;
            String^ capacitatText = textBox1->Text;
       
            if (nom != "" && capacitatText!= "") {

                if (Capacitat_TextBox_Validating(capacitatText)==false) {
              
                    return;
                }
                if (NomEspai_TextBox_Validating(nom) == false) {

                    return;
                }
                Int64^ capacitat = Int64::Parse(capacitatText);
                Int64^ cap = espai->GetCapacity();
                if (nom == espai->GetName() && *capacitat == *cap){
                    MessageManager::WarningMessage("Has de modificar com a mínim un camp.");
                }
                else{
                    this->modificaEspaisService->UpdateEspai(nom, capacitat, id_espai);
                    MessageManager::InfoMessage("Espai modificat!");
                    espai = this->modificaEspaisService->GetEspaiByName(nom);
                    this->label6->Text = L"Informació de " + espai->GetName();
                    this->textBox3->Text = nom;
                    this->textBox1->Text = capacitatText;
                    this->button1->Text = L"Modifica";
                    this->Button_Cancelar_Edita->Visible = false;
                    textBox3->Enabled = false;
                    textBox1->Enabled = false;
                    this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				       static_cast<System::Int32>(static_cast<System::Byte>(224)));
                    this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				       static_cast<System::Int32>(static_cast<System::Byte>(224)));
                }
            }

            else {
                MessageBox::Show("Falta informació de l'espai.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
        }
        else {
           this->button1->Text = L"Confirmar";
           this->label6->Text = L"Modificació de " + espai->GetName();
           textBox3->Enabled = true;
           textBox1->Enabled = true;
           this->textBox1->BackColor = SystemColors::Window;
		   this->textBox3->BackColor = SystemColors::Window;
           this->Button_Cancelar_Edita->Visible = true;
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

    System::Void ModificaEspaisUI::Button_Cancelar_Edita_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->label6->Text = L"Informació de " + espai->GetName();
        this->Button_Cancelar_Edita->Visible = false;
        this->button1->Text = L"Modificar";
        String^ name = espai->GetName();
        String^ capacity = espai->GetCapacity()->ToString();
        textBox3->Text = name;
        textBox1->Text = capacity;
        textBox3->Enabled = false;
        textBox1->Enabled = false;
        this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
        
    }


}


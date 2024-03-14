#include "pch.h"
#include "MyForm.h"
#include "Utils.h"
#include "DatabaseConnector.h"


#pragma once

namespace YourNamespace {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    public:
        Form1()
        {
            InitializeComponent();

            // Asocia el evento Click del botón al mismo manejador de eventos.
            button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        }

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Captura el texto del TextBox al hacer clic en el botón y lo muestra en un MessageBox.
            String^ texto = textBox1->Text;
            MessageBox::Show(texto);
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(12, 12);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(200, 20);
            this->textBox1->TabIndex = 0;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 38);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Capturar";
            this->button1->UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this->ClientSize = System::Drawing::Size(224, 73);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::Button^ button1;
    };
}

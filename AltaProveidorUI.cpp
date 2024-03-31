#include "pch.h"
#include "AltaProveidorUI.h"
#include "Proveidor.h"
#include "AltaProveidorService.h"
#include "MessageManager.h"


using namespace System;

namespace CppCLRWinFormsProject {

    AltaProveidorUI::AltaProveidorUI(void)
    {
        InitializeComponent();
        altaProveidorService = gcnew AltaProveidorService();

    }

    void AltaProveidorUI::AltaProveidorUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        textBox1->Text = "Nombre del Proveedor";
    }
    
    void AltaProveidorUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ id = textBox1->Text;
        String^ username = textBox2->Text;
        String^ password = textBox3->Text;
        String^ email = textBox4->Text;
        String^ surname = textBox5->Text;
        if ((!String::IsNullOrWhiteSpace(id)) && (!String::IsNullOrWhiteSpace(username)) && (!String::IsNullOrWhiteSpace(password)) && (!String::IsNullOrWhiteSpace(email)) && (!String::IsNullOrWhiteSpace(surname))) {
            altaProveidorService->AltaProveidor(id, username, password, email, surname);
            
           // MessageManager::ShowMessage("Proveedor registrado con éxito.");
        }
        else {
            
            MessageManager::WarningMessage("Falta información del proveedor.");
        }
    }

   
}


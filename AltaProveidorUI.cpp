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

    
    
    void AltaProveidorUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        
        String^ username = textBox3->Text;
        String^ password = textBox4->Text;
        String^ email = textBox2->Text;
        String^ name = textBox5->Text;
        if ((!String::IsNullOrWhiteSpace(username)) && (!String::IsNullOrWhiteSpace(password)) && (!String::IsNullOrWhiteSpace(email)) && (!String::IsNullOrWhiteSpace(name))) {
            this->altaProveidorService->AltaProveidor( username, email, name, password);
            this->Close();
           // MessageManager::ShowMessage("Proveedor registrado con éxito.");
        }
        else {
            
            MessageManager::WarningMessage("Falta información del proveedor.");
        }
    }

   
}


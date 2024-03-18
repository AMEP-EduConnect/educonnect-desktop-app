#include "pch.h"
#include "AltaProveidor.h"
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
        String^ proveidorInfo = textBox1->Text;
        if (!String::IsNullOrWhiteSpace(proveidorInfo)) {
            altaProveidorService->AltaProveidor(proveidorInfo);
            
           // MessageManager::ShowMessage("Proveedor registrado con éxito.");
        }
        else {
            
            MessageManager::WarningMessage("Falta información del proveedor.");
        }
    }

   
}


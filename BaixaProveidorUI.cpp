#include "pch.h"
#include "BaixaProveidor.h"
#include "Proveidor.h"
#include "BaixaProveidorService.h"
#include "MessageManager.h"


using namespace System;

namespace CppCLRWinFormsProject {

    BaixaProveidorUI::BaixaProveidorUI(void)
    {
        InitializeComponent();
        baixaProveidorService = gcnew BaixaProveidorService(); // Asume la existencia de esta clase
    }

    void BaixaProveidorUI::BaixaProveidorUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        textBox1->Text = "Nombre del Proveedor a eliminar";
    }

    void BaixaProveidorUI::button2_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ proveidorInfo = textBox1->Text;
        if (!String::IsNullOrWhiteSpace(proveidorInfo)) {
            try {
                baixaProveidorService->BaixaProveidor(proveidorInfo); // Asume que este método existe

                MessageManager::InfoMessage("Proveedor eliminado con éxito.");
            }
            catch (Exception^ e) {
                MessageManager::ErrorMessage("Error al eliminar el proveedor: " + e->Message);
            }
        }
        else {
            MessageManager::WarningMessage("Por favor, introduce el nombre del proveedor a eliminar.");
        }
    }
}



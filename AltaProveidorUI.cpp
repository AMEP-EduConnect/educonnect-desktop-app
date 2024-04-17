#include "pch.h"
#include "AltaProveidorUI.h"
#include "AltaProveidorService.h"
#include "MessageManager.h"
#include "MainPageUI.h"

using namespace System;

namespace CppCLRWinFormsProject {

    AltaProveidorUI::AltaProveidorUI(void)
    {
        InitializeComponent();
        altaProveidorService = gcnew AltaProveidorService();
        this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");

    }

    void AltaProveidorUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {   
        this->Hide();
        MainPageUI^ form = gcnew MainPageUI();
        form->ShowDialog();
        this->Close();
    }
    
    
    void AltaProveidorUI::button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        
        String^ username = textBox3->Text;
        String^ password = textBox4->Text;
        String^ email = textBox2->Text;
        String^ name = textBox5->Text;
        if ((!String::IsNullOrWhiteSpace(username)) && (!String::IsNullOrWhiteSpace(password)) && (!String::IsNullOrWhiteSpace(email)) && (!String::IsNullOrWhiteSpace(name))) {
            this->altaProveidorService->AltaProveidor( username, email, name, password);
           // MessageManager::ShowMessage("Proveedor registrado con éxito.");
        }
        else {
            
            MessageManager::WarningMessage("Falta informació del proveïdor.");
        }
    }

   
}


#include "pch.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "IniciSessioService.h"

#include "InformacioPersonal_ConsultaUI.h"
#include "FirstPageUI.h"

#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_CrearUI.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "AltaProveidorUI.h"
#include "BaixaProveidorUI.h"

namespace CppCLRWinFormsProject {

    MainPageUI::MainPageUI(void)
    {
        InitializeComponent();
        this->Text = L"EduConnect";

        //IMAGES
        //this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->BotoPersonal->Image = Image::FromFile("resources/Icons/usuario.png");
        this->BotoLogout->Image = Image::FromFile("resources/Icons/salida.png");
        
        this->BotoExplorar->Image = Image::FromFile("resources/Icons/busqueda.png");
        this->BotoElsMeus->Image = Image::FromFile("resources/Icons/usuarios-alt.png");
        this->BotoSessions->Image = Image::FromFile("resources/Icons/libro-cubierta-abierta.png");
        this->BotoEspais->Image = Image::FromFile("resources/Icons/libro-cubierta-abierta.png");
        this->BotoAdmin->Image = Image::FromFile("resources/Icons/herramientas.png");


        //CONTROL BAR
        this->Text = "";



    }
    void MainPageUI:: MainPageUI_Load(System::Object^ sender, System::EventArgs^ e) {

        try {
            String^ iconRoute = L".\\app.ico";

            if (System::IO::File::Exists(iconRoute)) {
                this->Icon = gcnew System::Drawing::Icon(iconRoute);
            }
            else {
                this->Icon = System::Drawing::SystemIcons::Application;
            }
        }
        catch (System::Exception^ ex) {
            Console::WriteLine("App icon not found: " + ex->Message);
        }

    }

    void MainPageUI::Perfil_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Hide();
		InformacioPersonal_ConsultaUI^ form = gcnew InformacioPersonal_ConsultaUI();
		form->ShowDialog();
		this->Close();
	}

    void MainPageUI::Tancar_Sessio_Click(System::Object^ sender, System::EventArgs^ e)
	{
		CurrentSession::Instance->LogoutCurrentUser();
        this->Hide();
		FirstPageUI^ form = gcnew FirstPageUI();
		form->ShowDialog();
		this->Close();
	}


    void MainPageUI::Consulta_Grup_Click(System::Object^ sender, System::EventArgs^ e) 
    {
		this->Hide();
		GrupEstudi_ConsultarUI^ form = gcnew GrupEstudi_ConsultarUI();
		form->ShowDialog();
		this->Close();
    }

    void MainPageUI::Edita_Grup_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		GrupEstudi_EditarUI^ form = gcnew GrupEstudi_EditarUI();
		form->ShowDialog();
		this->Close();
    }

    void MainPageUI::Gestiona_Grup_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		GrupEstudi_AssignarUI^ form = gcnew GrupEstudi_AssignarUI();
		form->ShowDialog();
		this->Close();
    }

    void MainPageUI::Crea_Grup_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		GrupEstudi_CrearUI^ form = gcnew GrupEstudi_CrearUI();
		form->ShowDialog();
		this->Close();
    }

    void MainPageUI::Alta_Proveidor_Click(System::Object^ sender, System::EventArgs^ e) {
    
		//this->Hide();
		//AltaProveidorUI^ form = gcnew AltaProveidorUI();
		//form->ShowDialog();
		//this->Close();

        AltaProveidorUI^ PanelUI = gcnew AltaProveidorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->panel1->Controls->Clear();
        this->panel1->Controls->Add(PanelUI);

        PanelUI->Show();
    }

    void MainPageUI::Baixa_Proveidor_Click(System::Object^ sender, System::EventArgs^ e) {
    
		this->Hide();
		BaixaProveidorUI^ form = gcnew BaixaProveidorUI();
		form->ShowDialog();
		this->Close();
    
    }

    void MainPageUI::panelContenedor_Resize(Object^ sender, EventArgs^ e) {
        AltaProveidorUI^ formHijo = dynamic_cast<AltaProveidorUI^>(panel1->Controls);
        if (formHijo != nullptr) {
            formHijo->Width = this->panel1->Width;
            formHijo->Height = this->panel1->Height;
        }
    }


}

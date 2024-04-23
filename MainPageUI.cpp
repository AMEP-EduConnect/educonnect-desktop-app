#include "pch.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "IniciSessioService.h"
#include "AdministradorUI.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "FirstPageUI.h"
#include "IniciUI.h"

#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_CrearUI.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "AltaProveidorUI.h"
#include "BaixaProveidorUI.h"
#include "UsuariRolRepository.h"

namespace CppCLRWinFormsProject {

    MainPageUI::MainPageUI(void)
    {
        InitializeComponent();
        this->Text = L"EduConnect";

        IniciUI^ PanelUI = gcnew IniciUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        //IMAGES
        //this->Background_PictureBox->Image = Image::FromFile("resources/Images/background2.png");
        this->BotoPersonal->Image = Image::FromFile("resources/Icons/usuario.png");
        this->BotoLogout->Image = Image::FromFile("resources/Icons/salida.png");
        this->BotoExplorar->Image = Image::FromFile("resources/Icons/busqueda.png");
        this->BotoElsMeus->Image = Image::FromFile("resources/Icons/usuarios-alt.png");
        this->BotoSessions->Image = Image::FromFile("resources/Icons/libro-cubierta-abierta.png");
        this->BotoEspais->Image = Image::FromFile("resources/Icons/edificio.png");
        this->BotoAdmin->Image = Image::FromFile("resources/Icons/herramientas.png");


        //CONTROL BAR
        this->Text = "";

        //ROLS
        Int64^ rol = CurrentSession::Instance->GetCurrentUserRol();

        if (*rol == 1) {
            this->BotoAdmin->Visible = true;
            this->BotoEspais->Visible = true;
        }
        else if (*rol == 3) {
            this->BotoAdmin->Visible = false;
            this->BotoEspais->Visible = true;
        }
        else {
            this->BotoAdmin->Visible = false;
            this->BotoEspais->Visible = false;
        }

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


    void MainPageUI::Tancar_Sessio_Click(System::Object^ sender, System::EventArgs^ e)
    {
        CurrentSession::Instance->LogoutCurrentUser();
        this->Hide();
        FirstPageUI^ form = gcnew FirstPageUI();
        form->ShowDialog();
        this->Close();
    }

    void MainPageUI::Perfil_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//this->Hide();
		//InformacioPersonal_ConsultaUI^ form = gcnew InformacioPersonal_ConsultaUI();
		//form->ShowDialog();
		//this->Close();

        InformacioPersonal_ConsultaUI^ PanelUI = gcnew InformacioPersonal_ConsultaUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

	}

    void MainPageUI::BotoInici_Click(System::Object^ sender, System::EventArgs^ e) {
        IniciUI^ PanelUI = gcnew IniciUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void MainPageUI::Admin_Click(System::Object^ sender, System::EventArgs^ e) {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

    }

    //System::Void ElsMeus_Click(System::Object^ sender, System::EventArgs^ e) {
        
    //}














}

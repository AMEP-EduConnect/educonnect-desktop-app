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
#include "EspaisRepository.h"
#include "UsuariRolRepository.h"
#include "StartPageUI.h"
#include "GrupEstudi_ExplorarUI.h"

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
            this->BotoElsMeus->Visible = false;
            this->BotoExplorar->Visible = false;
        }
        else {
            this->BotoAdmin->Visible = false;
            this->BotoEspais->Visible = false;
        }

    }
    void MainPageUI::MainPageUI_Load(System::Object^ sender, System::EventArgs^ e) {

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
        StartPageUI::Instance = gcnew StartPageUI();
        StartPageUI::Instance->ShowDialog();
        StartPageUI::Instance->captcha_ok = false;
        this->Close();

    }

    void MainPageUI::Perfil_Click(System::Object^ sender, System::EventArgs^ e)
    {
        InformacioPersonal_ConsultaUI^ PanelUI = gcnew InformacioPersonal_ConsultaUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoEspais->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

    }

    void MainPageUI::BotoInici_Click(System::Object^ sender, System::EventArgs^ e)
    {
        IniciUI^ PanelUI = gcnew IniciUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter ExtraBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoEspais->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

    }

    void MainPageUI::Admin_Click(System::Object^ sender, System::EventArgs^ e) {
        AdministradorUI^ PanelUI = gcnew AdministradorUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoEspais->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

    }
    Void MainPageUI::BotoEspais_Click(System::Object^ sender, System::EventArgs^ e) {
        ConsultaEspaisUI^ PanelUI = gcnew ConsultaEspaisUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        this->BotoEspais->Font = (gcnew System::Drawing::Font(L"Inter Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

	}
    //System::Void ElsMeus_Click(System::Object^ sender, System::EventArgs^ e) {
        
    void MainPageUI::ElsMeus_Click(System::Object^ sender, System::EventArgs^ e) {
        GrupEstudi_ConsultarUI^ PanelUI = gcnew GrupEstudi_ConsultarUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));


    }

    void MainPageUI::BotoExplorar_Click(System::Object^ sender, System::EventArgs^ e) {
        GrupEstudi_Explorar^ PanelUI = gcnew GrupEstudi_Explorar();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();

        this->BotoExplorar->Font = (gcnew System::Drawing::Font(L"Inter Medium", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));

        this->BotoInici->Font = (gcnew System::Drawing::Font(L"Inter", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoAdmin->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        this->BotoElsMeus->Font = (gcnew System::Drawing::Font(L"Inter Light", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));


    }














}
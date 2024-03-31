#include "pch.h"
#include "MainPage.h"
#include "Professor.h"
#include "Utils.h"
#include "DatabaseConnector.h"
#include "ProfessorService.h"


namespace CppCLRWinFormsProject {

    MainPage::MainPage(void)
    {
        InitializeComponent();
        this->Text = L"EduConnect";
    }
    void MainPage::MainPage_Load(System::Object^ sender, System::EventArgs^ e) {
        versionLabel->Text = L"V0.0 - Develop";

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

        testQuery();
    }
    //TESTING METHOD, DELETE LATER
    void MainPage::testQuery()
    {
        DatabaseConnector::Instance = gcnew DatabaseConnector();
        ProfessorService^ professorService = gcnew ProfessorService();
        Professor^ prof = gcnew Professor();
        try {
            Int64 id = 1;
            // es crida al m�tode de la classe ProfessorService que retorna un professor
            prof = professorService->GetProfessorById(id);
        }
        catch (Exception^ ex) {
            // codi per mostrar l�error en una finestra
            MessageBox::Show(ex->Message);
        }
        finally {
            // si tot va bé es tanca la connexió
            //DatabaseConnector::Instance->Disconnect();
            DatabaseConnector::Instance->Disconnect();
            MessageBox::Show("Database testing: " + prof->name);
        }

    }

}

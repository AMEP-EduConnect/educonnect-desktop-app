#include "pch.h"
#include "MainPage.h"
#include "Professor.h"
#include "Utils.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace CppCLRWinFormsProject {

    MainPage::MainPage(void)
    {
        InitializeComponent();
        this->Text = L"EduConnect";
        String^ server;
        String^ username;
        String^ password;
        String^ databaseName;
        Utils::readAndDecryptDatabaseCredentials(server, username, password, databaseName);
        connectionString = String::Format("server={0};port=3306;user id={1};password={2};database={3};AllowPublicKeyRetrieval=true;", server, username, password, databaseName);
        conn = gcnew MySqlConnection(connectionString);
    }
    void MainPage:: MainPage_Load(System::Object^ sender, System::EventArgs^ e) {
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
    void MainPage:: testQuery()
    {
        String^ sql = "SELECT * FROM professors WHERE name = 'Lidia'";
        MySqlCommand^ cmd = gcnew MySqlCommand(sql, conn);
        MySqlDataReader^ dataReader;
        Professor^ prof; // suposem que tenim la classe Professor
        try {
            // obrim la connexió
            conn->Open();
            // executem la comanda (cmd) que s’ha creat abans del try
            dataReader = cmd->ExecuteReader();
            if (dataReader->Read()) {
                // Es llegeix la informació per crear un objecte de tipus Professor
                // Agafarem les columnes per índex, la primera és la 0
                Int64 id = dataReader->GetInt64(0);
                String^ name = dataReader->GetString(1);
                String^ surname = dataReader->GetString(2);
                prof = gcnew Professor(id, name, surname);
            }
        }
        catch (Exception^ ex) {
            // codi per mostrar l’error en una finestra
            MessageBox::Show(ex->Message);
        }
        finally {
            // si tot va bé es tanca la connexió
            conn->Close();
            MessageBox::Show("Database testing: " + prof->name);
        }

    }

}

#include "pch.h"
#include "MainPage.h"


namespace CppCLRWinFormsProject {

    MainPage::MainPage(void)
    {
        InitializeComponent();
        this->Text = L"EduConnect";
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
    }



}

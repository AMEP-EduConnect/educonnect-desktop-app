#include "pch.h"
#include "GrupEstudi_InfoUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "MainPageUI.h"


namespace CppCLRWinFormsProject {

    GrupEstudi_InfoUI::GrupEstudi_InfoUI(String^ CurrentGrup)
    {
        InitializeComponent();
        this->CurrentGrup = CurrentGrup;
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    System::Void GrupEstudi_InfoUI::GoBack_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_ConsultarUI^ PanelUI = gcnew GrupEstudi_ConsultarUI();

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }
}
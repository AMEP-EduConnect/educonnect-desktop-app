#include "pch.h"
#include "StartPageUI.h"
#include "FirstPageUI.h"

using namespace System;

namespace CppCLRWinFormsProject {
	StartPageUI::StartPageUI(void)
	{
		InitializeComponent();
        this->pictureBox1->Image = Image::FromFile("background.png");
        FirstPageUI^ PanelUI = gcnew FirstPageUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        this->screen->Controls->Clear();
        this->screen->Controls->Add(PanelUI);
        PanelUI->Show();
        this->Icon = gcnew System::Drawing::Icon("app.ico");

	}




}
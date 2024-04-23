#include "pch.h"
#include "IniciUI.h"
#include "CurrentSession.h"
#include <ctime>
#include <iostream>
using namespace std;
using namespace System;

namespace CppCLRWinFormsProject {

    IniciUI::IniciUI(void) {
        InitializeComponent();
        SetWelcomeMessage();
        
        this->pictureBox4->Image = Image::FromFile("resources/Icons/square-plus.png");
        
    }

	Void IniciUI::SetWelcomeMessage() {

        String^ name = CurrentSession::Instance->GetCurrentUser()->GetName();

        time_t now = time(0);
        tm* time = localtime(&now);

        if (time->tm_hour > 6 and time->tm_hour < 12) this->Benvinguda->Text = "Bon dia, " + name;

        else if (time->tm_hour >= 12 and time->tm_hour < 20) this->Benvinguda->Text = "Bona tarda, " + name;

        else if (time->tm_hour >= 20 or time->tm_hour <= 6) this->Benvinguda->Text = "Bona nit, " + name;

	}

}
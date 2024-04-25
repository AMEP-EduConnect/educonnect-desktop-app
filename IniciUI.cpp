#include "pch.h"
#include "IniciUI.h"
#include "CurrentSession.h"
#include "GrupEstudi.h"
#include <ctime>
#include <iostream>
#include <vector>

#include "GrupEstudiService.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"

using namespace std;
using namespace System;
using namespace System;
using namespace System::Collections::Generic;


namespace CppCLRWinFormsProject {

    IniciUI::IniciUI(void) {
        grupEstudiService = gcnew GrupEstudiService();
        InitializeComponent();
        SetWelcomeMessage();
        SetRecentGroups();
        

        this->pictureBox4->Image = Image::FromFile("resources/Icons/square-plus.png");
        this->Grup1->Visible = false;
        this->Grup2->Visible = false;
        this->Grup3->Visible = false;
    }

	Void IniciUI::SetWelcomeMessage() {

        String^ name = CurrentSession::Instance->GetCurrentUser()->GetName();

        time_t now = time(0);
        tm* time = localtime(&now);

        if (time->tm_hour > 6 and time->tm_hour < 12) this->Benvinguda->Text = "Bon dia, " + name;

        else if (time->tm_hour >= 12 and time->tm_hour < 20) this->Benvinguda->Text = "Bona tarda, " + name;

        else if (time->tm_hour >= 20 or time->tm_hour <= 6) this->Benvinguda->Text = "Bona nit, " + name;

	}

    Void IniciUI::SetRecentGroups()
    {
       
        Usuari^ user = CurrentSession::Instance->GetCurrentUser();

        std::vector<GrupEstudi^> groups;

        groups = grupEstudiService->CheckNrecentGroups(gcnew Int64(3), user->GetUserId());
        
        if(groups.size() == 3) {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;
            this->Grup3->Visible = true;
            List<int>^ list = gcnew List<int>(0);
            list->Add(1);
            list[0] = 1;

        }
        else if (groups.size() == 2) {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;

        }
        else if (groups.size() == 1) {
            this->Grup1->Visible = true;

        }
        else {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;
            this->Grup3->Visible = true;

        }

    }


}
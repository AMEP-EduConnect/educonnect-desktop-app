#include "pch.h"
#include "IniciUI.h"
#include "CurrentSession.h"
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
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"

using namespace System::Collections::Generic;


namespace CppCLRWinFormsProject {

    IniciUI::IniciUI(void) {

        InitializeComponent();

        this->pictureBox4->Image = Image::FromFile("resources/Icons/square-plus.png");
        this->Grup1->Visible = false;
        this->Grup2->Visible = false;
        this->Grup3->Visible = false;
        //this->label5->Visible = false;

        grupEstudiService = gcnew GrupEstudiService();
        
        SetWelcomeMessage();
        SetRecentGroups();
     
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

        List<GrupEstudi^>^ groups = gcnew List<GrupEstudi^>(0);
        
    
        groups = grupEstudiService->CheckNrecentGroups(gcnew Int64(3), user->GetUserId());
        System::Collections::Generic::IEnumerator<GrupEstudi^>^ enumerator = groups->GetEnumerator();

        if(groups->Count == 3) {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;
            this->Grup3->Visible = true;
           
            enumerator->MoveNext();
            this->Grup1label->Text = enumerator->Current->GetGroupName();

            enumerator->MoveNext();
            this->Grup2label->Text = enumerator->Current->GetGroupName();
        
            enumerator->MoveNext();
            this->Grup3label->Text = enumerator->Current->GetGroupName();
            
        }
        else if (groups->Count == 2) {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;

            enumerator->MoveNext();
            this->Grup1label->Text = enumerator->Current->GetGroupName();

            enumerator->MoveNext();
            this->Grup2label->Text = enumerator->Current->GetGroupName();

        }
        else if (groups->Count == 1) {
            this->Grup1->Visible = true;

            enumerator->MoveNext();
            this->Grup1label->Text = enumerator->Current->GetGroupName();

        }
  

    }


}
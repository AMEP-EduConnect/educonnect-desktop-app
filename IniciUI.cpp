#include "pch.h"
#include "IniciUI.h"
#include "CurrentSession.h"
#include <ctime>
#include <iostream>
#include <vector>
#include <ctime>

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
#include "MainPageUI.h"
#include "GrupEstudi_CrearUI.h"
#include "GrupEstudi_InfoUI.h"
using namespace System::Collections::Generic;


namespace CppCLRWinFormsProject {

    IniciUI::IniciUI(void) {

        InitializeComponent();

        this->pictureBox4->Image = Image::FromFile("resources/Icons/square-plus.png");
  
        this->Grup1->Visible = false;
        this->Grup2->Visible = false;
        this->Grup3->Visible = false;

        grupEstudiService = gcnew GrupEstudiService();
		perfilPersonalConsultaService = gcnew PerfilPersonalConsultaService();
        
        SetWelcomeMessage();
        SetRecentGroups();
        fillflowlayoutpanel();
     
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
            this->Grup1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox3->Tag = enumerator->Current->GetGroupName();
            enumerator->MoveNext();
            this->Grup2label->Text = enumerator->Current->GetGroupName();
            this->Grup2->Tag = enumerator->Current->GetGroupName();
            this->pictureBox2->Tag = enumerator->Current->GetGroupName();
            enumerator->MoveNext();
            this->Grup3label->Text = enumerator->Current->GetGroupName();
            this->pictureBox1->Tag = enumerator->Current->GetGroupName();
            this->Grup3->Tag = enumerator->Current->GetGroupName();
        }
        else if (groups->Count == 2) {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;
            enumerator->MoveNext();
            this->Grup1label->Text = enumerator->Current->GetGroupName();
            this->pictureBox3->Tag = enumerator->Current->GetGroupName();
            this->Grup1->Tag = enumerator->Current->GetGroupName();
            enumerator->MoveNext();
            this->Grup2label->Text = enumerator->Current->GetGroupName();
            this->Grup2->Tag = enumerator->Current->GetGroupName();
            this->pictureBox2->Tag = enumerator->Current->GetGroupName();
        }
        else if (groups->Count == 1) {
            this->Grup1->Visible = true;

            enumerator->MoveNext();
            this->Grup1label->Text = enumerator->Current->GetGroupName();
            this->Grup1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox3->Tag = enumerator->Current->GetGroupName();
        }
  

    }

    Void IniciUI::pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
        GrupEstudi_CrearUI^ PanelUI = gcnew GrupEstudi_CrearUI(0);
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    System::Void IniciUI::pictureBox_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Panel^ clickedBox = dynamic_cast<Panel^>(sender);
        if (clickedBox != nullptr && clickedBox->Tag != nullptr) {
            String^ groupName = dynamic_cast<String^>(clickedBox->Tag);
            if (!String::IsNullOrEmpty(groupName)) {
                // Llama a la función que maneja el clic, pasando el nombre del grupo
                GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(groupName);
                PanelUI->TopLevel = false;
                PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                MainPageUI::Instance->screen->Controls->Clear();
                MainPageUI::Instance->screen->Controls->Add(PanelUI);
                PanelUI->Show();
            }
        }
    }

    System::Void IniciUI::fillflowlayoutpanel()
    {
       
            srand(time(0));

            List<AcademicTag^>^ all_tags = gcnew List<AcademicTag^>(0);
            List<AcademicTag^>^ user_tags = gcnew List<AcademicTag^>(0);
            List<GrupEstudi^>^ recomendations = gcnew List<GrupEstudi^>(0);
            
			user_tags = perfilPersonalConsultaService->GetAcademicTagsByUserIdWithGroup(CurrentSession::Instance->GetCurrentUser()->GetUserId());
            System::Collections::Generic::IEnumerator<AcademicTag^>^ enumerator1 = user_tags->GetEnumerator();
	

			all_tags = perfilPersonalConsultaService->GetAllAcademicTagsWithGroup(CurrentSession::Instance->GetCurrentUser()->GetUserId());
            System::Collections::Generic::IEnumerator<AcademicTag^>^ enumerator2 = all_tags->GetEnumerator();
      
            if(user_tags->Count > 0) { 
                int random = rand() % user_tags->Count + 1;
                if (random == 0) enumerator1->MoveNext();

                while (random > 0) {
                   
                    enumerator1->MoveNext();
                    random--;
                }
                
                recomendations = grupEstudiService->RecomanaNGrups(enumerator1->Current->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId(), gcnew Int64(3));
			}

            else if(all_tags->Count > 0) {
                int random = rand() % all_tags->Count + 1;
                if (random == 0) enumerator2->MoveNext();

                while (random > 0) {
                    enumerator2->MoveNext();
                    random--;
                }

				recomendations = grupEstudiService->RecomanaNGrups(enumerator2->Current->GetId(), CurrentSession::Instance->GetCurrentUser()->GetUserId(), gcnew Int64(3));
            }
			System::Collections::Generic::IEnumerator<GrupEstudi^>^ aux = recomendations->GetEnumerator();

			while (aux->MoveNext()) {
				AddPanelWithText(this->flowLayoutPanel2, aux->Current->GetGroupName());
			}

    }

    // Función para añadir un panel con texto al FlowLayoutPanel
    Void IniciUI::AddPanelWithText(FlowLayoutPanel^ flowLayout, String^ text) 
    {
     
        Panel^ panel = gcnew Panel();
        panel->Size = System::Drawing::Size(190, 70);
		panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;  
        panel->Name = text;  
        panel->BackColor = System::Drawing::Color::FromArgb(215, 228, 242);  
        panel->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
        panel->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);
		
        flowLayout->Controls->Add(panel);


        Label^ label = gcnew Label();
        label->Text = text;
        label->AutoSize = true;
        label->Dock = DockStyle::Bottom;  
        label->TextAlign = ContentAlignment::MiddleLeft; 
        label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        label->Margin = System::Windows::Forms::Padding(0, 3, 3, 30);
        
        flowLayout->Controls->Add(label);

    }

    Void IniciUI::panel_MouseEnter(System::Object^ sender, System::EventArgs^ e) 
    {
        Panel^ p = dynamic_cast<Panel^>(sender);
        if (p != nullptr) {
            p->BackColor = System::Drawing::Color::FromArgb(185, 209, 234); 
        }
    }

    Void IniciUI::panel_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
    {
        Panel^ p = dynamic_cast<Panel^>(sender);
        if (p != nullptr) {
            p->BackColor = System::Drawing::Color::FromArgb(215, 228, 242); 
        }
    }


}
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
#include "GrupEstudi_ExplorarUI.h"
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
            if (enumerator->Current->GetGroupName()->Length > 10) {
                this->Grup1label->Text = enumerator->Current->GetGroupName()->Substring(0, 10) + "...";
            }
            else this->Grup1label->Text = enumerator->Current->GetGroupName();

  
			String^ initials = extreureInicials(enumerator->Current->GetGroupName());

            this->Grup1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox3->Tag = enumerator->Current->GetGroupName();
            this->pictureBox3->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
            this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
            this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);

            enumerator->MoveNext();
            if (enumerator->Current->GetGroupName()->Length > 10) {
                this->Grup2label->Text = enumerator->Current->GetGroupName()->Substring(0, 10) + "...";
            }
            else this->Grup2label->Text = enumerator->Current->GetGroupName();

            String^ initials = extreureInicials(enumerator->Current->GetGroupName());

            this->Grup2->Tag = enumerator->Current->GetGroupName();
            this->pictureBox2->Tag = enumerator->Current->GetGroupName();
            this->pictureBox2->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
            this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
            this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);

            enumerator->MoveNext();
            if (enumerator->Current->GetGroupName()->Length > 10) {
                this->Grup3label->Text = enumerator->Current->GetGroupName()->Substring(0, 10) + "...";
            }
            else this->Grup3label->Text = enumerator->Current->GetGroupName();

            this->Grup1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox1->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
            this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
            this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);
            
        }
        else if (groups->Count == 2) {
            this->Grup1->Visible = true;
            this->Grup2->Visible = true;
            enumerator->MoveNext();
            if (enumerator->Current->GetGroupName()->Length > 10) {
                this->Grup1label->Text = enumerator->Current->GetGroupName()->Substring(0, 10) + "...";
            }
            else this->Grup1label->Text = enumerator->Current->GetGroupName();

            this->pictureBox3->Tag = enumerator->Current->GetGroupName();
            this->Grup1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox3->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
            this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
            this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);

            enumerator->MoveNext();
            if (enumerator->Current->GetGroupName()->Length > 10) {
                this->Grup2label->Text = enumerator->Current->GetGroupName()->Substring(0, 10) + "...";
            }
            else this->Grup2label->Text = enumerator->Current->GetGroupName();

            this->Grup2->Tag = enumerator->Current->GetGroupName();
            this->pictureBox2->Tag = enumerator->Current->GetGroupName();
            this->pictureBox2->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
            this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
            this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);
        }
        else if (groups->Count == 1) {
            this->Grup1->Visible = true;

            enumerator->MoveNext();
            
            if (enumerator->Current->GetGroupName()->Length > 10) {
                this->Grup1label->Text = enumerator->Current->GetGroupName()->Substring(0, 10) + "...";
            }
            else this->Grup1label->Text = enumerator->Current->GetGroupName();
             
            this->Grup1->Tag = enumerator->Current->GetGroupName();
            this->pictureBox3->Tag = enumerator->Current->GetGroupName();
			this->pictureBox3->Click += gcnew System::EventHandler(this, &IniciUI::pictureBox_Click);
            this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
            this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);
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
                GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(groupName, 0);
                PanelUI->TopLevel = false;
                PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                MainPageUI::Instance->screen->Controls->Clear();
                MainPageUI::Instance->screen->Controls->Add(PanelUI);
                PanelUI->Show();
            }
        }
    }
    System::Void IniciUI::pictureBoxSuggest_Click(System::Object^ sender, System::EventArgs^ e)
    {
        Panel^ clickedBox = dynamic_cast<Panel^>(sender);
        if (clickedBox != nullptr && clickedBox->Tag != nullptr) {
            String^ groupName = dynamic_cast<String^>(clickedBox->Tag);
            if (!String::IsNullOrEmpty(groupName)) {
                // Llama a la función que maneja el clic, pasando el nombre del grupo
                //GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(groupName, 0);
                GrupEstudi_Explorar^ PanelUI = gcnew GrupEstudi_Explorar(groupName);
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

        TableLayoutPanel^ table = gcnew TableLayoutPanel();
        table->Size = Drawing::Size(132, 200); 
        table->RowCount = 2;
        table->ColumnCount = 1;
        table->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
        table->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 50));
        table->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100));
        table->Margin = System::Windows::Forms::Padding(3, 3, 30, 3);


        Panel^ panel = gcnew Panel();
        panel->MinimumSize = Drawing::Size(126, 126);
        panel->Size = System::Drawing::Size(126, 126);
		panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;  
        panel->Name = text;  
        panel->BackColor = System::Drawing::Color::FromArgb(215, 228, 242);  
        panel->MouseEnter += gcnew System::EventHandler(this, &IniciUI::panel_MouseEnter);
        panel->MouseLeave += gcnew System::EventHandler(this, &IniciUI::panel_MouseLeave);
        panel->Tag = text;
        panel->Click += gcnew System::EventHandler(this, &IniciUI::pictureBoxSuggest_Click);

        table->Controls->Add(panel, 0, 0);
		
        


        Label^ label = gcnew Label();

        if (text->Length > 10) label->Text = text->Substring(0, 10) + "...";
        
        else label->Text = text;

        label->AutoSize = true;
        //label->Dock = DockStyle::Bottom;  
        label->Anchor = AnchorStyles::Left;
        label->TextAlign = ContentAlignment::MiddleLeft; 
        label->Font = (gcnew System::Drawing::Font(L"Inter Light", 12.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(0)));
        label->Margin = System::Windows::Forms::Padding(0, 0, 3, 0);

        table->Controls->Add(label, 0, 1);
        
        flowLayout->Controls->Add(table);
        

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


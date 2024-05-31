#include "pch.h"
#include "NotificacionsUI.h"
#include "Notificacio.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "GrupEstudi.h"
#include "BaixaUsuariService.h"
#include "CurrentSession.h"
#include "MessageManager.h"
#include "NotificacioService.h"
#include "GrupEstudiMembershipService.h"

using namespace System;

namespace CppCLRWinFormsProject {

    NotificacionsUI::NotificacionsUI(void)
    {
        InitializeComponent();
        notificacioService = gcnew NotificacioService();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
        grupEstudiService = gcnew GrupEstudiService();
        iniciSessioService = gcnew IniciSessioService();
        Acceptarbutton->Enabled = false;
        Rebutjarbutton->Enabled = false;
        Acceptarbutton->Visible = false;
        Rebutjarbutton->Visible = false;
        this->Load += gcnew System::EventHandler(this, &NotificacionsUI::LoadNotificacionsList);
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }



    Void NotificacionsUI::LoadNotificacionsList(System::Object^ sender, System::EventArgs^ e) {
        Llista_Notificacions->Items->Clear();
        Acceptarbutton->Enabled = false;
        Rebutjarbutton->Enabled = false;
        Acceptarbutton->Visible = false;
        Rebutjarbutton->Visible = false;
        Usuari^ current_user = CurrentSession::Instance->GetCurrentUser();
        Int64^ id_current_user = current_user->GetUserId();
        

        List<Notificacio^>^ notificacions = notificacioService->ListNotificacions(id_current_user);
        System::Collections::Generic::IEnumerator<Notificacio^>^ enumerator = notificacions->GetEnumerator();
        while (enumerator->MoveNext()) {
            Int64^ id = enumerator->Current->GetId();
            Int64^ id_source = enumerator->Current->GetSourceUserId();
            Usuari^ user_source = iniciSessioService->GetUsuariById(id_source);
            String^ nom_source = user_source->GetUsername();
            Int64^ id_grup = enumerator->Current->GetSourceGroupId();
            GrupEstudi^ grup_source = grupEstudiService->GetGrupEstudiById(id_grup);
            String^ nom_grup_source = grup_source->GetGroupName();
            Int64^ id_type = enumerator->Current->GetNotificationType();
            Int64^ id_status = enumerator->Current->GetStatusType();
            Int64^ id_destination = enumerator->Current->GetDestinationUserId();
            Usuari^ user_destination = iniciSessioService->GetUsuariById(id_destination);
            String^ nom_destination = user_destination->GetUsername();

            if (id_current_user == id_destination) {
                if (*id_type == 2LL) {
                    if (*id_status == 1LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_source + " t'ha invitat a unir-te al grup " + nom_grup_source);
                        /*Acceptarbutton->Enabled = true;
                        Acceptarbutton->Visible = true;
                        Rebutjarbutton->Enabled = true;
                        Rebutjarbutton->Visible = true;*/
                    }
                    /*else if (*id_status == 2LL) {
                        //Enviar missatge a solicitant
                        Llista_Notificacions->Items->Add(id + " - " + " Has estat acceptat al grup " + nom_grup_source);
                        Acceptarbutton->Enabled = false;
                        Rebutjarbutton->Enabled = false;
                    }
                    else {
                        //Enviar missatge a solicitant
                        Llista_Notificacions->Items->Add(id + " - " + " Has estat rebutjat pel grup " + nom_grup_source);
                        Acceptarbutton->Enabled = false;
                        Rebutjarbutton->Enabled = false;
                    }
                    */
                }

                else {
                    if (*id_status == 1LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_source + " ha solicitat unir-se al grup " + nom_grup_source);
                        
                    }
                    /*
                    else if (*id_status == 2LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_destination + " ha acceptat la invitació al grup " + nom_grup_source);
                        Acceptarbutton->Enabled = false;
                        Rebutjarbutton->Enabled = false;
                    }
                    else {
                        Llista_Notificacions->Items->Add(id + " - " + nom_destination + " ha solicitat unir-se al grup " + nom_grup_source);
                        Acceptarbutton->Enabled = false;
                        Rebutjarbutton->Enabled = false;
                    }
                    */
                }
            }
            else {
                if (*id_type == 1LL) {
                    /*if (*id_status == 1LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_source + " ha solicitat unir-se al grup " + nom_grup_source);
                        Acceptarbutton->Enabled = true;
                        Rebutjarbutton->Enabled = true;
                    }
                    else*/ if (*id_status == 2LL) {
                        //Enviar missatge a solicitant
                        Llista_Notificacions->Items->Add(id + " - " + " Has sigut acceptat al grup " + nom_grup_source);
                        
                    }
                    else if(*id_status == 3LL) {
                        //Enviar missatge a solicitant
                        Llista_Notificacions->Items->Add(id + " - " + " Has sigut rebutjat pel grup " + nom_grup_source);
                        
                    }
                }

                else {
                    /*if (*id_status == 1LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_source + " t'ha invitat a unir-te al grup " + nom_grup_source);
                        Acceptarbutton->Enabled = true;
                        Rebutjarbutton->Enabled = true;
                    }
                    else*/ if (*id_status == 2LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_destination + " ha acceptat la invitació al grup " + nom_grup_source);
                       
                    }
                    else if (*id_status == 3LL) {
                        Llista_Notificacions->Items->Add(id + " - " + nom_destination + " ha solicitat unir-se al grup " + nom_grup_source);
                        
                    }
                }
            }
        }
    }

    String^ NotificacionsUI::GetIdFromString(String^ input) {
        int pos = input->IndexOf(" - ");
        String^ id_noti;
        if (pos != -1) {
             id_noti = input->Substring(0, pos);
        }
        return id_noti;
    }
    
    System::Void NotificacionsUI::Acceptarbutton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (Llista_Notificacions->SelectedItem != nullptr) {

            Notificacio^ notificacio = notificacioService->GetNotificacioById(selectedId);
            Int64^ id_source = notificacio->GetSourceUserId();
            Int64^ id_destination = notificacio->GetDestinationUserId();
            Int64^ id_grup = notificacio->GetSourceGroupId();
            Int64^ status = 2LL;
            Int64^ id_user;
            Int64^ id_type = notificacio->GetNotificationType();
            if (id_type == 1LL) id_user = id_source;
            else id_user = id_destination;
            grupEstudiMembershipService->UserToGroup(id_user, id_grup);
            notificacioService->ChangeStatus(status, notificacio);
            if (id_type == 1LL)MessageManager::InfoMessage("S'ha acceptat la solicitud");
            else MessageManager::InfoMessage("Has acceptat la invitació");

            //Llista_Notificacions->Items->Clear();
            LoadNotificacionsList(sender, e);
        }
        else {
            MessageManager::WarningMessage("Selecciona una notificació de la llista.");
        }
    }    

    System::Void NotificacionsUI::Rebutjarbutton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (Llista_Notificacions->SelectedItem != nullptr) {
            Notificacio^ notificacio = notificacioService->GetNotificacioById(selectedId);
            Int64^ status = 3LL;
            Int64^ id_type = notificacio->GetNotificationType();
            notificacioService->ChangeStatus(status, notificacio);
            if (id_type == 1LL) MessageManager::InfoMessage("S'ha rebutjat la solicitud");
            else MessageManager::InfoMessage("Has rebutjat la invitació");
            LoadNotificacionsList(sender, e);
        }
        else {
            MessageManager::WarningMessage("Selecciona una notificació de la llista.");
        }
    }
    
    System::Void NotificacionsUI::Llista_Notificacions_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        //TODO: que GetIdFromString tenga un return de Int64^ y que se lo pase a Acceptarbutton_Click y Rebutjarbutton_Click
        //TODO: que cambie el estado del botón a disable si la notificación es origen/destino
        if (this != nullptr) {
            selectedIdString = this->GetIdFromString(this->Llista_Notificacions->SelectedItem->ToString());
            selectedId = Int64::Parse(selectedIdString);
            Notificacio^ notificacio = notificacioService->GetNotificacioById(selectedId);
            Int64^ id_source = notificacio->GetSourceUserId();

            Usuari^ current_user = CurrentSession::Instance->GetCurrentUser();
            Int64^ id_current_user = current_user->GetUserId();

            if (id_current_user == id_source) {
                Acceptarbutton->Enabled = true;
                Acceptarbutton->Visible = true;
                Rebutjarbutton->Enabled = true;
                Rebutjarbutton->Visible = true;

            }
            else {
                Acceptarbutton->Enabled = false;
                Acceptarbutton->Visible = false;
                Rebutjarbutton->Enabled = false;
                Rebutjarbutton->Visible = false;
            }
            //Llista_Notificacions->Items->Clear();
            //LoadNotificacionsList(sender, e);
        }
    }
    
    
}
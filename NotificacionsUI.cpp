#include "pch.h"
#include "NotificacionsUI.h"
#include "Notificacio.h"
#include "MainPageUI.h"
#include "Usuari.h"
#include "GrupEstudi.h"
#include "BaixaUsuariService.h"
#include "GrupEstudiRepository.h"
#include "CurrentSession.h"
#include "MessageManager.h"
#include "NotificacioService.h"
#include "GrupEstudiMembershipService.h"

using namespace System;

namespace CppCLRWinFormsProject {

    NotificacionsUI::NotificacionsUI(void)
    {
        InitializeComponent();
        //notificacioService = gcnew NotificacioService();
        //grupEstudiRepository = gcnew GrupEstudiRepository();


        this->Load += gcnew System::EventHandler(this, &NotificacionsUI::LoadNotificacionsList);
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }



    Void NotificacionsUI::LoadNotificacionsList(System::Object^ sender, System::EventArgs^ e) {
        //usuariRepository = gcnew UsuariRepository();
        //grupEstudiRepository = gcnew GrupEstudiRepository();
        //notificacioService = gcnew NotificacioService();
        Usuari^ destination_user = CurrentSession::Instance->GetCurrentUser();
        Int64^ id_destination = destination_user->GetUserId();
        
        Int64^ status = 1LL;
        List<Notificacio^>^ notificacions = notificacioService->ListNotificacions(id_destination, status);
        System::Collections::Generic::IEnumerator<Notificacio^>^ enumerator = notificacions->GetEnumerator();
        while (enumerator->MoveNext()) {
            Int64^ id = enumerator->Current->GetId();
            Int64^ id_source = enumerator->Current->GetSourceUserId();
            Usuari^ user_source = usuariRepository->GetUsuariById(id_source);
            String^ nom_source = user_source->GetUsername();
            Int64^ id_grup = enumerator->Current->GetSourceGroupId();
            GrupEstudi^ grup_source = grupEstudiRepository->GetGrupEstudiById(id_grup);
            String^ nom_grup_source = grup_source->GetGroupName();
            Int64^ id_type = enumerator->Current->GetNotificationType();

            if (id_type == 1LL) Llista_Notificacions->Items->Add(id + " - " + nom_source + " ha solicitat unir-se al grup " + nom_grup_source);
            else Llista_Notificacions->Items->Add(id + " - " + nom_source + " t'ha convidat al grup " + nom_grup_source);


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
           // notificacioService = gcnew NotificacioService();

            Notificacio^ notificacio = notificacioService->GetNotificacioById(selectedId);
            Int64^ id_source = notificacio->GetSourceUserId();
            Int64^ id_grup = notificacio->GetSourceGroupId();
            Int64^ status = 2LL;
            grupEstudiMembershipService->UserToGroup(id_source, id_grup);
            notificacioService->ChangeStatus(status, notificacio);

        }
        else {
            MessageManager::WarningMessage("Selecciona una notificaci� de la llista.");
        }
    }

    System::Void NotificacionsUI::Rebutjarbutton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (Llista_Notificacions->SelectedItem != nullptr) {
            Notificacio^ notificacio = notificacioService->GetNotificacioById(selectedId);
            Int64^ status = 3LL;
            notificacioService->ChangeStatus(status, notificacio);
        }
        else {
            MessageManager::WarningMessage("Selecciona una notificaci� de la llista.");
        }
    }
    
    System::Void NotificacionsUI::Llista_Notificacions_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        //TODO: que GetIdFromString tenga un return de Int64^ y que se lo pase a Acceptarbutton_Click y Rebutjarbutton_Click
        //TODO: que cambie el estado del bot�n a disable si la notificaci�n es origen/destino
        selectedIdString = this->GetIdFromString(this->Llista_Notificacions->SelectedItem->ToString());
        selectedId = Int64::Parse(selectedIdString);

    }
    

}
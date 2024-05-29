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
        notificacioService = gcnew NotificacioService();
        grupEstudiRepository = gcnew GrupEstudiRepository();


        this->Load += gcnew System::EventHandler(this, &NotificacionsUI::LoadNotificacionsList);
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }



    Void NotificacionsUI::LoadNotificacionsList(System::Object^ sender, System::EventArgs^ e) {
        usuariRepository = gcnew UsuariRepository();
        grupEstudiRepository = gcnew GrupEstudiRepository();
        notificacioService = gcnew NotificacioService();
        Usuari^ destination_user = CurrentSession::Instance->GetCurrentUser();
        Int64^ id_destination = destination_user->GetUserId();
        Int64^ status = 1LL;
        Int64^ type = 1LL;
        List<Notificacio^>^ notificacions = notificacioService->ListNotificacions(id_destination, type, status);
        System::Collections::Generic::IEnumerator<Notificacio^>^ enumerator = notificacions->GetEnumerator();
        while (enumerator->MoveNext()) {
            Int64^ id_source = enumerator->Current->GetSourceUserId();
            Usuari^ user_source = usuariRepository->GetUsuariById(id_source);
            String^ nom_source = user_source->GetUsername();
            Int64^ id_grup = enumerator->Current->GetSourceGroupId();
            GrupEstudi^ grup_source = grupEstudiRepository->GetGrupEstudiById(id_grup);
            String^ nom_grup_source = grup_source->GetGroupName();
            Int64^ id_type = enumerator->Current->GetNotificationType();

            if (id_type == 1LL) Llista_Notificacions->Items->Add(nom_source + " ha solicitat unir-se al grup " + nom_grup_source);
            else Llista_Notificacions->Items->Add(nom_source + " t'ha invitat al grup " + nom_grup_source);


        }
    }

    System::Void NotificacionsUI::Acceptarbutton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        return System::Void();
    }

    System::Void NotificacionsUI::Rebutjarbutton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        return System::Void();
    }



    Void NotificacionsUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
        MainPageUI^ PanelUI = gcnew  MainPageUI();

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();

    }
}
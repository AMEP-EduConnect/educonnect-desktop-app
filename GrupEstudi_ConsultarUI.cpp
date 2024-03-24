#include "pch.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembership.h"
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "Usuari.h"
#include "CurrentSession.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI(void)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
    }

    void GrupEstudi_ConsultarUI::button_Consultar(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        //this->Close();

        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        array<Int64^>^ arrayIdGroupEstudisOfUser = grupEstudiMembershipService->LoadGrupsEstudiMembershipByUserId(currentUser->GetUserId());

        // Limpiar el ListBox antes de cargar los nuevos grupos
        listaNoms->Items->Clear();

        for (int i = 0; i < arrayIdGroupEstudisOfUser->Length; i++) {
            GrupEstudi^ grupEstudiUser = grupEstudiMembershipService->LoadAllGrupEstudibyId(arrayIdGroupEstudisOfUser[i]);
            listaNoms->Items->Add(grupEstudiUser->GetGroupName());
        }
        
        //Falta que el estudiant pugui gestionar els grups d'estudi que te
    }

    void GrupEstudi_ConsultarUI::button_Cancel(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        this->Close();
    }

    void GrupEstudi_ConsultarUI::listBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e)
    { }



}

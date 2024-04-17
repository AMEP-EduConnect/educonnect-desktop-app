#include "pch.h"
#include "GrupEstudi_MembresUI.h"
#include "Usuari.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {
    GrupEstudi_Membres::GrupEstudi_Membres(void)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
        grupEstudiService = gcnew GrupEstudiService();
        //this->Background_PictureBox->Image = Image::FromFile("background.png");
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void GrupEstudi_Membres::GrupEstudi_Membres_Load(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_Membresreload();
    }

    void GrupEstudi_Membres::GrupEstudi_Membresreload() {
        //Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        Int64^ id = gcnew Int64(61); //Falta que agafi el id del grup d'estudi que s'ha seleccionat
        array<Int64^>^ arrayIdMemberOfGroupEstudis = grupEstudiMembershipService->LoadMembershipByGrupsEstudi(id);

        // Limpiar el ListBox antes de cargar los nuevos miembros
        Membres_Box->Items->Clear();

        for (int i = 0; i < arrayIdMemberOfGroupEstudis->Length; i++) {
            Usuari^ grupEstudiUser = grupEstudiMembershipService->LoadAllUsersById(arrayIdMemberOfGroupEstudis[i]);
            Membres_Box->Items->Add(grupEstudiUser->GetUsername());
        }

        //Falta que el estudiant pugui gestionar els grups d'estudi que te
    }

    void GrupEstudi_Membres::CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        this->Hide();
        MainPageUI^ form = gcnew MainPageUI();
        form->ShowDialog();
        this->Close();
    }


    void GrupEstudi_Membres::Membres_Box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
    {
        Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
        //bool isOwner = grupEstudiService->CheckUserIsOwnerId(currentUser->GetUserId());

        /*if (isOwner) {
            Expulsar_Button->Visible = true;
            Assignar_Button->Visible = true;
        }
        if (not isOwner) {
            Expulsar_Button->Visible = false;
            Assignar_Button->Visible = false;
        }*/
    }
	
	void GrupEstudi_Membres::Expulsar_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Falta implementar
	}

    void GrupEstudi_Membres::Assignar_Button_Click(System::Object^ sender, System::EventArgs^ e)
    {
		//Falta implementar
	}
}
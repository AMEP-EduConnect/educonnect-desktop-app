#include "pch.h"
#include "GrupEstudi_AssignarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_AssignarUI::GrupEstudi_AssignarUI(String^ groupName)
    {
        InitializeComponent();
        grupEstudiMembershipService = gcnew GrupEstudiMembershipService;
        grupEstudiService = gcnew GrupEstudiService();
        notificacioService = gcnew NotificacioService();
        Noms_ListBox = nomsListBox;
        NomGrup_TextBox->Text = Noms_ListBox;
        this->Icon = gcnew System::Drawing::Icon("app.ico");
        this->Load += gcnew System::EventHandler(this, &GrupEstudi_AssignarUI::GEstudiAssignarAdminUI_Load);
    }

    void GrupEstudi_AssignarUI::CancelarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(groupName, true);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void GrupEstudi_AssignarUI::ConvidarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (NomUsuari_TextBox->Text != "") {
            if (NomGrup_TextBox->Text != "") {
                if (grupEstudiService->CheckIfUserExists(NomUsuari_TextBox->Text)) {
                    if (grupEstudiService->CheckIfGroupExists(NomGrup_TextBox->Text)) {
                        Int64^ user_id = grupEstudiService->GetUserIdByName(NomUsuari_TextBox->Text);
                        Int64^ group_id = grupEstudiService->GetGroupIdByName(NomGrup_TextBox->Text);
                        if (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id)) {
                            MessageManager::WarningMessage("L'usuari ja esta assignat al grup d'estudi.");
                            return;
                        }
                        else if (notificacioService->CheckIfInvitationExists(group_id, user_id)) {
                            MessageManager::WarningMessage("L'usuari ja t� una invitaci� pendent per aquest grup.");
                            return;
                        }
                        else {
                            bool owner = grupEstudiService->CheckUserIsOwner(NomGrup_TextBox->Text);
                            if (!owner) {
                                MessageManager::WarningMessage("No ets el propietari del grup.");
                            }
                            else {
                                Int64^ notification_type = 2LL;
                                Int64^ status = 1LL;
                                Int64^ source_user_id = CurrentSession::Instance->GetCurrentUser()->GetUserId();

                                notificacioService->AddNotificacio(notification_type, status, group_id, source_user_id, user_id);
                                NomUsuari_TextBox->Text = "";
                                NomGrup_TextBox->Text = "";
                                MessageManager::InfoMessage("Invitaci� enviada amb �xit.");

                                GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(Noms_ListBox, true);

                                PanelUI->TopLevel = false;
                                PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                                PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                                MainPageUI::Instance->screen->Controls->Clear();
                                MainPageUI::Instance->screen->Controls->Add(PanelUI);
                                PanelUI->Show();
                            }
                        }
                    }
                    else {
                        MessageManager::WarningMessage("El grup no existeix.");
                    }
                }
                else {
                    MessageManager::WarningMessage("L'usuari no existeix.");
                }
            }
            else {
                if(Noms_ListBox->Items->Count == 0) MessageManager::WarningMessage("No existeixen usuaris per a assignar");
                
                else MessageManager::WarningMessage("Selecciona un usuari");
            }
    }
    
    Void GrupEstudi_AssignarUI::buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (buscador_textBox->Text == "Buscar Usuari..." or buscador_textBox->Text == "") {
			Noms_ListBox->Items->Clear();
            GEstudiAssignarAdminUI_Load(sender, e);
        }
        else {
            Int64^ group_id = grupEstudiService->GetGroupIdByName(groupName);
            String^ buscar_user = buscador_textBox->Text;
            List<Usuari^>^ users = grupEstudiService->LoadStudentsByStartingLetter(group_id, buscar_user);
            Noms_ListBox->ForeColor = System::Drawing::Color::Black;
            Noms_ListBox->Enabled = true;
            if (users->Count == Noms_ListBox->Items->Count) {
 
                return;
            }
            Noms_ListBox->Items->Clear();
            System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = users->GetEnumerator();
            while (enumerator->MoveNext())
                Noms_ListBox->Items->Add(enumerator->Current->GetUsername());
            if (Noms_ListBox->Items->Count == 0) {
                MessageManager::ErrorMessage("No s'ha trobat cap usuari amb aquest nom");
                buscador_textBox->Enabled = false;
                buscador_textBox->Enabled = true;
                buscador_textBox->ForeColor = System::Drawing::SystemColors::ActiveCaption;
                buscador_textBox->Text = L"Buscar Usuari...";
            }
        }
        else {
            MessageManager::WarningMessage("Falten camps per omplir.");
        }
    }
}

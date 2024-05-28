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
        this->groupName = groupName;

		this->AssignarGrupEstudi_Label->Text = "Assignar Membre a " + groupName;
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

   /* void GrupEstudi_AssignarUI::AssignaButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (NomUsuari_TextBox->Text != "") {
            if (NomGrup_TextBox->Text != "") {
                if (grupEstudiService->CheckIfUserExists(NomUsuari_TextBox->Text)) {
					if (grupEstudiService->CheckIfGroupExists(NomGrup_TextBox->Text)) {
                        try {
                            Int64^ user_id = grupEstudiService->GetUserIdByName(NomUsuari_TextBox->Text);
                            Int64^ group_id = grupEstudiService->GetGroupIdByName(NomGrup_TextBox->Text);
                            if (grupEstudiMembershipService->CheckIfUserIsInGroup(user_id, group_id)) {
								MessageManager::WarningMessage("L'usuari ja esta assignat al grup d'estudi.");
								return;
							}
                            else {
                                bool owner = grupEstudiService->CheckUserIsOwner(NomGrup_TextBox->Text);
                                if (not owner) {
                                    MessageManager::WarningMessage("No ets el propietari del grup.");
                                }
                                else {
                                    grupEstudiMembershipService->UserToGroup(user_id, group_id);
                                    NomUsuari_TextBox->Text = "";
                                    NomGrup_TextBox->Text = "";
                                    MessageManager::InfoMessage("Usuari assignat al grup d'estudi amb exit.");
                                    
                                    GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(groupName, true);

                                    PanelUI->TopLevel = false;
                                    PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
                                    PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

                                    MainPageUI::Instance->screen->Controls->Clear();
                                    MainPageUI::Instance->screen->Controls->Add(PanelUI);
                                    PanelUI->Show();
                                }
                            }
                        }
                        catch (Exception^ e) {
                            MessageManager::ErrorMessage(e->Message);
                        }
					}
					else {
						MessageManager::WarningMessage("El grup no existeix.");
					}
				}
                else {
                    MessageManager::WarningMessage("L'usuari no existeix");
                }
            }
            else {
                MessageManager::WarningMessage("Falten camps per omplir.");
            }
        }
		else {
			MessageManager::WarningMessage("Falten camps per omplir.");
		}
    }
    */
    Void GrupEstudi_AssignarUI::buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        if (buscador_textBox->Text == "Buscar Usuari...") {
            GEstudiAssignarAdminUI_Load(sender, e);
        }
        else {
            String^ buscar_user = buscador_textBox->Text;
            List<Usuari^>^ users = grupEstudiService->LoadUsersByStartingLetter(buscar_user);
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
    }

    Void GrupEstudi_AssignarUI::GEstudiAssignarAdminUI_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Usuari^>^ users = grupEstudiService->LoadAllUsers();

        Noms_ListBox->Items->Clear();
        System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = users->GetEnumerator();
        while (enumerator->MoveNext())
            Noms_ListBox->Items->Add(enumerator->Current->GetUsername());
    }

    Void GrupEstudi_AssignarUI::buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e) {
        if (buscador_textBox->Text == "Buscar Usuari...") { buscador_textBox->Clear(); }
        buscador_textBox->ForeColor = Color::Black;
    }



}




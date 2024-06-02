#include "pch.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_InfoUI.h"
#include "MainPageUI.h"

namespace CppCLRWinFormsProject {

    GrupEstudi_EditarUI::GrupEstudi_EditarUI(String^ NomGrup)
    {
        InitializeComponent();
        NomActual_TextBox->Text = NomGrup;
        grupEstudiService = gcnew GrupEstudiService();
        EditarDescripcio_TextBox->Text = grupEstudiService->GetGroupDescription(NomGrup);
        nomActual = NomActual_TextBox->Text;
        descripcioActual = EditarDescripcio_TextBox->Text;
        this->NomActual_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->EditarDescripcio_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->NomActual_TextBox->Enabled = false;
        this->EditarDescripcio_TextBox->Multiline = true;
        this->EditarDescripcio_TextBox->Enabled = false;
        this->Icon = gcnew System::Drawing::Icon("app.ico");
    }

    void GrupEstudi_EditarUI::CancelarButton_Click(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(nomActual,1);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }

    void GrupEstudi_EditarUI::noModificarButton_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageManager::InfoMessage("No s'ha modificat cap camp.");
        NomActual_TextBox->Text = nomActual;
        EditarDescripcio_TextBox->Text = descripcioActual;
        this->NomActual_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));
        this->EditarDescripcio_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
            static_cast<System::Int32>(static_cast<System::Byte>(224)));

        this->NomActual_TextBox->Enabled = false;
        this->EditarDescripcio_TextBox->Enabled = false;

        Cancelar_Button->Visible = true;
        Edita_Button->Text = "Modificar";
        noModificarButton->Visible = false;
    }

    void GrupEstudi_EditarUI::testEdita_Button(System::Object^ sender, System::EventArgs^ e)
    {
        if (grupEstudiService->CheckIfGroupExists(nomActual)) {
            bool checkD = false;
            bool checkN = false;
            noModificarButton->Visible = true;
            Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
            Int64^ currentUser_id = currentUser->GetUserId();
            bool owner = grupEstudiService->CheckUserIsOwner(nomActual);

            this->NomActual_TextBox->BackColor = SystemColors::Window;
            this->EditarDescripcio_TextBox->BackColor = SystemColors::Window;
            NomActual_TextBox->Enabled = true;
            EditarDescripcio_TextBox->Enabled = true;

            if (EditarDescripcio_TextBox->Text == descripcioActual and NomActual_TextBox->Text == nomActual and Edita_Button->Text == "Guardar") {
                MessageManager::WarningMessage("Modifica almenys un camp per actualitzar el grup!");
            }

            Cancelar_Button->Visible = false;
            Edita_Button->Text = "Guardar";

            if (owner == false) {
                MessageManager::WarningMessage("No pots editar un grup que no siguis propietari.");
                return;
            }

            else {
                if (EditarDescripcio_TextBox->Text != descripcioActual) {
                    if (EditarDescripcio_TextBox->Text == "") {
                        MessageManager::WarningMessage("La descripció del grup no pot ser buida.");
                        EditarDescripcio_TextBox->Text = descripcioActual;
                    }
                    else {
                        grupEstudiService->ModifyGroupDescription(nomActual, EditarDescripcio_TextBox->Text);
                        checkD = true;
                    }
                }

                if (NomActual_TextBox->Text != nomActual) {
                    if (NomActual_TextBox->Text == "") {
						MessageManager::WarningMessage("El nom del grup no pot ser buit.");
                        NomActual_TextBox->Text = nomActual;
					}
                    else {
                        if (grupEstudiService->CheckIfGroupExists(NomActual_TextBox->Text) == false) {
                            try {
                                grupEstudiService->ModifyGroupName(nomActual, NomActual_TextBox->Text);
                                checkN = true;
                            }
                            catch (Exception^ e) {
                                MessageManager::ErrorMessage(e->Message);
                            }

                        }
                        else {
                            MessageManager::WarningMessage("Ja existeix un grup amb aquest nom.");
                        }
                    }
                }

                if (checkD == true and checkN == false) {
                    MessageManager::InfoMessage("Descripció del grup modificada correctament.");
                    this->NomActual_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                        static_cast<System::Int32>(static_cast<System::Byte>(224)));
                    this->EditarDescripcio_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                        static_cast<System::Int32>(static_cast<System::Byte>(224)));

                    this->NomActual_TextBox->Enabled = false;
                    this->EditarDescripcio_TextBox->Enabled = false;

                    Cancelar_Button->Visible = true;
                    Edita_Button->Text = "Modificar";

                    nomActual = NomActual_TextBox->Text;
                    descripcioActual = EditarDescripcio_TextBox->Text;
                    //CancelarButton_Click(sender, e);
                }
                else if (checkN == true and checkD == false) {
                    MessageManager::InfoMessage("Nom del grup modificat correctament.");
                    this->NomActual_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                        static_cast<System::Int32>(static_cast<System::Byte>(224)));
                    this->EditarDescripcio_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                        static_cast<System::Int32>(static_cast<System::Byte>(224)));

                    this->NomActual_TextBox->Enabled = false;
                    this->EditarDescripcio_TextBox->Enabled = false;

                    Cancelar_Button->Visible = true;
                    Edita_Button->Text = "Modificar";

                    nomActual = NomActual_TextBox->Text;
                    descripcioActual = EditarDescripcio_TextBox->Text;
                }
                else if (checkN == true and checkD == true) {
                    MessageManager::InfoMessage("Nom i descripció del grup modificats correctament.");
                    this->NomActual_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                        static_cast<System::Int32>(static_cast<System::Byte>(224)));
                    this->EditarDescripcio_TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                        static_cast<System::Int32>(static_cast<System::Byte>(224)));

                    this->NomActual_TextBox->Enabled = false;
                    this->EditarDescripcio_TextBox->Enabled = false;

                    Cancelar_Button->Visible = true;
                    Edita_Button->Text = "Modificar";

                    nomActual = NomActual_TextBox->Text;
                    descripcioActual = EditarDescripcio_TextBox->Text;
                }
            }
        }
        else {
            MessageManager::WarningMessage("No existeix cap grup amb aquest nom.");
        }
    }
}


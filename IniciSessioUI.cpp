#include "pch.h"
#include "IniciSessioUI.h"
#include "MainPageUI.h"
#include "FirstPageUI.h"
#include "CaptchaUI.h"
#include "StartPageUI.h"
#include "CurrentSession.h"
#include "Usuari.h"

using namespace System;


namespace CppCLRWinFormsProject {


    void IniciSessioUI::ContinuarIniciSessioButton_Click(System::Object^ sender, System::EventArgs^ e)
    {

        IniciSessioService inici;
        Usuari^ currentUser;
        String^ username = NomUsuari_TextBox->Text;
        String^ password = Contrasenya_TextBox->Text;

        if (username == "" or password == "") {
            CredencialsIncorrectes_Label->Visible = true;
            CredencialsIncorrectes_Label2->Visible = true;
        }
        else {

            bool check = inici.CheckUsername(username, password);

            CaptchaUI^ form = gcnew CaptchaUI();
            form->ShowDialog();
            StartPageUI::Instance->captcha_ok;

            if (check == true) {
                if (StartPageUI::Instance->captcha_ok) {
                    currentUser = CurrentSession::Instance->GetCurrentUser();
                    bool isBan = reportService->UserInBlacklist(currentUser->GetUserId());
                    if (isBan == true) {
                        bool checkBan = reportService->IsUserBlacklisted(currentUser->GetUserId());
                        if (checkBan == true) {
                            ban_label->Text = reportService->MessageBanInfo(currentUser->GetUserId());
                            ban_label->Visible = true;
                            descriptionBan_label->Text = "Motiu del ban: " +reportService->GetDescriptionBlacklist(currentUser->GetUserId());
                            descriptionBan_label->Visible = true;
                            CredencialsIncorrectes_Label->Visible = false;
                            CredencialsIncorrectes_Label2->Visible = false;
                            Contrasenya_TextBox->Text = "";
                        }
                        else {
							StartPageUI::Instance->Hide();
							MainPageUI::Instance = gcnew MainPageUI();
							MainPageUI::Instance->ShowDialog();
							StartPageUI::Instance->Close();
						}
                    }
                    else {
                        StartPageUI::Instance->Hide();
                        MainPageUI::Instance = gcnew MainPageUI();
                        MainPageUI::Instance->ShowDialog();
                        StartPageUI::Instance->Close();
                    }
                }
                else {
                    CredencialsIncorrectes_Label2->Visible = true;
                    CredencialsIncorrectes_Label->Visible = false;
                    ban_label->Visible = false;
                    descriptionBan_label->Visible = false;
                }
            }
            else {
                CredencialsIncorrectes_Label->Visible = true;
                CredencialsIncorrectes_Label2->Visible = false;
                ban_label->Visible = false;
                descriptionBan_label->Visible = false;
                Contrasenya_TextBox->Text = "";
            }

            CurrentSession::Instance->LogoutCurrentUser();
        }
    }


    Void IniciSessioUI::GoBackButton_Click(System::Object^ sender, System::EventArgs^ e)
    {

        FirstPageUI^ PanelUI = gcnew FirstPageUI();
        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        StartPageUI::Instance->screen->Controls->Clear();
        StartPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
        this->Close();
        //this->System::ComponentModel::Component::Dispose();
    }

    Void IniciSessioUI::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (password_visible) {
            this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
            this->Contrasenya_TextBox->PasswordChar = true;
            password_visible = false;
            this->Contrasenya_TextBox->UseSystemPasswordChar = true;
        }
        else {
            this->pictureBox1->Image = Image::FromFile("resources/Icons/eye.png");
            this->Contrasenya_TextBox->PasswordChar = false;
            password_visible = true;
            this->Contrasenya_TextBox->UseSystemPasswordChar = false;
        }

    }


}
#include "pch.h"
#include "BaixaUsuariUI.h"
#include "BaixaUsuariService.h"
#include "MessageManager.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "BaixaUsuariService.h"
#include "FirstPageUI.h"
#include "CurrentSession.h"
#include "MainPageUI.h"
#include "AdministradorUI.h"
#include "UsuariRolRepository.h"
#include "StartPageUI.h"
using namespace System;
namespace CppCLRWinFormsProject {

	BaixaUsuariUI::BaixaUsuariUI(void)
	{
		InitializeComponent();
		baixaUsuariService = gcnew BaixaUsuariService();
		this->label1->Text = L"Està a punt d\'eliminar el teu compte. Si hi estàs d\'acord, introdueix la teva contrasenya.";
		this->Icon = gcnew System::Drawing::Icon("app.ico");
		this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
	}

	Void BaixaUsuariUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		
			InformacioPersonal_ConsultaUI^ PanelUI = gcnew InformacioPersonal_ConsultaUI();
			PanelUI->TopLevel = false;
			PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
			MainPageUI::Instance->screen->Controls->Clear();
			MainPageUI::Instance->screen->Controls->Add(PanelUI);
			PanelUI->Show();
		
	}

	System::Void BaixaUsuariUI::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (password_visible) {
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye-crossed.png");
			this->textBox1->PasswordChar = true;
			password_visible = false;
			this->textBox1->UseSystemPasswordChar = true;
		}
		else {
			this->pictureBox1->Image = Image::FromFile("resources/Icons/eye.png");
			this->textBox1->PasswordChar = false;
			password_visible = true;
			this->textBox1->UseSystemPasswordChar = false;
		}
		
	}

	Void BaixaUsuariUI::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ value = textBox1->Text;
		if (value == "") {
				MessageManager::ErrorMessage("Introdueix la contrasenya");
		}
		else {
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir l'usuari '" + CurrentSession::Instance->GetCurrentUser()->GetUsername() + "'?", "Confirmation", buttons);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				bool eliminar = baixaUsuariService->BaixaUsuari(value);

				if (eliminar) {
					MessageManager::InfoMessage("Usuari eliminat correctament!");
					MainPageUI::Instance->Hide();
					StartPageUI::Instance = gcnew StartPageUI();
					StartPageUI::Instance->ShowDialog();
					MainPageUI::Instance->Close();
					
				}
				else
				{
					MessageManager::ErrorMessage("Contrasenya incorrecte!");
					textBox1->Text = "";
				}
			}
		}
	}
}
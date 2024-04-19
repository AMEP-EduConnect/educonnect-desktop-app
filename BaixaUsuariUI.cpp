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
using namespace System;
namespace CppCLRWinFormsProject {

	BaixaUsuariUI::BaixaUsuariUI(void)
	{
		InitializeComponent();
		baixaUsuariService = gcnew BaixaUsuariService();
		Int64^ rol = CurrentSession::Instance->GetCurrentUserRol();
		if (*rol != 1) this->label1->Text = L"Està a punt d\'eliminar el compte. Si hi estàs d\'acord, introdueix la teva contrasenya:";
		else {
			this->textBox1->UseSystemPasswordChar = false;
			this->textBox1->PasswordChar = '\0';
			this->label1->Text = L"Introdueix el usuari que es vol eliminar:";
		}
		//this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	Void BaixaUsuariUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		Int64^ rol = CurrentSession::Instance->GetCurrentUserRol();
		if (*rol == 1) {
			AdministradorUI^ PanelUI = gcnew AdministradorUI();
			PanelUI->TopLevel = false;
			PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
			MainPageUI::Instance->screen->Controls->Clear();
			MainPageUI::Instance->screen->Controls->Add(PanelUI);
			PanelUI->Show();
		}
		else {
			InformacioPersonal_ConsultaUI^ PanelUI = gcnew InformacioPersonal_ConsultaUI();
			PanelUI->TopLevel = false;
			PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
			MainPageUI::Instance->screen->Controls->Clear();
			MainPageUI::Instance->screen->Controls->Add(PanelUI);
			PanelUI->Show();
		}
	}

	Void BaixaUsuariUI::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ value = textBox1->Text;
		Int64^ rol = CurrentSession::Instance->GetCurrentUserRol();
		if (value == "") {
			if (*rol == 1)
				MessageManager::ErrorMessage("Introdueix l'usuari que es vol eliminar");
			else
				MessageManager::ErrorMessage("Introdueix la contrasenya");
		}
		else {
			bool eliminar = baixaUsuariService->BaixaUsuari(value);
			if (eliminar) {
				MessageManager::InfoMessage("Usuari eliminat correctament!");
				if (CurrentSession::Instance->GetCurrentUserRol() == nullptr) {
					this->Hide();
					FirstPageUI^ form = gcnew FirstPageUI();
					form->ShowDialog();
					this->Close();
				}
				else {
					this->Hide();
					InformacioPersonal_ConsultaUI^ form = gcnew InformacioPersonal_ConsultaUI();
					form->ShowDialog();
					this->Close();
				}
			}
			else
			{
				if (*rol != 1) MessageManager::ErrorMessage("Contrasenya incorrecta!");
				else MessageManager::ErrorMessage("Usuari no trobat!");
			}
		}
	}
}
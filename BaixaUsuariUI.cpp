#include "pch.h"
#include "BaixaUsuariUI.h"
#include "BaixaUsuariService.h"
#include "MessageManager.h"
#include "InformacioPersonal_ConsultaUI.h"
#include "BaixaUsuariService.h"
#include "FirstPageUI.h"
using namespace System;
namespace CppCLRWinFormsProject {

	BaixaUsuariUI::BaixaUsuariUI(void)
	{
		InitializeComponent();
		baixaUsuariService = gcnew BaixaUsuariService();
		//this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	Void BaixaUsuariUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		InformacioPersonal_ConsultaUI^ form = gcnew InformacioPersonal_ConsultaUI();
		form->ShowDialog();
		this->Close();
	}

	Void BaixaUsuariUI::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ password = textBox1->Text;
		if (password == "") {
			MessageManager::ErrorMessage("Introdueix la contrasenya");
		}
		else {
			bool eliminar = baixaUsuariService->BaixaUsuari(password);
			if (eliminar) {
				MessageManager::InfoMessage("Usuari eliminat correctament");
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
			else MessageManager::ErrorMessage("Contrasenya incorrecta");
		}
	}
}
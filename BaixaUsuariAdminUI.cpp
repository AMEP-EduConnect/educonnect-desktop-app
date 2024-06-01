#include "pch.h"
#include "BaixaUsuariAdminUI.h"
#include "AdministradorUI.h"
#include "MessageManager.h"
#include "CurrentSession.h"
#include "MainPageUI.h"
using namespace System;
namespace CppCLRWinFormsProject {
	BaixaUsuariAdminUI::BaixaUsuariAdminUI(void)
	{
		InitializeComponent();
		baixaUsuariService = gcnew BaixaUsuariService();
		this->Load += gcnew System::EventHandler(this, &BaixaUsuariAdminUI::BaixaUsuariAdminUI_Load);
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}

	Void BaixaUsuariAdminUI::BaixaUsuariAdminUI_Load(System::Object^ sender, System::EventArgs^ e) {
		List<Usuari^>^ users = baixaUsuariService->LoadAllUsers();
		
		Noms_ListBox->Items->Clear();
		System::Collections::Generic::IEnumerator<Usuari^>^ enumerator = users->GetEnumerator();
		while (enumerator->MoveNext())
			Noms_ListBox->Items->Add(enumerator->Current->GetUsername());
	}
	Void BaixaUsuariAdminUI::buscar_button_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ buscar_user = buscador_textBox->Text;
		if (Noms_ListBox->Items->Contains(buscar_user)) {
			Noms_ListBox->SelectedItem = buscar_user;
		}
		else {
			MessageManager::ErrorMessage("No s'ha trobat cap grup amb aquest nom");
			buscador_textBox->Clear();
		}
	}

	Void BaixaUsuariAdminUI::button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Noms_ListBox->SelectedItem == nullptr) {
			MessageManager::ErrorMessage("Selecciona un usuari!");
			return;
		}
			String^ value = Noms_ListBox->SelectedItem->ToString();
		if (value == CurrentSession::Instance->GetCurrentUser()->GetUsername()) {
			MessageManager::ErrorMessage("No pots eliminar el teu usuari");
		}
		else {
			MessageBoxButtons buttons = MessageBoxButtons::YesNo;
			System::Windows::Forms::DialogResult result = MessageBox::Show("Vols suprimir l'usuari '" + value + "'?", "Confirmation", buttons);
			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				bool eliminar = baixaUsuariService->BaixaUsuari(value);
				if (eliminar) {
						MessageManager::InfoMessage("Usuari eliminat correctament!");
						BaixaUsuariAdminUI_Load(sender, e);
				}
			}
		}
	}
	Void BaixaUsuariAdminUI::Cancelar_Button_Click(System::Object^ sender, System::EventArgs^ e) {
			AdministradorUI^ PanelUI = gcnew AdministradorUI();
			PanelUI->TopLevel = false;
			PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;
			MainPageUI::Instance->screen->Controls->Clear();
			MainPageUI::Instance->screen->Controls->Add(PanelUI);
			PanelUI->Show();
		}
	Void BaixaUsuariAdminUI::buscador_textBox_Click(System::Object^ sender, System::EventArgs^ e) {
		if (buscador_textBox->Text == "Buscar Usuari...") { buscador_textBox->Clear(); }
		buscador_textBox->ForeColor = Color::Black;
	}

	Void BaixaUsuariAdminUI::buscador_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (buscador_textBox->Text == "Buscar Usuari...") {
			BaixaUsuariAdminUI_Load(sender, e);
		}
		else {
			String^ buscar_user = buscador_textBox->Text;
			List<Usuari^>^ users = baixaUsuariService->LoadUsersByStartingLetter(buscar_user);
			if(users->Count == Noms_ListBox->Items->Count) {
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
		
}
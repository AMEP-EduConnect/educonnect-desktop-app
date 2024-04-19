#include "pch.h"
#include "GrupEstudi_ExplorarUI.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi_MembresUI.h"
#include "MainPageUI.h"
#include "GrupEstudi_AssignarUI.h"
#include "Usuari.h"

namespace CppCLRWinFormsProject {
	GrupEstudi_Explorar::GrupEstudi_Explorar(void)
	{
		InitializeComponent();
		grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
		grupEstudiService = gcnew GrupEstudiService();
		//this->Background_PictureBox->Image = Image::FromFile("background.png");
		this->Icon = gcnew System::Drawing::Icon("app.ico");
	}
	
	void GrupEstudi_Explorar::GrupEstudi_Explorar_Load(System::Object^ sender, System::EventArgs^ e) {

		Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
		array<Int64^>^ arrayIdGroupEstudisOfUser = grupEstudiMembershipService->LoadAllGrupsEstudiNoIn(currentUser->GetUserId());
		array<Int64^>^ arrayIdGrupsEstudiMembershipOfUser = grupEstudiMembershipService->LoadGrupsEstudiMembershipByUserId(currentUser->GetUserId());

		// Crear un nuevo array para almacenar los elementos únicos
		array<Int64>^ uniqueIds = gcnew array<Int64>(arrayIdGroupEstudisOfUser->Length);
		int uniqueCount = 0;
		// Iterar sobre el primer array
		for each (Int64 id in arrayIdGroupEstudisOfUser) {
			bool found = false;
			// Verificar si el elemento está presente en el segundo array
			for each (Int64 memId in arrayIdGrupsEstudiMembershipOfUser) {
				if (id == memId) {
					found = true;
					break;
				}
			}
			// Si el elemento no está en el segundo array, agregarlo a la lista de únicos
			if (!found) {
				uniqueIds[uniqueCount++] = id;
			}
		}
		// Crear un nuevo array del tamaño correcto para almacenar los elementos únicos
		array<Int64>^ arrayIdGroupEstudisOfUserNoIn = gcnew array<Int64>(uniqueCount);
		Array::Copy(uniqueIds, arrayIdGroupEstudisOfUserNoIn, uniqueCount);
		
		// Limpiar el ListBox antes de cargar los nuevos grupos
		Noms_ListBox->Items->Clear();

		for (int i = 0; i < arrayIdGroupEstudisOfUserNoIn->Length; i++) {
			GrupEstudi^ grupEstudiUser = grupEstudiMembershipService->LoadAllGrupEstudibyId(arrayIdGroupEstudisOfUserNoIn[i]);
			Noms_ListBox->Items->Add(grupEstudiUser->GetGroupName());
		}

		//Falta que el estudiant pugui gestionar els grups d'estudi que te
	}

	void GrupEstudi_Explorar::Noms_ListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
			Membres_Button->Visible = true;
			Unirse_Button->Visible = true;
			Cancela_Button->Visible = false;

			Description_titulo->Visible = true;
			Num_membres->Visible = true;
			academicTag_titulo->Visible = true;

			nummem->Clear();
			nummem->Visible = true;
			numero_membres(sender, e);

			academictag->Clear();
			academictag->Visible = true;
			academic_tag(sender, e);

			Description_ListBox->Items->Clear();
			Description_ListBox->Visible = true;
			Description_ListBox_Load(sender, e);
	}

	void GrupEstudi_Explorar::academic_tag(System::Object^ sender, System::EventArgs^ e) {
		GrupEstudi^ grupEstudi = grupEstudiService->GetGrupEstudiByName(Noms_ListBox->Text);
		Int64^ academic_tag_id = grupEstudi->GetGroupAcademicTag();
		String^ academic_tag_name = grupEstudiService->GetAcademicTagNameById(academic_tag_id);
		academictag->Text = academic_tag_name;
	}

	void GrupEstudi_Explorar::numero_membres(System::Object^ sender, System::EventArgs^ e) {
		Int64^ id_group = grupEstudiService->GetGroupIdByName(Noms_ListBox->Text);
		array<Int64^>^ arrayIdMemberOfGroupEstudis = grupEstudiMembershipService->LoadMembershipByGrupsEstudi(id_group);
		int num_mem_int = arrayIdMemberOfGroupEstudis->Length;
		String^ num_mem_str = Convert::ToString(num_mem_int);
		nummem->Text = num_mem_str;
	}

	void GrupEstudi_Explorar::Description_ListBox_Load(System::Object^ sender, System::EventArgs^ e) {
		//Int64^ idgrup = grupEstudiService->GetGroupIdByName(Noms_ListBox->Text);
		GrupEstudi^ grupEstudi = grupEstudiService->GetGrupEstudiByName(Noms_ListBox->Text);
		String^ description = grupEstudi->GetDescription();
		Description_ListBox->Items->Add(description);
	}

	void GrupEstudi_Explorar::Membres_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		GrupEstudi_Membres^ PanelUI = gcnew GrupEstudi_Membres(Noms_ListBox->Text, false);

		PanelUI->TopLevel = false;
		PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

		MainPageUI::Instance->screen->Controls->Clear();
		MainPageUI::Instance->screen->Controls->Add(PanelUI);
		PanelUI->Show();
	}
	
	void GrupEstudi_Explorar::Unirse_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		//Solicita unirse al grupo
		//FALTA IMPLEMENTAR SPRINT 3
		Unirse_Button->Visible = false;
		Cancela_Button->Visible = true;
	}
		
	void GrupEstudi_Explorar::Cancela_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		//Cancela solicitud unirse al grupo
		//FALTA IMPLEMENTAR SPRINT 3
		Unirse_Button->Visible = true;
		Cancela_Button->Visible = false;
	}
}
#include "pch.h"
#include "DatabaseConnector.h"
#include "GrupEstudiService.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"
//#include "GrupsEstudiMembership.h"


GrupEstudiService::GrupEstudiService()
{
	grupEstudiRepository = gcnew GrupEstudiRepository();
	//DatabaseConnector::Instance = gcnew DatabaseConnector();
}

array<AcademicTag^>^ GrupEstudiService::LoadAllAcademicTags()
{
	return grupEstudiRepository->LoadAllAcademicTags();
}

void GrupEstudiService::CreateNewGrupEstudi(String^ group_name, String^ description, String^ academic_tag)
{
	try {
		if (this->CheckIfGroupExists(group_name)) {
			MessageManager::WarningMessage("El grup ja existeix!");
			return;
		}
		else {
			Int64^ academic_tag_id = grupEstudiRepository->GetAcademicTagByTagName(academic_tag);
			Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
			grupEstudiRepository->CreateNewGrupEstudi(group_name, description, academic_tag_id, currentUser->GetUserId());
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

void GrupEstudiService::DeleteGrupEstudi(String^ grup_name)
{
	try {
		this->CheckIfCurrentUserIsGroupOwner(grup_name);
		grupEstudiRepository->DeleteGrupEstudi(grup_name);
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

bool GrupEstudiService::CheckIfCurrentUserIsGroupOwner(String^ grup_name) {
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	GrupEstudi^ grup = grupEstudiRepository->GetGrupEstudiByName(grup_name);
	if (grup->GetGroupOwnerId() == currentUser->GetUserId()) {
		return true;
	}
	else {
		MessageManager::WarningMessage("No tens permisos per a realitzar aquesta acci�!");
		return false;
	}
}

//ZITRO STUFF
// 
//

void GrupEstudiService::ModifyGroupName(String^ group_name_act, String^ group_name_new) {
	try {
		grupEstudiRepository->UpdateGroupName(group_name_act, group_name_new);
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

void GrupEstudiService::ModifyGroupDescription(String^ group_name_act, String^ description_new) {
	try {
		grupEstudiRepository->UpdateGroupDescription(group_name_act, description_new);
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

bool GrupEstudiService::CheckIfGroupExists(String^ group_name_act) {
	GrupEstudi^ grup = grupEstudiRepository->GetGrupEstudiByName(group_name_act);
	
	return not System::String::IsNullOrEmpty(grup->GetGroupName());
}

bool GrupEstudiService::CheckIfUserExists(String^ user_name) {
	bool user_exist = grupEstudiRepository->CheckIfUserExists(user_name);
	return user_exist;
}

Int64^ GrupEstudiService::GetUserIdByName(String^ user_name) {
	return grupEstudiRepository->GetUserIdByName(user_name);
}

Int64^ GrupEstudiService::GetGroupIdByName(String^ group_name) {
	return grupEstudiRepository->GetGroupIdByName(group_name);
}

bool GrupEstudiService::CheckUserIsOwner(Int64^ currentUser, String^ group_name) {
	return grupEstudiRepository->CheckUserIsOwner(currentUser, group_name);
}

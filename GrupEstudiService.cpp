#include "pch.h"
#include "GrupEstudiService.h"
#include <vector>

GrupEstudiService::GrupEstudiService()
{
	grupEstudiRepository = gcnew GrupEstudiRepository();
	grupEstudiMembershipService = gcnew GrupEstudiMembershipService();
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
			grupEstudiMembershipService->UserToGroup(currentUser->GetUserId(), grupEstudiRepository->GetGroupIdByName(group_name));
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

void GrupEstudiService::DeleteGrupEstudi(String^ grup_name)
{
	bool isOwner = this->CheckUserIsOwner(grup_name);
	if (isOwner) {
		grupEstudiRepository->DeleteGrupEstudi(grup_name);
	}
	
}

void GrupEstudiService::ModifyGroupName(String^ group_name_act, String^ group_name_new)
{
	try {
		grupEstudiRepository->UpdateGroupName(group_name_act, group_name_new);
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

void GrupEstudiService::ModifyGroupDescription(String^ group_name_act, String^ description_new)
{
	try {
		grupEstudiRepository->UpdateGroupDescription(group_name_act, description_new);
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	
}

bool GrupEstudiService::CheckIfGroupExists(String^ group_name_act)
{
	GrupEstudi^ grup = grupEstudiRepository->GetGrupEstudiByName(group_name_act);
	
	return not System::String::IsNullOrEmpty(grup->GetGroupName());
}

bool GrupEstudiService::CheckIfUserExists(String^ user_name)
{
	bool user_exist = grupEstudiRepository->CheckIfUserExists(user_name);
	return user_exist;
}

Int64^ GrupEstudiService::GetUserIdByName(String^ user_name)
{
	return grupEstudiRepository->GetUserIdByName(user_name);
}

Int64^ GrupEstudiService::GetGroupIdByName(String^ group_name)
{
	return grupEstudiRepository->GetGroupIdByName(group_name);
}

bool GrupEstudiService::CheckUserIsOwner(String^ group_name)
{
	return grupEstudiRepository->CheckUserIsOwner(group_name);
}

List<GrupEstudi^>^ GrupEstudiService::CheckNrecentGroups(Int64^ N, Int64^ user_id)
{
	List<GrupEstudi^>^ groups = gcnew List<GrupEstudi^>(0);

	List<Int64>^ groups_id = gcnew List<Int64>(0);

	groups_id = grupEstudiMembershipService->CheckNRecentGroups(N, user_id);
	IEnumerator<Int64>^ enumerator = groups_id->GetEnumerator();

	while(enumerator->MoveNext())
		groups->Add(grupEstudiRepository->GetGrupEstudiById(enumerator->Current));
		

	return groups; 
}
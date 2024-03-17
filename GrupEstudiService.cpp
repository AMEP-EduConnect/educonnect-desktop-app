#include "pch.h"
#include "DatabaseConnector.h"
#include "GrupEstudiService.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"
#include "MessageManager.h"
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
		Int64^ academic_tag_id = grupEstudiRepository->GetAcademicTagId(academic_tag);
		grupEstudiRepository->CreateNewGrupEstudi(group_name, description, academic_tag_id);
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
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
#include "pch.h"
#include "DatabaseConnector.h"
#include "GrupEstudiService.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"
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
	grupEstudiRepository->CreateNewGrupEstudi(group_name, description, academic_tag);
}


//ZITRO STUFF
// 
//

void GrupEstudiService::UpdateGroupName(String^ group_name_act, String^ group_name_new) {
	GrupEstudiRepository^ name_estudi = gcnew GrupEstudiRepository();
	return name_estudi->UpdateGroupName(group_name_act, group_name_new);
}

void GrupEstudiService::ModifyGroupName(String^ group_name_act, String^ group_name_new) {
	UpdateGroupName(group_name_act, group_name_new);
}



void GrupEstudiService::UpdateGroupDescription(String^ group_name_act, String^ description_new) {
	GrupEstudiRepository^ description_estudi = gcnew GrupEstudiRepository();
	return description_estudi->UpdateGroupDescription(group_name_act, description_new);
}

void GrupEstudiService::ModifyGroupDescription(String^ group_name_act, String^ description_new) {
	UpdateGroupDescription(group_name_act, description_new);
}



GrupEstudi^ GrupEstudiService::GetGrupEstudiByName(String^ group_name_act) {
	GrupEstudiRepository^ estudi = gcnew GrupEstudiRepository();
	return estudi->GetGrupEstudiByName(group_name_act);
}

bool GrupEstudiService::ExistGroup(String^ group_name_act) {
	bool check = true;
	GrupEstudi^ grup_estudi = GetGrupEstudiByName(group_name_act);
	if (grup_estudi->GetGroupName() == "") {
		check = false;
	}
	return check;

}
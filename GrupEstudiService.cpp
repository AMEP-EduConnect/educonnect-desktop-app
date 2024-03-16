#include "pch.h"
#include "DatabaseConnector.h"
#include "GrupEstudiService.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"


GrupEstudiService::GrupEstudiService()
{
	grupEstudiRepository = gcnew GrupEstudiRepository();
	//DatabaseConnector::Instance = gcnew DatabaseConnector();
}


//ZITRO STUFF
// 
//

void GrupEstudiService::UpdateGroupName(String^ group_name_act, String^ group_name_new) {
	GrupEstudiRepository^ name_estudi = gcnew GrupEstudiRepository();
	return name_estudi->UpdateGroupName(group_name_act, group_name_new);
}

void GrupEstudiService::modifyGroupName(String^ group_name_act, String^ group_name_new) {
	UpdateGroupName(group_name_act, group_name_new);
}



void GrupEstudiService::UpdateGroupDescription(String^ group_name_act, String^ description_new) {
	GrupEstudiRepository^ description_estudi = gcnew GrupEstudiRepository();
	return description_estudi->UpdateGroupDescription(group_name_act, description_new);
}

void GrupEstudiService::modifyGroupDescription(String^ group_name_act, String^ description_new) {
	UpdateGroupDescription(group_name_act, description_new);
}



GrupEstudi^ GrupEstudiService::GetGrupEstudiByName(String^ group_name_act) {
	GrupEstudiRepository^ estudi = gcnew GrupEstudiRepository();
	return estudi->GetGrupEstudiByName(group_name_act);
}

bool GrupEstudiService::existGroup(String^ group_name_act) {
	bool check = true;
	GrupEstudi^ grup_estudi = GetGrupEstudiByName(group_name_act);
	if (grup_estudi->getGroupName() == "") {
		check = false;
	}
	return check;

}
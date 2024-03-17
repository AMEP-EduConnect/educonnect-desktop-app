#pragma once
#include "GrupEstudiRepository.h"
#include <vector>
#include "AcademicTag.h"
public ref class GrupEstudiService
{
public:
	GrupEstudiService();
	
	array<AcademicTag^>^ LoadAllAcademicTags();
	void CreateNewGrupEstudi(String^ group_name, String^ description, String^ academic_tag);

//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiByName(String^ group_name);

	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void ModifyGroupName(String^ group_name_act, String^ group_name_new);

	void UpdateGroupDescription(String^ group_name_act, String^ description_new);
	void ModifyGroupDescription(String^ group_name_act, String^ description_new);

	bool ExistGroup(String^ group_name_act);

private:
	GrupEstudiRepository^ grupEstudiRepository;
};
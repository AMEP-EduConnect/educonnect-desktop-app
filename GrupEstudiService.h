#pragma once
#include "GrupEstudiRepository.h"
#include <vector>
#include "AcademicTag.h"
public ref class GrupEstudiService
{
public:
	GrupEstudiService();

	array<AcademicTag^>^ LoadAllAcademicTags();

//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiByName(String^ group_name);

	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void modifyGroupName(String^ group_name_act, String^ group_name_new);

	void UpdateGroupDescription(String^ group_name_act, String^ description_new);
	void modifyGroupDescription(String^ group_name_act, String^ description_new);

	bool existGroup(String^ group_name_act);

private:
	GrupEstudiRepository^ grupEstudiRepository;
};
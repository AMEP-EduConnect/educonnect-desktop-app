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
	void ModifyGroupName(String^ group_name_act, String^ group_name_new);
	void ModifyGroupDescription(String^ group_name_act, String^ description_new);

	bool CheckIfGroupExists(String^ group_name_act);

private:
	GrupEstudiRepository^ grupEstudiRepository;
};
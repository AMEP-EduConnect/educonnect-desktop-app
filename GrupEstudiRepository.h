#pragma once
#include "GrupEstudi.h"
#include "AcademicTag.h"
public ref class GrupEstudiRepository
{
public:
	GrupEstudiRepository();
	array<AcademicTag^>^ LoadAllAcademicTags();

//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiById(Int64^ id);

	GrupEstudi^ GetGrupEstudiByName(String^ group_name);
	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void UpdateGroupDescription(String^ group_name_act, String^ description_new);

};
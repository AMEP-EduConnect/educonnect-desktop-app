#pragma once
#include "GrupEstudi.h"
#include "AcademicTag.h"
public ref class GrupEstudiRepository
{
public:
	GrupEstudiRepository();
	array<AcademicTag^>^ LoadAllAcademicTags();
	void CreateNewGrupEstudi(String^ group_name, String^ description, String^ academic_tag);

	Int64^ GetAcademicTagId(String^ academic_tag);

//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiById(Int64^ id);

	GrupEstudi^ GetGrupEstudiByName(String^ group_name);
	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void UpdateGroupDescription(String^ group_name_act, String^ description_new);

};
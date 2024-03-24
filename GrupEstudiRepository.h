#pragma once
#include "GrupEstudi.h"
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include "Usuari.h"

public ref class GrupEstudiRepository
{
public:
	GrupEstudiRepository();
	array<AcademicTag^>^ LoadAllAcademicTags();
	void CreateNewGrupEstudi(String^ group_name, String^ description, Int64^ academic_tag_id, Int64^ current_user_id);
	void DeleteGrupEstudi(String^ group_name);
	Int64^ GetAcademicTagByTagName(String^ academic_tag);

//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiById(Int64^ id);

	GrupEstudi^ GetGrupEstudiByName(String^ group_name);
	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void UpdateGroupDescription(String^ group_name_act, String^ description_new);
	//array<GrupEstudi^>^ LoadGrupsEstudiByUserId(Int64^ user_id);

	bool CheckIfUserExists(String^ user_name);

	Int64^ GetUserIdByName(String^ user_name);
	Int64^ GetGroupIdByName(String^ group_name);

	bool CheckUserIsOwner(Int64^ currentUser, String^ group_name);

};
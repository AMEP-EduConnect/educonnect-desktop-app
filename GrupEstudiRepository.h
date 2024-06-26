#pragma once
#include "GrupEstudi.h"
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"

public ref class GrupEstudiRepository
{
public:
	GrupEstudiRepository();
	array<AcademicTag^>^ LoadAllAcademicTags();
	void CreateNewGrupEstudi(String^ group_name, String^ description, Int64^ academic_tag_id, Int64^ current_user_id);
	void DeleteGrupEstudi(String^ group_name);
	bool DeleteGrupEstudiById(Int64^ group_id);
	Int64^ GetAcademicTagByTagName(String^ academic_tag);

	GrupEstudi^ GetGrupEstudiById(Int64^ id);
	GrupEstudi^ GetGrupEstudiByName(String^ group_name);
	List<GrupEstudi^>^ GetNGrupEstudiByacademic_tag(Int64^ academic_tag, Int64^ user_id, Int64^ N);

	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void UpdateGroupDescription(String^ group_name_act, String^ description_new);

	bool CheckIfUserExists(String^ user_name);
	String^ GetGroupDescription(String^ NomGrup);

	Int64^ GetUserIdByName(String^ user_name);
	Int64^ GetGroupIdByName(String^ group_name);

	bool CheckUserIsOwnerById(Int64^ id_user, Int64^ id_group);
	String^ GetAcademicTagNameById(Int64^ academic_tag_id);

	bool CheckUserIsOwner(String^ group_name);

	array<GrupEstudi^>^ LoadGrupsNoMembers(Int64^ user_id);

	Int64^ GetGrupOwnerId(Int64^ group_id);

	void ChangeGroupOwner(Int64^ group_id, Int64^ new_owner_id);
};
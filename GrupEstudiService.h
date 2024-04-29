#pragma once
#include "GrupEstudiMembershipService.h"
#include <vector>
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"
#include "MessageManager.h"
#include "Usuari.h"
#include "CurrentSession.h"

public ref class GrupEstudiService
{
public:
	GrupEstudiService();

	array<AcademicTag^>^ LoadAllAcademicTags();
	void CreateNewGrupEstudi(String^ group_name, String^ description, String^ academic_tag);
	void DeleteGrupEstudi(String^ grup_name);
	//ZITRO STUFF
	// 
	// 
	void ModifyGroupName(String^ group_name_act, String^ group_name_new);
	void ModifyGroupDescription(String^ group_name_act, String^ description_new);

	bool CheckIfGroupExists(String^ group_name_act);
	bool CheckIfUserExists(String^ user_name);

	Int64^ GetUserIdByName(String^ user_name);
	Int64^ GetGroupIdByName(String^ group_name);
	String^ GetGroupDescription(String^ NomGrup);

	GrupEstudi^ GetGrupEstudiById(Int64^ id);
	GrupEstudi^ GetGrupEstudiByName(String^ group_name);
	String^ GetAcademicTagNameById(Int64^ academic_tag_id);

	bool CheckUserIsOwner(String^ group_name);
	bool CheckUserIsOwnerByIds(Int64^ user_id, Int64^ group_id);

	void ChangeGroupOwner(Int64^ group_id, Int64^ new_owner_id);
	bool DeleteGrupEstudiById(Int64^ id);

	array<GrupEstudi^>^ LoadGrupsNoMembers(Int64^ user_id);

private:
	GrupEstudiRepository^ grupEstudiRepository;
	GrupEstudiMembershipService^ grupEstudiMembershipService;
};
#pragma once
#include "GrupEstudiMembership.h"
#include "GrupEstudi.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include <vector>
#include "Usuari.h"

using namespace System;
public ref class GrupEstudiMembershipRepository
{
public:
	GrupEstudiMembershipRepository();

	array<Int64^>^ LoadGrupsEstudiMembershipByUserId(Int64^ user_id);
	array<GrupEstudiMembership^>^ LoadAllGrupsEstudiMembershipByUserId(Int64^ user_id);

	array<Int64^>^ LoadMembershipByGrupsEstudi(Int64^ group_id);
	array<Int64^>^ LoadAllGrupsEstudiNoIn(Int64^ user_id);

	void UserToGroup(Int64^ user_id, Int64^ group_id);
	//array<GrupEstudi^>^ LoadAllGrupEstudibyId(Int64^ group_id);
	GrupEstudi^ LoadAllGrupEstudibyId(Int64^ group_id);
	Usuari^ LoadAllUsersById(Int64^ user_id);

	bool CheckIfUserIsInGroup(Int64^ user_id, Int64^ group_id);
	void DeleteUserFromGroup(Int64^ user_id, Int64^ group_id);
	bool UserInSomeGroup(Int64^ user_id);
	Int64^ GetOldestUserInGroup(Int64^ group_id);
	Int64^ CheckIfGroupHasUsers(Int64^ group_id);
	List<Int64>^ CheckNRecentGroups(Int64^ N, Int64^ user_id);

};
	

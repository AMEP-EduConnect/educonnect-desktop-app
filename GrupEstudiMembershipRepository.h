#pragma once
#include "GrupEstudiMembership.h"
#include "GrupEstudi.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include <vector>

using namespace System;
public ref class GrupEstudiMembershipRepository
{
public:
	GrupEstudiMembershipRepository();

	array<Int64^>^ LoadGrupsEstudiMembershipByUserId(Int64^ user_id);
	void UserToGroup(Int64^ user_id, Int64^ group_id);
	//array<GrupEstudi^>^ LoadAllGrupEstudibyId(Int64^ group_id);
	GrupEstudi^ LoadAllGrupEstudibyId(Int64^ group_id);
	bool CheckIfUserIsInGroup(Int64^ user_id, Int64^ group_id);
	void DeleteUserFromGroup(Int64^ user_id, Int64^ group_id);
	Int64^ CheckIfGroupHasUsers(Int64^ group_id);
	Int64^ GetOldestUserInGroup(Int64^ group_id);
	std::vector<Int64> CheckNRecentGroups(Int64^ N, Int64^ user_id);

};
	

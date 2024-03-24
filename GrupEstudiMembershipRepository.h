#pragma once
#include "GrupEstudiMembership.h"
#include "GrupEstudi.h"
#include "AcademicTag.h"
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

};

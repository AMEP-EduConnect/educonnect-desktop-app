#pragma once
#include "GrupEstudiMembershipRepository.h"
#include "GrupEstudi.h"
#include <vector>
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "GrupEstudiMembership.h"
#include "MessageManager.h"
#include "Usuari.h"
public ref class GrupEstudiMembershipService
{
public:
	GrupEstudiMembershipService();

	array<Int64^>^ LoadGrupsEstudiMembershipByUserId(Int64^ user_id);
	array<Int64^>^ LoadMembershipByGrupsEstudi(Int64^ group_id);
	array<Int64^>^ LoadAllGrupsEstudiNoIn(Int64^ user_id);

	//array<GrupEstudi^>^ LoadAllGrupEstudibyId(Int64^ group_id);
	GrupEstudi^ LoadAllGrupEstudibyId(Int64^ group_id);
	Usuari^ LoadAllUsersById(Int64^ user_id);
	

	void UserToGroup(Int64^ user_id, Int64^ group_id);
	bool CheckIfUserIsInGroup(Int64^ user_id, Int64^ group_id);
	void DeleteUserFromGroup(Int64^ user_id, Int64^ group_id);

private:
	GrupEstudiMembershipRepository^ grupEstudiMembershipRepository;
};

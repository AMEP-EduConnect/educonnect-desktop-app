#pragma once
#include "GrupEstudiMembership.h"
#include "AcademicTag.h"
public ref class GrupEstudiMembershipRepository
{
public:
	GrupEstudiMembershipRepository();

	array<Int64^>^ LoadGrupsEstudiMembershipByUserId(Int64^ user_id);

};

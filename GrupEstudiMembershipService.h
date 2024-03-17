#pragma once
#include "GrupEstudiMembershipRepository.h"
#include <vector>
#include "AcademicTag.h"
public ref class GrupEstudiMembershipService
{
public:
	GrupEstudiMembershipService();

	array<Int64^>^ LoadGrupsEstudiMembershipByUserId(Int64^ user_id);

private:
	GrupEstudiMembershipRepository^ grupEstudiMembershipRepository;
};

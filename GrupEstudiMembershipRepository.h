#pragma once
#include "GrupEstudiMembership.h"
#include "AcademicTag.h"
using namespace System;
public ref class GrupEstudiMembershipRepository
{
public:
	GrupEstudiMembershipRepository();

	array<Int64^>^ LoadGrupsEstudiMembershipByUserId(Int64^ user_id);

};

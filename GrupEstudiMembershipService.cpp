#include "pch.h"
#include "DatabaseConnector.h"
#include "GrupEstudiMembershipService.h"
#include "GrupEstudiMembershipRepository.h"
#include "GrupEstudiMembership.h"


GrupEstudiMembershipService::GrupEstudiMembershipService()
{
	grupEstudiMembershipRepository = gcnew GrupEstudiMembershipRepository();
	//DatabaseConnector::Instance = gcnew DatabaseConnector();
}

array<Int64^>^ GrupEstudiMembershipService::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{	//el Int64^ user_id es el ID del usuario con la sessión iniciada !!!!!!!!!
	return grupEstudiMembershipRepository->LoadGrupsEstudiMembershipByUserId(user_id);
}
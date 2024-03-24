#include "pch.h"
#include "GrupEstudiMembershipService.h"



GrupEstudiMembershipService::GrupEstudiMembershipService()
{
	grupEstudiMembershipRepository = gcnew GrupEstudiMembershipRepository();
	//DatabaseConnector::Instance = gcnew DatabaseConnector();
}

array<Int64^>^ GrupEstudiMembershipService::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{	
	return grupEstudiMembershipRepository->LoadGrupsEstudiMembershipByUserId(user_id);
}

//array<GrupEstudi^>^ GrupEstudiMembershipService::LoadAllGrupEstudibyId(Int64^ group_id)
//{
//	return grupEstudiMembershipRepository->LoadAllGrupEstudibyId(group_id);
//}

GrupEstudi^ GrupEstudiMembershipService::LoadAllGrupEstudibyId(Int64^ group_id)
{
	return grupEstudiMembershipRepository->LoadAllGrupEstudibyId(group_id);
}

void GrupEstudiMembershipService::UserToGroup(Int64^ user_id, Int64^ group_id) {
	grupEstudiMembershipRepository->UserToGroup(user_id, group_id);
}

bool GrupEstudiMembershipService::CheckIfUserIsInGroup(Int64^ user_id, Int64^ group_id) {
	return grupEstudiMembershipRepository->CheckIfUserIsInGroup(user_id, group_id);
}

void GrupEstudiMembershipService::DeleteUserFromGroup(Int64^ user_id, Int64^ group_id) {
	grupEstudiMembershipRepository->DeleteUserFromGroup(user_id, group_id);
}
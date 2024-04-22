#include "pch.h"
#include "GrupEstudiMembershipService.h"



GrupEstudiMembershipService::GrupEstudiMembershipService()
{
	grupEstudiMembershipRepository = gcnew GrupEstudiMembershipRepository();
}

array<Int64^>^ GrupEstudiMembershipService::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{
	return grupEstudiMembershipRepository->LoadGrupsEstudiMembershipByUserId(user_id);
}

array<Int64^>^ GrupEstudiMembershipService::LoadMembershipByGrupsEstudi(Int64^ group_id) 
{
	return grupEstudiMembershipRepository->LoadMembershipByGrupsEstudi(group_id);
}

array<Int64^>^ GrupEstudiMembershipService::LoadAllGrupsEstudiNoIn(Int64^ user_id) {
	return grupEstudiMembershipRepository->LoadAllGrupsEstudiNoIn(user_id);
}

//array<GrupEstudi^>^ GrupEstudiMembershipService::LoadAllGrupEstudibyId(Int64^ group_id)
//{
//	return grupEstudiMembershipRepository->LoadAllGrupEstudibyId(group_id);
//}

GrupEstudi^ GrupEstudiMembershipService::LoadAllGrupEstudibyId(Int64^ group_id)
{
	return grupEstudiMembershipRepository->LoadAllGrupEstudibyId(group_id);
}

Usuari^ GrupEstudiMembershipService::LoadAllUsersById(Int64^ user_id)
{
	return grupEstudiMembershipRepository->LoadAllUsersById(user_id);
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

Int64^ GrupEstudiMembershipService::GetOldestUserInGroup(Int64^ group_id) {
	return grupEstudiMembershipRepository->GetOldestUserInGroup(group_id);
}

bool GrupEstudiMembershipService::UserInSomeGroup(Int64^ user_id) {
	return grupEstudiMembershipRepository->UserInSomeGroup(user_id);
}
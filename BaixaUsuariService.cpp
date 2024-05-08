#include "pch.h"
#include "BaixaUsuariService.h"
#include "CurrentSession.h"

BaixaUsuariService::BaixaUsuariService()
{
	usuariRepository = gcnew UsuariRepository();
	grupEstudiRepository = gcnew GrupEstudiRepository();
	grupEstudiMembershipRepository = gcnew GrupEstudiMembershipRepository();
	credentialMagamentService = gcnew CredentialManagementService();
}

bool BaixaUsuariService::BaixaUsuari(String^ value) {
		Int64^ id_user;
		if (*CurrentSession::Instance->GetCurrentUserRol() == 1LL) {
			bool check = usuariRepository->CheckUsuariByUser(value);
			if(not check) return false;
			id_user = usuariRepository->GetUserId(value);
		}
		else 
		{
			id_user = CurrentSession::Instance->GetCurrentUser()->GetUserId();
			bool check = credentialMagamentService->VerifyPassword(value, CurrentSession::Instance->GetCurrentUser()->GetPassword());
			if(check == false) return false;
		}
		array<Int64^>^ grups = grupEstudiMembershipRepository->LoadGrupsEstudiMembershipByUserId(id_user);
		int i = 0;

		while(i < grups->Length) {
			Int64^ count = grupEstudiMembershipRepository->CheckIfGroupHasUsers(grups[i]);
			if (grupEstudiRepository->CheckUserIsOwnerById(id_user, grups[i]) == true and *count > 1LL) {
				Int64^ new_owner = grupEstudiMembershipRepository->GetOldestUserInGroup(grups[i]);
				grupEstudiRepository->ChangeGroupOwner(grups[i], new_owner);
			}
			grupEstudiMembershipRepository->DeleteUserFromGroup(id_user, grups[i]);
			if (*count == 1LL) {
				bool delete_group = grupEstudiRepository->DeleteGrupEstudiById(grups[i]);
			}
			i++;
		}
		usuariRepository->DeleteUser(id_user);
		if(*CurrentSession::Instance->GetCurrentUserRol() != 1LL) CurrentSession::Instance->LogoutCurrentUser();
		return true;
}

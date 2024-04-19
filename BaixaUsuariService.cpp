#include "pch.h"
#include "BaixaUsuariService.h"
#include "CurrentSession.h"

BaixaUsuariService::BaixaUsuariService()
{
	usuariRepository = gcnew UsuariRepository();
	grupEstudiRepository = gcnew GrupEstudiRepository();
	grupEstudiMembershipRepository = gcnew GrupEstudiMembershipRepository();
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
			if(CurrentSession::Instance->GetCurrentUser()->GetPassword() != value) return false;
		}
		array<Int64^>^ grups = grupEstudiMembershipRepository->LoadGrupsEstudiMembershipByUserId(id_user);
		int i = 0;
		// Mentre hi hagi grups als quals pertany l'usuari
		while(i < grups->Length) {
			// Verificar si es owner del grup i que hi hagui més d'un usuari al grup
			Int64^ count = grupEstudiMembershipRepository->CheckIfGroupHasUsers(grups[i]);
			if (grupEstudiRepository->CheckUserIsOwnerById(id_user, grups[i]) == true and *count > 1LL) {
				Int64^ new_owner = grupEstudiMembershipRepository->GetOldestUserInGroup(grups[i]);
				grupEstudiRepository->ChangeGroupOwner(grups[i], new_owner);
			}
			// Eliminar usuari del grup
			grupEstudiMembershipRepository->DeleteUserFromGroup(id_user, grups[i]);
			// Si el grup queda sense membres, elimina el grup
			if (*count == 1LL) {
				bool delete_group = grupEstudiRepository->DeleteGrupEstudiById(grups[i]);
			}
			i++;
		}
		// Eliminar usuari
		usuariRepository->DeleteUser(id_user);
		if(*CurrentSession::Instance->GetCurrentUserRol() != 1LL) CurrentSession::Instance->LogoutCurrentUser();
		return true;
}

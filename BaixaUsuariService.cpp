#include "pch.h"
#include "BaixaUsuariService.h"
#include "CurrentSession.h"
#include "GrupEstudiMembershipRepository.h"
#include "GrupEstudiRepository.h"
BaixaUsuariService::BaixaUsuariService()
{
	usuariRepository = gcnew UsuariRepository();
}

bool BaixaUsuariService::BaixaUsuari(String^ password) {
	Int64^ id_user = CurrentSession::Instance->GetCurrentUser()->GetUserId();
	Int64^ not_id;
	if (id_user != not_id) {
		// Verificació de la contrasenya
		if(CurrentSession::Instance->GetCurrentUser()->GetPassword() != password) return false;
		GrupEstudiMembershipRepository^ grupEstudiMembershipRepository = gcnew GrupEstudiMembershipRepository();
		GrupEstudiRepository^ grupEstudiRepository = gcnew GrupEstudiRepository();
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
		CurrentSession::Instance->LogoutCurrentUser();
		return true;
	}
	else return false;
}

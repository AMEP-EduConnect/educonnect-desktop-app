#include "pch.h"
#include "PerfilPersonalModificaService.h"


PerfilPersonalModificaService::PerfilPersonalModificaService()
{
	usuariRepository = gcnew UsuariRepository();
}

bool PerfilPersonalModificaService::ModificaUsuari(String^ username, String^ password, String^ email, String^ nom)
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	if (username == "") {
		username = currentUser->GetUsername();
	}
	if (password == "") {
		password = currentUser->GetPassword();
	}
	if (email == "") {
		email = currentUser->GetEmail();
	}
	if (nom == "") {
		nom = currentUser->GetName();
	}
	return this->usuariRepository->UpdateUser(username, password, email, nom);	
}

bool PerfilPersonalModificaService::CheckUsername(String^ username)
{
	return this->usuariRepository->CheckUsuariByUser(username);
}

bool PerfilPersonalModificaService::CheckEmail(String^ email)
{
	return this->usuariRepository->CheckUsuariByEmail(email);
}
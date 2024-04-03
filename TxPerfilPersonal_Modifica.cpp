#include "pch.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "TxPerfilPersonal_Modifica.h"
#include "UsuariRepository.h"
#include "Usuari.h"

TxPerfilPersonal_Modifica::TxPerfilPersonal_Modifica()
{
	usuariRepository = gcnew UsuariRepository();
}

bool TxPerfilPersonal_Modifica::ModificaUsuari(String^ username, String^ password, String^ email, String^ nom)
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

bool TxPerfilPersonal_Modifica::CheckUsername(String^ username)
{
	return this->usuariRepository->CheckUsuariByUser(username);
}

bool TxPerfilPersonal_Modifica::CheckEmail(String^ email)
{
	return this->usuariRepository->CheckUsuariByEmail(email);
}
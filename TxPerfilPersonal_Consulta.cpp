#include "pch.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "TxPerfilPersonal_Consulta.h"
#include "UsuariRepository.h"
#include "Usuari.h"

TxPerfilPersonal_Consulta::TxPerfilPersonal_Consulta()
{
	usuariRepository = gcnew UsuariRepository();
}

Usuari^ TxPerfilPersonal_Consulta::GetCurrentUser()
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	return currentUser;
}
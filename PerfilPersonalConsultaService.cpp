#include "pch.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "PerfilPersonalConsultaService.h"
#include "UsuariRepository.h"
#include "Usuari.h"

PerfilPersonalConsultaService::PerfilPersonalConsultaService()
{
	usuariRepository = gcnew UsuariRepository();
}

Usuari^ PerfilPersonalConsultaService::GetCurrentUser()
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	return currentUser;
}
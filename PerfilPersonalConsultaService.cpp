#include "pch.h"
#include "PerfilPersonalConsultaService.h"


PerfilPersonalConsultaService::PerfilPersonalConsultaService()
{
	usuariRepository = gcnew UsuariRepository();
}

Usuari^ PerfilPersonalConsultaService::GetCurrentUser()
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	return currentUser;
}
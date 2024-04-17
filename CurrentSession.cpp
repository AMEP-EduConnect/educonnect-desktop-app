#include "pch.h"
#include "CurrentSession.h"

//Singleton class to Connect to get current session information
CurrentSession::CurrentSession()
{
	currentUser = nullptr;
    currentUserRol = nullptr;
}

void CurrentSession::LogNewUser(Usuari^ newUser, Int64^ id_rol)
{
    if (currentUser == nullptr) {
        MessageManager::InfoMessage("USUARI INICIAT CORRECTAMENT!");
        currentUser = newUser;
       currentUserRol = gcnew UsuariRol(newUser->GetUserId(), id_rol);
    }
    else MessageManager::WarningMessage("USUARI JA INICIAT");
}

void CurrentSession::LogoutCurrentUser()
{
    currentUser = nullptr;
}

Usuari^ CurrentSession::GetCurrentUser()
{
    return currentUser;
}
Int64^ CurrentSession::GetCurrentUserRol()
{
	return currentUserRol->GetRolId();
}   


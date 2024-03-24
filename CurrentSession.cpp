#include "pch.h"
#include "CurrentSession.h"

//Singleton class to connect to get current session information
CurrentSession::CurrentSession()
{
	currentUser = nullptr;
}

void CurrentSession::LogNewUser(Usuari^ newUser)
{
    if (currentUser == nullptr) {
        MessageManager::InfoMessage("USUARIO INICIADO");
        currentUser = newUser;
    }
    else MessageManager::WarningMessage("USUARIO YA INICIADO");
}

void CurrentSession::LogoutCurrentUser()
{
    currentUser = nullptr;
}

Usuari^ CurrentSession::GetCurrentUser()
{
    return currentUser;
}



#include "pch.h"
#include "CurrentSession.h"
#include "MessageManager.h"
#include "UsuariRepository.h"
//Singleton class to connect to get current session information
CurrentSession::CurrentSession()
{
    currentUser = nullptr;
    
    //currentUser = gcnew Usuari(a, "Pepe1234", "Pepe1234", "pepe@gmail.com", "Pepe");   
   
    /*this->currentUser->SetName("pepe");
    this->currentUser->SetEmail("pepe@gmail.com");
    this->currentUser->SetUsername("Pepe1234");
    this->currentUser->SetPassword("Pepe1234");
    this->currentUser->SetUserId(a);*/
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
    Int64^ a = gcnew Int64(1);
    Usuari^ user = gcnew Usuari;
    UsuariRepository^ user_ = gcnew UsuariRepository;
    user = user_->GetUsuariById(a);
    return user;
    //return currentuser;
}
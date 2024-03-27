#pragma once
#include "Usuari.h"
#include "MessageManager.h"
using namespace System;

public ref class CurrentSession
{
public:
	static CurrentSession^ Instance;
	CurrentSession();
    void LogNewUser(Usuari^ newUser);
    Usuari^ GetCurrentUser();
    void LogoutCurrentUser();

private:
	Usuari^ currentUser;
};
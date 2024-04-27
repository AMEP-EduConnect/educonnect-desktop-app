#pragma once
#include "Usuari.h"
#include "UsuariRol.h"
#include "MessageManager.h"
using namespace System;

public ref class CurrentSession
{
public:
	static CurrentSession^ Instance;
	CurrentSession();
	void LogNewUser(Usuari^ newUser, Int64^ id_rol);
	Usuari^ GetCurrentUser();
	Int64^ GetCurrentUserRol();
	void LogoutCurrentUser();

private:
	Usuari^ currentUser;
	UsuariRol^ currentUserRol;
};

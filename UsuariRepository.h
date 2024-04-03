#pragma once
#include "Usuari.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include <vector>

public ref class UsuariRepository
{
public:

	UsuariRepository();
	Usuari^ GetUsuariById(Int64^ id);
	Usuari^ GetUsuariByPassUser(String^ username, String^ password);
	Usuari^ GetUsuariByUser(String^ username);
	bool CheckUsuariByUser(String^ username);
    bool CheckUsuariByEmail(String^ email);
	Int64^ CreateUser(String^ username, String^ email, String^ name, String^ password);
	bool CreateUserRol(Int64^ id);
	bool UpdateUser(String^ username, String^ password, String^ email, String^ name);
};

#pragma once
#include "Usuari.h"

public ref class UsuariRepository
{
	public:

		UsuariRepository();
		Usuari^ GetUsuariById(Int64^ id);
		Usuari^ GetUsuariByPassUser(String^ username, String^ password);
		Usuari^ GetUsuariByUser(String^ username);
		bool CheckUsuariByUser(String^ username);
        bool CheckUsuariByEmail(String^ email);
		bool CreateUser(String^ username, String^ email, String^ name, String^ password);
		
};

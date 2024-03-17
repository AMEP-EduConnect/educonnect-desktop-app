#pragma once
#include "Usuari.h"
// PASARELA
public ref class UsuariRepository
{
	public:

		UsuariRepository();
		Usuari^ GetUsuariById(Int64^ id);
		Usuari^ GetUsuariByPassUser(String^ username, String^ password);
		bool CheckUsuariByUser(String^ username);
};

#pragma once
#include "Usuari.h"

public ref class UsuariRepository
{
	public:

		UsuariRepository();
		Usuari^ GetUsuariById(Int64^ id);
		Usuari^ GetUsuariByUsername(String^ user);

};

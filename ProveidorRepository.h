#pragma once
#include "Usuari.h"
public ref class ProveidorRepository
{
public:
	ProveidorRepository();
	bool CreateNewProveidor(String^ username, String^ email, String^ name, String^ password);
	bool CheckIfProveidorExists(String^username);
	bool CreateUserRol(Int64^ id);
	Usuari^ GetProveidorByName(String^ username);
	void DeleteProveidor(String^ name);
	bool CheckIfIsProveidor(Int64^ providerId);
	Int64^ CheckProveidorandGetId(String^ username);
};



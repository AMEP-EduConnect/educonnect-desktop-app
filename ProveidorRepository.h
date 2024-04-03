#pragma once
#include "Proveidor.h"
public ref class ProveidorRepository
{
public:
	ProveidorRepository();
	bool AltaProveidor(String^ username, String^ email, String^ name, String^ password);
	bool CheckIfProveidorExists(String^username);
	bool CreateUserRol(Int64^ id);
	Proveidor^ GetProveidorByName(String^ username);
	void BaixaProveidor(String^ name);
	//Proveidor^ GetProveidorByName(String^ name);
};



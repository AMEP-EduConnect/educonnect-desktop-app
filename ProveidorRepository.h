#pragma once
#include "Proveidor.h"
public ref class ProveidorRepository
{
public:
	ProveidorRepository();
	bool AltaProveidor(String^ username, String^ email, String^ name, String^ password);
	Int64^ CheckIfProveidorExists(String^username);
	bool CreateUserRol(Int64^ id);
	Proveidor^ GetProveidorByName(String^ username);
	void BaixaProveidor(String^ name);
	bool CheckIfIsProveidor(Int64^ providerId);
};



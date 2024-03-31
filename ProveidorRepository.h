#pragma once
#include "Proveidor.h"
public ref class ProveidorRepository
{
public:
	ProveidorRepository();
	void ProveidorRepository::AltaProveidor(String^ id, String^ username, String^ password, String^ email, String^ surname);
	Proveidor^ GetProveidorByName(String^ username);
	void BaixaProveidor(String^ name);
	//Proveidor^ GetProveidorByName(String^ name);
};



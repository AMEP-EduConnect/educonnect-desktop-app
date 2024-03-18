#pragma once
#include "Proveidor.h"
public ref class ProveidorRepository
{
public:
	ProveidorRepository();
	void AltaProveidor(String^ name);
	Proveidor^ GetProveidorByName(String^ name);
};


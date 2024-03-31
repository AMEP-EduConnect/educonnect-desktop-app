#pragma once
#include "Proveidor.h"
public ref class ProveidorRepository
{
public:
	ProveidorRepository();
	void BaixaProveidor(String^ name);
	Proveidor^ GetProveidorByName(String^ name);
};


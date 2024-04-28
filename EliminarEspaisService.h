#pragma once
#include "Espais.h"
#include "EspaisRepository.h"
public ref class EliminarEspaisService
{
public:
	EliminarEspaisService();
	bool eliminarEspais(String^ name);
	Espais^ getEspai(String^ name);

private:
	EspaisRepository^ espaisRepository;
};


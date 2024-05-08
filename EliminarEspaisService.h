#pragma once
#include "Espai.h"
#include "EspaisRepository.h"
public ref class EliminarEspaisService
{
public:
	EliminarEspaisService();
	bool eliminarEspais(String^ name);
	Espai^ getEspai(String^ name);

private:
	EspaisRepository^ espaisRepository;
};


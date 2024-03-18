#pragma once
#include "InformacioPersonalRepository.h"
#include <vector>

public ref class InformacioPersonalService
{
public:
	InformacioPersonalService();
	Usuari^ GetUsuariById(Int64^ id);

	private:
		InformacioPersonalRepository^ informacioPersonalRepository;
};
#pragma once

#include "Usuari.h"
#include <vector>

public ref class InformacioPersonalRepository
{
public:
	InformacioPersonalRepository();
	Usuari^ GetUsuariById(Int64^ id);
};

#pragma once
#include "Usuari.h"
#include "Espais.h"
#include "EspaisRepository.h"
#include <vector>

public ref class AltaEspaisService
{
public:
    AltaEspaisService();
    bool AltaEspai(String^ nom, Int64^ capacitat);

private:
    EspaisRepository^ espaisRepository;
    Usuari^ usuari;
    Espais^ espais;

};

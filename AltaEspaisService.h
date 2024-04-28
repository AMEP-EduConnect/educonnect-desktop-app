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
    bool CheckNameEspai(String^ name);

private:
    EspaisRepository^ espaisRepository;
    Usuari^ usuari;
    Espai^ espais;

};

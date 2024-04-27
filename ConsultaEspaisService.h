#pragma once
#include "Espais.h"
#include "EspaisRepository.h"
using namespace System::Collections::Generic;
public ref class ConsultaEspaisService
{
public:
    ConsultaEspaisService();
    List<Espais^>^ ListEspais(Int64^ id_prov);
private:
    EspaisRepository^ espaisRepository;


};


#pragma once
#include "Espai.h"
#include "EspaisRepository.h"
using namespace System::Collections::Generic;
public ref class ConsultaEspaisService
{
public:
    ConsultaEspaisService();
    List<Espai^>^ ListEspais(Int64^ id_prov);
private:
    EspaisRepository^ espaisRepository;


};


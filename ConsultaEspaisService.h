#pragma once
#include "Espais.h"
#include "EspaisRepository.h"
using namespace System::Collections::Generic;
public ref class ConsultaEspaisService
{
public:
    ConsultaEspaisService();
    List<Espai^>^ ListEspais(Int64^ id_prov);
    bool CheckIfEspaiExistsByName(String^ name);
    Int64^ GetEspaiIdByName(String^ name);
    Espai^ GetEspaiByEspaiId(Int64^ id);
    String^ GetEspaiInfoById(Int64^ id);
private:
    EspaisRepository^ espaisRepository;


};


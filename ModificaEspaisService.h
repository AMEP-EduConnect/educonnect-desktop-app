
#include "Usuari.h"
#include "Espai.h"
#include "EspaisRepository.h"
#include <vector>

public ref class ModificaEspaisService
{
public:
    ModificaEspaisService();
    bool CheckNameEspai(String^ name);
    //bool GetEspaiByProviderid(String^ provider);
    bool UpdateEspai(String^ name, Int64^ capacity, Int64^ id_espai);
    Espai^ GetEspaiByName(String^ name);
private:
    EspaisRepository^ espaisRepository;
    Usuari^ usuari;
    Espai^ espais;

};

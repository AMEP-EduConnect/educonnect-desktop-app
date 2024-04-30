
#include "Usuari.h"
#include "Espai.h"
#include "EspaisRepository.h"
#include <vector>

public ref class ModificaEspaisService
{
public:
    ModificaEspaisService();
    bool CheckNameEspai(String^ name);
    bool UpdateEspai(String^ name);
    Espai^ GetEspaiByName(String^ name);
private:
    EspaisRepository^ espaisRepository;
    Usuari^ usuari;
    Espai^ espais;

};

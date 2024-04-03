#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class AltaProveidorService
{
public:
    AltaProveidorService();

    void AltaProveidor(String^ id, String^ username, String^ password, String^ email, String^ surname);
    bool CheckIfProveidorExists(String^ name);


private:
    ProveidorRepository^ proveidorRepository;
}; 

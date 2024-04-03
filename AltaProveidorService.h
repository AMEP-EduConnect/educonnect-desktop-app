#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class AltaProveidorService
{
public:
    AltaProveidorService();

    bool AltaProveidor(String^ username, String^ email, String^ name, String^ password);
    bool CheckIfProveidorExists(String^ name);


private:
    ProveidorRepository^ proveidorRepository;
}; 

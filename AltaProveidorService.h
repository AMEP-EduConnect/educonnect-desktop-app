#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include <vector>

public ref class AltaProveidorService
{
public:
    AltaProveidorService();

    bool AltaProveidor(String^ username, String^ email, String^ name, String^ password);

private:
    UsuariRepository^ usuariRepository;
    UsuariRolRepository^ usuariRolRepository;
}; 

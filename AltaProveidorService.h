#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include <vector>
#include "CredentialManagementService.h"
public ref class AltaProveidorService
{
public:
    AltaProveidorService();

    bool AltaProveidor(String^ username, String^ email, String^ name, String^ password);

private:
    UsuariRepository^ usuariRepository;
    UsuariRolRepository^ usuariRolRepository;
    CredentialManagementService^ credentialManagementService;
}; 

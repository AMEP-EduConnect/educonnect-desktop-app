#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include "GrupEstudiMembershipRepository.h"
#include "GrupEstudiRepository.h"
#include "CredentialManagementService.h"
public ref class BaixaUsuariService
{
public:
		BaixaUsuariService();
		bool BaixaUsuari(String^ username);

		List<Usuari^>^ LoadAllUsers();

		List<Usuari^>^ LoadUsersByStartingLetter(String^ username);

private:
	UsuariRepository^ usuariRepository;
	GrupEstudiMembershipRepository^ grupEstudiMembershipRepository;
	GrupEstudiRepository^ grupEstudiRepository;
	CredentialManagementService^ credentialMagamentService;
};
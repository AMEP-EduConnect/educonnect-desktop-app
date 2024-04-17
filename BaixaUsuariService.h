#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include "GrupEstudiMembershipRepository.h"
#include "GrupEstudiRepository.h"
public ref class BaixaUsuariService
{
public:
		BaixaUsuariService();
		bool BaixaUsuari(String^ username);

private:
	UsuariRepository^ usuariRepository;
	GrupEstudiMembershipRepository^ grupEstudiMembershipRepository;
	GrupEstudiRepository^ grupEstudiRepository;
};
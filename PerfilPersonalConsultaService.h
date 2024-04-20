#pragma once
#include "UsuariRepository.h"
#include "InformacioPersonal_ConsultaUI.h"


public ref class PerfilPersonalConsultaService
{
public:
	PerfilPersonalConsultaService();

	Usuari^ GetCurrentUser();

private:
	UsuariRepository^ usuariRepository;
};
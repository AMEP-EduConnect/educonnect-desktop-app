#pragma once
#include "UsuariRepository.h"
#include "Usuari.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"


public ref class PerfilPersonalConsultaService
{
public:
	PerfilPersonalConsultaService();

	Usuari^ GetCurrentUser();

private:
	UsuariRepository^ usuariRepository;
};
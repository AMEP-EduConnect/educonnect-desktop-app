#pragma once
#include "UsuariRepository.h"
#include "InformacioPersonal_ConsultaUI.h"
public ref class TxPerfilPersonal_Consulta
{
public:
	TxPerfilPersonal_Consulta();

	Usuari^ GetCurrentUser();

private:
	UsuariRepository^ usuariRepository;
};
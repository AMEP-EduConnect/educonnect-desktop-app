#pragma once
#include "UsuariRepository.h"

public ref class PerfilPersonalModificaService
{
public:
	PerfilPersonalModificaService();

	bool ModificaUsuari(String^ username, String^ password, String^ email, String^ nom);
	bool CheckUsername(String^ username);
	bool CheckEmail(String^ email);

private:
	UsuariRepository^ usuariRepository;
};
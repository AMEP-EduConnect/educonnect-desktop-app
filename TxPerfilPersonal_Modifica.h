#pragma once
#include "UsuariRepository.h"

public ref class TxPerfilPersonal_Modifica
{
public:
	TxPerfilPersonal_Modifica();

	bool ModificaUsuari(String^ username, String^ password, String^ email, String^ nom);
	bool CheckUsername(String^ username);
	bool CheckEmail(String^ email);

private:
	UsuariRepository^ usuariRepository;
};
#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
public ref class RegistreService
{
	
	public:

		RegistreService();

		bool CheckUsername(String^ username);
        bool CheckEmail(String^ email);
		bool CreateUser(String^ username, String^ email, String^ name, String^ password);

	private:

		UsuariRepository^ usuariRepository;
		UsuariRolRepository^ usuariRolRepository;
};
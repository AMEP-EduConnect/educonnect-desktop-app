#pragma once
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
public ref class TxRegistre
{
	
	public:

		TxRegistre();

		bool CheckUsername(String^ username);
        bool CheckEmail(String^ email);
		bool CreateUser(String^ username, String^ email, String^ name, String^ password);

	private:

		UsuariRepository^ usuariRepository;

};
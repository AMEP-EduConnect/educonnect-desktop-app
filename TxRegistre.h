#pragma once
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
public ref class TxRegistre
{
	
	public:

		TxRegistre();

		bool CheckUsername(String^ username);


	private:

		UsuariRepository^ usuariRepository;

};
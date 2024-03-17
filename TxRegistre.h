#pragma once
#include "UsuariRepository.h"

public ref class TxRegistre
{
	
	public:

		TxRegistre();

		bool CheckUsername(String^ username);


	private:

		UsuariRepository^ usuariRepository;

};
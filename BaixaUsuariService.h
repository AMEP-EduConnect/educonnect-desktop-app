#pragma once
#include "UsuariRepository.h"
public ref class BaixaUsuariService
{
public:
		BaixaUsuariService();
		bool BaixaUsuari(String^ password);

private:
	UsuariRepository^ usuariRepository;
};
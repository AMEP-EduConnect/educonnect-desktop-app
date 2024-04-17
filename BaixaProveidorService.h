#pragma once
#include "UsuariRepository.h"
#include "UsuariRolRepository.h"
#include <vector>

public ref class BaixaProveidorService
{
public:
	BaixaProveidorService();
	bool BaixaProveidor(String^ username);

private:
	UsuariRepository^ usuariRepository;
	UsuariRolRepository^ usuariRolRepository;
};

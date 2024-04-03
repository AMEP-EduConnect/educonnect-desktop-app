#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class BaixaProveidorService
{
public:
	BaixaProveidorService();

	bool BaixaProveidor(String^ username);

	bool CheckIfProveidorExists(String^ username);

private:
	ProveidorRepository^ proveidorRepository;
};

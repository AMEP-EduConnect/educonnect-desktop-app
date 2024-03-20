#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class ProveidorService
{
public:
	ProveidorService();

	void BaixaProveidor(String^ name);
	bool CheckIfProveidorExists(String^ name);


private:
	ProveidorRepository^ proveidorRepository;
};
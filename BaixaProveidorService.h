#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class BaixaProveidorService
{
public:
	BaixaProveidorService();

	void BaixaProveidor(String^ name);
	//void AltaProveidor(String^ id, String^ username, String^ password, String^ email, String^ surname);
	bool CheckIfProveidorExists(String^ name);


private:
	ProveidorRepository^ proveidorRepository;
};
#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class ProveidorService
{
public:
	ProveidorService();

	void AltaProveidor(String ^ name); 
	bool CheckIfProveidorExists(String^ name);


private:
	ProveidorRepository^ proveidorRepository;
};
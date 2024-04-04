#pragma once
#include "ProveidorRepository.h"
#include <vector>

public ref class BaixaProveidorService
{
public:
	BaixaProveidorService();
	bool BaixaProveidor(String^ username);
	Int64^ CheckProveidorExists(String^ username);
	bool CheckIsProveidor(Int64^ id_role);

private:
	ProveidorRepository^ proveidorRepository;
};

#pragma once
#include "DatabaseConnector.h"
#include "Espais.h"
#include <vector>
using namespace System::Collections::Generic;
public ref class EspaisRepository
{
public:

	EspaisRepository();
	bool CreateEspai(String^ name, Int64^ capacity, Int64^ proveidor_id);
	List<Espai^>^ GetEspaisById(Int64^ proveidor_id);
	Espai^ GetEspaiByName(String^ name);
	bool DeleteEspai(Int64^ id);
	bool CheckEspaiByName(String^ name);
};
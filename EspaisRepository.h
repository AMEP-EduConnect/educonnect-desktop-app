#pragma once
#include "DatabaseConnector.h"
#include "Espai.h"
#include <vector>
using namespace System::Collections::Generic;
public ref class EspaisRepository
{
public:

	EspaisRepository();
	bool UpdateEspaiName(String^ name);
	bool UpdateEspaiCapacity(Int64^ capacity);
	bool CreateEspai(String^ name, Int64^ capacity, Int64^ proveidor_id);
	List<Espai^>^ GetEspaiById(Int64^ proveidor_id);
	Espai^ GetEspaiByName(String^ name);
	bool DeleteEspai(Int64^ id);
	bool CheckEspaiByName(String^ name);
};
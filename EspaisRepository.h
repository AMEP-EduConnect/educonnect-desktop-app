#pragma once
#include "DatabaseConnector.h"
#include "Espais.h"
#include <vector>
using namespace System::Collections::Generic;
public ref class EspaisRepository
{
public:

	EspaisRepository();
	bool CreateEspai(String^ name, Int64^ capacity, Int64^ user_id);
	List<Espais^>^ GetEspaisById(Int64^ id_prov);
	Espais^ GetEspaiByName(String^ name);
	bool DeleteEspai(Int64^ id);
};
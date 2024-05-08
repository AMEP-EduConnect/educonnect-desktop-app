#pragma once
#include "DatabaseConnector.h"
#include "Espai.h"
#include <vector>
using namespace System::Collections::Generic;
public ref class EspaisRepository
{
public:

	EspaisRepository();
	
	bool UpdateEspai(String^ name, Int64^ capacity, Int64^ id_espai);
	bool CreateEspai(String^ name, Int64^ capacity, Int64^ proveidor_id);
	List<Espai^>^ GetEspaisById(Int64^ proveidor_id);
	Espai^ GetEspaiByEspaiId(Int64^ espai_id);
	Espai^ GetEspaiByName(String^ name);
	bool DeleteEspai(Int64^ id);
	String^ GetInfoEspaiById(Int64^ id);
	bool CheckEspaiByName(String^ name, Int64^ provider_id);
};

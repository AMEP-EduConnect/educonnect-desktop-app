#pragma once
#include "DatabaseConnector.h"
#include "Espais.h"
#include <vector>

public ref class EspaisRepository
{
public:

	EspaisRepository();
	//Espais^ GetEspaiById(Int64^ id);
	//Espais^ GetEspaiByPassUser(String^ username, String^ password);
	//Espais^ GetEspaiByUser(String^ username);

	bool CreateEspai(String^ nombre, Int64^ capacidad_grupos, Int64^ provider_id);

	//bool DeleteEspai(Int64^ id);

	//bool UpdateEspai(String^ username, String^ password, String^ email, String^ name);
	//Int64^ GetEspaiId(String^ username);
};
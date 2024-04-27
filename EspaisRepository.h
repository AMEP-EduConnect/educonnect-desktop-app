#pragma once
#include "DatabaseConnector.h"
#include "Espais.h"
#include <vector>

public ref class EspaisRepository
{
public:

	EspaisRepository();
	bool CreateEspai(String^ name, Int64^ capacity, Int64^ user_id);

};
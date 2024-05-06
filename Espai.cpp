#include "pch.h"
#include "Espai.h"

Espai::Espai()
{

}

Espai::Espai(Int64^ espai_id, String^ name, Int64^ capacity, Int64^ proveidor_id)
{
	this->espai_id = espai_id;
	this->name = name;
	this->capacity = capacity;
	this->provider_id = proveidor_id;
}

void Espai::SetEspaiId(Int64^ value)
{
    this->espai_id = value;
}


Int64^ Espai::GetEspaiId()
{
    return this->espai_id;
}



void Espai::SetName(String^ value)
{
    this->name = value;
}


String^ Espai::GetName()
{
    return this->name;
}


void Espai::SetCapacity(Int64^ value)
{
    this->capacity = value;
}


Int64^ Espai::GetCapacity()
{
    return this->capacity;
}


void Espai::SetId_provider(Int64^ value)
{
    this->provider_id = value;
}


Int64^ Espai::GetId_provider()
{
    return this->provider_id;
}



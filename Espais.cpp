#include "pch.h"
#include "Espais.h"

Espai::Espai()
{

}

Espai::Espai(Int64^ espai_id, String^ name, Int64^ capacity, Int64^ proveidor_id)
{
	this->espai_id = espai_id;
	this->name = name;
	this->capacity = capacity;
	this->proveidor_id = proveidor_id;
}

void Espai::SetEspaiId(Int64^ value)
{
    this->espai_id = value;
}


Int64^ Espai::GetEspaiId()
{
    return this->espai_id;
}



void Espai::SetNom(String^ value)
{
    this->name = value;
}


String^ Espai::GetNom()
{
    return this->name;
}


void Espai::SetCapacitat(Int64^ value)
{
    this->capacity = value;
}


Int64^ Espai::GetCapacitat()
{
    return this->capacity;
}


void Espai::SetId_proveidor(Int64^ value)
{
    this->proveidor_id = value;
}


Int64^ Espai::GetId_proveidor()
{
    return this->proveidor_id;
}



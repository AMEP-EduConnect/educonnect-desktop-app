#include "pch.h"
#include "Espais.h"

Espais::Espais()
{
	espai_id;
	nom = "";
	capacitat;
	id_proveidor;
	

}

Espais::Espais(Int64^ espai_id, String^ nom, Int64^ capacitat, Int64^ id_proveidor)
{
	this->espai_id = espai_id;
	this->nom = nom;
	this->capacitat = capacitat;
	this->id_proveidor = id_proveidor;
}

void Espais::SetEspaiId(Int64^ value)
{
    this->espai_id = value;
}


Int64^ Espais::GetEspaiId()
{
    return this->espai_id;
}



void Espais::SetNom(String^ value)
{
    this->nom = value;
}


String^ Espais::GetNom()
{
    return this->nom;
}


void Espais::SetCapacitat(Int64^ value)
{
    this->capacitat = value;
}


Int64^ Espais::GetCapacitat()
{
    return this->capacitat;
}


void Espais::SetId_proveidor(Int64^ value)
{
    this->id_proveidor = value;
}


Int64^ Espais::GetId_proveidor()
{
    return this->id_proveidor;
}



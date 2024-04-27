#pragma once

using namespace System;

public ref class Espais
{
public:
	Espais();

	Espais(Int64^ espai_id, String^ nom, Int64^ capacitat, Int64^ id_proveidor);

	void SetEspaiId(Int64^ value);
	Int64^ GetEspaiId();


	void SetNom(String^ value);
	String^ GetNom();


	void SetCapacitat(Int64^ value);
	Int64^ GetCapacitat();


	void SetId_proveidor(Int64^ value);
	Int64^ GetId_proveidor();


private:
	property Int64^ espai_id;
	property String^ nom;
	property Int64^ capacitat;
	property Int64^ id_proveidor;

};

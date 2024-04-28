#pragma once

using namespace System;

public ref class Espai
{
public:
	Espai();

	Espai(Int64^ espai_id, String^ name, Int64^ capacity, Int64^ proveidor_id);

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
	property String^ name;
	property Int64^ capacity;
	property Int64^ proveidor_id;

};

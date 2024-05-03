#pragma once

using namespace System;

public ref class Espai
{
public:
	Espai();

	Espai(Int64^ espai_id, String^ name, Int64^ capacity, Int64^ provider_id);

	void SetEspaiId(Int64^ value);
	Int64^ GetEspaiId();

	

	void SetName(String^ value);
	String^ GetName();


	void SetCapacity(Int64^ value);
	Int64^ GetCapacity();


	void SetId_provider(Int64^ value);
	Int64^ GetId_provider();


private:
	property Int64^ espai_id;
	property String^ name;
	property Int64^ capacity;
	property Int64^ provider_id;

};

#pragma once
using namespace System;
public ref class Proveidor
{
public:

	Proveidor();
	// Constructor
	Proveidor(String^ name);

private:

	property String^ name;

public:

	//getters

	String^ GetProveidorName();

	//setters

	void SetProveidorName(String^ name);

};
//prova
#pragma once
using namespace System;

public ref class UsuariRol
{
	public:
	UsuariRol();
	UsuariRol(Int64^ user_id, Int64^ rol_id);
	void SetUserId(Int64^ value);
	Int64^ GetUserId();
	void SetRolId(Int64^ value);
	Int64^ GetRolId();
private:
	Int64^ user_id;
	Int64^ rol_id;
};


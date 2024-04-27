#pragma once
using namespace System;
using namespace System::Collections::Generic;
public ref class UsuariRolRepository
{
	public:
	UsuariRolRepository();
	bool CreateUserRol(Int64^ user_id, Int64^ rol_id);
	bool DeleteUserRol(Int64^ id);
	Int64^ GetRolId(Int64^ user_id);
	List<Int64>^ GetUsersByRolId(Int64^ rol_id);
};


#pragma once

using namespace System;

public ref class GrupSessionAttendant
{
public:
	GrupSessionAttendant();
	GrupSessionAttendant(Int64^ id, Int64^ idsession, Int64^ iduser);

	Int64^ GetId();
	Int64^ GetIdSession();
	Int64^ GetIdUser();

	void SetId(Int64^ id);
	void SetIdSession(Int64^ idsession);
	void SetIdUser(Int64^ iduser);

private:
	property Int64^ id;
	property Int64^ idsession;
	property Int64^ iduser;

};


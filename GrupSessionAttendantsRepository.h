#pragma once

using namespace System;

public ref class GrupSessionAttendantsRepository
{
public:
	GrupSessionAttendantsRepository();
	void AsistirSessionAttendant(Int64^ idsession, Int64^ iduser);
	void EliminaSessionAttendant(Int64^ idsession, Int64^ iduser);
	bool IsAttendant(Int64^ idsession, Int64^ iduser);
	Int64^ GetSessionAttendantsCount(Int64^ idsession);
};


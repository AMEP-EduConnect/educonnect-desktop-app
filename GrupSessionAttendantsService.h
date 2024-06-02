#pragma once
#include "GrupSessionAttendantsRepository.h"

using namespace System;

public ref class GrupSessionAttendantsService
{
public:
	GrupSessionAttendantsService();

	void AsistirSessionAttendant(Int64^ idsession, Int64^ iduser);
	void EliminaSessionAttendant(Int64^ idsession, Int64^ iduser);
	bool IsAttendant(Int64^ idsession, Int64^ iduser);
	Int64^ GetSessionAttendantsCount(Int64^ idsession);
	array<Int64^>^ GetIdSessions(Int64^ iduser);

private:
	GrupSessionAttendantsRepository^ grupSessionAttendantsRepository;
};


#include "pch.h"
#include "GrupSessionAttendantsService.h"

GrupSessionAttendantsService::GrupSessionAttendantsService()
{
	grupSessionAttendantsRepository = gcnew GrupSessionAttendantsRepository();
}

void GrupSessionAttendantsService::AsistirSessionAttendant(Int64^ idsession, Int64^ iduser)
{
	this->AsistirSessionAttendant(idsession, iduser);
}

void GrupSessionAttendantsService::EliminaSessionAttendant(Int64^ idsession, Int64^ iduser)
{
	this->EliminaSessionAttendant(idsession, iduser);
}

bool GrupSessionAttendantsService::IsAttendant(Int64^ idsession, Int64^ iduser)
{
	return this->IsAttendant(idsession, iduser);
}



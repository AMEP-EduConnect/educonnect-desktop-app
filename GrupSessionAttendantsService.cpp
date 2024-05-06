#include "pch.h"
#include "GrupSessionAttendantsService.h"

GrupSessionAttendantsService::GrupSessionAttendantsService()
{
	grupSessionAttendantsRepository = gcnew GrupSessionAttendantsRepository();
}

void GrupSessionAttendantsService::AsistirSessionAttendant(Int64^ idsession, Int64^ iduser)
{
	grupSessionAttendantsRepository->AsistirSessionAttendant(idsession, iduser);
}

void GrupSessionAttendantsService::EliminaSessionAttendant(Int64^ idsession, Int64^ iduser)
{
	grupSessionAttendantsRepository->EliminaSessionAttendant(idsession, iduser);
}

bool GrupSessionAttendantsService::IsAttendant(Int64^ idsession, Int64^ iduser)
{
	return grupSessionAttendantsRepository->IsAttendant(idsession, iduser);
}



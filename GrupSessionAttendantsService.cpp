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

Int64^ GrupSessionAttendantsService::GetSessionAttendantsCount(Int64^ idsession)
{
	return grupSessionAttendantsRepository->GetSessionAttendantsCount(idsession);
}

array<Int64^>^ GrupSessionAttendantsService::GetIdSessions(Int64^ iduser)
{
	return grupSessionAttendantsRepository->GetIdSessions(iduser);
}



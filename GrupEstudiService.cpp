#include "pch.h"
#include "DatabaseConnector.h"
#include "GrupEstudiService.h"
#include "GrupEstudiRepository.h"
#include "GrupEstudi.h"


GrupEstudiService::GrupEstudiService()
{
	grupEstudiRepository = gcnew GrupEstudiRepository();
}

array<AcademicTag^>^ GrupEstudiService::LoadAllAcademicTags()
{
	return grupEstudiRepository->LoadAllAcademicTags();
}


//ZITRO STUFF
// 
// 
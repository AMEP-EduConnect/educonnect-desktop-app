#pragma once
#include "GrupEstudiRepository.h"
#include <vector>
#include "AcademicTag.h"
public ref class GrupEstudiService
{
public:
	GrupEstudiService();

	array<AcademicTag^>^ LoadAllAcademicTags();

//ZITRO STUFF
// 
// 

private:
	GrupEstudiRepository^ grupEstudiRepository;
};
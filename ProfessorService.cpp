#include "pch.h"
#include "DatabaseConnector.h"
#include "ProfessorService.h"
#include "ProfessorRepository.h"
#include "Professor.h"


ProfessorService::ProfessorService()
{
	professorRepository = gcnew ProfessorRepository();
}

Professor^ ProfessorService::GetProfessorById(Int64^ id)
{
	return professorRepository->GetProfessorById(id);
}

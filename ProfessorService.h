#pragma once
#include "ProfessorRepository.h"
#include <vector>
public ref class ProfessorService
{
public:
	ProfessorService();

	Professor^ GetProfessorById(Int64^ id);

	//std::vector<Professor^> GetAllProfessors();

	//void AddProfessor(Professor^ professor);
	//void UpdateProfessor(Professor^ professor);
	// DeleteProfessor(Int64^ id);

	private:
		ProfessorRepository^ professorRepository;
};
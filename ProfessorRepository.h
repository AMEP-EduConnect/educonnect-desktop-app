#pragma once
#include "Professor.h"
#include <vector>
using namespace System::Collections::Generic;

public ref class ProfessorRepository
{
public:
	ProfessorRepository();
	Professor^ GetProfessorById(Int64^ id);
	//std::vector<Professor^> GetAllProfessors();
	//void AddProfessor(Professor^ professor);
	//void UpdateProfessor(Professor^ professor);
	//void DeleteProfessor(Int64^ id);

};
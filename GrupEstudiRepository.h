#pragma once
#include "GrupEstudi.h"

public ref class GrupEstudiRepository
{
public:
	GrupEstudiRepository();
	//std::vector<Professor^> GetAllProfessors();
	//void AddProfessor(Professor^ professor);
	//void UpdateProfessor(Professor^ professor);
	//void DeleteProfessor(Int64^ id);


//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiById(Int64^ id);

	GrupEstudi^ GetGrupEstudiByName(String^ group_name);
	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void UpdateGroupDescription(String^ group_name_act, String^ description_new);

};
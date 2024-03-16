#pragma once
#include "GrupEstudiRepository.h"
#include <vector>
public ref class GrupEstudiService
{
public:
	GrupEstudiService();

	

	//std::vector<Professor^> GetAllProfessors();

	//void AddProfessor(Professor^ professor);
	//void UpdateProfessor(Professor^ professor);
	// DeleteProfessor(Int64^ id);

//ZITRO STUFF
// 
// 
	GrupEstudi^ GetGrupEstudiByName(String^ group_name);

	void UpdateGroupName(String^ group_name_act, String^ group_name_new);
	void modifyGroupName(String^ group_name_act, String^ group_name_new);

	void UpdateGroupDescription(String^ group_name_act, String^ description_new);
	void modifyGroupDescription(String^ group_name_act, String^ description_new);

	bool existGroup(String^ group_name_act);

private:
	GrupEstudiRepository^ grupEstudiRepository;
};
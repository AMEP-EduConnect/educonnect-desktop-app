#include "pch.h"
#include "ProfessorRepository.h"
#include "DatabaseConnector.h"

ProfessorRepository::ProfessorRepository()
{

}

Professor^ ProfessorRepository::GetProfessorById(Int64^ id)
{
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM professors WHERE id = " + id;
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Professor^ professor = gcnew Professor();
	while (data->Read())
	{
		professor->id = data->GetInt64(0);
		professor->name = data->GetString(1);
		professor->surname = data->GetString(2);
	}
	return professor;

}


#include "pch.h"
#include "GrupEstudiRepository.h"
#include "DatabaseConnector.h"

GrupEstudiRepository::GrupEstudiRepository()
{

}



//ZITRO STUFF
// 
// 

GrupEstudi^ GrupEstudiRepository::GetGrupEstudiById(Int64^ id)
{
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM studyGroups WHERE id = " + id;
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	GrupEstudi^ grupestudi = gcnew GrupEstudi();
	while (data->Read())
	{
		grupestudi->setId(data->GetInt64(0));
		grupestudi->setGroupName(data->GetString(1));
		grupestudi->setGroupOwnerId(data->GetInt64(2));
		grupestudi->setGroupAcademicTag(data->GetInt64(3));
		grupestudi->setDescription(data->GetString(4));
	}
	return grupestudi;
}

GrupEstudi^ GrupEstudiRepository::GetGrupEstudiByName(String^ group_name_act) {
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM studyGroups WHERE group_name = " + group_name_act;
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	GrupEstudi^ grupestudi = gcnew GrupEstudi();

	while (data->Read())
	{
		grupestudi->setId(data->GetInt64(0));
		grupestudi->setGroupName(data->GetString(1));
		grupestudi->setGroupOwnerId(data->GetInt64(2));
		grupestudi->setGroupAcademicTag(data->GetInt64(3));
		grupestudi->setDescription(data->GetString(4));
	}
	DatabaseConnector::Instance->disconnect();
	return grupestudi;
}


void GrupEstudiRepository::UpdateGroupName(String^ group_name_act, String^ group_name_new) {
	DatabaseConnector::Instance->connect();
	//String^ sql = "UPDATE studyGroups SET group_name = '@group_name_new' WHERE group_name = '@group_name_act'";
	String ^ sql = "UPDATE studyGroups SET group_name = '" + group_name_new + "' WHERE group_name = '" + group_name_act + "'";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->getConn());
	//command->Parameters->AddWithValue("@group_name_new", group_name_new);
	//command->Parameters->AddWithValue("@group_name_act", group_name_act);

	int rowsAffected = command->ExecuteNonQuery();

	DatabaseConnector::Instance->disconnect();

	Console::WriteLine(rowsAffected + " rows updated.");
}

void GrupEstudiRepository::UpdateGroupDescription(String^ group_name_act, String^ description_new) {
	DatabaseConnector::Instance->connect();
	//String^ sql = "UPDATE studyGroups SET description = '@description_new' WHERE group_name = '@group_name_act'";
	String^ sql = "UPDATE studyGroups SET group_name = '" + description_new + "' WHERE group_name = '" + group_name_act + "'";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->getConn());
	//command->Parameters->AddWithValue("@description_new", description_new);
	//command->Parameters->AddWithValue("@group_name_act", group_name_act);

	int rowsAffected = command->ExecuteNonQuery();

	DatabaseConnector::Instance->disconnect();

	Console::WriteLine(rowsAffected + " rows updated.");
}

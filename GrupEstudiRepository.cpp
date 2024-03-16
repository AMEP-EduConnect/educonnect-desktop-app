#include "pch.h"
#include "GrupEstudiRepository.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
GrupEstudiRepository::GrupEstudiRepository()
{

}
array<AcademicTag^>^ GrupEstudiRepository::LoadAllAcademicTags()
{
	array<AcademicTag^>^ academicTags = gcnew array<AcademicTag^>(0);
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM academicTags";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	while (data->Read())
	{
		AcademicTag^ academicTag = gcnew AcademicTag();
		academicTag->SetId(data->GetInt64(0));
		academicTag->SetTagName(data->GetString(1));
		Array::Resize(academicTags, academicTags->Length + 1);
		academicTags[academicTags->Length - 1] = academicTag;
	}
	DatabaseConnector::Instance->disconnect();
	return academicTags;
}

void GrupEstudiRepository::CreateNewGrupEstudi(String^ group_name, String^ description, String^ academic_tag)
{
	DatabaseConnector::Instance->connect();
	//TODO: recoger el id del usuario logeado, falta hacer la instancia de la sesión de usuario
	String^ sql = "INSERT INTO studyGroups (group_name, group_owner_id, group_academic_tag, description) VALUES ('" + group_name + "', 1, " + academic_tag + ", '" + description + "')";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->getConn());
	command->ExecuteNonQuery();
	DatabaseConnector::Instance->disconnect();
}

Int64^ GrupEstudiRepository::GetAcademicTagId(String^ academic_tag)
{
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT id from academicTags where tag_name = '"+academic_tag+"'";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Int64^ lastId = nullptr;
	while (data->Read())
	{
		lastId = data->GetInt64(0);
	}
	DatabaseConnector::Instance->disconnect();
	return lastId;
}


//ZITRO STUFF
// 
// 

GrupEstudi^ GrupEstudiRepository::GetGrupEstudiById(Int64^ id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroups WHERE id = " + id;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	GrupEstudi^ grupestudi = gcnew GrupEstudi();
	while (data->Read())
	{
		grupestudi->SetId(data->GetInt64(0));
		grupestudi->SetGroupName(data->GetString(1));
		grupestudi->SetGroupOwnerId(data->GetInt64(2));
		grupestudi->SetGroupAcademicTag(data->GetInt64(3));
		grupestudi->SetDescription(data->GetString(4));
	}
	return grupestudi;
}

GrupEstudi^ GrupEstudiRepository::GetGrupEstudiByName(String^ group_name_act) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroups WHERE group_name = " + group_name_act;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	GrupEstudi^ grupestudi = gcnew GrupEstudi();

	while (data->Read())
	{
		grupestudi->SetId(data->GetInt64(0));
		grupestudi->SetGroupName(data->GetString(1));
		grupestudi->SetGroupOwnerId(data->GetInt64(2));
		grupestudi->SetGroupAcademicTag(data->GetInt64(3));
		grupestudi->SetDescription(data->GetString(4));
	}
	DatabaseConnector::Instance->Disconnect();
	return grupestudi;
}


void GrupEstudiRepository::UpdateGroupName(String^ group_name_act, String^ group_name_new) {
	DatabaseConnector::Instance->Connect();
	//String^ sql = "UPDATE studyGroups SET group_name = '@group_name_new' WHERE group_name = '@group_name_act'";
	String ^ sql = "UPDATE studyGroups SET group_name = '" + group_name_new + "' WHERE group_name = '" + group_name_act + "'";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
	//command->Parameters->AddWithValue("@group_name_new", group_name_new);
	//command->Parameters->AddWithValue("@group_name_act", group_name_act);

	int rowsAffected = command->ExecuteNonQuery();

	DatabaseConnector::Instance->Disconnect();

	Console::WriteLine(rowsAffected + " rows updated.");
}

void GrupEstudiRepository::UpdateGroupDescription(String^ group_name_act, String^ description_new) {
	DatabaseConnector::Instance->Connect();
	//String^ sql = "UPDATE studyGroups SET description = '@description_new' WHERE group_name = '@group_name_act'";
	String^ sql = "UPDATE studyGroups SET group_name = '" + description_new + "' WHERE group_name = '" + group_name_act + "'";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
	//command->Parameters->AddWithValue("@description_new", description_new);
	//command->Parameters->AddWithValue("@group_name_act", group_name_act);

	int rowsAffected = command->ExecuteNonQuery();

	DatabaseConnector::Instance->Disconnect();

	Console::WriteLine(rowsAffected + " rows updated.");
}

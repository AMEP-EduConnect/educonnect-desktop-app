#include "pch.h"
#include "GrupEstudiRepository.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include "GrupEstudi.h"
#include "Usuari.h"
GrupEstudiRepository::GrupEstudiRepository()
{

}

array<AcademicTag^>^ GrupEstudiRepository::LoadAllAcademicTags()
{
	array<AcademicTag^>^ academicTags = gcnew array<AcademicTag^>(0);
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM academicTags";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteInternCommand(sql);
	while (data->Read())
	{
		AcademicTag^ academicTag = gcnew AcademicTag();
		academicTag->SetId(data->GetInt64(0));
		academicTag->SetTagName(data->GetString(1));
		Array::Resize(academicTags, academicTags->Length + 1);
		academicTags[academicTags->Length - 1] = academicTag;
	}
	DatabaseConnector::Instance->Disconnect();
	return academicTags;
}

void GrupEstudiRepository::CreateNewGrupEstudi(String^ group_name, String^ description, Int64^ academic_id, Int64^ current_user_id)
{
	DatabaseConnector::Instance->Connect();

	String^ sql = "INSERT INTO studyGroups (group_name, group_owner_id, group_academic_tag, description) VALUES (@GroupName, @CurrentUserId, @AcademicId, @Description)";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());

		command->Parameters->AddWithValue("@GroupName", group_name);
		command->Parameters->AddWithValue("@AcademicId", academic_id);
		command->Parameters->AddWithValue("@Description", description);
		command->Parameters->AddWithValue("@CurrentUserId", current_user_id);	

		command->ExecuteNonQuery();
		MessageManager::InfoMessage("Grup d'estudi creat correctament!");
		DatabaseConnector::Instance->Disconnect();
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

Int64^ GrupEstudiRepository::GetAcademicTagByTagName(String^ academic_tag)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT id FROM academicTags WHERE tag_name = '" + academic_tag + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteInternCommand(sql);
	Int64^ tagId = nullptr;

	try
	{
		if (data->Read())
		{
			tagId = data->GetInt64(0);
		}
		else
		{
			throw gcnew Exception("Materia no encontrada!");
		}
	}
	finally
	{
		data->Close(); // Asegúrate de cerrar el lector de datos
		DatabaseConnector::Instance->Disconnect();
	}

	return tagId;
}


//ZITRO STUFF
// 
// 

GrupEstudi^ GrupEstudiRepository::GetGrupEstudiById(Int64^ id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroups WHERE id = " + id;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteInternCommand(sql);
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
	String^ sql = "SELECT * FROM studyGroups WHERE group_name = '" + group_name_act + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteInternCommand(sql);
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

	String^ sql = "UPDATE studyGroups SET group_name = @group_name_new WHERE group_name = @group_name_act";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());

	// Agregamos los parámetros a la consulta
	command->Parameters->AddWithValue("@group_name_new", group_name_new);
	command->Parameters->AddWithValue("@group_name_act", group_name_act);

	int rowsAffected = command->ExecuteNonQuery();

	DatabaseConnector::Instance->Disconnect();

	Console::WriteLine(rowsAffected + " rows updated.");
}

void GrupEstudiRepository::UpdateGroupDescription(String^ group_name_act, String^ description_new) {
	DatabaseConnector::Instance->Connect();

	String^ sql = "UPDATE studyGroups SET description = @description_new WHERE group_name = @group_name_act";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());

	// Agregamos los parámetros a la consulta
	command->Parameters->AddWithValue("@description_new", description_new);
	command->Parameters->AddWithValue("@group_name_act", group_name_act);

	int rowsAffected = command->ExecuteNonQuery();

	DatabaseConnector::Instance->Disconnect();

	Console::WriteLine(rowsAffected + " rows updated.");
}

bool GrupEstudiRepository::CheckIfUserExists(String^ user_name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = '" + user_name + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	bool trobat = false;

	// Verificar si hay al menos una fila devuelta por la consulta
	if (data->Read()) {
		// Si la consulta devuelve al menos una fila, el usuario existe
		trobat = true;
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return trobat;
}

Int64^ GrupEstudiRepository::GetUserIdByName(String^ user_name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT id FROM users WHERE username = '" + user_name + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	Int64^ id_user;

	while (data->Read())
	{
		id_user = data->GetInt64(0);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();

	return id_user;
}

Int64^ GrupEstudiRepository::GetGroupIdByName(String^ group_name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT id FROM studyGroups WHERE group_name = '" + group_name + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	Int64^ id_group;

	while (data->Read())
	{
		id_group = data->GetInt64(0);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();

	return id_group;
}

bool GrupEstudiRepository::CheckUserIsOwner(Int64^ currentUser, String^ group_name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroups WHERE group_owner_id = " + currentUser + " AND group_name = '" + group_name + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	bool owner = false;

	if (data->Read()) {
		owner = true;
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();

	return owner;
}
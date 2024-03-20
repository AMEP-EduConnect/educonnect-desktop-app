#include "pch.h"
#include "GrupEstudiMembershipRepository.h"
#include "GrupEstudi.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"

using namespace System;

GrupEstudiMembershipRepository::GrupEstudiMembershipRepository()
{

}

array<Int64^>^ GrupEstudiMembershipRepository::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{
    array<Int64^>^ user_groupEstudiMembership = gcnew array<Int64^>(0);
    DatabaseConnector::Instance->Connect();
    String^ sql = "SELECT group_id FROM studyGroupsMembership WHERE user_id = " + user_id;
    MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);

	// Obtener el número de filas
	int rowCount = 0;
	while (data->Read())
	{
		rowCount++;
	}
	data->Close();

	// Crear un nuevo arreglo con el tamaño correcto
	array<Int64^>^ tempArray = gcnew array<Int64^>(rowCount);

	// Volver a ejecutar la consulta
	data = DatabaseConnector::Instance->ExecuteCommand(sql);

	int index = 0;
	while (data->Read())
	{
		tempArray[index++] = data->GetInt64(0);
	}

	// Asignar el nuevo arreglo al arreglo original
	user_groupEstudiMembership = tempArray;

	DatabaseConnector::Instance->Disconnect();
	return user_groupEstudiMembership;
}

GrupEstudi^ GrupEstudiMembershipRepository::LoadAllGrupEstudibyId(Int64 ^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroups WHERE id = " + group_id;
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



//Crear nova instància de membership;
//PREGUNTAR SOBRE LA VARIABLE DateTime;
void GrupEstudiMembershipRepository::UserToGroup(Int64 ^ user_id, Int64 ^ group_id) {
	DatabaseConnector::Instance->Connect();

	// Utilizamos una consulta parametrizada para evitar problemas de sintaxis y de seguridad
	String^ sql = "INSERT INTO studyGroupsMembership (user_id, group_id) VALUES (@UserId, @GroupId)";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());

		// Agregamos los parámetros a la consulta
		command->Parameters->AddWithValue("@UserId", user_id);
		command->Parameters->AddWithValue("@GroupId", group_id);

		command->ExecuteNonQuery();
		DatabaseConnector::Instance->Disconnect();
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

bool GrupEstudiMembershipRepository::CheckIfUserIsInGroup(Int64^ user_id, Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroupsMembership WHERE user_id = " + user_id + " AND group_id = " + group_id;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	bool exists = data->HasRows;
	DatabaseConnector::Instance->Disconnect();
	return exists;
}

void GrupEstudiMembershipRepository::DeleteUserFromGroup(Int64^ user_id, Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM studyGroupsMembership WHERE user_id = " + user_id + " AND group_id = " + group_id;
	DatabaseConnector::Instance->ExecuteCommand(sql);
	DatabaseConnector::Instance->Disconnect();
}
#include "pch.h"
#include "GrupEstudiMembershipRepository.h"


using namespace System;

GrupEstudiMembershipRepository::GrupEstudiMembershipRepository()
{

}

array<Int64^>^ GrupEstudiMembershipRepository::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{
    array<Int64^>^ user_groupEstudiMembership = gcnew array<Int64^>(0);
    DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT group_id FROM studyGroupsMembership WHERE user_id = @user_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    array<Int64^>^ tempArray = gcnew array<Int64^>(user_groupEstudiMembership->Length + 1);
    for (int i = 0; i < user_groupEstudiMembership->Length; i++)
    {
        tempArray[i] = user_groupEstudiMembership[i];
    }
    user_groupEstudiMembership = tempArray;
    int index = user_groupEstudiMembership->Length;
	// Obtener el n�mero de filas
	int rowCount = 0;
	while (data->Read())
	{
		rowCount++;
	}
	data->Close();

	// Crear un nuevo arreglo con el tama�o correcto
	tempArray = gcnew array<Int64^>(rowCount);

	// Volver a ejecutar la consulta
	data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);

	index = 0;
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
	String^ sql = "SELECT * FROM studyGroups WHERE id = @id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", group_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
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



//Crear nova inst�ncia de membership;
//PREGUNTAR SOBRE LA VARIABLE DateTime;
void GrupEstudiMembershipRepository::UserToGroup(Int64 ^ user_id, Int64 ^ group_id)
{
	DatabaseConnector::Instance->Connect();
	// Utilizamos una consulta parametrizada para evitar problemas de sintaxis y de seguridad
	String^ sql = "INSERT INTO studyGroupsMembership (user_id, group_id) VALUES (@UserId, @GroupId)";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
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
	String^ sql = "SELECT * FROM studyGroupsMembership WHERE user_id = @user_id AND group_id = @group_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id->ToString());
	params->Add("@group_id", group_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	bool exists = data->HasRows;
	DatabaseConnector::Instance->Disconnect();
	return exists;
}

void GrupEstudiMembershipRepository::DeleteUserFromGroup(Int64^ user_id, Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM studyGroupsMembership WHERE user_id = @user_id AND group_id = @group_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id->ToString());
	params->Add("@group_id", group_id->ToString());
	DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	DatabaseConnector::Instance->Disconnect();
}

bool GrupEstudiMembershipRepository::CheckIfGroupHasUsers(Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM studyGroupsMembership WHERE group_id = @group_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@group_id", group_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->Disconnect();
	return check;
}

// Create a function that return the first user that member_since is the oldest
Int64^ GrupEstudiMembershipRepository::GetOldestUserInGroup(Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_id FROM studyGroupsMembership WHERE group_id = @group_id ORDER BY member_since ASC LIMIT 1";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@group_id", group_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ user_id;
	while (data->Read())
	{
		user_id = data->GetInt64(0);
	}
	DatabaseConnector::Instance->Disconnect();
	return user_id;
}

#include "pch.h"
#include "GrupEstudiMembershipRepository.h"
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
	String^ sql = "SELECT user_group FROM studyGroupsMembership WHERE user_id = " + user_id;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	while (data->Read())
	{
		Array::Resize(user_groupEstudiMembership, user_groupEstudiMembership->Length + 1);
		user_groupEstudiMembership[user_groupEstudiMembership->Length - 1] = data->GetInt64(0);
	}
	DatabaseConnector::Instance->Disconnect();
	return user_groupEstudiMembership;
}

/*array<Int64^>^ GrupEstudiMembershipRepository::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{
	array<Int64^>^ user_groupEstudiMembership = gcnew array<Int64^>(0);
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_group FROM studyGroupsMembership WHERE user_id = " + user_id;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	int index = 0; // Variable para llevar el control del índice del arreglo
	while (data->Read())
	{
		Array::Resize(user_groupEstudiMembership, index + 1); // Resize utilizando el índice
		user_groupEstudiMembership[index] = data->GetInt64(0);
		index++; // Incrementar el índice después de añadir un elemento
	}
	DatabaseConnector::Instance->Disconnect();
	return user_groupEstudiMembership;
}*/

/*array<Int64^>^ GrupEstudiMembershipRepository::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
{
	array<Int64^>^ user_groupEstudiMembership = gcnew array<Int64^>(0);
	int count = 0; // Variable para llevar el control del tamaño actual del arreglo

	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_group FROM studyGroupsMembership WHERE user_id = " + user_id;
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);

	while (data->Read())
	{
		// Crear un nuevo arreglo con un tamaño incrementado en uno
		array<Int64^>^ newArray = gcnew array<Int64^>(count + 1);

		// Copiar los elementos del arreglo original al nuevo arreglo
		for (int i = 0; i < count; i++)
		{
			newArray[i] = user_groupEstudiMembership[i];
		}

		// Agregar el nuevo elemento al final del nuevo arreglo
		newArray[count] = data->GetInt64(0);

		// Actualizar el arreglo original con el nuevo arreglo
		user_groupEstudiMembership = newArray;

		// Incrementar el contador de elementos
		count++;
	}

	DatabaseConnector::Instance->Disconnect();
	return user_groupEstudiMembership;
}*/


//Crear nova instància de membership;
//PREGUNTAR SOBRE LA VARIABLE DateTime;
void GrupEstudiMembershipRepository::CreateNewGrupEstudiMembership(Int64 ^ user_id, Int64 ^ group_id, DateTime ^ member_since) {
	DatabaseConnector::Instance->Connect();

	// Utilizamos una consulta parametrizada para evitar problemas de sintaxis y de seguridad
	String^ sql = "INSERT INTO studyGroupsMembership (user_id, group_id, member_since) VALUES (@UserId, @GroupId, @Date)";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());

		// Agregamos los parámetros a la consulta
		command->Parameters->AddWithValue("@UserId", user_id);
		command->Parameters->AddWithValue("@GroupId", group_id);
		command->Parameters->AddWithValue("@Date", member_since);

		command->ExecuteNonQuery();
		MessageManager::InfoMessage("^Membresia al grup d'estudi creada correctament!");
		DatabaseConnector::Instance->Disconnect();
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}
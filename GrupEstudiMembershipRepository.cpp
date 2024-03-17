#include "pch.h"
#include "GrupEstudiMembershipRepository.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"

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
    array<Int64^>^ tempArray = gcnew array<Int64^>(user_groupEstudiMembership->Length + 1);
    for (int i = 0; i < user_groupEstudiMembership->Length; i++)
    {
        tempArray[i] = user_groupEstudiMembership[i];
    }
    user_groupEstudiMembership = tempArray;
    int index = user_groupEstudiMembership->Length;

    while (data->Read())
    {
        user_groupEstudiMembership[index++] = data->GetInt64(0);
    }

    DatabaseConnector::Instance->Disconnect();
    return user_groupEstudiMembership;
}

//array<Int64^>^ GrupEstudiMembershipRepository::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
//{
//	array<Int64^>^ user_groupEstudiMembership = gcnew array<Int64^>(0);
//	DatabaseConnector::Instance->Connect();
//	String^ sql = "SELECT user_group FROM studyGroupsMembership WHERE user_id = " + user_id;
//	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
//	int index = 0; // Variable para llevar el control del índice del arreglo
//	while (data->Read())
//	{
//		Array::Resize(user_groupEstudiMembership, index + 1); // Resize utilizando el índice
//		user_groupEstudiMembership[index] = data->GetInt64(0);
//		index++; // Incrementar el índice después de añadir un elemento
//	}
//	DatabaseConnector::Instance->Disconnect();
//	return user_groupEstudiMembership;
//}
//
//array<Int64^>^ GrupEstudiMembershipRepository::LoadGrupsEstudiMembershipByUserId(Int64^ user_id)
//{
//	array<Int64^>^ user_groupEstudiMembership = gcnew array<Int64^>(0);
//	int count = 0; // Variable para llevar el control del tamaño actual del arreglo
//
//	DatabaseConnector::Instance->Connect();
//	String^ sql = "SELECT user_group FROM studyGroupsMembership WHERE user_id = " + user_id;
//	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
//
//	while (data->Read())
//	{
//		// Crear un nuevo arreglo con un tamaño incrementado en uno
//		array<Int64^>^ newArray = gcnew array<Int64^>(count + 1);
//
//		// Copiar los elementos del arreglo original al nuevo arreglo
//		for (int i = 0; i < count; i++)
//		{
//			newArray[i] = user_groupEstudiMembership[i];
//		}
//
//		// Agregar el nuevo elemento al final del nuevo arreglo
//		newArray[count] = data->GetInt64(0);
//
//		// Actualizar el arreglo original con el nuevo arreglo
//		user_groupEstudiMembership = newArray;
//
//		// Incrementar el contador de elementos
//		count++;
//	}
//
//	DatabaseConnector::Instance->Disconnect();
//	return user_groupEstudiMembership;
//}



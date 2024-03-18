#pragma once
#include "pch.h"
#include "ProveidorRepository.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
ProveidorRepository::ProveidorRepository()
{

}


void ProveidorRepository::AltaProveidor(String^ name)
{
	DatabaseConnector::Instance->Connect();

	String^ sql = "INSERT INTO proveidors (name) VALUES (@Name)";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());

		command->Parameters->AddWithValue("@Name", name);


		command->ExecuteNonQuery();
		MessageManager::InfoMessage("Proveidor donat d'alta");
		DatabaseConnector::Instance->Disconnect();
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

GrupEstudi^ ProveidorRepository::GetProveidorByName(String^ name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM proveidors WHERE name = '" + name + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	Proveidor^ proveidor = gcnew Proveidor();

	while (data->Read())
	{
		grupestudi->SetNom(data->GetInt64(0));

	}
	DatabaseConnector::Instance->Disconnect();
	return proveidor;
}
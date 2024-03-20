#pragma once
#include "pch.h"
#include "ProveidorRepository.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
ProveidorRepository::ProveidorRepository()
{

}

void ProveidorRepository::BaixaProveidor(String^ name)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM proveidors WHERE name = @Name";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@Name", name);
		command->ExecuteNonQuery();
		MessageManager::InfoMessage("Proveidor eliminat");
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
	finally {
		DatabaseConnector::Instance->Disconnect();
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
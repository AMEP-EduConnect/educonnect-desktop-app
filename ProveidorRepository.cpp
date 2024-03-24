
#include "pch.h"
#include "ProveidorRepository.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"

ProveidorRepository::ProveidorRepository()
{

}


void ProveidorRepository::AltaProveidor(String^ id, String^ username, String^ password, String^ email, String^ surname)
{
    DatabaseConnector::Instance->Connect();

    String^ sqlInsertUser = "INSERT INTO users (id, username, password, email, surname) VALUES (@Id, @Username, @Password, @Email, @Surname)";
    String^ sqlInsertRole = "INSERT IGNORE INTO roles (id, role_name) VALUES (4, 'proveidor')";
    String^ sqlLinkUserRole = "INSERT INTO user_roles (user_id, role_id) VALUES (@Id, 4)";

    try {
        MySqlCommand^ command = gcnew MySqlCommand(sqlInsertUser, DatabaseConnector::Instance->GetConn());
        command->Parameters->AddWithValue("@Id", id);
        command->Parameters->AddWithValue("@Username", username);
        command->Parameters->AddWithValue("@Password", password);
        command->Parameters->AddWithValue("@Email", email);
        command->Parameters->AddWithValue("@Surname", surname);

        command->ExecuteNonQuery();

       

        command = gcnew MySqlCommand(sqlInsertRole, DatabaseConnector::Instance->GetConn());
        command->ExecuteNonQuery();

        command = gcnew MySqlCommand(sqlLinkUserRole, DatabaseConnector::Instance->GetConn());
        command->Parameters->AddWithValue("@Id", id);
        command->ExecuteNonQuery();

        MessageManager::InfoMessage("Proveidor donat d'alta");

        DatabaseConnector::Instance->Disconnect();
    }
    catch (Exception^ e) {
        MessageManager::ErrorMessage(e->Message);
    }
}

Proveidor^ ProveidorRepository::GetProveidorByName(String^ username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = '" + username + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	Proveidor^ proveidor = gcnew Proveidor();

	while (data->Read())
	{
		proveidor->SetProveidorName(data->GetString(0));

	}
	DatabaseConnector::Instance->Disconnect();
	return proveidor;
}
#include "pch.h"
#include "DatabaseConnector.h"
#include "Utils.h"
#include "MessageManager.h"

//Singleton class to Connect to the database from any context
DatabaseConnector::DatabaseConnector()
{
    String^ server;
    String^ username;
    String^ password;
    String^ databaseName;
    Utils::ReadAndDecryptDatabaseCredentials(server, username, password, databaseName);
    conn = gcnew MySqlConnection(String::Format("server={0};port=3306;user id={1};password={2};database={3};AllowPublicKeyRetrieval=true;", server, username, password, databaseName));
}

void DatabaseConnector::Connect()
{
    conn->Open();
}

MySqlConnection^ DatabaseConnector::GetConn()
{
    return this->conn;
}

void DatabaseConnector::Disconnect()
{
    conn->Close();
}

MySqlDataReader^ DatabaseConnector::ExecuteCommand(String^ sql)
{
    MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->conn);
    MySqlDataReader^ dataReader;
    try {
        dataReader = cmd->ExecuteReader();
    }
    catch (InvalidOperationException^ ex) {
        MessageManager::ErrorMessage(ex->Message);
        this->Connect();
    }

    return dataReader;
}

MySqlDataReader^ DatabaseConnector::ExecuteClientCommand(String^ sql, Dictionary<String^, Object^>^ params)
{
	MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->conn);
	if (params != nullptr) {
		for each (KeyValuePair<String^, Object^> kvp in params) {
			cmd->Parameters->AddWithValue(kvp.Key, kvp.Value);
		}
	}
	MySqlDataReader^ dataReader = nullptr;
	try {
		dataReader = cmd->ExecuteReader();
	}
	catch (InvalidOperationException^ ex) {
		this->Connect();
		MessageManager::ErrorMessage(ex->Message);
	}
	return dataReader;
}


MySqlDataReader^ DatabaseConnector::ExecuteInternCommand(String^ sql)
{
	MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->conn);
	MySqlDataReader^ dataReader;
	try {
		dataReader = cmd->ExecuteReader();
	}
	catch (InvalidOperationException^ ex) {
		MessageManager::ErrorMessage(ex->Message);
		this->Connect();
	}

	return dataReader;
}
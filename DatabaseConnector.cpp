#include "pch.h"
#include "DatabaseConnector.h"
#include "Utils.h"

//Singleton class to connect to the database from any context
DatabaseConnector::DatabaseConnector()
{
	String^ server;
	String^ username;
	String^ password;
	String^ databaseName;
	Utils::readAndDecryptDatabaseCredentials(server, username, password, databaseName);
	conn = gcnew MySqlConnection(String::Format("server={0};port=3306;user id={1};password={2};database={3};AllowPublicKeyRetrieval=true;", server, username, password, databaseName));
}

void DatabaseConnector::connect()
{
	try
	{
		conn->Open();
	}
	catch (MySqlException^ ex)
	{
		Console::WriteLine("Error: " + ex->Message);
	}
}

void DatabaseConnector::disconnect()
{
	conn->Close();
}

MySqlDataReader^ DatabaseConnector::executeClientCommand(String^ sql, Dictionary<String^, Object^>^ params) {
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
		//MessageManager::ErrorMessage(ex->Message);
		this->connect();
	}
	return dataReader;
}


MySqlDataReader^ DatabaseConnector::executeInternCommand(String^ sql)
{
	MySqlCommand^ cmd = gcnew MySqlCommand(sql, this->conn);
	MySqlDataReader^ dataReader;
	try {
		dataReader = cmd->ExecuteReader();
	}
	catch (InvalidOperationException^ ex) {
		//MessageManager::ErrorMessage(ex->Message);
		this->connect();
	}

	return dataReader;
}
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
    Utils::ReadAndDecryptDatabaseCredentials(server, username, password, databaseName);
    conn = gcnew MySqlConnection(String::Format("server={0};port=3306;user id={1};password={2};database={3};AllowPublicKeyRetrieval=true;", server, username, password, databaseName));
}

void DatabaseConnector::Connect()
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
    dataReader = cmd->ExecuteReader();
    return dataReader;
}

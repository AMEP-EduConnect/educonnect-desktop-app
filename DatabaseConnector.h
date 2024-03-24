#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;

public ref class DatabaseConnector
{
public:
	static DatabaseConnector^ Instance;
	DatabaseConnector();
	void Connect();
	void Disconnect();
	MySqlConnection^ GetConn();
	MySqlDataReader^ ExecuteInternCommand(String^ sql);
	MySqlDataReader^ ExecuteClientCommand(String^ sql, Dictionary<String^, Object^>^ params);

private:
    String^ server;
    String^ username;
    String^ password;
    String^ databaseName;
    MySqlConnection^ conn;
};
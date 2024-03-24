#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Collections::Generic;

public ref class DatabaseConnector
{
public:
	static DatabaseConnector^ Instance;
	DatabaseConnector();
	void connect();
	void disconnect();
	MySqlDataReader^ executeClientCommand(String^ sql, Dictionary<String^, Object^>^ params);
	MySqlDataReader^ executeInternCommand(String^ sql);

private:
	String^ server;
	String^ username;
	String^ password;
	String^ databaseName;
	MySqlConnection^ conn;
};
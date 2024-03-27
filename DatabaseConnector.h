#pragma once
#include "Utils.h"
#include "MessageManager.h"

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
    MySqlDataReader^ ExecuteCommand(String^ sql);
    MySqlConnection^ GetConn();

private:
    String^ server;
    String^ username;
    String^ password;
    String^ databaseName;
    MySqlConnection^ conn;
};
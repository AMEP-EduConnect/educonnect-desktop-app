#pragma once
using namespace System;
using namespace MySql::Data::MySqlClient;


public ref class DatabaseConnector
{
public:
    static DatabaseConnector^ Instance;
    DatabaseConnector();
    void connect();
    void disconnect();
    MySqlDataReader^ executeCommand(String^ sql);
    MySqlConnection^ getConn();

private:
    String^ server;
    String^ username;
    String^ password;
    String^ databaseName;
    MySqlConnection^ conn;
};
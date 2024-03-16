#pragma once

using namespace System;

public ref class Utils
{
public:
    static void ReadAndDecryptDatabaseCredentials(String^% server, String^% username, String^% password, String^% databaseName);
};
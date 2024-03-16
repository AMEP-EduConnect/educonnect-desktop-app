#include "pch.h"
#include "Utils.h"

using namespace System;
using namespace System::Xml;
using namespace System::Security::Cryptography;

void Utils:: ReadAndDecryptDatabaseCredentials(String^% server, String^% username, String^% password, String^% databaseName)
{
    try
    {
        String^ filePath = "credentials.xml";
        XmlDocument^ xmlDoc = gcnew XmlDocument();
        xmlDoc->Load(filePath);

        XmlNode^ databaseNode = xmlDoc->SelectSingleNode("/credentials/database");

        server = databaseNode->SelectSingleNode("server")->InnerText;
        username = databaseNode->SelectSingleNode("username")->InnerText;
        password = databaseNode->SelectSingleNode("password")->InnerText;
        databaseName = databaseNode->SelectSingleNode("database_name")->InnerText;
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Error: " + ex->Message);
    }
}
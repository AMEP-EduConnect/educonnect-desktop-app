#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"


UsuariRepository::UsuariRepository()
{

}

Usuari^ UsuariRepository::GetUsuariById(Int64^ id)
{
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM users WHERE id = " + id;
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Usuari^ usuari = gcnew Usuari();
	while (data->Read())
	{
		//usuari-> = data->GetInt64(0);
		//professor->name = data->GetString(1);
		//professor->surname = data->GetString(2);
	}
	return usuari;

}

Usuari^ UsuariRepository::GetUsuariByUsername(String^ user) {
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM users WHERE username = " + user;
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Usuari^ usuari = gcnew Usuari();
	while (data->Read())
	{
		usuari->id = data->GetInt64(0);
		usuari->username = data->GetString(1);
		usuari->password = data->GetString(2);
		usuari->email = data->GetString(3);
		usuari->name = data->GetString(4);
	}
	return usuari;
}

//NEXT FEATURE
/*Usuari^ GetUsuariBySession(Int64^ token) {
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM users WHERE username = " + token;
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Usuari^ usuari = gcnew Usuari();
	while (data->Read())
	{
		usuari->id = data->GetInt64(0);
		usuari->username = data->GetString(1);
		usuari->password = data->GetString(2);
		usuari->email = data->GetString(3);
		usuari->name = data->GetString(4);
	}
	return usuari;
}*/
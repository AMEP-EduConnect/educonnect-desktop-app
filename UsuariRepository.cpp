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

Usuari^ UsuariRepository::GetUsuariByPassUser(String^ username, String^ password) {
	DatabaseConnector::Instance->connect();

	String^ sql = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Usuari^ usuari = gcnew Usuari();

	while (data->Read())
	{
		usuari->user_id = data->GetInt64(0);
		usuari->username = data->GetString(1);
		usuari->password = data->GetString(2);
		usuari->email = data->GetString(3);
		usuari->name = data->GetString(4);
	}
	DatabaseConnector::Instance->disconnect();
	return usuari;
}
bool UsuariRepository::CheckUsuariByUser(String^ username) {
	DatabaseConnector::Instance->connect();

	String^ sql = "SELECT username FROM users WHERE username = '" + username + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Usuari^ usuari = gcnew Usuari();
	bool check;
	if (data != nullptr && data->Read() == false) check = false;
	else check = true;
	DatabaseConnector::Instance->disconnect();
	return check;
}
#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"


UsuariRepository::UsuariRepository() {

}

Usuari^ UsuariRepository::GetUsuariById(Int64^ id) {
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
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
	}
	DatabaseConnector::Instance->disconnect();
	CurrentSession::Instance->LogNewUser(usuari);
	return usuari;
}

Usuari^ UsuariRepository::GetUsuariByUser(String^ username) {
	DatabaseConnector::Instance->connect();

	String^ sql = "SELECT * FROM users WHERE username = '" + username + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	Usuari^ usuari = gcnew Usuari();

	while (data->Read())
	{
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
	}
	DatabaseConnector::Instance->disconnect();
	return usuari;
	
}

bool UsuariRepository::CheckUsuariByUser(String^ username) {
	DatabaseConnector::Instance->connect();

	String^ sql = "SELECT username FROM users WHERE username = '" + username + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);

	bool check;

	if (data != nullptr && data->Read() == false) check = false;
	else check = true;
	DatabaseConnector::Instance->disconnect();
	return check;
}

bool UsuariRepository::CheckUsuariByEmail(String^ email) {
    DatabaseConnector::Instance->connect();

    String^ sql = "SELECT username FROM users WHERE email = '" + email + "'";
    MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);

    bool check;

    if (data != nullptr && data->Read() == false) check = false;
    else check = true;
    DatabaseConnector::Instance->disconnect();
    return check;
}

bool UsuariRepository::CreateUser(String^ username, String^ email, String^ name, String^ password) {
	DatabaseConnector::Instance->connect();

	String^ sql = "INSERT INTO users (username, password, email, name) VALUES ('"
	+ username + "', '"
	+ password + "', '"
	+ email + "', '"
	+ name + "')";

	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);

	bool check;

	if (data != nullptr && data->Read() == false) check = false;
	else check = true;
	DatabaseConnector::Instance->disconnect();
	return check;
}
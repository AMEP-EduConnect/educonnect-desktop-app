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
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
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
	bool check = false;
		data->Close();
		sql = "SELECT LAST_INSERT_ID();";
	MySqlDataReader^ data2 = DatabaseConnector::Instance->executeCommand(sql);
	Int64^ id;
		while (data2->Read()) {
			id = data2->GetInt64(0);
		}
		data2->Close();
		DatabaseConnector::Instance->disconnect();
		check = CreateUserRol(id);
		return check;
}
bool UsuariRepository::CreateUserRol(Int64^ id) {
	DatabaseConnector::Instance->connect();
	String^ sql = "INSERT INTO users_roles (user_id, role_id) VALUES ("
		+ id->ToString() + ",2)";
	MySqlDataReader^ data3 = DatabaseConnector::Instance->executeCommand(sql);
		data3->Close();
		DatabaseConnector::Instance->disconnect();
		return true;
}



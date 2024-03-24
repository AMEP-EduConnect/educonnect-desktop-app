#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include <vector>

UsuariRepository::UsuariRepository() {

}

Usuari^ UsuariRepository::GetUsuariById(Int64^ id) {
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM users WHERE id = @id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@id", id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->executeClientCommand(sql, params);
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
	MySqlDataReader^ data = DatabaseConnector::Instance->executeInternCommand(sql);
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
	String^ sql = "SELECT username FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@Username", username);
	MySqlDataReader^ data = DatabaseConnector::Instance->executeInternCommand(sql);
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
	String^ sql = "SELECT username FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@Username", username);

	MySqlDataReader^ data = DatabaseConnector::Instance->executeClientCommand(sql, params);

	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->disconnect();
	return check;
}

bool UsuariRepository::CheckUsuariByEmail(String^ email) {
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT username FROM users WHERE email = @Email";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@Email", email);

	MySqlDataReader^ data = DatabaseConnector::Instance->executeClientCommand(sql, params);

	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->disconnect();
	return check;
}


bool UsuariRepository::CreateUser(String^ username, String^ email, String^ name, String^ password) {
	DatabaseConnector::Instance->connect();
	String^ sql = "INSERT INTO users (username, password, email, name) VALUES (@Username, @Password, @Email, @Name)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@Username", username);
	params->Add("@Password", password);
	params->Add("@Email", email);
	params->Add("@Name", name);

	MySqlDataReader^ data = DatabaseConnector::Instance->executeClientCommand(sql,params);
	bool check = false;
	data->Close();
	sql = "SELECT LAST_INSERT_ID();";
	MySqlDataReader^ data2 = DatabaseConnector::Instance->executeInternCommand(sql);
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
	String^ sql = "INSERT INTO users_roles (user_id, role_id) VALUES (@id,2)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@id", id->ToString());
	MySqlDataReader^ data3 = DatabaseConnector::Instance->executeClientCommand(sql,params);
	data3->Close();
	DatabaseConnector::Instance->disconnect();
	return true;
}






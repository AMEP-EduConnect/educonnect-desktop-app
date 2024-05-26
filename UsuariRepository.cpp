#include "pch.h"
#include "UsuariRepository.h"

UsuariRepository::UsuariRepository() {

}

Usuari^ UsuariRepository::GetUsuariById(Int64^ id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE id = @id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Usuari^ usuari = gcnew Usuari();
	while (data->Read())
	{
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
	}
	DatabaseConnector::Instance->Disconnect();
	return usuari;

} 

Usuari^ UsuariRepository::GetUsuariByPassUser(String^ username, String^ password) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = @Username AND password = @Password";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	params->Add("@Password", password);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Usuari^ usuari = gcnew Usuari();
	while (data->Read())
	{
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
	}
	DatabaseConnector::Instance->Disconnect();
	return usuari;
}


Usuari^ UsuariRepository::GetUsuariByUser(String^ username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql,params);
	Usuari^ usuari = gcnew Usuari();

	while (data->Read())
	{
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
	}
	DatabaseConnector::Instance->Disconnect();
	return usuari;
}

bool UsuariRepository::CheckUsuariByUser(String^ username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT username FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);

	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->Disconnect();
	return check;
}

bool UsuariRepository::CheckUsuariByEmail(String^ email) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT username FROM users WHERE email = @Email";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Email", email);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);

	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->Disconnect();
	return check;
}


Int64^ UsuariRepository::CreateUser(String^ username, String^ email, String^ name, String^ password) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO users (username, password, email, name) VALUES (@Username, @Password, @Email, @Name)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	params->Add("@Password", password);
	params->Add("@Email", email);
	params->Add("@Name", name);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql,params);
	bool check = false;
	data->Close();
	sql = "SELECT LAST_INSERT_ID();";
	MySqlDataReader^ data2 = DatabaseConnector::Instance->ExecuteInternCommand(sql);
	Int64^ id;
	while (data2->Read()) {
		id = data2->GetInt64(0);
	}
	data2->Close();
	DatabaseConnector::Instance->Disconnect();
	return id;
}

bool UsuariRepository::UpdateUser(String^ username, String^ password, String^ email, String^ name) {
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	DatabaseConnector::Instance->Connect();
	String^ sql = "UPDATE users SET username=@Username, password=@Password, email=@Email, name=@Name WHERE id=@id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	params->Add("@Password", password);
	params->Add("@Email", email);
	params->Add("@Name", name);
	params->Add("@id", currentUser->GetUserId()->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	currentUser->SetUsername(username);
	currentUser->SetPassword(password);
	currentUser->SetEmail(email);
	currentUser->SetName(name);
	return true;
}

bool UsuariRepository::DeleteUser(Int64^ id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM users WHERE id=@id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}


Int64^ UsuariRepository::GetUserId(String^ username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT id FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ id;
	while (data->Read()) {
		id = data->GetInt64(0);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return id;
}

Usuari^ UsuariRepository::GetProveidorByEspaiId(Int64^ espai_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE id = (SELECT proveidor_id FROM espais WHERE id = @id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", espai_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Usuari^ usuari = gcnew Usuari();
	while (data->Read())
	{
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
	}
	DatabaseConnector::Instance->Disconnect();
	return usuari;

}
List<Usuari^>^ UsuariRepository::GetUsersByRolId(Int64^ rol_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users u INNER JOIN users_roles ur ON u.id = ur.user_id WHERE ur.role_id = @rol_id ORDER BY u.username ASC";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@rol_id", rol_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<Usuari^>^ users = gcnew List<Usuari^>(0);
	while (data->Read()) {
		Usuari^ usuari = gcnew Usuari();
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
		users->Add(usuari);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return users;
}

List<Usuari^>^ UsuariRepository::GetUsersByStartingLetter(Int64^ rol_id, String^ username)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users u INNER JOIN users_roles ur ON u.id = ur.user_id WHERE u.username LIKE @username AND ur.role_id = @rol_id ORDER BY u.username ASC";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@rol_id", rol_id);
	params->Add("@username", username);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<Usuari^>^ users = gcnew List<Usuari^>(0);
	while (data->Read()) {
		Usuari^ usuari = gcnew Usuari();
		usuari->SetUserId(data->GetInt64(0));
		usuari->SetUsername(data->GetString(1));
		usuari->SetPassword(data->GetString(2));
		usuari->SetEmail(data->GetString(3));
		usuari->SetName(data->GetString(4));
		users->Add(usuari);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return users;
}

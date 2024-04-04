
#include "pch.h"
#include "ProveidorRepository.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"

ProveidorRepository::ProveidorRepository()
{

}

void ProveidorRepository::DeleteProveidor(String^ username)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
}


bool ProveidorRepository::CreateNewProveidor(String^ username, String^ email, String^ name, String^ password)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO users (username, password, email, name) VALUES (@Username, @Password, @Email, @Name)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	params->Add("@Password", password);
	params->Add("@Email", email);
	params->Add("@Name", name);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
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
	check = CreateUserRol(id);
	return check;
}
bool ProveidorRepository::CreateUserRol(Int64^ id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO users_roles (user_id, role_id) VALUES (@id,3)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", id->ToString());
	MySqlDataReader^ data3 = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data3->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

Int64^ ProveidorRepository::CheckProveidorandGetId(String^username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ providerId;
	while (data->Read())
	{
		providerId = data->GetInt64(0);
	}
	DatabaseConnector::Instance->Disconnect();
	return providerId;
	
}

bool ProveidorRepository::CheckIfProveidorExists(String^ username) {

	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT username FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Username", username);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);

	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->Disconnect();
	return check;

}

bool ProveidorRepository::CheckIfIsProveidor(Int64^ providerId) {
	DatabaseConnector::Instance->Connect();
	String^ sqlCheckIfProvider = "SELECT * FROM users_roles WHERE user_id = @User_Id and role_id = 3";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@User_Id", providerId->ToString());
	MySqlDataReader^ providerRoleChecker = DatabaseConnector::Instance->ExecuteClientCommand(sqlCheckIfProvider, params);
	bool check = providerRoleChecker->Read();
	DatabaseConnector::Instance->Disconnect();
	return check;
}

Proveidor^ ProveidorRepository::GetProveidorByName(String^ username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = '" + username + "'";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteCommand(sql);
	Proveidor^ proveidor = gcnew Proveidor();

	while (data->Read())
	{
		proveidor->SetProveidorName(data->GetString(0));

	}
	DatabaseConnector::Instance->Disconnect();
	return proveidor;
}

#include "pch.h"
#include "ProveidorRepository.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"

ProveidorRepository::ProveidorRepository()
{

}

void ProveidorRepository::BaixaProveidor(String^ username)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM users WHERE username = @Username";
	MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
	command->Parameters->AddWithValue("@username", username);
	int rowsAffected = command->ExecuteNonQuery();
	DatabaseConnector::Instance->Disconnect();
}


bool ProveidorRepository::AltaProveidor(String^ username, String^ email, String^ name, String^ password)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO users (username, password, email, name) VALUES (@Username, @Password, @Email, @Name)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
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
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@id", id->ToString());
	MySqlDataReader^ data3 = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data3->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

bool ProveidorRepository::CheckIfProveidorExists(String^username) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM users WHERE username = @Username";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>();
	params->Add("@Username", username);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ providerId;
	while (data->Read())
	{
		providerId = data->GetInt64(0);
	}
	DatabaseConnector::Instance->Disconnect();
	return this->CheckIfIsProveidor(providerId);
}

bool ProveidorRepository::CheckIfIsProveidor(Int64^ providerId) {
	DatabaseConnector::Instance->Connect();
	String^ sqlCheckIfProvider = "SELECT role_id FROM users_roles WHERE user_id = @User_Id";

	Dictionary<String^, Object^>^ params2 = gcnew Dictionary<String^, Object^>();
	params2->Add("@User_Id", providerId);

	MySqlDataReader^ providerRoleChecker = DatabaseConnector::Instance->ExecuteClientCommand(sqlCheckIfProvider, params2);
	Int64^ currentRoleId;

	while (providerRoleChecker->Read())
	{
		currentRoleId = providerRoleChecker->GetInt64(0);
	}

	DatabaseConnector::Instance->Disconnect(); 
	if(currentRoleId == 3LL)
	{
		return true;
	}
	else
	{
		return false;
	}
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
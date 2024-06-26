#include "pch.h"
#include "UsuariRolRepository.h"
#include "DatabaseConnector.h"

UsuariRolRepository::UsuariRolRepository() {

}
bool UsuariRolRepository::CreateUserRol(Int64^ user_id, Int64^ rol_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO users_roles (user_id, role_id) VALUES (@user_id,@rol_id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id->ToString());
	params->Add("@rol_id", rol_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}
bool UsuariRolRepository::DeleteUserRol(Int64^ id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM users_roles WHERE user_id=@id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

Int64^ UsuariRolRepository::GetRolId(Int64^ user_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT role_id FROM users_roles WHERE user_id=@user_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ rol_id;
	while (data->Read()) {
		rol_id = data->GetInt64(0);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return rol_id;
}

List<Int64>^ UsuariRolRepository::GetUsersByRolId(Int64^ rol_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_id FROM users_roles WHERE role_id=@rol_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@rol_id", rol_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<Int64>^ users = gcnew List<Int64>(0);
	while (data->Read()) {
		users->Add(data->GetInt64(0));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return users;
}
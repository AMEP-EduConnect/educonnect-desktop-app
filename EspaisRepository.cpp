#include "pch.h"
#include "EspaisRepository.h"

EspaisRepository::EspaisRepository() {

}

bool EspaisRepository::CreateEspai(String^ name, Int64^ capacity, Int64^ proveidor_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO espais (name, capacity, proveidor_id) VALUES (@name, @capacity, @proveidor_id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@name", name);
	params->Add("@capacity", capacity);
	params->Add("@proveidor_id", proveidor_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}
List<Espai^>^ EspaisRepository::GetEspaisById(Int64^ proveidor_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM espais WHERE proveidor_id=@proveidor_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@proveidor_id", proveidor_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<Espai^>^ espais = gcnew List<Espai^>(0);
	while (data->Read()) {
		Espai^ espai = gcnew Espai(data->GetInt64(0),data->GetString(1), data->GetInt64(2), data->GetInt64(3));
		espais->Add(espai);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return espais;
}
Espai^ EspaisRepository::GetEspaiByEspaiId(Int64^ espai_id)
{

	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM espais WHERE id=@id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", espai_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Espai^ espai;
	while (data->Read()) {
		espai = gcnew Espai(data->GetInt64(0), data->GetString(1), data->GetInt64(2), data->GetInt64(3));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return espai;

}
Espai^ EspaisRepository::GetEspaiByName(String^ name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM espais WHERE name=@name";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@name", name);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Espai^ espai;
	while (data->Read()) {
		espai = gcnew Espai(data->GetInt64(0), data->GetString(1), data->GetInt64(2), data->GetInt64(3));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return espai;
}
bool EspaisRepository::DeleteEspai(Int64^ id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM espais WHERE id=@id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

bool EspaisRepository::CheckEspaiByName(String^ name) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT name FROM espais WHERE name = @Name";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Name", name);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);

	bool check = data != nullptr && data->Read();
	DatabaseConnector::Instance->Disconnect();
	return check;
}

String^ EspaisRepository::GetInfoEspaiById(Int64^ id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT u.username, e.name FROM espais e JOIN users u ON e.proveidor_id = u.id WHERE e.id = @id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@id", id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	String^ info;
	if (data->Read()) {
		info = (data->GetString(0) + " - " + data->GetString(1));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return info;
}
#include "pch.h"
#include "EspaisRepository.h"

EspaisRepository::EspaisRepository() {

}

bool EspaisRepository::CreateEspai(String^ name, Int64^ capacity, Int64^ user_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO espais (name, capacity, user_id) VALUES (@name, @capacity, @user_id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@name", name);
	params->Add("@capacity", capacity);
	params->Add("@user_id", user_id);


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
	return true;
}

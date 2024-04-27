#include "pch.h"
#include "EspaisRepository.h"

EspaisRepository::EspaisRepository() {

}

bool EspaisRepository::CreateEspai(String^ nombre, Int64^ capacidad_grupos, Int64^ provider_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO espais (nombre, capacidad_grupos, provider_id) VALUES (@Nombre, @Capacidad_grupos, @Provider_id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@Nombre", nombre);
	params->Add("@Capacidad_grupos", capacidad_grupos);
	params->Add("@Provider_id", provider_id);


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

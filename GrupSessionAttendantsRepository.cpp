#include "pch.h"
#include "GrupSessionAttendantsRepository.h"
#include "GrupSessionAttendant.h"
#include "DatabaseConnector.h"

GrupSessionAttendantsRepository::GrupSessionAttendantsRepository()
{

}

void GrupSessionAttendantsRepository::AsistirSessionAttendant(Int64^ idsession, Int64^ iduser)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT into grupSessionsAttendants (session_id, user_id) VALUES (@idsession, @iduser)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@idsession", idsession);
	params->Add("@iduser", iduser);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
}

void GrupSessionAttendantsRepository::EliminaSessionAttendant(Int64^ idsession, Int64^ iduser)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM grupSessionsAttendants WHERE session_id = @idsession AND user_id = @iduser";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@idsession", idsession);
	params->Add("@iduser", iduser);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
}

bool GrupSessionAttendantsRepository::IsAttendant(Int64^ idsession, Int64^ iduser)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessionsAttendants WHERE session_id = @idsession AND user_id = @iduser";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@idsession", idsession);
	params->Add("@iduser", iduser);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	bool attendance = data->HasRows;
	DatabaseConnector::Instance->Disconnect();
	return attendance;
}

Int64^ GrupSessionAttendantsRepository::GetSessionAttendantsCount(Int64^ idsession)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT COUNT(*) FROM grupSessionsAttendants WHERE session_id = @idsession";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@idsession", idsession);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ count = 0LL;
	while (data->Read()) {
		count = data->GetInt64(0);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return count;
}

array<Int64^>^ GrupSessionAttendantsRepository::GetIdSessions(Int64^ iduser)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT session_id FROM grupSessionsAttendants WHERE user_id = @iduser";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@iduser", iduser);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	
	array<Int64^>^ sessionsid = gcnew array<Int64^>(data->FieldCount);
	int j = 0;
	while (data->Read()) {
		sessionsid[j] = data->GetInt64(0);
		++j;
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return sessionsid;
}

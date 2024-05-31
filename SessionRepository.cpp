#include "pch.h"
#include "SessionRepository.h"
#include "Session.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "Usuari.h"

SessionRepository::SessionRepository()
{
}

bool SessionRepository::CreateSession(Int64^ grup_id, Int64^ espai_id, String^ session_name, DateTime^ session_start_date, DateTime^ session_end_date)
{
	try {
		DatabaseConnector::Instance->Connect();
		String^ sql = "INSERT INTO grupSessions (group_id, espai_id, session_name, session_start_date, session_end_date) VALUES (@grup_id, @espai_id, @session_name, @session_start_date, @session_end_date)";
		Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
		params->Add("@grup_id", grup_id);
		params->Add("@espai_id", espai_id);
		params->Add("@session_name", session_name);
		params->Add("@session_start_date", session_start_date);
		params->Add("@session_end_date", session_end_date);
		MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
		data->Close();
		DatabaseConnector::Instance->Disconnect();
		return true;
	}
	catch (Exception^ e) {
		return false;
	}

}

Int64^ SessionRepository::GetSessionId(Int64^ user_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT id FROM grupSessions WHERE group_id=@user_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Int64^ session_id;
	while (data->Read()) {
		session_id = data->GetInt64(0);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return session_id;
}

bool SessionRepository::DeleteSession(Int64^ session_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM grupSessions WHERE id=@session_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@session_id", session_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

bool SessionRepository::UpdateSessionName(String^ newSessionName, String^ oldSessionName)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "UPDATE grupSessions SET session_name=@newSessionName WHERE session_name=@oldSessionName";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@newSessionName", newSessionName);
	params->Add("@oldSessionName", oldSessionName);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

bool SessionRepository::UpdateSessionEspai(Int64^ newEspaiId, Int64^ oldEspaiId)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "UPDATE grupSessions SET espai_id=@newEspaiId WHERE espai_id=@oldEspaiId";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@newEspaiId", newEspaiId);
	params->Add("@oldEspaiId", oldEspaiId);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;

}

bool SessionRepository::UpdateSessionDate(DateTime^ newSessionDate, DateTime^ endSessionDate, Int64^ session_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "UPDATE grupSessions SET session_start_date=@newSessionDate, session_end_date=@endSessionDate WHERE id=@session_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@newSessionDate", newSessionDate);
	params->Add("@endSessionDate", endSessionDate);
	params->Add("@session_id", session_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;	
}

List<Session^>^ SessionRepository::GetSessionsByDate(DateTime^ selectedDay, Int64^ currentGrupId)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessions WHERE group_id=@currentGrupId AND DATE_FORMAT(session_start_date, '%Y-%m-%d') = DATE_FORMAT(@selectedDay, '%Y-%m-%d')";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@currentGrupId", currentGrupId);
	params->Add("@selectedDay", selectedDay);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<Session^>^ sessions = gcnew List<Session^>(0);
	while (data->Read()) {
		Session^ session = gcnew Session(data->GetInt64(0), data->GetInt64(1), data->GetInt64(2), data->GetString(3), data->GetDateTime(4), data->GetDateTime(5));
		sessions->Add(session);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return sessions;

}

Session^ SessionRepository::CheckIfTimeStampIsFree(DateTime^ selectedDay)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessions WHERE session_start_date=@selectedDay";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@selectedDay", selectedDay);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Session^ session;
	while (data->Read()) {
		session = gcnew Session(data->GetInt64(0), data->GetInt64(1), data->GetInt64(2), data->GetString(3), data->GetDateTime(4), data->GetDateTime(5));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return session;
}

Session^ SessionRepository::GetSessionById(Int64^ session_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessions WHERE id=@session_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@session_id", session_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Session^ session;
	while (data->Read()) {
		session = gcnew Session(data->GetInt64(0), data->GetInt64(1), data->GetInt64(2), data->GetString(3), data->GetDateTime(4), data->GetDateTime(5));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return session;
}

Session^ SessionRepository::GetSessionByName(String^ name)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessions WHERE session_name=@name";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@name", name);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Session^ session;
	while (data->Read()) {
		session = gcnew Session(data->GetInt64(0), data->GetInt64(1), data->GetInt64(2), data->GetString(3), data->GetDateTime(4), data->GetDateTime(5));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return session;
}

List<Session^>^ SessionRepository::GetSessionsByGroupIdAndStartDate(Int64^ groupId, String^ date)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessions WHERE group_id=@groupId AND session_start_date >= @date ORDER BY session_start_date ASC";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@groupId", groupId);
	params->Add("@date", date);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<Session^>^ sessions = gcnew List<Session^>(0);
	while (data->Read()) {
		Session^ session = gcnew Session(data->GetInt64(0), data->GetInt64(1), data->GetInt64(2), data->GetString(3), data->GetDateTime(4), data->GetDateTime(5));
		sessions->Add(session);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return sessions;
}

void SessionRepository::GetSessionsByGroupIdArray(Int64^ groupId, String^ dateString, String^ dateFinish,List<Session^>^& aux)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM grupSessions WHERE group_id=@groupId AND session_start_date >= @date AND session_start_date < @date2 ORDER BY session_start_date ASC";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@groupId", groupId);
	params->Add("@date", dateString);
	params->Add("@date2", dateFinish);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	while (data->Read()) {
		Session^ session = gcnew Session(data->GetInt64(0), data->GetInt64(1), data->GetInt64(2), data->GetString(3), data->GetDateTime(4), data->GetDateTime(5));
		aux->Add(session);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();

	return;
}



#include "pch.h"
#include "SessionRepository.h"
#include "Session.h"
#include "DatabaseConnector.h"

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
	return 0LL;
}

bool SessionRepository::DeleteSession(Int64^ user_id)
{
	return false;
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

List<Session^>^ SessionRepository::GetSessionsByGroupId(Int64^ groupId, String^ date)
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



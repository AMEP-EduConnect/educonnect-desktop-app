#include "pch.h"
#include "ReportsRepository.h"
#include <vector>
#include "DatabaseConnector.h"


using namespace System::Collections::Generic;
using namespace System;

ReportsRepository::ReportsRepository()
{
}

void ReportsRepository::CreateReport(Int64^ user_rep, Int64^ user_id, String^ issue_description) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO user_reports (user_rep, user_id, issue_description) VALUES (@UserRep, @UserId, @IssueDescription)";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@UserRep", user_rep);
		command->Parameters->AddWithValue("@UserId", user_id);
		command->Parameters->AddWithValue("@IssueDescription", issue_description);
		command->ExecuteNonQuery();
		DatabaseConnector::Instance->Disconnect();
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

bool ReportsRepository::ReportExists(Int64^ user_rep, Int64^ user_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM user_reports WHERE user_rep = @UserRep AND user_id = @UserId";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@UserRep", user_rep);
		command->Parameters->AddWithValue("@UserId", user_id);
		MySqlDataReader^ reader = command->ExecuteReader();
		if (reader->HasRows) {
			DatabaseConnector::Instance->Disconnect();
			return true;
		}
		else {
			DatabaseConnector::Instance->Disconnect();
			return false;
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
		return false;
	}
}

array<Int64^>^ ReportsRepository::LoadReportData() {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_rep, user_id, id FROM user_reports";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, nullptr);

	int rowCount = 0;
	while (data->Read()) {
		rowCount++;
	}

	data->Close();
	data = DatabaseConnector::Instance->ExecuteClientCommand(sql, nullptr);

	array<Int64^>^ reportData = gcnew array<Int64^>(rowCount * 3);
	int index = 0;
	while (data->Read()) {
		reportData[index++] = data->GetInt64(0); // user_rep
		reportData[index++] = data->GetInt64(1); // user_id
		reportData[index++] = data->GetInt64(2); // id
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return reportData;
}

String^ ReportsRepository::GetReportDescription(Int64^ report_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT issue_description FROM user_reports WHERE id = @ReportId";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@ReportId", report_id);
		MySqlDataReader^ reader = command->ExecuteReader();
		if (reader->HasRows) {
			reader->Read();
			String^ description = reader->GetString(0);
			DatabaseConnector::Instance->Disconnect();
			return description;
		}
		else {
			DatabaseConnector::Instance->Disconnect();
			return "";
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
		return "";
	}
}

void ReportsRepository::DeleteReport(Int64^ report_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM user_reports WHERE id = @ReportId";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@ReportId", report_id);
		command->ExecuteNonQuery();
		DatabaseConnector::Instance->Disconnect();
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

Int64^ ReportsRepository::GetReportedMember(Int64^ report_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_id FROM user_reports WHERE id = @ReportId";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@ReportId", report_id);
		MySqlDataReader^ reader = command->ExecuteReader();
		if (reader->HasRows) {
			reader->Read();
			Int64^ userId = reader->GetInt64(0);
			DatabaseConnector::Instance->Disconnect();
			return userId;
		}
		else {
			DatabaseConnector::Instance->Disconnect();
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

Int64^ ReportsRepository::GetReportMember(Int64^ report_id) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT user_rep FROM user_reports WHERE id = @ReportId";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@ReportId", report_id);
		MySqlDataReader^ reader = command->ExecuteReader();
		if (reader->HasRows) {
			reader->Read();
			Int64^ userId = reader->GetInt64(0);
			DatabaseConnector::Instance->Disconnect();
			return userId;
		}
		else {
			DatabaseConnector::Instance->Disconnect();
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}
}

array<Int64^>^ ReportsRepository::LoadSuspendedTimes() {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT times_ban FROM suspendedTimes";
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, nullptr);

	int rowCount = 0;
	while (data->Read()) {
		rowCount++;
	}

	data->Close();
	data = DatabaseConnector::Instance->ExecuteClientCommand(sql, nullptr);

	array<Int64^>^ reportData = gcnew array<Int64^>(rowCount);
	int index = 0;
	while (data->Read()) {
		reportData[index++] = data->GetInt64(0);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return reportData;
}

String^ ReportsRepository::GetNamesTimes(Int64^ names_times) {
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT name_times FROM suspendedTimes WHERE times_ban = @NamesTimes";
	try {
		MySqlCommand^ command = gcnew MySqlCommand(sql, DatabaseConnector::Instance->GetConn());
		command->Parameters->AddWithValue("@NamesTimes", names_times);
		MySqlDataReader^ reader = command->ExecuteReader();
		if (reader->HasRows) {
			reader->Read();
			String^ names_times = reader->GetString(0);
			DatabaseConnector::Instance->Disconnect();
			return names_times;
		}
		else {
			DatabaseConnector::Instance->Disconnect();
			return "";
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
		return "";
	}
}
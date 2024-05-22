#include "pch.h"
#include "ReportsRepository.h"
#include <vector>

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
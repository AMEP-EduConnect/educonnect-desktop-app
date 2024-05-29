#include "pch.h"
#include "ReportsService.h"

ReportsService::ReportsService()
{
	reportsRepository = gcnew ReportsRepository();
}

void ReportsService::CreateReport(Int64^ user_rep, Int64^ user_id, String^ issue_description) {
	return reportsRepository->CreateReport(user_rep, user_id, issue_description);
}

bool ReportsService::ReportExists(Int64^ user_rep, Int64^ user_id) {
	return reportsRepository->ReportExists(user_rep, user_id);
}

array<Int64^>^ ReportsService::LoadReportData()
{
	return reportsRepository->LoadReportData();
}

String^ ReportsService::GetReportDescription(Int64^ report_id) {
	return reportsRepository->GetReportDescription(report_id);
}

void ReportsService::DeleteReport(Int64^ report_id) {
	return reportsRepository->DeleteReport(report_id);
}

Int64^ ReportsService::GetReportedMember(Int64^ report_id) {
	return reportsRepository->GetReportedMember(report_id);
}

Int64^ ReportsService::GetReportMember(Int64^ report_id) {
	return reportsRepository->GetReportMember(report_id);
}

array<Int64^>^ ReportsService::LoadSuspendedTimes() {
		return reportsRepository->LoadSuspendedTimes();
}


String^ ReportsService::GetNamesTimes(Int64^ names_times) {
		return reportsRepository->GetNamesTimes(names_times);
}

void ReportsService::SetBlackListDescription(String^ description_report) {
	return reportsRepository->SetBlackListDescription(description_report);
}

void ReportsService::SetBlacklist(Int64^ id_user, String^ description_admin, Int64^ time_counter) {
	return reportsRepository->SetBlacklist(id_user, description_admin, time_counter);
}

Int64^ ReportsService::GetSuspendedTime(String^ name_time) {
	return reportsRepository->GetSuspendedTime(name_time);
}

String^ ReportsService::GetDescriptionBlacklist(Int64^ UserId) {
		return reportsRepository->GetDescriptionBlacklist(UserId);
}
Int64^ ReportsService::GetTimeCounterBlacklist(Int64^ UserId) {
			return reportsRepository->GetTimeCounterBlacklist(UserId);
}

DateTime^ ReportsService::GetIssueDateBlacklist(Int64^ UserId) {
	return reportsRepository->GetIssueDateBlacklist(UserId);
}
DateTime^ ReportsService::GetCurrentTimestamp() {
		return reportsRepository->GetCurrentTimestamp();
}
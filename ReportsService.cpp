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

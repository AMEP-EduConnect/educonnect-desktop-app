#pragma once
#include "ReportsRepository.h"
#include "Reports.h"
#include <vector>
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
#include <vector>
#include "Usuari.h"

public ref class ReportsService
{
public:
	ReportsService();
	void CreateReport(Int64^ user_rep, Int64^ user_id, String^ issue_description);
	bool ReportExists(Int64^ user_rep, Int64^ user_id);

	array<Int64^>^ LoadReportData();
	String^ GetReportDescription(Int64^ report_id);
	void DeleteReport(Int64^ report_id);
	Int64^ GetReportedMember(Int64^ report_id);
	Int64^ GetReportMember(Int64^ report_id);

	array<Int64^>^ LoadSuspendedTimes();
	String^ GetNamesTimes(Int64^ names_times);

	void SetBlackListDescription(String^ description_report);
	Int64^ GetSuspendedTime(String^ name_time);
	void SetBlacklist(Int64^ id_user, String^ description_admin, Int64^ time_counter);

	String^ GetDescriptionBlacklist(Int64^ UserId);
	Int64^ GetTimeCounterBlacklist(Int64^ UserId);
	DateTime^ GetIssueDateBlacklist(Int64^ UserId);
	DateTime^ GetCurrentTimestamp();

	bool IsUserBlacklisted(Int64^ UserId);
	bool UserInBlacklist(Int64^ UserId);
	String^ MessageBanInfo(Int64^ UserId);

private:
	ReportsRepository^ reportsRepository;
};
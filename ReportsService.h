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

private:
	ReportsRepository^ reportsRepository;
};
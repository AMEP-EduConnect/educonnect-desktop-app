#pragma once
#include "GrupEstudiMembership.h"
#include "GrupEstudi.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
#include "MessageManager.h"
#include <vector>
#include "Usuari.h"

using namespace System;
public ref class ReportsRepository
{
public:
		ReportsRepository();
		
		void CreateReport(Int64^ user_rep, Int64^ user_id, String^ issue_description);
		bool ReportExists(Int64^ user_rep, Int64^ user_id);
};

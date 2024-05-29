#include "pch.h"
#include "ReportsService.h"
#include <utility>

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

bool ReportsService::UserInBlacklist(Int64^ UserId) {
    	return reportsRepository->UserInBlacklist(UserId);
}

bool ReportsService::IsUserBlacklisted(Int64^ UserId) {
    bool trobat = true;
    String^ ReportAdminDescription = reportsRepository->GetDescriptionBlacklist(UserId);
    Int64^ TiempoBan = reportsRepository->GetTimeCounterBlacklist(UserId);
    DateTime^ DataAdminBan = reportsRepository->GetIssueDateBlacklist(UserId);
    DateTime^ DataActual = reportsRepository->GetCurrentTimestamp();

    Int64 totalSegundos = Convert::ToInt64(*TiempoBan * 3600);
    DateTime dataAdminBan = *DataAdminBan;
    DateTime dataActual = *DataActual;
    TimeSpan diferencia = dataActual.Subtract(dataAdminBan);
    int segundosTranscurridos = (int)diferencia.TotalSeconds;
    int segundosRestantesTotal = totalSegundos - segundosTranscurridos;
    int horasRestantes = segundosRestantesTotal / 3600;
    segundosRestantesTotal %= 3600;
    int minutosRestantes = segundosRestantesTotal / 60;
    int segundosRestantes = segundosRestantesTotal % 60;

    if (segundosTranscurridos >= totalSegundos) {
        trobat = false;
    }

    if (trobat == false) {
        reportsRepository->DeleteBlacklist(UserId);
	}

    return UserInBlacklist(UserId);
}

String^ ReportsService::MessageBanInfo(Int64^ UserId) {
        String^ ReportAdminDescription = reportsRepository->GetDescriptionBlacklist(UserId);
        Int64^ TiempoBan = reportsRepository->GetTimeCounterBlacklist(UserId);
        DateTime^ DataAdminBan = reportsRepository->GetIssueDateBlacklist(UserId);
        DateTime^ DataActual = reportsRepository->GetCurrentTimestamp();

        Int64 totalSegundos = Convert::ToInt64(*TiempoBan * 3600);
        DateTime dataAdminBan = *DataAdminBan;
        DateTime dataActual = *DataActual;
        TimeSpan diferencia = dataActual.Subtract(dataAdminBan);
        int segundosTranscurridos = (int)diferencia.TotalSeconds;
        int segundosRestantesTotal = totalSegundos - segundosTranscurridos;
        int horasRestantes = segundosRestantesTotal / 3600;
        segundosRestantesTotal %= 3600;
        int minutosRestantes = segundosRestantesTotal / 60;
        int segundosRestantes = segundosRestantesTotal % 60;

        String^ MessageBan = "Tiempo restantes para desbanear: " + horasRestantes + ":" + minutosRestantes + ":" + segundosRestantes + ".";
        return MessageBan;
}
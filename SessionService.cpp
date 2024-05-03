#include "pch.h"
#include "SessionService.h"
#include "Session.h"
#include "MessageManager.h"

using namespace System;

SessionService::SessionService()
{
	sessionRepository = gcnew SessionRepository();
	consultaEspaisService = gcnew ConsultaEspaisService();
}

bool SessionService::CreateSession(Int64^ group_id, String^ espai_name, String^ session_name, DateTime^ session_start_date)
{
	String^ realName = this->GetFormattedEspai(espai_name);
	
	Int64^ espai_id = consultaEspaisService->GetEspaiIdByName(realName);
	DateTime^ session_end_date = session_start_date->AddMinutes(30);
	if (this->sessionRepository->CreateSession(group_id, espai_id, session_name, session_start_date, session_end_date)) {
		return true;
	}
	else {
		return false;
	}
}

Int64^ SessionService::GetSessionId(Int64^ user_id)
{
	return sessionRepository->GetSessionId(user_id);
}

bool SessionService::DeleteSession(Int64^ user_id)
{
	return sessionRepository->DeleteSession(user_id);
}

bool SessionService::CheckIfTimeStampIsFree(DateTime^ selectedDay)
{

	Session^ isFree =this->sessionRepository->CheckIfTimeStampIsFree(selectedDay);
	if (isFree == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SessionService::CheckIfSessionNameIsAvailable(String^ name)
{
	Session^ exists = this->sessionRepository->GetSessionByName(name);
	if (exists == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

List<String^>^ SessionService::GenerateAllTimeStamps()
{
	List<String^>^ allTimeStamps = gcnew List<String^>(0);
	for (int i = 8; i < 21; i++)
	{
		allTimeStamps->Add(i.ToString() + ":00 - " + i.ToString() + ":30");
		allTimeStamps->Add(i.ToString() + ":30 - " + (i + 1).ToString() + ":00");
	}
	return allTimeStamps;
}
String^ SessionService::GetFormattedEspai(String^ name)
{
	int separator = name->IndexOf("-");
	String^ formattedName;

	if (separator != -1) {
		formattedName = name->Substring(0, separator)->Trim();
	}
	else {
		formattedName = name;
	}

	return formattedName;
}
Double SessionService::GetFormattedHour(String^ hour)
{
	String^ formattedHour = hour->Substring(0, hour->IndexOf(":"));
	return System::Convert::ToDouble(formattedHour);
}

Session^ SessionService::GetSessionById(Int64^ user_id)
{
	return sessionRepository->GetSessionById(user_id);
}



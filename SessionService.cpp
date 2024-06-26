#include "pch.h"
#include "SessionService.h"
#include "Session.h"
#include "MessageManager.h"
#include "CurrentSession.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
SessionService::SessionService()
{
	sessionRepository = gcnew SessionRepository();
	consultaEspaisService = gcnew ConsultaEspaisService();
}

bool SessionService::CreateSession(Int64^ group_id, String^ espai_name, String^ session_name, DateTime^ session_start_date)
{
	String^ realName = this->GetFormattedEspai(espai_name);
	
	Int64^ espai_id = consultaEspaisService->GetEspaiIdByName(realName);
	DateTime^ session_end_date = session_start_date->AddHours(1);
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

bool SessionService::DeleteSession(Int64^ session_id)
{
	return sessionRepository->DeleteSession(session_id);
}

bool SessionService::UpdateSessionName(String^ newSessionName, String^ oldSessionName)
{
	if (this->sessionRepository->UpdateSessionName(newSessionName, oldSessionName))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SessionService::UpdateSessionEspai(Int64^ newEspaiId, Int64^ oldEspaiId)
{
	if (this->sessionRepository->UpdateSessionEspai(newEspaiId, oldEspaiId))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SessionService::UpdateSessionDate(DateTime^ newSessionDate, Int64^ session_id)
{
	DateTime^ endSessionDate = newSessionDate->AddHours(1);
	if (this->sessionRepository->UpdateSessionDate(newSessionDate, endSessionDate, session_id))
	{
		return true;
	}
	else
	{
		return false;
	}
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

bool SessionService::CheckIfTimeStampIsOlderThanCurrentTime(DateTime^ selectedDay)
{
	DateTime^ currentTime = DateTime::Now;
	String^ onlyCurrentHour = currentTime->ToString("HH:mm");
	String^ onlySelectedHour = selectedDay->ToString("HH:mm");
	if (currentTime->ToString("yyyy-MM-dd") == selectedDay->ToString("yyyy-MM-dd"))
	{
		if (this->GetFormattedHour(onlyCurrentHour) >= this->GetFormattedHour(onlySelectedHour))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool SessionService::CheckIfSelectedDayMonthIsOlderThanCurrentTime(DateTime^ selectedDay)
{
	DateTime^ currentTime = DateTime::Now;

	DateTime currentDateOnly(currentTime->Year, currentTime->Month, currentTime->Day);
	DateTime selectedDateOnly(selectedDay->Year, selectedDay->Month, selectedDay->Day);

	return currentDateOnly <= selectedDateOnly;
}

List<String^>^ SessionService::GenerateAllTimeStamps()
{
	List<String^>^ allTimeStamps = gcnew List<String^>(0);
	for (int i = 8; i < 21; i++)
	{
		allTimeStamps->Add(i.ToString() + ":00 - " + (i + 1).ToString() + ":00");
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

List<Session^>^ SessionService::GetSessionsByGroupIdAndStartDate(Int64^ groupId, DateTime^ date)
{
	String^ formattedTimestamp = date->ToString("yyyy-MM-dd HH:mm:ss",CultureInfo::InvariantCulture);
	return sessionRepository->GetSessionsByGroupIdAndStartDate(groupId,formattedTimestamp);
}

List<Session^>^ SessionService::GetSessionsByGroupIdArray(array<Int64^>^ groupId, String^ dateString, String^ dateFinish)
{
	List<Session^>^ sessionsdia = gcnew List<Session^>(0);
	for (int i = 0; i < groupId->Length; ++i) {
		sessionRepository->GetSessionsByGroupIdArray(groupId[i], CurrentSession::Instance->GetCurrentUser()->GetUserId(), dateString, dateFinish, sessionsdia);
	}

	return sessionsdia;
}


Session^ SessionService::GetSessionById(Int64^ session_id)
{
	return sessionRepository->GetSessionById(session_id);
}



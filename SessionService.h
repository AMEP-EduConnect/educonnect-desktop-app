#pragma once
#include "SessionRepository.h"
#include "ConsultaEspaisService.h"
using namespace System::Collections::Generic;
using namespace System;

public ref class SessionService
{
public:
	SessionService();
	bool CreateSession(Int64^ group_id, String^ espai_name, String^ session_name, DateTime^ session_start_date);
	Int64^ GetSessionId(Int64^ user_id);
	bool DeleteSession(Int64^ session_id);
	bool UpdateSessionName(String^ newSessionName, String^ oldSessionName);
	bool UpdateSessionEspai(Int64^ newEspaiId, Int64^ oldEspaiId);
	bool UpdateSessionDate(DateTime^ newSessionDate, Int64^ session_id);

	bool CheckIfTimeStampIsFree(DateTime^ selectedDay);
	bool CheckIfSessionNameIsAvailable(String^ name);

	List<String^>^ GenerateAllTimeStamps();
	String^ GetFormattedEspai(String^ name);
	Double GetFormattedHour(String^ hour);
	List<Session^>^ GetSessionsByGroupIdAndStartDate(Int64^ groupId, DateTime^ date);
	List<Session^>^ GetSessionsByGroupIdArray(array<Int64^>^ groupId, String^ dateString, String^ dateFinish);
	Session^ GetSessionById(Int64^ session_id);
	

private:
	SessionRepository^ sessionRepository;
	ConsultaEspaisService^ consultaEspaisService;
};
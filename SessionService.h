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
	bool DeleteSession(Int64^ user_id);

	bool CheckIfTimeStampIsFree(DateTime^ selectedDay);
	bool CheckIfSessionNameIsAvailable(String^ name);

	List<String^>^ GenerateAllTimeStamps();
	String^ GetFormattedEspai(String^ name);
	Double GetFormattedHour(String^ hour);

private:
	SessionRepository^ sessionRepository;
	ConsultaEspaisService^ consultaEspaisService;
};
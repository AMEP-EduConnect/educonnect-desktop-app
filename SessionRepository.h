#pragma once
#include "Session.h"
using namespace System;
using namespace System::Collections::Generic;
public ref class SessionRepository
{
public:
	SessionRepository();
	bool CreateSession(Int64^ grup_id, Int64^ espai_id, String^ session_name, DateTime^ session_start_date, DateTime^ session_end_date);
	Int64^ GetSessionId(Int64^ user_id);
	bool DeleteSession(Int64^ user_id);
	List<Session^>^ GetSessionsByDate(DateTime^ selectedDay, Int64^ currentGrupId);
	Session^ CheckIfTimeStampIsFree(DateTime^ selectedDay);
	Session^ GetSessionById(Int64^ session_id);
	Session^ GetSessionByName(String^ name);
	List<Session^>^ GetSessionsByGroupId(Int64^ groupId, String^ date);
};
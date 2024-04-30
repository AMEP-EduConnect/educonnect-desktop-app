#pragma once
using namespace System;

public ref class SessionRepository
{
public:
	SessionRepository();
	Int64^ CreateSession(Int64^ user_id);
	Int64^ GetSessionId(Int64^ user_id);
	bool DeleteSession(Int64^ user_id);
};
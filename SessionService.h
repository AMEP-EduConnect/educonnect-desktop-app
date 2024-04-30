#pragma once
#include "SessionRepository.h"

using namespace System;

public ref class SessionService
{
public:
	SessionService();
	Int64^ CreateSession(Int64^ user_id);
	Int64^ GetSessionId(Int64^ user_id);
	bool DeleteSession(Int64^ user_id);

private:
	SessionRepository^ sessionRepository;
};
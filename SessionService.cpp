#include "pch.h"
#include "SessionService.h"

using namespace System;

SessionService::SessionService()
{
	sessionRepository = gcnew SessionRepository();
}

Int64^ SessionService::CreateSession(Int64^ user_id)
{
	return sessionRepository->CreateSession(user_id);
}

Int64^ SessionService::GetSessionId(Int64^ user_id)
{
	return sessionRepository->GetSessionId(user_id);
}

bool SessionService::DeleteSession(Int64^ user_id)
{
	return sessionRepository->DeleteSession(user_id);
}

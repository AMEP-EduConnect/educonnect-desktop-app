#include "pch.h"
#include "ChatGrupEstudiService.h"
using namespace System;
using namespace System::Globalization;
using namespace System::Collections::Generic;
ChatGrupEstudiService::ChatGrupEstudiService()
{
    chatMessageRepository = gcnew ChatMessageRepository();
}

bool ChatGrupEstudiService::SendMenssage(Int64^ group_id, Int64^ user_id, String^ message)
{
    return chatMessageRepository->AddMessage(group_id, user_id, message);
}
List<ChatMessage^>^ ChatGrupEstudiService::GetChatMembers(Int64^ group_id)
{
	return chatMessageRepository->GetMessages(group_id);
}
List<ChatMessage^>^ ChatGrupEstudiService::CheckLastsMessage(Int64^ group_id, Int64^ user_id, DateTime^ timestamp)
{
	String^ formattedTimestamp = timestamp->ToString("yyyy-MM-dd HH:mm:ss", CultureInfo::InvariantCulture);
	return chatMessageRepository->GetLastsMessages(group_id, user_id, formattedTimestamp);
}
#pragma once
#include "ChatMessageRepository.h"
#include "ChatMessage.h"
using namespace System;
public ref class ChatGrupEstudiService
{
public:
	ChatGrupEstudiService();
	bool SendMenssage(Int64^ group_id, Int64^ user_id, String^ message);
	List<ChatMessage^>^ GetChatMembers(Int64^ group_id);

	//List<ChatMessage^>^ CheckLastsMessage(Int64^ group_id, Int64^ user_id, DateTime^ timestamp);

	List<ChatMessage^>^ CheckLastsMessage(Int64^ group_id, Int64^ user_id, Int64^ messageid);


private:
	ChatMessageRepository^ chatMessageRepository;
};


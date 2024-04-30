#pragma once
#include "ChatMessage.h"
using namespace System;
using namespace System::Collections::Generic;
public ref class ChatMessageRepository
{
	public:
	bool AddMessage(Int64^ group_id, Int64^ user_id, String^ message);
	List<ChatMessage^>^ GetMessages(Int64^ group_id);

	List<ChatMessage^>^ GetLastsMessages(Int64^ group_id, Int64^ user_id, String^ formattedTimestamp);


	
};


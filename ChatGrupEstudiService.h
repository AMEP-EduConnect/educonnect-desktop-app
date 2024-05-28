#pragma once
#include "ChatMessageRepository.h"
#include "ChatMessage.h"
#include "UsuariRepository.h"
#include "FileRepository.h"
#include "File.h"
using namespace System;
public ref class ChatGrupEstudiService
{
public:
	ChatGrupEstudiService();
	bool SendMenssage(Int64^ group_id, Int64^ user_id, String^ message);
	List<ChatMessage^>^ GetChatMembers(Int64^ group_id);

	//List<ChatMessage^>^ CheckLastsMessage(Int64^ group_id, Int64^ user_id, DateTime^ timestamp);

	List<ChatMessage^>^ CheckLastsMessage(Int64^ group_id, Int64^ user_id, Int64^ messageid);

	List<Files^>^ CheckLastsFiles(Int64^ group_id, Int64^ file_id);

	String^ GetUsernameMessageById(Int64^ user_id);

	bool SendFile(Int64^ group_id, Int64^ user_id, String^ file_name, String^ file_type, array<Byte>^ file_content);

	List<Files^>^ GetFiles(Int64^ group_id);

	Files^ GetFileById(Int64^ file_id);

	bool DeleteFile(Int64^ file_id);


private:
	ChatMessageRepository^ chatMessageRepository;
	UsuariRepository^ usuariRepository;
	FileRepository^ filesRepository;
};


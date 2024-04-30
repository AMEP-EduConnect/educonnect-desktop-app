#include "pch.h"
#include "ChatMessageRepository.h"
#include "DatabaseConnector.h"
#include "ChatMessage.h"
bool ChatMessageRepository::AddMessage(Int64^ group_id, Int64^ user_id, String^ message)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO ChatMessage (user_id, group_id, content) VALUES (@userId, @groupId, @content)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@userId", user_id);
	params->Add("@groupId", group_id);
	params->Add("@content", message);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}
List<ChatMessage^>^ ChatMessageRepository::GetMessages(Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM ChatMessage WHERE group_id = @groupId ORDER BY timestamp ASC LIMIT 20";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@groupId", group_id->ToString());
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<ChatMessage^>^ messages = gcnew List<ChatMessage^>(0);
	while (data->Read())
	{
		ChatMessage^ message = gcnew ChatMessage();
		message->setId(data->GetInt64(0));
		message->setUserId(data->GetInt64(1));
		message->setGroupId(data->GetInt64(2));
		message->setMessage(data->GetString(3));
		message->setTimestamp(data->GetDateTime(4));
		messages->Add(message);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return messages;
}
List<ChatMessage^>^ ChatMessageRepository::GetLastsMessages(Int64^ group_id, Int64^ user_id, Int64^ message_id)//String^ formattedTimestamp)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM ChatMessage WHERE group_id = @groupId AND user_id != @user_id AND id > @message_id ORDER BY timestamp ASC";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@groupId", group_id);
	params->Add("@user_id", user_id);
	params->Add("@message_id", message_id);
	//params->Add("@timestamp", formattedTimestamp);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<ChatMessage^>^ messages = gcnew List<ChatMessage^>(0);
	while (data->Read())
	{
		ChatMessage^ message = gcnew ChatMessage();
		message->setId(data->GetInt64(0));
		message->setUserId(data->GetInt64(1));
		message->setGroupId(data->GetInt64(2));
		message->setMessage(data->GetString(3));
		message->setTimestamp(data->GetDateTime(4));
		messages->Add(message);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return messages;
}


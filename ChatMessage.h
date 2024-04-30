#pragma once
using namespace System;
public ref class ChatMessage
{
public:
	ChatMessage();
	ChatMessage(System::Int64^ userId, System::Int64^ groupId, String^ message);
	String^ getMessage();
	Int64^ getUserId();
	DateTime^ getTimestamp();
	Int64^ getGroupId();
	Int64^ getId();
	void setId(Int64^ id);
	void setGroupId(Int64^ groupId);
	void setTimestamp(DateTime^ timestamp);
	void setMessage(String^ message);
	void setUserId(Int64^ userId);
private:
	Int64^ id;
	Int64^ userId;
	Int64^ groupId;
	String^ message;
	DateTime^ timestamp;
};
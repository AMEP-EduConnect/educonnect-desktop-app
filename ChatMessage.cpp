#include "pch.h"
#include "ChatMessage.h"
ChatMessage::ChatMessage() {}

ChatMessage::ChatMessage(String^ username, Int64^ userId, Int64^ groupId, String^ message)
{
	this->username = username;
    this->userId = userId;
    this->groupId = groupId;
    this->message = message;
    this->timestamp = DateTime::Now; 
}


String^ ChatMessage::getMessage()
{
	return this->message;
}
Int64^ ChatMessage::getUserId()
{
	return this->userId;
}

DateTime^ ChatMessage::getTimestamp()
{
	return this->timestamp;
}
Int64^ ChatMessage::getGroupId()
{
	return this->groupId;
}
Int64^ ChatMessage::getId()
{
	return this->id;
}
void ChatMessage::setId(Int64^ id)
{
	this->id = id;
}
void ChatMessage::setGroupId(Int64^ groupId)
{
	this->groupId = groupId;
}

void ChatMessage::setTimestamp(DateTime^ timestamp)
{
	this->timestamp = timestamp;
}

void ChatMessage::setMessage(String^ message)
{
	this->message = message;
}

void ChatMessage::setUserId(Int64^ userId)
{
	this->userId = userId;
}

String^ ChatMessage::getUsername()
{
	return this->username;
}

void ChatMessage::setUsername(String^ username)
{
	this->username = username;
}


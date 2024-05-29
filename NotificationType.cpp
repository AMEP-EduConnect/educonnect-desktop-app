#include "pch.h"
#include "NotificationType.h"

NotificationType::NotificationType()
{
	id = nullptr;
	notificationType = "";
}

NotificationType::NotificationType(Int64^ id, String^ notificationType)
{
	this->id = id;
	this->notificationType = notificationType;
}

void NotificationType::SetId(Int64^ value)
{
	this->id = value;
}

Int64^ NotificationType::GetId()
{
	return this->id;
}

void NotificationType::SetNotificationType(String^ value)
{
	this->notificationType = value;
}

String^ NotificationType::GetNotificationType()
{
	return this->notificationType;
}

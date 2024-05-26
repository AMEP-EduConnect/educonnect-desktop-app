#include "pch.h"
#include "Notificacio.h"

Notificacio::Notificacio()
{
	id = nullptr;
	notification_type_id = nullptr;
	status_id = nullptr;
	source_group_id = nullptr;
	source_user_id = nullptr;
	destination_user_id = nullptr;
}

Notificacio::Notificacio(Int64^ id, Int64^ notification_type_id, Int64^ status_id, Int64^ source_group_id, Int64^ source_user_id, Int64^ destination_user_id)
{
	this->id = id;
	this->notification_type_id = notification_type_id;
	this->status_id = status_id;
	this->source_group_id = source_group_id;
	this->source_user_id = source_user_id;
	this->destination_user_id = destination_user_id;
}

void Notificacio::SetId(Int64^ value)
{
	this->id = value;
}

Int64^ Notificacio::GetId()
{
	return this->id;
}

void Notificacio::SetNotificationType(Int64^ value)
{
	this->notification_type_id = value;
}

Int64^ Notificacio::GetNotificationType()
{
	return this->notification_type_id;
}

void Notificacio::SetStatus(Int64^ value)
{
	this->status_id = value;
}

Int64^ Notificacio::GetStatus()
{
	return this->status_id;
}

void Notificacio::SetSourceGroupId(Int64^ value)
{
	this->source_group_id = value;
}

Int64^ Notificacio::GetSourceGroupId()
{
	return this->source_group_id;
}

void Notificacio::SetSourceUserId(Int64^ value)
{
	this->source_user_id = value;
}

Int64^ Notificacio::GetSourceUserId()
{
	return this->source_user_id;
}

void Notificacio::SetDestinationUserId(Int64^ value)
{
	this->destination_user_id = value;
}

Int64^ Notificacio::GetDestinationUserId()
{
	return this->destination_user_id;
}


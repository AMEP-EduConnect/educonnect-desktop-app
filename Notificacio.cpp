#include "pch.h"
#include "Notificacio.h"

Notificacio::Notificacio()
{
	id;
	group_id;
	source_id;
	destination_id;
	role = "";
}

Notificacio::Notificacio(Int64^ id, Int64^ group_id, Int64^ source_id, Int64^ destination_id, String^ role)
{
	this->id = id;
	this->group_id = group_id;
	this->source_id = source_id;
	this->destination_id = destination_id;
	this->role = role;
}

void Notificacio::SetId(Int64^ value)
{
	this->id = value;
}

Int64^ Notificacio::GetId()
{
	return this->id;

}

void Notificacio::SetGroup_id(Int64^ value)
{
	this->group_id = value;
}

Int64^ Notificacio::GetGroup_id()
{
	return this->group_id;
}

void Notificacio::SetSource_id(Int64^ value)
{
	this->source_id = value;
}

Int64^ Notificacio::GetSource_id()
{
	return this->source_id;

}

void Notificacio::SetDestination_id(Int64^ value)
{
	this->destination_id = value;
}

Int64^ Notificacio::GetDestination_id()
{
	return this->destination_id;

}

void Notificacio::SetRole(String^ value)
{
	this->role = value;
}

String^ Notificacio::GetRole()
{
	return this->role;

}

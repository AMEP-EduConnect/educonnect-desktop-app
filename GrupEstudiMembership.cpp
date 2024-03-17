#include "pch.h"
#include "GrupEstudiMembership.h"


GrupEstudiMembership::GrupEstudiMembership()
{
	id = nullptr;
	user_id = nullptr;
	group_id = nullptr;
	member_since = "";
}

GrupEstudiMembership::GrupEstudiMembership(Int64^ id, Int64^ user_id, Int64^ group_id, String^ member_since)
{
	this->id = id;
	this->user_id = user_id;
	this->group_id = group_id;
	this->member_since = member_since;
}

Int64^ GrupEstudiMembership::GetId()
{
	return id;
}

Int64^ GrupEstudiMembership::GetUserId()
{
	return user_id;
}

Int64^ GrupEstudiMembership::GetGroupId()
{
	return group_id;
}

String^ GrupEstudiMembership::GetMemberSince()
{
	return member_since;
}


void GrupEstudiMembership::SetId(Int64^ id)
{
	this->id = id;
}

void GrupEstudiMembership::SetUserId(Int64^ user_id)
{
	this->user_id = user_id;
}

void GrupEstudiMembership::SetGroupId(Int64^ group_id)
{
	this->group_id = group_id;
}

void GrupEstudiMembership::SetMemberSince(String^ member_since)
{
	this->member_since = member_since;
}


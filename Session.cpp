#include "pch.h"
#include "Session.h"

Session::Session()
{
	id = nullptr;
	group_id = nullptr;
	espai_id = nullptr;
	session_name = "";
	session_start_date = nullptr;
	session_end_date = nullptr;
}	

Session::Session(Int64^ id, Int64^ group_id, Int64^ espai_id, String^ session_name, DateTime^ session_start_date, DateTime^ session_end_date)
{
	this->id = id;
	this->group_id = group_id;
	this->espai_id = espai_id;
	this->session_name = session_name;
	this->session_start_date = session_start_date;
	this->session_end_date = session_end_date;
}

Int64^ Session::GetId()
{
	return id;
}

Int64^ Session::GetGroupId()
{
	return group_id;
}

Int64^ Session::GetEspaiId()
{
	return espai_id;
}

String^ Session::GetSessionName()
{
	return session_name;
}

DateTime^ Session::GetSessionStartDate()
{
	return session_start_date;
}

DateTime^ Session::GetSessionEndDate()
{
	return session_end_date;
}

void Session::SetId(Int64^ id)
{
	this->id = id;
}

void Session::SetGroupId(Int64^ group_id)
{
	this->group_id = group_id;
}

void Session::SetEspaiId(Int64^ espai_id)
{
	this->espai_id = espai_id;
}

void Session::SetSessionName(String^ session_name)
{
	this->session_name = session_name;
}

void Session::SetSessionStartDate(DateTime^ session_start_date)
{
	this->session_start_date = session_start_date;
}

void Session::SetSessionEndDate(DateTime^ session_end_date)
{
	this->session_end_date = session_end_date;
}

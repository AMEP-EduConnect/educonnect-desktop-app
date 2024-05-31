#include "pch.h"
#include "Reports.h"

Report::Report()
{
	id = nullptr;
	user_rep = nullptr;
	user_id = nullptr;
	issue_description = "";
	issue_date = "";
}

Report::Report(Int64^ id, Int64^ user_rep, Int64^ user_id, String^ issue_description, String^ issue_date)
{
	this->id = id;
	this->user_rep = user_rep;
	this->user_id = user_id;
	this->issue_description = issue_description;
	this->issue_date = issue_date;
}

Int64^ Report::GetId()
{
	return id;
}

Int64^ Report::GetUserRepId()
{
	return user_rep;
}

Int64^ Report::GetUserId()
{
	return user_id;
}

String^ Report::GetDescription()
{
	return issue_description;
}

String^ Report::GetDate()
{
	return issue_date;
}

void Report::SetId(Int64^ id)
{
	this->id = id;
}

void Report::SetUserRepId(Int64^ user_rep)
{
	this->user_rep = user_rep;
}

void Report::SetUserId(Int64^ user_id)
{
	this->user_id = user_id;
}

void Report::SetDescription(String^ issue_description)
{
	this->issue_description = issue_description;
}

void Report::SetDate(String^ issue_date)
{
	this->issue_date = issue_date;
}




#pragma once

using namespace System;

public ref class Session
{
public:
	Session();
	Session(Int64^ id, Int64^ group_id, Int64^ espai_id, String^ session_name, DateTime^ session_start_date, DateTime^ session_end_date);

	Int64^ GetId();
	Int64^ GetGroupId();
	Int64^ GetEspaiId();
	String^ GetSessionName();
	DateTime^ GetSessionStartDate();
	DateTime^ GetSessionEndDate();

	void SetId(Int64^ id);
	void SetGroupId(Int64^ group_id);
	void SetEspaiId(Int64^ espai_id);
	void SetSessionName(String^ session_name);
	void SetSessionStartDate(DateTime^ session_start_date);
	void SetSessionEndDate(DateTime^ session_end_date);

private:
	property Int64^ id;
	property Int64^ group_id;
	property Int64^ espai_id;
	property String^ session_name;
	property DateTime^ session_start_date;
	property DateTime^ session_end_date;
};


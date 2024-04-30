#pragma once

using namespace System;

public ref class Session
{
public:
	Session();
	Session(Int64^ id, Int64^ group_id, Int64^ espai_id, String^ session_name, String^ session_start_date, String^ session_end_date);

	Int64^ GetId();
	Int64^ GetGroupId();
	Int64^ GetEspaiId();
	String^ GetSessionName();
	String^ GetSessionStartDate();
	String^ GetSessionEndDate();

	void SetId(Int64^ id);
	void SetGroupId(Int64^ group_id);
	void SetEspaiId(Int64^ espai_id);
	void SetSessionName(String^ session_name);
	void SetSessionStartDate(String^ session_start_date);
	void SetSessionEndDate(String^ session_end_date);

private:
	property Int64^ id;
	property Int64^ group_id;
	property Int64^ espai_id;
	property String^ session_name;
	property String^ session_start_date;
	property String^ session_end_date;
};


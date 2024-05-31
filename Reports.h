#pragma once
using namespace System;
public ref class Report
{
	public:
		Report();
		Report(Int64^ id, Int64^ user_rep, Int64^ user_id, String^ issue_description, String^ issue_date);


	private:
		property Int64^ id;
		property Int64^ user_rep;
		property Int64^ user_id;
		property String^ issue_description;
		property String^ issue_date;

	public:
		Int64^ GetId();
		Int64^ GetUserRepId();
		Int64^ GetUserId();
		String^ GetDescription();
		String^ GetDate();


		void SetId(Int64^ id);
		void SetUserRepId(Int64^ user_rep);
		void SetUserId(Int64^ user_id);
		void SetDescription(String^ issue_description);
		void SetDate(String^ issue_date);
};

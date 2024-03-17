#pragma once
using namespace System;
public ref class GrupEstudiMembership
{
public:

	GrupEstudiMembership();
	// Constructor
	GrupEstudiMembership(Int64^ id, Int64^ user_id, Int64^ group_id, String^ member_since);

private:
	property Int64^ id;
	property Int64^ user_id;
	property Int64^ group_id;
	property String^ member_since;

public:

	//getters
	Int64^ GetId();
	Int64^ GetUserId();
	Int64^ GetGroupId();
	String^ GetMemberSince();

	//setters
	void SetId(Int64^ id);
	void SetUserId(Int64^ user_id);
	void SetGroupId(Int64^ group_id);
	void SetMemberSince(String^ member_since);
};
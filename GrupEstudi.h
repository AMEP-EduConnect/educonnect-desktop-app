#pragma once
using namespace System;
public ref class GrupEstudi
{
public:
	
	GrupEstudi();

	GrupEstudi(Int64^ id, String^ group_name, Int64^ group_owner_id, Int64^ group_academic_tag, String^ description);

private:
	property Int64^ id;
	property String^ group_name;
	property Int64^ group_owner_id;
	property Int64^ group_academic_tag;
	property String^ description;
	property array<Int64>^ memberIds;
public:

	Int64^ GetId();
	String^ GetGroupName();
	Int64^ GetGroupOwnerId();
	Int64^ GetGroupAcademicTag();
	String^ GetDescription();
	array<Int64>^ GetMemberIds();

	void SetId(Int64^ id);
	void SetGroupName(String^ group_name);
	void SetGroupOwnerId(Int64^ group_owner_id);
	void SetGroupAcademicTag(Int64^ group_academic_tag);
	void SetDescription(String^ description);


};
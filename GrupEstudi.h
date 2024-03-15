#pragma once
using namespace System;
public ref class GrupEstudi
{
public:
	
	GrupEstudi();
	// Constructor
	GrupEstudi(Int64^ id, String^ group_name, Int64^ group_owner_id, Int64^ group_academic_tag, String^ description);

private:
	property Int64^ id;
	property String^ group_name;
	property Int64^ group_owner_id;
	property Int64^ group_academic_tag;
	property String^ description;
	property array<Int64>^ memberIds;
public:

	//getters
	Int64^ getId();
	String^ getGroupName();
	Int64^ getGroupOwnerId();
	Int64^ getGroupAcademicTag();
	String^ getDescription();
	array<Int64>^ getMemberIds();
	//setters
	void setId(Int64^ id);
	void setGroupName(String^ group_name);
	void setGroupOwnerId(Int64^ group_owner_id);
	void setGroupAcademicTag(Int64^ group_academic_tag);
	void setDescription(String^ description);
	//List
	//void addMemberId(Int64^ member_id);

//ZITRO STUFF
// 
// 
};
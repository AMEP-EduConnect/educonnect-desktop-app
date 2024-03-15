#pragma once
using namespace System;

public ref class GrupEstudi
{
public:
	
	GrupEstudi();
	// Constructor
	GrupEstudi(Int64^ id, String^ group_name, Int64^ group_owner_id, Int64^ group_academic_tag, String^ description);

private:
	Int64^ id;
	String^ group_name;
	Int64^ group_owner_id;
	Int64^ group_academic_tag;
	String^ description;
public:

	//getters
	Int64^ getId();
	String^ getGroupName();
	Int64^ getGroupOwnerId();
	Int64^ getGroupAcademicTag();
	String^ getDescription();
	//setters
	void setId(Int64^ id);
	void setGroupName(String^ group_name);
	void setGroupOwnerId(Int64^ group_owner_id);
	void setGroupAcademicTag(Int64^ group_academic_tag);
	void setDescription(String^ description);


};
#pragma once
using namespace System;

public ref class AcademicTag
{
private:
		Int64^ id;
		String^ tag_name;

public:
	AcademicTag();
	AcademicTag(Int64^ id, String^ tag_name);

	//getters
	Int64^ getId();
	String^ getTagName();
	//setters
	void setId(Int64^ id);
	void setTagName(System::String^ tag_name);	

};
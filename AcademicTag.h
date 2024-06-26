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

	Int64^ GetId();
	String^ GetTagName();

	void SetId(Int64^ id);
	void SetTagName(System::String^ tag_name);	

};
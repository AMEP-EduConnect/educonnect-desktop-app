#include "pch.h"
#include "AcademicTag.h"


AcademicTag::AcademicTag()
{
	id = nullptr;
	tag_name = "";
}

AcademicTag::AcademicTag(Int64^ id, String^ tag_name)
{
	this->id = id;
	this->tag_name = tag_name;
}

Int64^ AcademicTag::getId()
{
	return id;
}

String^ AcademicTag::getTagName()
{
	return tag_name;
}

void AcademicTag::setId(Int64^ id)
{
	this->id = id;
}

void AcademicTag::setTagName(System::String^ tag_name)
{
	this->tag_name = tag_name;
}


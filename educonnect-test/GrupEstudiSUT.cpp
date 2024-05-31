#include "GrupEstudiSUT.h"

GrupEstudiSUT::GrupEstudiSUT()
{
	id = nullptr;
	group_name = "";
	group_academic_tag = nullptr;
	group_owner_id = nullptr;
	description = "";
	memberIds = gcnew array<Int64>(0);

}

GrupEstudiSUT::GrupEstudiSUT(Int64^ id, String^ group_name, Int64^ group_owner_id, Int64^ group_academic_tag, String^ description)
{
	this->id = id;
	this->group_name = group_name;
	this->group_owner_id = group_owner_id;
	this->group_academic_tag = group_academic_tag;
	this->description = description;
	memberIds = gcnew array<Int64>(0);
}

Int64^ GrupEstudiSUT::GetId()
{
	return id;
}

String^ GrupEstudiSUT::GetGroupName()
{
	return group_name;
}

Int64^ GrupEstudiSUT::GetGroupOwnerId()
{
	return group_owner_id;
}

Int64^ GrupEstudiSUT::GetGroupAcademicTag()
{
	return group_academic_tag;
}

String^ GrupEstudiSUT::GetDescription()
{
	return description;
}

array<Int64>^ GrupEstudiSUT::GetMemberIds()
{
	return memberIds;
}

void GrupEstudiSUT::SetId(Int64^ id)
{
	this->id = id;
}

void GrupEstudiSUT::SetGroupName(String^ group_name)
{
	this->group_name = group_name;
}

void GrupEstudiSUT::SetGroupOwnerId(Int64^ group_owner_id)
{
	this->group_owner_id = group_owner_id;
}

void GrupEstudiSUT::SetGroupAcademicTag(Int64^ group_academic_tag)
{
	this->group_academic_tag = group_academic_tag;
}

void GrupEstudiSUT::SetDescription(String^ description)
{
	this->description = description;
}
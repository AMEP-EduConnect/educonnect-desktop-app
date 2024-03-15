#include "pch.h"
#include "GrupEstudi.h"


GrupEstudi::GrupEstudi()
{
	id = nullptr;
	group_name = "";
	group_academic_tag = nullptr;
	group_owner_id = nullptr;
	description = "";
	memberIds = gcnew array<Int64>(0);

}

GrupEstudi::GrupEstudi(Int64^ id, String^ group_name, Int64^ group_owner_id, Int64^ group_academic_tag, String^ description)
{
	this->id = id;
	this->group_name = group_name;
	this->group_owner_id = group_owner_id;
	this->group_academic_tag = group_academic_tag;
	this->description = description;
	memberIds = gcnew array<Int64>(0);
}

Int64^ GrupEstudi::getId()
{
	return id;
}

String^ GrupEstudi::getGroupName()
{
	return group_name;
}

Int64^ GrupEstudi::getGroupOwnerId()
{
	return group_owner_id;
}

Int64^ GrupEstudi::getGroupAcademicTag()
{
	return group_academic_tag;
}

String^ GrupEstudi::getDescription()
{
	return description;
}

array<Int64>^ GrupEstudi::getMemberIds()
{
	return memberIds;
}

void GrupEstudi::setId(Int64^ id)
{
	this->id = id;
}

void GrupEstudi::setGroupName(String^ group_name)
{
	this->group_name = group_name;
}

void GrupEstudi::setGroupOwnerId(Int64^ group_owner_id)
{
	this->group_owner_id = group_owner_id;
}

void GrupEstudi::setGroupAcademicTag(Int64^ group_academic_tag)
{
	this->group_academic_tag = group_academic_tag;
}

void GrupEstudi::setDescription(String^ description)
{
	this->description = description;
}



//ZITRO STUFF
// 
// 
//void GrupEstudi::addMemberId(Int64^ member_id)
//{
//	Array::Resize(memberIds, memberIds->Length + 1);
//	memberIds[memberIds->Length - 1] = member_id;
//}
//
//void GrupEstudi::removeMemberId(Int64^ member_id)
//{
//	for (int i = 0; i < memberIds->Length; i++)
//	{
//		if (memberIds[i] == member_id)
//		{
//			for (int j = i; j < memberIds->Length - 1; j++)
//			{
//				memberIds[j] = memberIds[j + 1];
//			}
//			Array::Resize(memberIds, memberIds->Length - 1);
//			break;
//		}
//	}
//}



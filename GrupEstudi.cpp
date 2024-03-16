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

Int64^ GrupEstudi::GetId()
{
	return id;
}

String^ GrupEstudi::GetGroupName()
{
	return group_name;
}

Int64^ GrupEstudi::GetGroupOwnerId()
{
	return group_owner_id;
}

Int64^ GrupEstudi::GetGroupAcademicTag()
{
	return group_academic_tag;
}

String^ GrupEstudi::GetDescription()
{
	return description;
}

array<Int64>^ GrupEstudi::GetMemberIds()
{
	return memberIds;
}

void GrupEstudi::SetId(Int64^ id)
{
	this->id = id;
}

void GrupEstudi::SetGroupName(String^ group_name)
{
	this->group_name = group_name;
}

void GrupEstudi::SetGroupOwnerId(Int64^ group_owner_id)
{
	this->group_owner_id = group_owner_id;
}

void GrupEstudi::SetGroupAcademicTag(Int64^ group_academic_tag)
{
	this->group_academic_tag = group_academic_tag;
}

void GrupEstudi::SetDescription(String^ description)
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



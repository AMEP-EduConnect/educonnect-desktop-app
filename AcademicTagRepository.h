#pragma once
#include "AcademicTag.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class AcademicTagRepository
{

public:

	// ACADEMIC TAGs CRUD
	AcademicTagRepository();

	bool CreateAcademicTag(String^ tag_name);

	AcademicTag^ GetAcademicTagById(Int64^ id);
	AcademicTag^ GetAcademicTagByName(String^ tag_name);
	List<AcademicTag^>^ GetAllAcademicTags();
	List<AcademicTag^>^ GetAllAcademicTagsWithGroup(Int64^ user_id);


	bool UpdateAcademicTag(Int64^ id, String^ tag_name);

	bool DeleteAcademicTag(Int64^ id);


	// ACADEMIC TAG RELATIONS
	bool AsociateAcademicTagToUser(Int64^ user_id, Int64^ tag_id);
	bool DeleteAcademicTagFromUser(Int64^ user_id, Int64^ tag_id);

	List<AcademicTag^>^ GetAcademicTagsByUserId(Int64^ user_id);
	List<AcademicTag^>^ GetAcademicTagsByUserIdWithGroup(Int64^ user_id);


};


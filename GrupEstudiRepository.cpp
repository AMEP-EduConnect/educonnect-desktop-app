#include "pch.h"
#include "GrupEstudiRepository.h"
#include "DatabaseConnector.h"
#include "AcademicTag.h"
GrupEstudiRepository::GrupEstudiRepository()
{

}
array<AcademicTag^>^ GrupEstudiRepository::LoadAllAcademicTags()
{
	array<AcademicTag^>^ academicTags = gcnew array<AcademicTag^>(0);
	DatabaseConnector::Instance->connect();
	String^ sql = "SELECT * FROM academicTags";
	MySqlDataReader^ data = DatabaseConnector::Instance->executeCommand(sql);
	while (data->Read())
	{
		AcademicTag^ academicTag = gcnew AcademicTag();
		academicTag->setId(data->GetInt64(0));
		academicTag->setTagName(data->GetString(1));
		Array::Resize(academicTags, academicTags->Length + 1);
		academicTags[academicTags->Length - 1] = academicTag;
	}
	DatabaseConnector::Instance->disconnect();
	return academicTags;
}


//ZITRO STUFF
// 
// 


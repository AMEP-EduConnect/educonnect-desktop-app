#include "pch.h"
#include "AcademicTagRepository.h"


AcademicTagRepository::AcademicTagRepository()
{

}

bool AcademicTagRepository::CreateAcademicTag(String^ tag_name)
{
	return false;
}

AcademicTag^ AcademicTagRepository::GetAcademicTagById(Int64^ id)
{
	throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

AcademicTag^ AcademicTagRepository::GetAcademicTagByName(String^ tag_name)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM academicTags WHERE tag_name = @tag_name";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@tag_name", tag_name);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	AcademicTag^ academicTag = nullptr;

	if (data->Read()) {
		academicTag = gcnew AcademicTag(data->GetInt64(0), data->GetString(1));
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return academicTag;
}

List<AcademicTag^>^ AcademicTagRepository::GetAllAcademicTags()
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM academicTags ORDER BY tag_name ASC";

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteInternCommand(sql);
	List<AcademicTag^>^ academicTags = gcnew List<AcademicTag^>(0);

	while (data->Read()) {
		AcademicTag^ academicTag = gcnew AcademicTag(data->GetInt64(0), data->GetString(1));
		academicTags->Add(academicTag);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return academicTags;

}

List<AcademicTag^>^ AcademicTagRepository::GetAllAcademicTagsWithGroup(Int64^ user_id)
{

	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT DISTINCT at.id, at.tag_name FROM academicTags at JOIN studyGroups sg ON at.id = sg.group_academic_tag";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	//params->Add("@user_id", user_id);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteInternCommand(sql);
	List<AcademicTag^>^ academicTags = gcnew List<AcademicTag^>(0);

	while (data->Read()) {
		AcademicTag^ academicTag = gcnew AcademicTag(data->GetInt64(0), data->GetString(1));
		academicTags->Add(academicTag);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return academicTags;

}





bool AcademicTagRepository::UpdateAcademicTag(Int64^ id, String^ tag_name)
{
	return false;
}

bool AcademicTagRepository::DeleteAcademicTag(Int64^ id)
{
	return false;
}




bool AcademicTagRepository::AsociateAcademicTagToUser(Int64^ user_id, Int64^ tag_id)
{

	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO users_academicTags (user_id, academicTag_id) VALUES (@user_id, @tag_id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id);
	params->Add("@tag_id", tag_id);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;

}

bool AcademicTagRepository::DeleteAcademicTagFromUser(Int64^ user_id, Int64^ tag_id)
{

	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM users_academicTags WHERE user_id = @user_id AND academicTag_id = @tag_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id);
	params->Add("@tag_id", tag_id);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;

}

List<AcademicTag^>^ AcademicTagRepository::GetAcademicTagsByUserId(Int64^ user_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM academicTags WHERE id IN (SELECT academicTag_id FROM users_academicTags WHERE user_id = @user_id)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<AcademicTag^>^ academicTags = gcnew List<AcademicTag^>(0);

	while (data->Read()) {
		AcademicTag^ academicTag = gcnew AcademicTag(data->GetInt64(0), data->GetString(1));
		academicTags->Add(academicTag);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return academicTags;

}

List<AcademicTag^>^ AcademicTagRepository::GetAcademicTagsByUserIdWithGroup(Int64^ user_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT DISTINCT at.id, at.tag_name FROM users_academicTags uat JOIN academicTags at ON uat.academicTag_id = at.id JOIN studyGroups sg ON uat.academicTag_id = sg.group_academic_tag WHERE uat.user_id = @user_id AND sg.id NOT IN(SELECT usg.group_id FROM studyGroupsMembership usg WHERE usg.user_id = @user_id)";

	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@user_id", user_id);

	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	List<AcademicTag^>^ academicTags = gcnew List<AcademicTag^>(0);

	while (data->Read()) {
		AcademicTag^ academicTag = gcnew AcademicTag(data->GetInt64(0), data->GetString(1));
		academicTags->Add(academicTag);
	}

	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return academicTags;
	
}

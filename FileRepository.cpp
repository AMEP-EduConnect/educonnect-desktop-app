#include "pch.h"
#include "FileRepository.h"

bool FileRepository::AddFile(Int64^ group_id, Int64^ user_id, String^ file_name, String^ file_type, array<Byte>^ file_content)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "INSERT INTO files (group_id, user_id, file_name, file_type, file_content) VALUES (@group_id, @user_id, @file_name, @file_type, @file_content)";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@group_id", group_id);
	params->Add("@user_id", user_id);
	params->Add("@file_name", file_name);
	params->Add("@file_type", file_type);
	params->Add("@file_content", file_content);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

Files^ FileRepository::GetFile(Int64^ file_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM files WHERE id = @file_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@file_id", file_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	Files^ file = gcnew Files();
	array<Byte>^ file_content = gcnew array<Byte>(0);
	while (data->Read())
	{
		file->set_id(data->GetInt64(0));
		file->set_user_id(data->GetInt64(1));
		file->set_group_id(data->GetInt64(2));
		file->set_filename(data->GetString(3));
		file->set_file_type(data->GetString(4));
		file_content = (array<Byte>^)data->GetValue(5);
		file->set_file_content(file_content);
		file->set_upload_timestamp(data->GetDateTime(6));
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return file;
}

List<Files^>^ FileRepository::GetFiles(Int64^ group_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "SELECT * FROM files WHERE group_id = @group_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@group_id", group_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	
	array<Byte>^ file_content = gcnew array<Byte>(0);
	List<Files^>^ files = gcnew List<Files^>(0);
	while(data->Read())
	{
		Files^ file = gcnew Files();
		file->set_id(data->GetInt64(0));
		file->set_user_id(data->GetInt64(1));
		file->set_group_id(data->GetInt64(2));
		file->set_filename(data->GetString(3));
		file->set_file_type(data->GetString(4));
		file_content = (array<Byte>^)data->GetValue(5);
		file->set_file_content(file_content);
		file->set_upload_timestamp(data->GetDateTime(6));
		files->Add(file);
	}
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return files;
}

bool FileRepository::DeleteFileById(Int64^ file_id)
{
	DatabaseConnector::Instance->Connect();
	String^ sql = "DELETE FROM files WHERE id = @file_id";
	Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
	params->Add("@file_id", file_id);
	MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
	data->Close();
	DatabaseConnector::Instance->Disconnect();
	return true;
}

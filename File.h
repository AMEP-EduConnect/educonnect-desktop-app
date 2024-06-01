#pragma once
using namespace System;
public ref class Files
{
public:
	//getters
	Int64^ get_id();
	Int64^ get_group_id();
	Int64^ get_user_id();
	String^ get_filename();
	String^ get_file_type();
	DateTime^ get_upload_timestamp();
	array<Byte>^ get_file_content();
	//setters
	void set_id(Int64^ id);
	void set_group_id(Int64^ group_id);
	void set_user_id(Int64^ user_id);
	void set_filename(String^ filename);
	void set_file_type(String^ file_type);
	void set_upload_timestamp(DateTime^ time);
	void set_file_content(array<Byte>^ file_content);
	Files();
	Files(Int64^ id, Int64^ group_id, Int64^ user_id, String^ filename, String^ file_type, array<Byte>^ file_content);

private:
	Int64^ id;
	Int64^ group_id;
	Int64^ user_id;
	String^ filename;
	String^ file_type;
	array<Byte>^ file_content;
	DateTime^ upload_timestamp;
};


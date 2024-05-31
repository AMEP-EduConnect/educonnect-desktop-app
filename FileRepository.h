#pragma once
#include "DatabaseConnector.h"
#include "File.h"
using namespace System;
using namespace System::IO;
public ref class FileRepository
{
public:
	bool AddFile(Int64^ group_id, Int64^ user_id, String^ file_name, String^ file_type, array<Byte>^ file_content);
	Files^ GetFile(Int64^ file_id);
	List<Files^>^ GetFiles(Int64^ group_id);
	bool DeleteFileById(Int64^ file_id);
	List<Files^>^ GetLastsFiles(Int64^ group_id, Int64^ file_id);
	//System::String^ LoadFromFile(System::String^ fileName);
};


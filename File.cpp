#include "pch.h"
#include "File.h"

using namespace System;
using namespace System::IO;
using namespace System::Text;
Files::Files()
{
}
Files::Files(Int64^ id, Int64^ group_id, Int64^ user_id, String^ filename, String^ file_type, array<Byte>^ file_content)
{
	this->id = id;
	this->group_id = group_id;
	this->user_id = user_id;
	this->filename = filename;
	this->file_type = file_type;
	this->file_content = file_content;
}

Int64^ Files::get_id()
{
	return this->id;
	// TODO: Insertar una instrucción "return" aquí
}

Int64^ Files::get_group_id()
{
	return this->group_id;
}

Int64^ Files::get_user_id()
{
	return this->user_id;
}

String^ Files::get_filename()
{
	return this->filename;
}

String^ Files::get_file_type()
{
	return this->file_type;
}

DateTime^ Files::get_upload_timestamp()
{
	return this->upload_timestamp;
	// TODO: Insertar una instrucción "return" aquí
}

array<Byte>^ Files::get_file_content()
{
	return this->file_content;
}

void Files::set_id(Int64^ id)
{
	this->id = id;
}

void Files::set_group_id(Int64^ group_id)
{
	this->group_id = group_id;
}

void Files::set_user_id(Int64^ user_id)
{
	this->user_id = user_id;
}

void Files::set_filename(String^ filename)
{
	this->filename = filename;
}

void Files::set_file_type(String^ file_type)
{
	this->file_type = file_type;
}

void Files::set_upload_timestamp(DateTime^ time)
{
	this->upload_timestamp = time;
}

void Files::set_file_content(array<Byte>^ file_content)
{
	this->file_content = file_content;
}

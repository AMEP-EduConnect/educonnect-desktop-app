#include "pch.h"
#include "Usuari.h"

Usuari::Usuari()
{
	user_id;
	username = "";
	password = "";
	email = "";
	name = "";

}

Usuari::Usuari(Int64^ user_id, String^ username, String^ password, String^ email, String^ name)
{
	this->user_id = user_id;
	this->username = username;
	this->password = password;
	this->email = email;
	this->name = name;
}

Int64^ Usuari::GetId()
{
	return user_id;
}

String^ Usuari::GetUsername()
{
	return username;
}

String^ Usuari::GetPassword()
{
	return password;
}

String^ Usuari::GetEmail()
{
	return email;
}

String^ Usuari::GetName()
{
	return name;
}

void Usuari::SetUsername(String^ username)
{
	this->username = username;
}

void Usuari::SetPassword(String^ password)
{
	this->password = password;
}

void Usuari::SetEmail(String^ email)
{
	this->email = email;
}

void Usuari::SetName(String^ name)
{
	this->name = name;
}
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
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

void Usuari::SetUserId(Int64^ value)
    {
        this->user_id = value;
    }

    
    Int64^ Usuari::GetUserId()
    {
        return this->user_id;
    }

    
    void Usuari::SetUsername(String^ value)
    {
        this->username = value;
    }

    
    String^ Usuari::GetUsername()
    {
        return this->username;
    }

    
    void Usuari::SetPassword(String^ value)
    {
        this->password = value;
    }

    
    String^ Usuari::GetPassword()
    {
        return this->password;
    }

    
    void Usuari::SetEmail(String^ value)
    {
        this->email = value;
    }

    
    String^ Usuari::GetEmail()
    {
        return this->email;
    }

    
    void Usuari::SetName(String^ value)
    {
        this->name = value;
    }

    String^ Usuari::GetName()
    {
        return this->name;
    }
#include "UsuariSUT.h"

UsuariSUT::UsuariSUT()
{
    user_id;
    username = "";
    password = "";
    email = "";
    name = "";

}

UsuariSUT::UsuariSUT(Int64^ user_id, String^ username, String^ password, String^ email, String^ name)
{
    this->user_id = user_id;
    this->username = username;
    this->password = password;
    this->email = email;
    this->name = name;
}

void UsuariSUT::SetUserId(Int64^ value)
{
    this->user_id = value;
}


Int64^ UsuariSUT::GetUserId()
{
    return this->user_id;
}


void UsuariSUT::SetUsername(String^ value)
{
    this->username = value;
}


String^ UsuariSUT::GetUsername()
{
    return this->username;
}


void UsuariSUT::SetPassword(String^ value)
{
    this->password = value;
}


String^ UsuariSUT::GetPassword()
{
    return this->password;
}


void UsuariSUT::SetEmail(String^ value)
{
    this->email = value;
}


String^ UsuariSUT::GetEmail()
{
    return this->email;
}


void UsuariSUT::SetName(String^ value)
{
    this->name = value;
}

String^ UsuariSUT::GetName()
{
    return this->name;
}

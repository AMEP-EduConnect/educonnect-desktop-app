#pragma once

using namespace System;

public ref class Usuari
{
public:
    Usuari();
    // Constructor
    Usuari(Int64^ user_id,String^ username, String^ password, String^ email, String^ name);
    // Setter para user_id
    void SetUserId(Int64^ value);

    // Getter para user_id
    Int64^ GetUserId();

    // Setter para username
    void SetUsername(String^ value);

    // Getter para username
    String^ GetUsername();

    // Setter para password
    void SetPassword(String^ value);

    // Getter para password
    String^ GetPassword();

    // Setter para email
    void SetEmail(String^ value);

    // Getter para email
    String^ GetEmail();

    // Setter para name
    void SetName(String^ value);

    // Getter para name
    String^ GetName();
private:
    property Int64^ user_id;
    property String^ username;
    property String^ password;
    property String^ email;
	property String^ name;


};
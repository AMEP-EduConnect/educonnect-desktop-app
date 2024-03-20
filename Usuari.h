#pragma once

using namespace System;

public ref class Usuari
{
public:
    Usuari();
    // Constructor
    Usuari(Int64^ user_id, String^ username, String^ password, String^ email, String^ name);

    void SetUserId(Int64^ value);
    Int64^ GetUserId();


    void SetUsername(String^ value);
    String^ GetUsername();


    void SetPassword(String^ value);
    String^ GetPassword();


    void SetEmail(String^ value);
    String^ GetEmail();


    void SetName(String^ value);
    String^ GetName();

private:
    property Int64^ user_id;
    property String^ username;
    property String^ password;
    property String^ email;
    property String^ name;


};
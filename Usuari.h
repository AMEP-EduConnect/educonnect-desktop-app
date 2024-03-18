#pragma once

using namespace System;

public ref class Usuari
{
public:
    Usuari();
    // Constructor
    Usuari(Int64^ user_id,String^ username, String^ password, String^ email, String^ name);
    //Getters
    Int64^ GetId();
    String^ GetUsername();
    String^ GetPassword();
    String^ GetEmail();
    String^ GetName();
    //Setters
    void SetUsername(String^ username);
    void SetPassword(String^ password);
    void SetEmail(String^ email);
    void SetName(String^ name);

    // Properties
    property Int64^ user_id;
    property String^ username;
    property String^ password;
    property String^ email;
	property String^ name;
};
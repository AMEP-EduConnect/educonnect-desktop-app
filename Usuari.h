#pragma once

using namespace System;

public ref class Usuari
{
public:
    Usuari();
    // Constructor
    Usuari(Int64^ user_id, String^ username, String^ password, String^ email, String^ name);

    // Setters

public:
    property Int64^ user_id;
    property String^ username;
    property String^ password;
    property String^ email;
    property String^ name;
};
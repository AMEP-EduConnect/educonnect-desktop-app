#pragma once
//TESTING FILE, DELETE LATER
using namespace System;

public ref class Professor
{
public:
    Professor();
    // Constructor
    Professor(Int64^ id, String^ name, String^ surname);

    // Properties
    property Int64^ id;
    property String^ name;
    property String^ surname;
};
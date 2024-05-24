#pragma once
using namespace System;
public ref class Notificacio
{
public:
    Notificacio();

    Notificacio(Int64^ id, Int64^ group_id, Int64^ source_id, Int64^ destination_id, String^ role);

    void SetId(Int64^ value);
    Int64^ GetId();


    void SetGroup_id(Int64^ value);
    Int64^ GetGroup_id();


    void SetSource_id(Int64^ value);
    Int64^ GetSource_id();


    void SetDestination_id(Int64^ value);
    Int64^ GetDestination_id();


    void SetRole(String^ value);
    String^ GetRole();

private:
    property Int64^ id;
    property Int64^ group_id;
    property Int64^ source_id;
    property Int64^ destination_id;
    property String^ role;

};


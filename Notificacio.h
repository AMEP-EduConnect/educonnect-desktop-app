#pragma once
using namespace System;
public ref class Notificacio
{
public:
    Notificacio();

    Notificacio(Int64^ id, Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id);

    void SetId(Int64^ value);
    Int64^ GetId();
    void SetNotificationType(Int64^ value);
    Int64^ GetNotificationType();
    void SetStatusType(Int64^ value);
    Int64^ GetStatusType();
    void SetSourceGroupId(Int64^ value);
    Int64^ GetSourceGroupId();
    void SetSourceUserId(Int64^ value);
    Int64^ GetSourceUserId();
    void SetDestinationUserId(Int64^ value);
    Int64^ GetDestinationUserId();

private:
    property Int64^ id;
    property Int64^ notification_type_id;
    property Int64^ status_id;
    property Int64^ source_group_id;
    property Int64^ source_user_id;
    property Int64^ destination_user_id;

};


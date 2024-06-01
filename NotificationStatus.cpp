#include "pch.h"
#include "NotificationStatus.h"

NotificationStatus::NotificationStatus()
{
    id = nullptr;
    statusType = "";
}

NotificationStatus::NotificationStatus(Int64^ id, String^ statusType)
{
    this->id = id;
    this->statusType = statusType;
}

void NotificationStatus::SetId(Int64^ value)
{
    this->id = value;
}

Int64^ NotificationStatus::GetId()
{
    return this->id;
}

void NotificationStatus::SetStatusType(String^ value)
{
    this->statusType = value;
}

String^ NotificationStatus::GetStatusType()
{
    return this->statusType;
}

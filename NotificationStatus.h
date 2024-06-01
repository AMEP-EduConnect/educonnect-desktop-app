#pragma once
using namespace System;

public ref class NotificationStatus
{
public:
	NotificationStatus();
	NotificationStatus(Int64^ id, String^ statusType);
	void SetId(Int64^ value);
	Int64^ GetId();
	void SetStatusType(String^ value);
	String^ GetStatusType();
private:
	property Int64^ id;
	property String^ statusType;
};
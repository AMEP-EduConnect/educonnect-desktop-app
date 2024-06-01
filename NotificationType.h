#pragma once
using namespace System;

public ref class NotificationType
{
public:
	NotificationType();

	NotificationType(Int64^ id, String^ notificationType);

	void SetId(Int64^ value);
	Int64^ GetId();
	void SetNotificationType(String^ value);
	String^ GetNotificationType();

private:
	property Int64^ id;
	property String^ notificationType;
};
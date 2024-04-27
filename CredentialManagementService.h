#pragma once
using namespace System;
public ref class CredentialManagementService
{
public:
    CredentialManagementService();
    String^ HashPassword(String^ password);
    bool VerifyPassword(String^ enteredPassword, String^ storedHash);
};


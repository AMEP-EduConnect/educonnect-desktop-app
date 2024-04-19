#include "pch.h"
#include <msclr\marshal_cppstd.h>
#include "CredentialManagementService.h"
using namespace System;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace msclr::interop;

CredentialManagementService::CredentialManagementService()
{
   
}

String^ CredentialManagementService::HashPassword(String^ password)
{
    array<Byte>^ salt = gcnew array<Byte>(32);  
    RNGCryptoServiceProvider^ rng = gcnew RNGCryptoServiceProvider();
    rng->GetBytes(salt);

    int iterations = 10000; 
    Rfc2898DeriveBytes^ pbkdf2 = gcnew Rfc2898DeriveBytes(password, salt, iterations);
    array<Byte>^ hash = pbkdf2->GetBytes(32);  

    array<Byte>^ hashBytes = gcnew array<Byte>(salt->Length + hash->Length); 
    Array::Copy(salt, 0, hashBytes, 0, salt->Length);
    Array::Copy(hash, 0, hashBytes, salt->Length, hash->Length);

    String^ hashString = BitConverter::ToString(hashBytes)->Replace("-", String::Empty);
    return hashString;
}

bool CredentialManagementService::VerifyPassword(String^ enteredPassword, String^ storedHash)
{
    array<Byte>^ hashBytes = gcnew array<Byte>(64); 
    for (int i = 0; i < 64; i++)
    {
        hashBytes[i] = Convert::ToByte(storedHash->Substring(i * 2, 2), 16);
    }

    array<Byte>^ salt = gcnew array<Byte>(32);
    Array::Copy(hashBytes, 0, salt, 0, 32);

    array<Byte>^ hash = gcnew array<Byte>(32);
    Array::Copy(hashBytes, 32, hash, 0, 32);

    int iterations = 10000;
    Rfc2898DeriveBytes^ pbkdf2 = gcnew Rfc2898DeriveBytes(enteredPassword, salt, iterations);
    array<Byte>^ testHash = pbkdf2->GetBytes(32);

    for (int i = 0; i < 32; i++)
    {
        if (testHash[i] != hash[i])
            return false;
    }

    return true;
}



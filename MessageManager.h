#pragma once

using namespace System;
using namespace System::Windows::Forms;

public ref class MessageManager
{
public:
    static void ErrorMessage(String^ message);
    static void WarningMessage(String^ message);
    static void InfoMessage(String^ message);
}; #pragma once

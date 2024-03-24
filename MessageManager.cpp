#include "pch.h"
#include "MessageManager.h"

void MessageManager::ErrorMessage(String^ message)
{
    String^ title = "Error - EduConnect";
    MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Error);
}

void MessageManager::WarningMessage(String^ message)
{
    String^ title = "Precauci� - EduConnect";
    MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Warning);
}

void MessageManager::InfoMessage(String^ message)
{
    String^ title = "Informaci� - EduConnect";
    MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
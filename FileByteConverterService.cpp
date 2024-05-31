#include "pch.h"
#include "FileByteConverterService.h"
#include "MessageManager.h"

array<Byte>^ FileByteConverterService::FileToBytes(String^ filePath)
{
    {
        try {
            FileStream^ fileStream = File::OpenRead(filePath);
            array<Byte>^ fileData = gcnew array<Byte>(fileStream->Length);
            fileStream->Read(fileData, 0, fileStream->Length);
            fileStream->Close();
            return fileData;
        }
        catch (Exception^ e) {
            MessageManager::WarningMessage("Error al leer el archivo: " + e->Message);
            return nullptr;
        }
    }
}

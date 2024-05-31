#pragma once
#include "ChatMessageRepository.h"
using namespace System;
using namespace System::IO;
public ref class FileByteConverterService
{
public:
    array<Byte>^ FileToBytes(String^ filePath);

};


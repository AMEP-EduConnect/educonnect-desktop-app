#include "pch.h"
#include "Proveidor.h"

Proveidor::Proveidor()
{

    name = "";

}

Proveidor::Proveidor(String^ name)
{

    this->name = name;
 
}
String^ Proveidor::GetProveidorName()
{
    return name;
}


void Proveidor::SetProveidorName(String^ name)
{
    this->name = name;
}

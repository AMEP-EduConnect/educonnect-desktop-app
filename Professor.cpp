#include "pch.h"
#include "Professor.h"
//TESTING FILE, DELETE LATER
Professor::Professor()
{
    id = nullptr;
    name = "";
    surname = "";
}

Professor::Professor(Int64^ id, String^ name, String^ surname)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
}

#include "pch.h"
#include "Professor.h"
//TESTING FILE, DELETE LATER
// 
// Default constructor
Professor::Professor()
{
    // Initialize members to default values
    id = nullptr;
    name = "";
    surname = "";
}

// Constructor with parameters
Professor::Professor(Int64^ id, String^ name, String^ surname)
{
    // Initialize the Professor object with provided parameters
    this->id = id;
    this->name = name;
    this->surname = surname;
}

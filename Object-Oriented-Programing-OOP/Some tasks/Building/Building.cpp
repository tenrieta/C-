#include "Building.h"
#include <cstring>

Building::Building()
{
    this->height = 0;
    this->area = 0;
    this->address = 0;
}

Building::Building(const Building& b)
{
    setHeight(b.height);
    setArea(b.area);
    setAddress(b.address);
}

Building& Building:: operator = (const Building& b)
{
    if(this!= &b)
        delete[] this->address;
    setHeight(b.height);
    setArea(b.area);
    setAddress(b.address);
    return *this;
}


Building::~Building()
{
    delete[] this->address;
}

void Building:: setHeight(unsigned int heigh)
{
    this->height = height;
}

void Building:: setArea(float area)
{
    this->area = area;
}

void Building:: setAddress(char* address)
{
    this->address = new char[strlen(address)+1];
    strcpy(this->address,address);
}

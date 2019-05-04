#include "House.h"
#include <cstring>

House::House()
{
    this->floors = 0;
    this->owner = NULL;
    count++;
}

House:: House(const House& h):Building(h),owner(NULL)
{
    setFloors(h.floors);
    setOwner(h.owner);
}

House& House:: operator = (const House& h)
{
    if(this != &h)
    {
        delete[] owner;
    }
    Building::operator = (h);
    setFloors(h.floors);
    setOwner(h.owner);
    return *this;
}

House::~House()
{
    delete[] this->owner;
}

void House:: setFloors(unsigned short floors)
{
    this->floors = floors;
}

void House:: setOwner(char* owner)
{
    this->owner = new char[strlen(owner)+1];
    strcpy(this->owner, owner);
}

void House:: add


int House:: count = 0;

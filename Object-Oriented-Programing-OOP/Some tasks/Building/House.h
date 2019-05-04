#ifndef HOUSE_H
#define HOUSE_H
#include "Building.h"

class House: public Building
{
    public:
        House();
        House(const House& h);
        House& operator = (const House& h);
        ~House();
        void setFloors(unsigned short floors);
        unsigned short getFloors()const{return this->floors;}
        void setOwner(char* owner);
        char* getOwner()const{return this->owner;}
        //static int getCount()const{return count;}
        static int count;
    protected:
    private:
        unsigned short floors;
        char* owner;
};

#endif // HOUSE_H

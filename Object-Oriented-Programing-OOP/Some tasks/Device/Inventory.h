#ifndef INVENTORY_H
#define INVENTORY_H
#include "Device.h"

class Inventory
{
    public:
        Inventory();
        //Inventory(const Inventory& i)
        //Inventory& operator = (const Inventory& i);
        ~Inventory();
        void addDevice(Device* d);
        void setSizze(int sizze);
        int getSizze(){return this->sizze;}
        void print();
        Device** arr;
    protected:
        int sizze = 0;
    private:
};

#endif // INVENTORY_H

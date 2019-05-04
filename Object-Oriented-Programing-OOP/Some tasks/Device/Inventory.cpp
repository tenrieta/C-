#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory()
{
    arr = NULL;
}

/*Inventory:: Inventory(const Inventory& i)
{

}

Inventory& Inventory:: operator = (const Inventory& i)
{

}*/

Inventory:: ~Inventory()
{
}

void Inventory:: addDevice(Device* d)
{
    Device** tmp = new Device*[sizze];
    for(int i=0; i<sizze; i++)
    {
        tmp[i] = arr[i];
    }
    delete[] arr;
    sizze++;
    arr = new Device*[sizze];
    for(int i=0; i<sizze-1; i++)
    {
        arr[i] = tmp[i];
    }
    arr[sizze-1] = d;
}

void Inventory:: print()
{
    for(int i=0; i<sizze; i++)
    {
        cout<<arr[i];
    }
}

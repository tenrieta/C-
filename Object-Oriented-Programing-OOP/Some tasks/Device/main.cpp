#include <iostream>
#include "Car.h"
#include "Laptop.h"
#include "Inventory.h"
using namespace std;

int main()
{
    Car c("pesho",10,100);
    Laptop l("gosho",15);
    Inventory i;
    cout<<i.getSizze()<<endl;
    i.addDevice(&c);
    i.arr[0]->print();
    i.addDevice(&l);
    i.arr[1]->print();
    cout<<endl;
    cout<<i.getSizze()<<endl;
    return 0;
}

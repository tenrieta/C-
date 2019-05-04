#include "Laptop.h"
#include <iostream>;
#include <cstring>
using namespace std;

Laptop::Laptop(char* producer, int speed)
{
    setProducer(producer);
    this->speed = speed;
}

Laptop:: Laptop(const Laptop& l)
{
    setSpeed(l.speed);
    setProducer(l.producer);

}

Laptop& Laptop:: operator = (const Laptop& l)
{
    if(this!=&l)
    {
        setSpeed(l.speed);
        setProducer(l.producer);
    }
    return *this;
}

Laptop::~Laptop()
{
    delete[] this->producer;
}

void Laptop:: print()
{
    cout<<"Producer: ";
    for(int i=0; i<strlen(producer); i++)
    {
        cout<<producer[i];
    }
    cout<<",Speed: "<<speed<<endl;
}

int Laptop:: getPref()
{
    return this->speed;
}

void Laptop:: setSpeed(int speed)
{
    this->speed = speed;
}

void Laptop:: setProducer(char* producer)
{
    if(this->producer!=NULL)
    delete[] this->producer;
    this->producer =  new char[strlen(producer)+1];
    strcpy(this->producer, producer);
}

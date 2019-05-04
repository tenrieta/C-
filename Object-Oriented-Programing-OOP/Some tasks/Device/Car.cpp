#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;

Car::Car(char* producer, int power, int mass)
{
    this->power = power;
    this->mass = mass;
    setProducer(producer);
}

Car::Car(const Car& c)
{
    this->power = c.power;
    this->mass = c.mass;
    setProducer(c.producer);
}

Car& Car:: operator = (const Car& c)
{
    if(this != &c)
    {
        setPower(c.power);
        setMass(c.mass);
    }
    return *this;
}

Car::~Car()
{
    delete[] this->producer;
}

void Car:: print()
{
    cout<<"Producer: ";
    for(int i=0; i<strlen(producer); i++)
    {
        cout<<producer[i];
    }
    cout<<",Power: "<<power<<",Mass: "<<mass<<endl;
}

int Car:: getPref()
{
    return this->power;
}

void Car:: setPower(int power)
{
    this->power = power;
}

void Car:: setMass(int mass)
{
    this->mass = mass;
}

void Car:: setProducer(char* producer)
{
    if(this->producer!=NULL)
    delete[] this->producer;
    this->producer =  new char[strlen(producer)+1];
    strcpy(this->producer, producer);
}

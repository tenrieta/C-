#ifndef LAPTOP_H
#define LAPTOP_H
#include "Device.h"

class Laptop: public Device
{
    public:
        Laptop(char* producer, int speed);
        Laptop(const Laptop& l);
        Laptop& operator = (const Laptop& l);
        ~Laptop();
        void print();
        int getPref();
        void setSpeed(int speed);
        int getSpeed(){return this->speed;}
        void setProducer(char* producer);
        char* getProducer(){return this->producer;};
    protected:
    private:
         int speed;
};

#endif // LAPTOP_H

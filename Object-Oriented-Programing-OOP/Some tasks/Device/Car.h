#ifndef CAR_H
#define CAR_H
#include "Device.h"

class Car: public Device
{
    public:
        Car(char* producer, int power, int mass);
        Car(const Car& c);
        Car& operator = (const Car& c);
       ~Car();
       virtual void print();
       virtual int getPref();
       void setPower(int power);
       int getPower(){return this->power;}
       void setMass(int mass);
       int getMass(){return this->mass;}
        void setProducer(char* producer);
        char* getProducer(){return this->producer;};
    protected:
        int power;
        int mass;
    private:
};

#endif // CAR_H

#include "Device.h"
#include <cstring>

Device::Device()
{
    producer = NULL;
}

Device::Device(const Device& d)
{
    this->producer = new char[strlen(d.producer)];
    strcpy(this->producer, d.producer);
}


Device::~Device()
{
    delete[] this->producer;
}

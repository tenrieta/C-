#ifndef DEVICE_H
#define DEVICE_H


class Device
{
    public:
        Device();
        Device(const Device& d);
        ~Device();
        virtual void print() = 0;
        virtual int getPref() = 0;
    protected:
        char* producer;
    private:
};

#endif // DEVICE_H

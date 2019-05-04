#ifndef BUILDING_H
#define BUILDING_H


class Building
{
    public:
        Building();
        Building(const Building& b);
        Building& operator = (const Building& b);
        ~Building();
        void setHeight(unsigned int height);
        unsigned int getHeight()const{return this->height;}
        void setArea(float area);
        float getArea()const{return this->area;}
        void setAddress(char* address);
        char* getAddress()const{return this->address;}
    protected:
        unsigned int height;
        float area;
        char* address;
};

#endif // BUILDING_H

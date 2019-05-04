#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

struct point
{
    double x;
    double y;
    double z;
    point& operator=(const point& p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }
};
class Figure
{
public:
    Figure()
    {}
    Figure(const Figure& fig)
    {}
    Figure& operator = (const Figure& fig)
    {
        return *this;
    }
    ~Figure()
    {}
    virtual void printCordinates() = 0;
    virtual void scaleAndTranslate(double translateXtmp,double translateYtmp,double translateZtmp,double scalar) = 0;
};

class Sphere: public Figure
{
public:
Sphere();
Sphere(const Sphere& sphere);
Sphere& operator = (const Sphere& sph);
~Sphere();
void setPoint(double x,double y,double z);
void setRadius(double r);
double getPointX() const;
double getPointY() const;
double getPointZ() const;
double getRadius() const;
virtual void printCordinates()
{
    cout << "Sphere " << p.x << " " << p.y << " " << p.z << " " << radius <<  endl;
}
virtual void scaleAndTranslate(double translateXtmp,double translateYtmp,double translateZtmp,double scalar)
{
    p.x = (scalar*p.x) + translateXtmp;
    p.y = (scalar*p.y) + translateYtmp;
    p.z = (scalar*p.z) + translateZtmp;
}

    private:
    point p;
    double radius;
};
Sphere::Sphere()
    {
        p.x = 0;
        p.y = 0;
        p.z = 0;
        radius = 0;
    }
    Sphere::Sphere(const Sphere& sphere)
    {
        this->p = sphere.p;
        this->radius = sphere.radius;
    }
    Sphere& Sphere::operator = (const Sphere& sph)
    {
        if(this==&sph)
        {
            return *this;
        }
        this->p = sph.p;
        this->radius = sph.radius;
        return *this;
    }
    Sphere::~Sphere()
    {}
    void Sphere::setPoint(double x,double y,double z)
    {
        this->p.x = x;
        this->p.y = y;
        this->p.z = z;
    }
    void Sphere::setRadius(double r)
    {
        this->radius = r;
    }
    double Sphere::getPointX() const
    {
        return p.x;
    }
    double Sphere::getPointY() const
    {
        return p.y;
    }
    double Sphere::getPointZ() const
    {
        return p.z;
    }
    double Sphere::getRadius() const
    {
        return this->radius;
    }
class Cuboid: public Figure
{
public:
Cuboid();
Cuboid(const Cuboid& cub);
Cuboid& operator = (const Cuboid& cub);
~Cuboid();
void setPoint1(double x,double y, double z);
void setPoint2(double x,double y, double z);
double getPointX1() const;
double getPointY1() const;
double getPointZ1() const;
double getPointX2() const;
double getPointY2() const;
double getPointZ2() const;

virtual void printCordinates()
{
cout << "Cuboid " << p[0].x << " " << p[0].y << " " << p[0].z << " " << p[1].x << " " << p[1].y << " " << p[1].z << endl;
}
virtual void scaleAndTranslate(double translateXtmp,double translateYtmp,double translateZtmp,double scalar)
{
p[0].x = (scalar*p[0].x) + translateXtmp;
p[1].x = (scalar*p[1].x) + translateXtmp;
p[0].y = (scalar*p[0].y) + translateYtmp;
p[1].y = (scalar*p[1].y) + translateYtmp;
p[0].z = (scalar*p[0].z) + translateZtmp;
p[1].z = (scalar*p[1].z) + translateZtmp;
}

private:
point p[2];
};
Cuboid::Cuboid()
    {
        p[0].x = 0;
        p[0].y = 0;
        p[0].z = 0;
        p[1].x = 0;
        p[1].y = 0;
        p[1].z = 0;
    }
     Cuboid::Cuboid(const Cuboid& cub)
    {
        this->p[0] = cub.p[0];
        this->p[1] = cub.p[1];
    }
    Cuboid&  Cuboid:: operator = (const Cuboid& cub)
    {
        if(this==&cub)
        {
            return *this;
        }
        this->p[0] = cub.p[0];
        this->p[1] = cub.p[1];
        return *this;
    }
 Cuboid::~Cuboid()
{}
void Cuboid::setPoint1(double x,double y, double z)
{
        this->p[0].x = x;
        this->p[0].y = y;
        this->p[0].z = z;
}
void Cuboid::setPoint2(double x,double y, double z)
{
        this->p[1].x = x;
        this->p[1].y = y;
        this->p[1].z = z;
}
double Cuboid::getPointX1() const
{
    return p[0].x;
}
double  Cuboid::getPointY1() const
{
    return p[0].z;
}
double Cuboid::getPointZ1() const
{
    return p[0].z;
}
double Cuboid::getPointX2() const
{
    return p[1].x;
}
double Cuboid::getPointY2() const
{
    return p[1].y;
}
double Cuboid::getPointZ2() const
{
    return p[1].z;
}
class Pyramid: public Figure
{
public:
    Pyramid();
    Pyramid(const Pyramid& pyr);
    Pyramid& operator = (const Pyramid& pyr);
    ~Pyramid();
    void setPoint1(double x,double y, double z);
    void setPoint2(double x,double y, double z);
    void setPoint3(double x,double y, double z);
    void setPoint4(double x,double y, double z);
    double getPointX1() const;
    double getPointY1() const;
    double getPointZ1() const;
    double getPointX2() const;
    double getPointY2() const;
    double getPointZ2() const;
    double getPointX3() const;
    double getPointY3() const;
    double getPointZ3() const;
    double getPointX4() const;
    double getPointY4() const;
    double getPointZ4() const;

    virtual void printCordinates()
    {
        cout << "Pyramid " << p[0].x << " " << p[0].y << " " << p[0].z << " " << p[1].x << " " << p[1].y << " " << p[1].z << " " << p[2].x << " " << p[2].y << " " << p[2].z <<" " << p[3].x << " " << p[3].y << " " << p[3].z <<  endl;
    }
    virtual void scaleAndTranslate(double translateXtmp,double translateYtmp,double translateZtmp,double scalar)
    {
        p[0].x = (scalar*p[0].x) + translateXtmp;
        p[1].x = (scalar*p[1].x) + translateXtmp;
        p[2].x = (scalar*p[2].x) + translateXtmp;
        p[3].x = (scalar*p[3].x) + translateXtmp;
        p[0].y = (scalar*p[0].y) + translateYtmp;
        p[1].y = (scalar*p[1].y) + translateYtmp;
        p[2].y = (scalar*p[2].y) + translateYtmp;
        p[3].y = (scalar*p[3].y) + translateYtmp;
        p[0].z =  (scalar*p[0].z) + translateZtmp;
        p[1].z = (scalar*p[1].z) + translateZtmp;
        p[2].z = (scalar*p[2].z) + translateZtmp;
        p[3].z = (scalar*p[3].z) + translateZtmp;
    }
private:
point p[4];
};
 Pyramid::Pyramid()
    {
        p[0].x = 0;
        p[0].y = 0;
        p[0].z = 0;
        p[1].x = 0;
        p[1].y = 0;
        p[1].z = 0;
        p[2].x = 0;
        p[2].y = 0;
        p[2].z = 0;
        p[3].x = 0;
        p[3].y = 0;
        p[3].z = 0;
    }
    Pyramid::Pyramid(const Pyramid& pyr)
    {
        this->p[0] = pyr.p[0];
        this->p[1] = pyr.p[1];
        this->p[2] = pyr.p[2];
        this->p[3] = pyr.p[3];
    }
    Pyramid& Pyramid::operator = (const Pyramid& pyr)
    {
        if(this==&pyr)
        {
            return *this;
        }
        this->p[0] = pyr.p[0];
        this->p[1] = pyr.p[1];
        this->p[2] = pyr.p[2];
        this->p[3] = pyr.p[3];
        return *this;
    }
    Pyramid::~Pyramid()
    {}
    void Pyramid::setPoint1(double x,double y, double z)
    {
        this->p[0].x = x;
        this->p[0].y = y;
        this->p[0].z = z;
    }
    void Pyramid::setPoint2(double x,double y, double z)
    {
        this->p[1].x = x;
        this->p[1].y = y;
        this->p[1].z = z;
    }
    void Pyramid::setPoint3(double x,double y, double z)
    {
        this->p[2].x = x;
        this->p[2].y = y;
        this->p[2].z = z;
    }
    void Pyramid::setPoint4(double x,double y, double z)
    {
        this->p[3].x = x;
        this->p[3].y = y;
        this->p[3].z = z;
    }
    double Pyramid::getPointX1() const
    {
        return p[0].x;
    }
    double Pyramid::getPointY1() const
    {
        return p[0].y;
    }
    double Pyramid::getPointZ1() const
    {
        return p[0].z;
    }
    double Pyramid::getPointX2() const
    {
        return p[1].x;
    }
    double Pyramid::getPointY2() const
    {
        return p[1].y;
    }
    double Pyramid::getPointZ2() const
    {
        return p[1].z;
    }
    double Pyramid::getPointX3() const
    {
        return p[2].x;
    }
    double Pyramid::getPointY3() const
    {
        return p[2].y;
    }
    double Pyramid::getPointZ3() const
    {
        return p[2].z;
    }
    double Pyramid::getPointX4() const
    {
        return p[3].x;
    }
    double Pyramid::getPointY4() const
    {
        return p[3].y;
    }
    double Pyramid::getPointZ4() const
    {
        return p[3].z;
    }
void printIndex(int index)
{
    ifstream file("file.txt");
    int i = 0,flag = 0;
    double translateXtmp;
    double translateYtmp;
    double translateZtmp;
    double xtmp;
    double ytmp;
    double ztmp;
    double radius;
    double scalarTmp;
    char figCheck[10];
    char tmpString[10];
    Sphere s1;
    Cuboid c1;
    Pyramid p1;
    while(!file.eof())
    {
        file >> figCheck;
        if(strcmp(figCheck,"sphere")== 0)
        {
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            file >> radius;
            s1.setRadius(radius);
            s1.setPoint(xtmp,ytmp,ztmp);
            if(index == i)
            {
                s1.printCordinates();
            }
        }
        else if(strcmp(figCheck,"cuboid")== 0)
        {
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            c1.setPoint1(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            c1.setPoint2(xtmp,ytmp,ztmp);
            if(index == i)
            {
                c1.printCordinates();
            }
        }
        else if(strcmp(figCheck,"pyramid")== 0)
        {
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint1(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint2(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint3(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint4(xtmp,ytmp,ztmp);
            if(index == i)
            {
                p1.printCordinates();
            }
        }
        else if (strcmp(figCheck,"group") == 0)
        {
            file >> tmpString;
            file >> translateXtmp;
            file >> translateYtmp;
            file >> translateZtmp;
            file >> scalarTmp;
            do
            {
                file >> figCheck;
                if(strcmp(figCheck,"sphere") == 0)
                {
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    file >> radius;
                    s1.setRadius(radius);
                    s1.setPoint(xtmp,ytmp,ztmp);
                    s1.scaleAndTranslate(translateXtmp,translateYtmp,translateYtmp,scalarTmp);
                    if(index == i)
                    {
                        s1.printCordinates();
                    }
                }
                else if(strcmp(figCheck,"cuboid") == 0)
                {
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    c1.setPoint1(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    c1.setPoint2(xtmp,ytmp,ztmp);
                    c1.scaleAndTranslate(translateXtmp,translateYtmp,translateZtmp,scalarTmp);
                    if(index == i)
                    {
                        c1.printCordinates();
                    }
                }
                else if(strcmp(figCheck,"pyramid") == 0)
                {
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint1(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint2(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint3(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint4(xtmp,ytmp,ztmp);
                    p1.scaleAndTranslate(translateXtmp,translateYtmp,translateYtmp,scalarTmp);
                    if(index == i)
                    {
                        p1.printCordinates();
                    }
                }
                else
                {
                    file >> tmpString;
                    flag = 1;
                }
            }while(!flag);
            flag = 0;
        }
        i++;
        flag = 0;
    }
    file.close();
}

void findPoint(double x,double y,double z)
{
    ifstream file("file.txt");
    Cuboid c1;
    Sphere s1;
    Pyramid p1;
    char figType[10];
    char tmpString[10];
    int flag = 0;
    double translateXtmp;
    double translateYtmp;
    double translateZtmp;
    double xtmp;
    double ytmp;
    double ztmp;
    double radius;
    double scalarTmp;
    while(!file.eof())
    {
        file >> figType;
        if(strcmp(figType,"sphere") == 0)
        {
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            file >> radius;
            s1.setRadius(radius);
            s1.setPoint(xtmp,ytmp,ztmp);
            if((s1.getPointX() == x) && (s1.getPointY() == y) && (s1.getPointZ() == z))
            {
                s1.printCordinates();
            }
        }
        else if(strcmp(figType,"cuboid") == 0)
        {
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            c1.setPoint1(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            c1.setPoint2(xtmp,ytmp,ztmp);
            if((( c1.getPointX1()==x) && (c1.getPointY1() == y) && (c1.getPointZ1() == z)) || (( c1.getPointX2()==x) && (c1.getPointY2() == y) && (c1.getPointZ2() == z)))
            {
                c1.printCordinates();
            }
        }
        else if(strcmp(figType,"pyramid") == 0)
        {
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint1(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint2(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint3(xtmp,ytmp,ztmp);
            file >> xtmp;
            file >> ytmp;
            file >> ztmp;
            p1.setPoint4(xtmp,ytmp,ztmp);
            if((( p1.getPointX1()==x) && (p1.getPointY1() == y) && (p1.getPointZ1() == z)) || (( p1.getPointX2()==x) && (p1.getPointY2() == y) && (p1.getPointZ2() == z)) || (( p1.getPointX3()==x) && (p1.getPointY3() == y) && (p1.getPointZ3() == z)) || (( p1.getPointX4()==x) && (p1.getPointY4() == y) && (p1.getPointZ4() == z)))
            {
                p1.printCordinates();
            }
        }
        else if (strcmp(figType,"group") == 0)
        {
            file >> tmpString;
            file >> translateXtmp;
            file >> translateYtmp;
            file >> translateZtmp;
            file >> scalarTmp;
            do
            {
                file >> figType;
                if(strcmp(figType,"sphere") == 0)
                {
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    file >> radius;
                    s1.setRadius(radius);
                    s1.setPoint(xtmp,ytmp,ztmp);
                    s1.scaleAndTranslate(translateXtmp,translateYtmp,translateYtmp,scalarTmp);
                    if((s1.getPointX() == x) && (s1.getPointY() == y) && (s1.getPointZ() == z))
                    {
                        s1.printCordinates();
                    }
                }
                else if(strcmp(figType,"cuboid") == 0)
                {
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    c1.setPoint1(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    c1.setPoint2(xtmp,ytmp,ztmp);
                    c1.scaleAndTranslate(translateXtmp,translateYtmp,translateZtmp,scalarTmp);
                    if((( c1.getPointX1() == x) && (c1.getPointY1() == y) && (c1.getPointZ1() == z)) || (( c1.getPointX2()==x) && (c1.getPointY2() == y) && (c1.getPointZ2() == z)))
                    {
                        c1.printCordinates();
                    }
                }
                else if(strcmp(figType,"pyramid") == 0)
                {
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint1(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint2(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint3(xtmp,ytmp,ztmp);
                    file >> xtmp;
                    file >> ytmp;
                    file >> ztmp;
                    p1.setPoint4(xtmp,ytmp,ztmp);
                    p1.scaleAndTranslate(translateXtmp,translateYtmp,translateYtmp,scalarTmp);
                    if((( p1.getPointX1()==x) && (p1.getPointY1() == y) && (p1.getPointZ1() == z)) || (( p1.getPointX2()==x) && (p1.getPointY2() == y) && (p1.getPointZ2() == z)) || (( p1.getPointX3()==x) && (p1.getPointY3() == y) && (p1.getPointZ3() == z)) || (( p1.getPointX4()==x) && (p1.getPointY4() == y) && (p1.getPointZ4() == z)))
                    {
                        p1.printCordinates();
                    }
                }
                else
                {
                    file >> tmpString;
                    flag = 1;
                }
            }while(!flag);
            flag = 0;
        }
    }
file.close();
}

int main()
{
    findPoint(3.0,7.5,6.3);
    printIndex(2);
return 0;
}

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class Eggs
{
    public:
        Eggs();
        Eggs(const Eggs& eg1);
        Eggs& operator = (const Eggs& eg1);
        ~Eggs();
        void setEggName(char* namee);
        char* getEggName()const;
        void setEggSize(int length);
        int getEggSize()const;
        void freeName();
    private:
        char* name;
};

class Basket
{
    public:
        void setBasketName(char* namee);
        char* getBasketName() const;
        void setIndex(int index);
        int getIndex()const;
        void setNumber(int numberOfEggs);
        int getNumber()const;
        void setLimit(int lim);
        int getLimit()const;
        void freeName();
        void addEgg(const Eggs & egg);
        void removeEgg(char* namee);
        void Resize();
        void Resize2();
        void serialize();
        Basket(char* namee);
        Basket(const Basket& ba1);
        Basket& operator = (const Basket& ba1);
        ~Basket();
        void report(char* filename);
    private:
        Eggs * eggs;
        char* name;
        int index;
        int limit;
        int numberOfEggs;
};

Eggs::Eggs()
{};

Eggs:: Eggs(const Eggs& eg1)
{
    this->name = new char[strlen(eg1.name)+1];
    strcpy(this->name, eg1.name);
};

Eggs& Eggs:: operator = (const Eggs& eg1)
{
    if(this==&eg1)
    return *this;
    delete [] this->name;
    this->name = new char[strlen( eg1.name)+1];
    strcpy(this->name, eg1.name);
    return *this;
};

Eggs::~Eggs()
{
    delete[] this->name;
}

void Eggs::setEggName(char* namee)
{
    freeName();
    int length = strlen(namee);
    this->name = new char[length+1];
    strcpy(this->name,namee);
}

char* Eggs:: getEggName()const
{
  return this->name;
}

void Eggs:: freeName()
{
    //delete[] this->name;
}

Basket:: Basket(char* namee)
: numberOfEggs(0),eggs(NULL),index(0),limit(1)
{
    int length = strlen(namee);
    this->name = new char[length+1];
    strcpy(this->name,namee);
    eggs = new Eggs[limit];
}

Basket :: Basket(const Basket& ba1)
{
    delete[] this->name;
    this->name = new char[strlen(ba1.name)+1];
    strcpy(this->name, ba1.name);
    this->index = ba1.index;
    this->limit= ba1.limit;
    this->numberOfEggs = ba1.numberOfEggs;
};
Basket& Basket:: operator = (const Basket& ba1)
{
    if(this==&ba1)
    return *this;
    delete [] this->name;
    this->name = new char[strlen( ba1.name)+1];
    strcpy(this->name, ba1.name);
    this->index = ba1.index;
    this->limit= ba1.limit;
    this->numberOfEggs = ba1.numberOfEggs;
    return *this;
};


Basket::~Basket()
{
    delete[] this->name;
    delete [] eggs;
}

void Basket:: setBasketName(char* name)
{
    delete [] this->name;
	int length = strlen(name);
    this->name = new char[length+1];
    strcpy(this->name,name);
}
char* Basket:: getBasketName() const
{
    return this->name;
}
void Basket:: setLimit(int lim)
{
    this->limit += lim;
}
int Basket:: getLimit()const
{
    return this->limit;
}

void Basket::setIndex(int index)
{
   this->index = index;
}

int Basket:: getIndex()const
{
    return this->index;
}

void Basket::setNumber(int numberOfEggs)
{
   this->numberOfEggs = numberOfEggs;
}

int Basket:: getNumber()const
{
    return this->numberOfEggs;
}

void Basket::freeName()
{
    delete[] name;
}

void Basket::addEgg(const Eggs & egg)
{
    Resize();
    this->eggs[getNumber()]= egg;
    this->numberOfEggs++;
}

void Basket::removeEgg(char* namee)
{
    for(int i=0;i<getNumber();i++)
    {
        if((strcmp(this->eggs[i].getEggName(),namee)==0))
        {
            this->index = i;
            //Resize2();
            this->numberOfEggs--;
            break;
        }
    }
}

void Basket::Resize()
{
    Eggs* tmp=new Eggs[limit];
    for(int i=0;i<getNumber();i++)
    {
        tmp[i] = eggs[i];
    }
    if(getNumber() >= (limit/2))
    {
        this->limit = 2*limit;
        this->eggs= new Eggs[limit];
    }
    for(int i=0;i<getNumber();i++)
    {
         eggs[i] = tmp[i];
    }
}

void Basket::Resize2()
{
        int p = 0;
        Eggs * eggs2 = NULL;
        eggs2 = new Eggs[limit];
        for(int i = 0;i<getNumber();i++)
        {
            eggs2[p] = this->eggs[i];
            if(this->index == i)
            {
                eggs2[p] = this->eggs[++i];
            }
            p++;
        }
        this->limit -= 1;
        this->eggs= new Eggs[limit];
        for(int i = 0;i<getNumber()-1;i++)
        {
            this->eggs[i] = eggs2[i];
        }
        delete [] eggs2;
}

void Basket::report(char* filename)
{
    ofstream myfile(filename,ios::app);
    myfile << "Basket " << this->name;
    myfile << endl;
    for(int i=0;i<getNumber();i++)
    {
        myfile << "Egg " << eggs[i].getEggName();
        myfile << endl;
    }
    myfile.close();
}

void Basket::serialize()
{
    ofstream myfile("ser.bin", ios::binary | ios::app);
    myfile.write((char*)&this->name, strlen(this->name));
    for(int i=0;i<this->getNumber();i++)
    {
        // myfile.write((char*)(&this->eggs[i].getEggName()), strlen(eggs[i].getEggName()));
    }
    myfile.close();
}

int main()
{
    char test[] = "Test";
    char baskettest[] = "BasketTest";
    char filetest[] = "test.txt";
    Eggs eg1,eg2,eg3,eg4;
    Basket ba2(baskettest);
    eg1.setEggName(test);
    eg2.setEggName(test);
    eg3.setEggName(test);
    eg4.setEggName(test);
    ba2.addEgg(eg1);
    ba2.addEgg(eg2);
    ba2.addEgg(eg3);
    ba2.addEgg(eg4);
    ba2.report(filetest);
    cout << ba2.getNumber()<< endl;
    ba2.removeEgg(test);
    cout << ba2.getNumber() << endl;
    return 0;
}

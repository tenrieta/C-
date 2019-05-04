#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
using namespace std;
class Eggs
{
    public:
        Eggs();
        Eggs(const Eggs& eg1);
        Eggs& operator = (const Eggs& eg1);
        bool operator < (Eggs&egg);
        bool operator <= (Eggs&egg);
        Eggs& operator * (Eggs&egg);
        Eggs& operator / (Eggs&egg);
        char* operator + (Eggs&egg);
        char* operator -- ();
        char* operator ++ ();
        char* operator -- (int);
        char* operator ++ (int);
        Eggs& operator ^ (Eggs&egg);
        ~Eggs();
        void setEggName(char* namee);
        char* getEggName()const;
        void setEggSize(int eggSize);
        int getEggSize()const;
        void freeName();
    private:
        char* name;
        int eggSize;
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
        char* operator [] (int indexx);
        char* operator [] (char* str);
        char* operator + (const Basket&ba1);
        char* operator +=(const Basket&ba1);
        char* operator + (char* str);
        char* operator +=(char* str);
        Basket& operator * (int number);
        bool operator *=(int number);
        bool operator / (int number);
        bool operator /= (int number);
        Basket& operator % (const Basket&basket);
        Basket& operator %= (const Basket&basket);
        Basket& operator ==(const Basket&basket);
        Basket& operator != (const Basket&basket);
        bool operator < (const Basket&basket);
        bool operator <= (const Basket&other);
        bool operator >= (const Basket&other);
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

bool Eggs:: operator < (Eggs&egg)
{
    cout<<"Operator '< ': ";
    if(this->eggSize==egg.eggSize)
    {
        cout<<"Qicata s edna i sushta duljina"<<endl;
        return 0;
    }

    else if(this->eggSize<egg.eggSize)
    {
        cout<<"Vtoroto qice e s po-golqma dyljina"<<endl;
        return 0;
    }
    else
    {
        cout<<"Purvoto qice e s po-golqma duljina"<<endl;
        return 0;
    }
}

bool Eggs:: operator <= (Eggs&egg)
{
    cout<<"Operator '<=': ";
    if(!strcmp(this->name, egg.name))
    {
        cout<<"Qicata sa ednakvi"<<endl;
        return 0;
    }

    else if(strcmp(this->name, egg.name)<0)
    {
        cout<<"Vtoroto qice e po-golqmo"<<endl;
        return 0;
    }
    else
    {
        cout<<"Purvoto qice e po-golqmo"<<endl;
        return 0;
    }
}

Eggs& Eggs:: operator * (Eggs&egg)
{
    if(this==&egg)
    return *this;
    this->eggSize *= egg.eggSize;
    cout<<"Operator '* ': ";
    return *this;
}

Eggs& Eggs:: operator / (Eggs&egg)
{
    if(this==&egg)
    return *this;
    this->eggSize /= egg.eggSize;
    cout<<"Operator '/ ': ";
    return *this;
}

char * Eggs:: operator + (Eggs&egg)
{
    cout<<"Operator '+ ': ";
    char *tmp = new char [this->eggSize+egg.eggSize];
    strcpy(tmp,this->name);
    strcat(tmp, egg.name);
    return tmp;
}

char * Eggs:: operator -- ()
{
    cout<<"Operator '--': ";
    char* tmp= new char[this->eggSize];
    strcpy(tmp, this->name);
    for(int i=0; i<eggSize; i++)
    {
        if((this->name[i] >= 'a')&&(this->name[i]<='z'))
        {
            tmp[i]-=0x20;
        }
    }
    cout<<tmp<<endl;
    return tmp;
}
char * Eggs:: operator ++ ()
{
    cout<<"Operator '++': ";
    char* tmp= new char[this->eggSize];
    strcpy(tmp, this->name);
    for(int i=0; i<eggSize; i++)
    {
        if((this->name[i] >= 'A')&&(this->name[i]<='Z'))
        {
            tmp[i]+=0x20;
        }
    }
    cout<<tmp<<endl;
    return tmp;
}

char * Eggs:: operator -- (int)
{
    cout<<"Operator '--': ";
    char* tmp= new char[this->eggSize];
    strcpy(tmp, this->name);
    for(int i=0; i<eggSize; i++)
    {
        if((this->name[i]!='A')&&(this->name[i]!='a'))
        {
            tmp[i]-=0x1;
        }
    }
    cout<<tmp<<endl;
    return tmp;
}
char * Eggs:: operator ++ (int)
{
    cout<<"Operator '++': ";
    char* tmp= new char[this->eggSize];
    strcpy(tmp, this->name);
    for(int i=0; i<eggSize; i++)
    {
        if((this->name[i]!='Z')&&(this->name[i]!='z'))
        {
            tmp[i]+=0x1;
        }
    }
    cout<<tmp<<endl;
    return tmp;
}

Eggs& Eggs:: operator ^ (Eggs&egg)
{
    if(this==&egg)
    return *this;
    cout<<"Operator '^ ': ";
    this->eggSize = pow(this->eggSize, egg.eggSize);
    return *this;
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

void Eggs:: setEggSize(int eggSize)
{
    this->eggSize += eggSize;
}

int Eggs:: getEggSize()const
{
    return this->eggSize;
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

char* Basket::operator [] (int indexx)
{
        cout<<"Operator '[int]': ";
        if(indexx >= getNumber())
        {
            cout<<"nqma tolkova qica"<<endl;
        }
        else
        {
            for(int i=0; i<=this->getNumber(); i++)
            {
                if(i == indexx)
                {
                    //cout<< eggs[i].name<<endl;
                    return eggs[i].getEggName();
                }
            }
        }
}

char* Basket:: operator [] (char* str)
{
    cout<<"Operator '[str]': ";
    int flag=0,index;
    char* p;
    for(int i=0; i<this->getNumber();i++)
    {
        p = strstr(eggs[i].getEggName(),str);
        if(p!=0)
        {
            flag=1;
            index = i;
            break;
        }
    }
    if(flag==1)
    {
        return eggs[index].getEggName();
    }
    else
    {
        cout<<"nqma takuv niz" << endl;
        return 0;
    }
}
char* Basket::operator + (const Basket&basket)
{
    cout<<"Operator '+': ";
    char* arr = new char[(strlen(this->name) + strlen( basket.name) + 1)];
    strcpy(arr,this->name);
    strcat(arr, basket.name);
    return arr;
}
char* Basket::operator += (const Basket&basket)
{
    cout<<"Operator '+=': ";
    char* arr = new char[(strlen(this->name) + strlen( basket.name) + 1)];
    strcpy(arr,this->name);
    strcat(arr, basket.name);
    cout << arr << endl;
    return arr;
}
char* Basket:: operator + (char* str)
{
    cout<<"Operator '+ str': ";
    int length = 0;
    for(int i = 0;i<this->numberOfEggs;i++)
    {
        length+=strlen(this->eggs[i].getEggName());
    }
    str = new char[length];
    strcpy(str,eggs[0].getEggName());
    for(int i=1; i<this->getNumber(); i++)
    {
        strcat(str,this->eggs[i].getEggName());
    }
return str;
}
char* Basket:: operator +=(char* str)
{
    cout<<"Operator '+= str': ";
    int length = 0;
    for(int i = 0;i<this->numberOfEggs;i++)
    {
        length+=strlen(this->eggs[i].getEggName());
    }
    str = new char[length];
    strcpy(str,eggs[0].getEggName());
    for(int i=1; i<this->getNumber(); i++)
    {
        strcat(str,this->eggs[i].getEggName());
    }
    cout << str << endl;
    return str;
}
 Basket& Basket:: operator * (int number)
{
    cout<<"Operator '*': ";
    int tmp = 1;
    for(int i=0; i<this->numberOfEggs; i++)
    {
        tmp = number*this->eggs[i].getEggSize();
        //cout << number*this->eggs[i].eggSize << " ";
        this->eggs[i].setEggSize(tmp);
    }
    cout << endl;
    return *this;
}
bool Basket:: operator *=(int number)
{
   /* cout<<"Operator '*=': ";
    int tmp = 1;
    for(int i=0; i<this->numberOfEggs; i++)
    {
        tmp *= number*this->eggs[i].eggSize;
        cout << number*this->eggs[i].eggSize << " ";
    }
    cout << endl;*/
    return 1;
}

bool Basket:: operator / (int number)
{
  /*  int tmp = 1;
    for(int i=0; i<this->getNumber(); i++)
    {
        tmp /= this->eggs[i].eggSize/number;
        cout << this->eggs[i].eggSize/number << " ";
    }
    cout << endl; */
    return 1;
}

bool Basket:: operator /=(int number)
{
    cout<<"Operator '/=': ";
    int tmp = 1;
    for(int i=0; i<this->getNumber(); i++)
    {
        tmp /= this->eggs[i].getEggSize()/number;
        cout << this->eggs[i].getEggSize()/number << " ";
    }
    cout << endl;
    return 1;
}
Basket& Basket::operator % (const Basket&basket)
{
    if(this==&basket)
        return *this;
    cout<<"Operator '% ': ";
    int section = 0;
    for(int i=0;i<this->getNumber();i++)
    {
        for(int p=0;p<basket.getNumber();p++)
        {
            if(!(strcmp(this->eggs[i].getEggName(),basket.eggs[p].getEggName())))
            {
                section++;
                cout << basket.eggs[p].getEggName() << " ";
            }
        }
    }
    cout << "Broqt im e ";
    return *this;
}
Basket& Basket::operator %=(const Basket&basket)
{
    if(this==&basket)
        return *this;
    cout<<"Operator '%=': ";
    int section = 0;
    for(int i=0;i<this->numberOfEggs;i++)
    {
        for(int p=0;p<basket.getNumber();p++)
        {
            if(!(strcmp(this->eggs[i].getEggName(),basket.eggs[p].getEggName())))
            {
                section++;
                cout << basket.eggs[p].getEggName() << " ";
            }
        }
    }
    cout << "Broqt im e " << section << endl;
    return *this;
}

Basket& Basket::operator ==(const Basket&basket)
{
    if(this==&basket)
    return *this;
    cout<<"Operator '==': ";
    if(this->getNumber()!=basket.getNumber())
    {
         cout<<"Koshnicite ne sa ravni"<<endl;
         return *this;
    }
    else
    {
         for(int i=0; i<this->getNumber();i++)
         {
            if(strcmp(this->eggs[i].getEggName(), basket.eggs[i].getEggName()))
            {
                cout <<"Koshnicite ne sa ravni"<<endl;
                return *this;
            }
         }
    }
    cout <<"Koshnicite sa ravni"<<endl;
    return *this;
}

Basket& Basket::operator !=(const Basket&basket)
{
    if(this==&basket)
    return *this;
    cout<<"Operator '!=': ";
    if(this->getNumber()!=basket.getNumber())
    {
         cout<<"Koshnicite ne sa ravni"<<endl;
         return *this;
    }
    else
    {
         for(int i=0; i<this->getNumber();i++)
         {
            if(strcmp(this->eggs[i].getEggName(), basket.eggs[i].getEggName()))
            {
                cout <<"Koshnicite ne sa ravni"<<endl;
                return *this;
            }
         }
    }
    cout <<"Koshnicite  sa ravni"<<endl;
    return *this;
}

bool Basket::operator < (const Basket&basket)
{
    cout<<"Operator '< ': ";
    if(this-> getNumber() < basket.getNumber())
    {
        cout << "Po-malko e" << endl;
        return 1;
    }
    else if(this-> getNumber() > basket.getNumber())
    {
        cout << "Po-golqmo e" << endl;
        return 0;
    }
    else  if(this->getNumber()==basket.getNumber())
    {
        for(int i = 0;i <this->getNumber();i++)
        {
            if(strcmp(this->eggs[i].getEggName(),basket.eggs[i].getEggName()) < 0)
            {
                cout << "Po-malko e" << endl;
                return 1;
            }
            else if(strcmp(this->eggs[i].getEggName(),basket.eggs[i].getEggName()) > 0)
            {
                cout << "Po-golqmo e" << endl;
                return 0;
            }
        }
    }
    cout << "ravni sa" << endl;
    return 0;
}

bool Basket::operator <=(const Basket&basket)
{
    cout<<"Operator '<=': ";
    if(this-> getNumber() < basket.getNumber())
    {
        cout << "Po-malko e" << endl;
        return 1;
    }
    else if(this-> getNumber() > basket.getNumber())
    {
        cout << "Po-golqmo e" << endl;
        return 0;
    }
    else  if(this->getNumber()==basket.getNumber())
    {
        for(int i = 0;i <this->getNumber();i++)
        {
            if(strcmp(this->eggs[i].getEggName(),basket.eggs[i].getEggName()) < 0)
            {
                cout << "Po-malko e" << endl;
                return 1;
            }
            else if(strcmp(this->eggs[i].getEggName(),basket.eggs[i].getEggName()) > 0)
            {
                cout << "Po-golqmo e" << endl;
                return 0;
            }
        }
    }
    cout <<  "ravni sa" << endl;
    return 1;
}

bool Basket::operator >=(const Basket&basket)
{
    cout<<"Operator '>=': ";
    if(this-> getNumber() < basket.getNumber())
    {
        cout << "Po-malko e" << endl;
        return 0;
    }
    else if(this->getNumber()> basket.getNumber())
    {
        cout << "Po-golqmo e" << endl;
        return 1;
    }
    else  if(this->getNumber()==basket.getNumber())
    {
        for(int i = 0;i <this->getNumber();i++)
        {
            if(strcmp(this->eggs[i].getEggName(),basket.eggs[i].getEggName()) < 0)
            {
                cout << "Po-malko e" << endl;
                return 0;
            }
            else if(strcmp(this->eggs[i].getEggName(),basket.eggs[i].getEggName()) > 0)
            {
                cout << "Po-golqmo e" << endl;
                return 1;
            }
        }
    }
    cout <<  "ravni sa" << endl;
    return 1;
}

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
    char* asd;
    char test[] = "Test";
    char baskettest[] = "BasketTest";
    char filetest[] = "test.txt";
    Eggs eg1,eg2,eg3,eg4;
    Basket ba2(baskettest);
    Basket ba1(baskettest);
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
    cout << ba1+ba2 << endl;
    ba1 += ba2;
    ba1+asd;
    //ba1 += asd;
    ba1*4;
    cout<<endl;
    ba1*=4;
    ba1/4;
    ba1/=4;
    ba1%ba2;
    ba1%=ba2;
    ba1==ba2;
    ba1!=ba2;
    ba1 < ba2;
    ba1 <= ba2;
    ba2 >= ba1;
    //cout << ba1.getNumber() << endl;
    ba1.removeEgg(test);
   /* eg1<eg2;    //Sravnqva duljinata na 2 qica
    eg1<=eg2;   //Sravnqva 2 qica leksikografski
    eg1*eg2;    // Umnojava razmera na 2 qica
    cout << eg1.getEggSize()<<endl;
    eg1/eg2;
    cout<<eg1.getEggSize()<<endl;    // Deli razmera na 2 qica
    eg1+eg2;
    cout<<eg1<<endl;    // Konkatenira 2 imena na qica
    --eg1;                  // Pravi vsichki malki bukvi ot qiceto v golemi
    ++eg1;                  // Pravi vsichki golemi bukvi malki
    eg1--;                  // Vrushta bukvite nazad s 1 primer: "abc" => aab
    eg1++;                  // Uvelichava bukvite nazad s 1 primer: "abc" => bcd
    eg1^eg3;      // Vdiga 1to qice na stepen goleminata na drugoto
    cout<< eg1.getEggSize() <<endl;
    */
    cout << "Opisanie za operatorite za qicata sa napisani kato komentari pri primera v main" << endl;
    delete []asd;
    return 0;
}

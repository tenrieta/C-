#include <iostream>
//#include <cstring>
using namespace std;

int strlen(char* str);
void strcpy(char* str, const char* cpy_str);
void strcat(char * dest, char const * src);

class Pages
{
public:
    Pages();
    Pages(const Pages& pg);
    Pages& operator = (const Pages& pg);
//    Pages& operator +(Pages& text);
    ~Pages();
    void setText(char* text);
    char* getText()const;
private:
    char* text;
};

class Processor
{
    public:
        Processor();
        Processor(const Processor& pr);
        Processor& operator +(const Processor& text);//dobavqne na nova transformaciq
        char* operator -(const Processor& pr); // premahvane na transformaciq
        Processor& operator =(const Processor& pr);//ravenstvo na dva niza
        Processor& operator + (char* str);
        //Processor& operator ++(const Processor& pr);//vkliuchvane na transformaciite
        //Processor& operator --(const Processor& pr);//izkluchvane na transformaciite
        ~Processor();
        void setFirstText(char* first_text);
        char* getFirstText()const;
        void setNewText(char* new_text);
        char* getNewText()const;
        void setLimit(int limit);
        int getLimit()const;
        char* createWithStr(char* str);
        char* createForTransformations(char* str);

    private:
        Pages* text;
        char* first_text;
        char* new_text;
        int limit;
};

Pages:: Pages()
{};
Pages :: Pages(const Pages& pg)
{
    this->text = new char[strlen(pg.text)+1];
    strcpy(this->text, pg.text);
};
Pages& Pages:: operator = (const Pages& pg)
{
    if(this==&pg)
    return *this;
    delete [] this->text;
    this->text = new char[strlen(pg.text)+1];
    strcpy(this->text, pg.text);
    return *this;
};

Pages:: ~Pages()
{
    delete this->text;
}

void Pages:: setText(char* text)
{
    this->text = new char[strlen(text)+1];
    strcpy(this->text, text);
}
char* Pages:: getText()const
{
    return this->text;
}

Processor:: Processor()
{};

Processor:: Processor(const Processor& pr)
{
    delete [] this->first_text;
    delete [] this->new_text;
    this->first_text = new char[strlen(pr.first_text)+1];
    strcpy(this->first_text, pr.first_text);
    this->new_text = new char[strlen(pr.new_text)+1];
    strcpy(this->new_text, pr.new_text);
    this->limit= pr.limit;
    delete [] this-> text;
    this->text = new Pages[limit];
    for(int i = 0;i < pr.limit;i++)
    {
        this->text[i] = pr.text[i];
    }
};
Processor& Processor:: operator = (const Processor& pr)
{
    if(this==&pr)
    return *this;
    delete [] this->first_text;
    delete [] this->new_text;
    this->first_text = new char[strlen(pr.first_text)+1];
    strcpy(this->first_text, pr.first_text);
    this->new_text = new char[strlen(pr.new_text)+1];
    strcpy(this->new_text, pr.new_text);
    this->limit= pr.limit;
    delete [] this-> text;
    this->text = new Pages[limit];
    for(int i = 0;i < pr.limit;i++)
    {
        this->text[i] = pr.text[i];
    }
    return *this;
};
Processor& Processor:: operator + (char* str)
{
    int length = strlen(this->new_text);
    char* tmpSting = new char[strlen(this->new_text)];
    strcpy(tmpSting,this->new_text);
    delete [] new_text;
    this->new_text = new char[length + strlen(str)+ 1];
    strcpy(new_text,tmpSting);
    strcat(new_text,str);
    delete [] tmpSting;
    return *this;
}

Processor:: ~Processor()
{
    delete[] first_text;
    delete[] new_text;
}


void Processor:: setFirstText(char* first_text)
{
    int length = strlen(first_text);
    this->first_text = new char[length+1];
    strcpy(this->first_text,first_text);
}
char* Processor:: getFirstText()const
{
    return this->first_text;
}
void Processor:: setNewText(char* new_text)
{
    int length = strlen(new_text);
    this->new_text = new char[length+1];
    strcpy(this->new_text,new_text);
}
char* Processor:: getNewText()const
{
    return  this->new_text;
}

void Processor:: setLimit(int limit)
{
    this->limit += limit;
}

int Processor:: getLimit()const
{
    return this->limit;
}

char* Processor:: createWithStr(char* str)
{

}

char* Processor:: createForTransformations(char* str)
{

}

Processor& Processor:: operator +(const Processor& text)
{
    if(this==&text)
    return *this;
    this->limit++;
    return *this;
}

int strlen(char* str)
{
    int len = 0;
    while(str[len])
    {
        ++len;
    }
    return len;
}

void strcpy(char* str, const char* cpy_str)
{
    int i = 0;
    while(cpy_str[i]!=0)
    {
        str[i] = cpy_str[i];
        i++;
    }
    str='\0';
}
void strcat(char * dest, char const * src)
{
  char * d = dest;
  while (*d++);
  char const * s = src;
  while(*s)
  {
    *d++ = *s++;
  }
  *d = 0;
}

char* Capital(char* str)
{
    int i=0;
    while(str[i]!=0)
    {
      if(str[i]>='a'&& str[i]<='z')
        {
            str[i]-=32;
        }
        i++;
    }
    str[i] = 0;
return str;
}

char* Lowercase(char* str)
{
    int i=0;
    while(str[i]!=0)
    {
        if(str[i]>='A'&& str[i]<='Z')
        {
            str[i]+=32;
        }
        i++;
    }
    str[i] = 0;
return str;
}

char* ChangeSymbol(char* str, char symbol, char new_symbol)
{
    int i = 0;
    while(str[i]!=0)
    {
        if(str[i]==symbol)
        {
            str[i] = new_symbol;
        }
        i++;
    }
return str;
}

char* ChangeSymbols(char* str, char symbol, char new_symbol)
{
    int i = 0;
    while(str[i]!=0)
    {
        while(str[i]==symbol)
        {
            str[i] = new_symbol;
            i++;
        }
        i++;
    }
return str;
}

int main()
{
    char* tmp = new char[256];
    Processor pr;
    char str[120] = "test";
    pr.setFirstText(str);
    cout << pr.getFirstText() << endl;
    tmp = Capital(pr.getFirstText());
    pr.setFirstText(tmp);
    //pr = pr+"asd";
    cout<< pr.getFirstText() << endl;
    cout<<Lowercase(str)<<endl;
    //cout<<ChangeSymbol(str,'a','e')<<endl;
    //cout<< ChangeSymbols(str,'a','e');
    return 0;
    return 0;
}

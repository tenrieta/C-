#include "Book.h"
#include <iostream>
#include <cstring>
using namespace std;

Book::Book()
{
    this->title = NULL;
    this->pages = 0;
}

Book::Book(char* title, int pages):title(NULL)
{
    setTitle(title);
    setPages(pages);
}


Book::Book(const Book& b)
{
    setTitle(b.title);
    setPages(b.pages);
}

Book& Book:: operator = (const Book& b)
{
    //this->title = NULL;
    setTitle(b.title);
    setPages(b.pages);
    return *this;
}


Book::~Book()
{
    delete[] this->title;
}

void Book:: setTitle(char* title)
{
if(this->title!=NULL)
    {
        delete[] this->title;
    }
    this->title = new char[strlen(title)+1];
    strcpy(this->title, title);
}

void Book:: setPages(int pages)
{
    this->pages = pages;
}

bool operator > (const Book& l, const Book& r)
{
    if(strcmp(l.title, r.title)>0)
        return true;
    return false;
}

bool operator < (const Book& l, const Book& r)
{
    if(strcmp(l.title,r.title)!=0)
        return(!(l>r));
    return false;
}

bool operator == (const Book& l, const Book& r)
{
    if(strcmp(l.title,r.title)==0)
        return true;
    return false;
}

bool operator != (const Book& l, const Book& r)
{
    if(!(l==r))
        return true;
    return false;
}
ostream& operator << (ostream& o, const Book& b)
{
    o<<"Title: ";
    for(int i=0; i<strlen(b.title); i++)
    {
        o<<b.title[i];
    }
    o<<", Pages: "<<b.pages;
    return o;
}

istream& operator >> (istream& i, Book& b)
{
    cout<<"Title: ";
    cin.getline(b.title, 256);
    cin>>b.pages;
    return i;
}

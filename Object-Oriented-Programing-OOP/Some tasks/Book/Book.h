#ifndef BOOK_H
#define BOOK_H
#include <iostream>;

class Book
{
    public:
        Book();
        Book(char* title, int pages);
        Book(const Book& b);
        Book& operator =(const Book& b);
        ~Book();
        void setTitle(char* title);
        char* getTitle(){return this->title;}
        void setPages(int pages);
        int getPages(){return this->pages;}
        friend std:: ostream& operator << (std:: ostream& o, const Book& b);
        friend std:: istream& operator >> (std:: istream& i, Book& b);
        friend bool operator > (const Book& l, const Book& r);
        friend bool operator == (const Book& l, const Book& r);
        friend bool operator != (const Book& l, const Book& r);
        friend bool operator < (const Book& l, const Book& r);
    protected:
        char* title;
        int pages;
};

#endif // BOOK_H

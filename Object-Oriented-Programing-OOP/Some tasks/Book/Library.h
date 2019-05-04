#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"

class Library
{
    public:
        Library();
        ~Library();
        void addBook(Book b);
        void removeBook(Book b);
        int getBooks(){return this->books;}
        Book& operator[](int idx);
    protected:
    private:
        Book* arr;
        int books;
};

#endif // LIBRARY_H

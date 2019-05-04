#include "Library.h"

Library::Library()
{
    arr = NULL;
    books = 0;
}

Library::~Library()
{
    delete[] this->arr;
}

void Library:: addBook(Book b)
{
    Book* tmp = new Book[books];
    for(int i =0; i<books; i++)
    {
        tmp[i] = arr[i];
    }
    books++;
    delete[] arr;
    arr = new Book[books];
    for(int i =0; i<books-1; i++)
    {
        arr[i] = tmp[i];
    }
    arr[books-1] = b;
}

void Library:: removeBook(Book b)
{
    Book* tmp = new Book[books-1];
    for(int i=0, j=0; j<books; i++, j++)
    {
        if(arr[j] != b)
        {
            tmp[i] = arr[j];
        }
        else
        {
            i--;
        }
    }
    books--;
    delete[] arr;
    arr = new Book[books];
    for(int i=0; i<books; i++)
    {
        arr[i] = tmp[i];
    }
}

Book& Library:: operator[](int idx)
{
    return this->arr[idx];
}

#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;

int main()
{
    Book b1("Gosho", 10);
    Book b2("Aesho", 5);
    Library l;
    if(b1<b2)
        cout << "Hello can you hear me" << endl;
    l.addBook(b1);
    l.addBook(b2);
    cout<<l.getBooks()<<endl;
    l.removeBook(b1);
    cout<<l.getBooks()<<endl;
    return 0;
}

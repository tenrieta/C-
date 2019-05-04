#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack s;
    int sizze;
    cin>>sizze;
    s.setSize(sizze);
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(3);
    s.pop();
    s.pop();
    s.push(4);
    s.push(5);
    s.push(3);
    s.print();
    return 0;
}

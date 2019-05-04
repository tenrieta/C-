#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue q;
    int s;
    cout<<"Kolko da e goleminata na steka"<<endl;
    cin>>s;
    q.setSize(s);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(6);
    q.print();
    cout<<"Elementi: "<<q.countElem()<<endl;
    q.dequeue();
    q.dequeue();
    q.print();
    cout<<"Elementi: "<<q.countElem()<<endl;
    q.enqueue(5);
    q.print();
    cout<<"Elementi: "<<q.countElem()<<endl;
    return 0;
}

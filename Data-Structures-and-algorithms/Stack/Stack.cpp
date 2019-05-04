#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    sizze = 0;
    arr = new int[sizze];
    top = 0;
}

Stack::~Stack()
{
    delete[] arr;
}

void Stack:: push(int elem)
{
    if(top>=sizze)
    {
        resizze();
    }
    arr[top] = elem;
    top++;

}

int Stack:: pop()
{
    if(top==0)
        cout<<"Nothing to pop"<<endl;
    else
        top--;
}

void Stack:: setSize(int s)
{
    sizze = s;
}

void Stack:: print()
{
    for(int i=0; i<top; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Stack:: resizze()
{
    int* tmpArr = new int[sizze];
    for(int i=0; i<sizze; i++)
    {
        tmpArr[i] = arr[i];
    }
    delete[] arr;
    sizze *= 2;
    arr = new int[sizze];
    for(int i=0; i<sizze; i++)
    {
        arr[i] = tmpArr[i];
    }
    delete[] tmpArr;
}

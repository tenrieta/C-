#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    sizze = 0;
    arr = new int[1];
    head = 0;
    tail = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

void Queue:: enqueue(int elem)
{
    if(sizze < tail-head+1)
    {
        resizze();
    }
    arr[tail] = elem;
    tail++;
}

int Queue:: dequeue()
{
    if(head>tail)
    {
        cout<<"Nothing to dequeue"<<endl;
    }
    else
    {
        head++;
    }
}

void Queue:: resizze()
{
    int* tmpArr = new int[sizze];
    int j = 0;
    for(int i=head; i<tail; i++)
    {
        tmpArr[j] = arr[i];
        j++;
    }
    sizze *= 2;
    delete[] arr;
    arr = new int[sizze];
    for(int i=0; i<j;i++)
    {
        arr[i] = tmpArr[i];
    }
    delete[] tmpArr;
}

void Queue:: print()
{
    for(int i=head; i<tail; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Queue:: setSize(int s)
{
    sizze = s;
}

int Queue:: getSizze()const
{
    return sizze;
}

int Queue:: countElem()
{
    return tail-head;
}

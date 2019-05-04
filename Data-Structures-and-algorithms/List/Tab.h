#ifndef TAB_H
#define TAB_H
#include <iostream>
#include <time.h>

using namespace std;

struct Tab
{
    char* url;
    Tab* prev;
    Tab* next;
    time_t timer;
    Tab(Tab* prev = NULL, Tab* next = NULL, time_t timer = 0)
    :next(next), prev(prev), timer(timer)
    {
        url = new char[256];
    }
};

#endif


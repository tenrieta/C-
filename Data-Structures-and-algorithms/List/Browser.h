#ifndef BROWSER_H
#define BROWSER_H
#include "Tab.h"

class Browser
{
public:
    Browser();
    Browser(const Browser& b);
    Browser& operator = (const Browser& b);
    ~Browser();
    Tab* firstTab();
    Tab* lastTab();
    Tab* nextTab(Tab* t);
    void forwardTab();
    void prevTab();
    void print();
    void addTab(Tab *t);
    void removeTab();
    void deleteTabData(Tab* t);
    void changeDataTab(Tab* t);
    void go(Tab* t);
private:
    Tab* helper;
    Tab* cur;
    Tab* head;
    Tab* activeTab;
    int sizze;
};

#endif

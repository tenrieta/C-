#include "Browser.h"
#include <iostream>
#include <cstring>

Browser:: Browser()
{
    cur = new Tab;
    head = new Tab;
    helper = new Tab;
    helper->url = NULL;
    helper->prev = cur;
    helper->next = head;
    cur->next = helper;
    cur->prev = helper;
    head = cur;
    strcpy(head->url,"about:blank");
    head->timer = time(&head->timer);
    activeTab = cur;
    sizze = 0;
}

Browser:: Browser(const Browser& b)
{
    std::cout<<"Browser cant be copied"<<std::endl;
}

Browser& Browser:: operator = (const Browser& b)
{
    std::cout<<"Browser cant be assigned"<<std::endl;
    return *this;
}

Browser:: ~Browser()
{
    Tab* t;
    Tab* tmp;
    t = firstTab();
    tmp = firstTab();
    while(t!=NULL)
    {
        deleteTabData(t);
        tmp = nextTab(t);
        t = tmp;
    }
    delete helper;
}

Tab* Browser:: firstTab()
{
    return head;
}

Tab* Browser:: lastTab()
{
    return cur;
}

Tab* Browser:: nextTab(Tab* t)
{
    return t->next;
}
void Browser:: forwardTab()
{
    if(activeTab != cur)
        activeTab = activeTab->next;
}
void Browser:: prevTab()
{
    if(activeTab != head)
        activeTab = activeTab->prev;
}


void Browser:: print()
{
    Tab* t = new Tab;
    t = firstTab();
    while(t != helper)
    {
        std::cout<<t->url<<" "<<t->timer<<std::endl;
        t = nextTab(t);
    }
}

void Browser:: addTab(Tab* t)
{
    Tab* tmp = new Tab;
    tmp = t;
    changeDataTab(tmp);
    cur->next = tmp;
    tmp->prev = cur;
    tmp->next = helper;
    cur = tmp;
    activeTab = cur;
}

void Browser:: removeTab()
{
    Tab* tmp;
    if((activeTab == head) && (head == cur))
    {
        strcpy(head->url,"about:blank");
        head->timer = time(&head->timer);
    }
    else
    {
        if((activeTab != cur) && (activeTab != head))
        {
            activeTab->prev->next = activeTab->next;
            activeTab->next->prev = activeTab->prev;
            tmp = activeTab->next;
        }
        else if(activeTab == cur)
        {
            activeTab->prev->next = helper;
            cur = activeTab->prev;
            tmp = activeTab->prev;
        }
        else if(activeTab == head)
        {
            activeTab->next->prev = helper;
            head = activeTab->next;
            tmp = activeTab->next;
        }
        deleteTabData(activeTab);
        activeTab = tmp;
    }
}

void Browser:: deleteTabData(Tab* t)
{
    delete t;
}

void Browser:: changeDataTab(Tab* t)
{
    t->timer = time(&t->timer);
}
void Browser::go(Tab* t)
{
    changeDataTab(activeTab);
    strcpy(activeTab->url,t->url);
}

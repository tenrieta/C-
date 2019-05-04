#include <iostream>
#include <cstring>
#include "Browser.h"

using namespace std;

int main()
{
    char* command = new char[7];
    char* url = new char[256];
    char* input = new char[264];
    int j = 0, i = 0;
    Tab* t;
    Tab* tmp;
    Browser b;
    while(1)
    {
        t = new Tab;
        cin.getline(input, 264);
        cin.clear();
        while(input[i]!=' '&&input[i]!='\0')
        {
            command[j] = input[i];
            i++;
            j++;
        }
        command[j] = '\0';
        j = 0;
        if(input[i]==' ')
        {
            i++;
            while(input[i]!='\0')
            {
                t->url[j] = input[i];
                i++;
                j++;
            }
            t->url[j] = '\0';
        }
        i = 0;
        j = 0;
        if(strcmp("GO",command)==0)
        {
           b.go(t);
        }
        else if(strcmp("INSERT",command)==0)
        {
            b.addTab(t);
        }
        else if(strcmp("BACK",command)==0)
        {
            b.prevTab();
        }
        else if(strcmp("FORWARD",command)==0)
        {
            b.forwardTab();
        }
        else if(strcmp("REMOVE",command)==0)
        {
            b.removeTab();
        }
        else if(strcmp("PRINT",command)==0)
        {
            b.print();
        }
        else if(strcmp("SORT",command)==0)
        {

        }
        else
        {
            cout<<"input error"<<endl;
        }
        command[0] = '\0';
        input[0] = '\0';
    }
    return 0;
}

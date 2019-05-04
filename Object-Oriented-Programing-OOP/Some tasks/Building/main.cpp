#include <iostream>
#include "Building.h"
#include "House.h"

using namespace std;

int main()
{
    House h1;
    House h2;
    h1.setHeight(56);
    h2.setHeight(64);
    House h[h1.count];
    int maxx = 0;
    cout<<h1.count<<endl;
    for(int i=0;i<h1.count/2;i++)
    {
        if(h[i].getHeight()<h[i+1].getHeight())
        {
            maxx = i;
        }
    }
    cout<<h[maxx].getHeight()<<endl;


    return 0;
}

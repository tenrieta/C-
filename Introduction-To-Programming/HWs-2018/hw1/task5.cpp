/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 5
 * @compiler GCC
 *
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x,y,u,v;
    cin>>x>>y;
    cin>>u>>v;
    double X = x + u;
    double Y = y + v;
    double distance = sqrt((X*X)+(Y*Y));
    if(distance<=8)
    {
        if(distance<=3)
        {
            if(distance<=1)
            {
                cout<<"60"<<endl;
            }
            else
            {
                cout<<"20"<<endl;
            }
        }
        else
        {
            cout<<"10"<<endl;
        }
    }
    else
    {
        cout<<"0"<<endl;
    }

    return 0;
}

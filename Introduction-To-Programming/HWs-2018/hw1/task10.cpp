/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 10
 * @compiler GCC
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a1, b1, c1, a2, b2, c2;
    float x, y;
    int a12, b12, c12;
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;
    y = (a1*c2-a2*c1)/(a1*b2-a2*b1);
    x = (c1 - b1*y)/a1;
    if((a1==0)&&(a2==0))
    {
        a12 = 0;
        b12 = 0;
        c12 = 0;
        x = 0;
        y = 0;
    }
    else if(a1>=a2)
    {
        a12 = a1/a2;
        b12 = b1/b2;
        c12 = c1/c2;
    }
    else
    {
        a12 = a2/a1;
        b12 = b2/b1;
        c12 = c2/c1;
    }
    float tmp1 = a1*x + b1*y;
    float tmp2 = a2*x + b2*y;
    if((tmp1!=c1) && (tmp2!=c2))
    {
        cout<<"No solution";
    }
    else if((a12==b12)&&(b12==c12))
    {
        cout<<"Many solutions";
    }
    else
    {
        cout<<setprecision(5)<<x<<" "<<y;
    }

    return 0;
}

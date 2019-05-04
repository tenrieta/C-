/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 8
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

int main()
{
    unsigned int sum;
    unsigned int cnt50 = 0, cnt20 = 0, cnt10 = 0, cnt5 = 0, cnt2 = 0, cnt1 = 0;
    cin>>sum;
    cout<<sum<<" = ";
    if(sum>=50)
    {
        cnt50 = sum/50;
        sum = sum - (cnt50*50);
        cout<<cnt50<<"*50";
        if(sum!=0)
        {
            cout<<" + ";
        }
    }
    if(sum>=20)
    {
        cnt20 = sum/20;
        sum = sum - (cnt20*20);
        cout<<cnt20<<"*20";
        if(sum!=0)
        {
            cout<<" + ";
        }
    }
    if(sum>=10)
    {
        cnt10 = sum/10;
        sum = sum - (cnt10*10);
        cout<<cnt10<<"*10";
        if(sum!=0)
        {
            cout<<" + ";
        }
    }
    if(sum>=5)
    {
        cnt5 = sum/5;
        sum = sum - (cnt5*5);
        cout<<cnt5<<"*5";
        if(sum!=0)
        {
            cout<<" + ";
        }
    }
    if(sum>=2)
    {
        cnt2 = sum/2;
        sum = sum - (cnt2*2);
        cout<<cnt2<<"*2";
        if(sum!=0)
        {
            cout<<" + ";
        }
    }
    if(sum==1)
    {
        cnt1 = sum/1;
        sum = sum - (cnt1*1);
        cout<<cnt1<<"*1";
    }
    if(sum==0)
    {
        return 0;
    }

    return 0;
}

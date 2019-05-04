/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 9
 * @compiler GCC
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int x, y;
    char op;
    int sum;
    cin>>x>>op>>y;
    if(x>=16)
    {
        x = x%16;
    }
    if(y>=16)
    {
        y = y%16;
    }
    switch(op)
    {
    case '+':
        sum = x + y;
        break;
    case '-':
        sum = x - y;
        break;
    case '.':
        sum = x * y;
        break;
    case '/':
        sum = x / y;
        break;
    case '%':
        if((y==0)&&(op=='%'))
        {
            cout<<"Division by zero!"<<endl;
            return 0;
        }
        sum = x % y;
        break;
    default:
        cout<<"Bad input data!"<<endl;
        return 0;
        break;
    }
    if(sum<0)
    {
        sum = 16 + sum;
    }
    if(sum>=16)
    {
        sum = sum % 16;
    }
    cout<<sum<<endl;
    return 0;
}

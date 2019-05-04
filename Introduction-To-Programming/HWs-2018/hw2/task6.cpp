/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 6
 * @compiler GCC
 *
 */

#include <iostream>
using namespace std;

unsigned long long factorial(unsigned long long n)
{
    unsigned long long fact = 1, i = 1;
    while(n!=0)
    {
        fact *= i;
        i++;
        n--;
    }
return fact;
}

int main()
{
    unsigned long  long num, n, k1, k2, idx;
    cin>>num;
    n = factorial(num);
    for(int i=0; i<=num; i++)
    {
        k1 = factorial(i);
        k2 = num - i;
        k2 = factorial(k2);
        if((i == 0) || ((k1*k2) == 0))
        {
            idx = 1;
        }
        else
        {
            idx = n/(k1*k2);
        }

        if(i!=num)
        {
            cout<< idx <<" ";
        }
        else
        {
            cout<< idx <<endl;
        }
    }

    return 0;
}

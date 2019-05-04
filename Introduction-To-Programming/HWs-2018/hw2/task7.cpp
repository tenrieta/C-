/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 7
 * @compiler GCC
 *
 */
#include <iostream>

using namespace std;

int pow(int x, int n)
{
    int sum = 1;
    while(n!=0)
    {
         sum *= x;
         n--;
    }
return sum;
}

int main()
{
    unsigned int n, m, y, x;
    int tmp;
    bool flag1 = 0, flag2 = 0;
    cin>> n >> m >> y;
    if((n <= 0)||(n>=1000001)||(m <= 1)||(m >= 10001)||(y <= 0)||(y >= m))
    {
        return 0;
    }
    for(int x = 1; x < m; x++)
    {
        if(((pow(x,n) - y)% m ) == 0)
        {
            if(flag1)
            {
                cout<<" "<< x;
            }
            else
            {
                cout<< x ;
                flag1 = 1;
            }
            flag2 = 1;
        }
    }
    if(flag2==0)
    {
        tmp = -1;
        cout<< tmp;
    }
    cout<<endl;
    return 0;
}

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
    unsigned long nq, p1, p2, max1 = 0, max2 = 0, i = 0, j = 0, tmp;
    int arr[256];
    unsigned long long n;
    do
    {
        cin>>nq;
    }while((nq<1)&&(nq>=1000000));
    tmp = nq;
    while(nq!=0)
    {
        cin>> p1 >> n >> p2;
        if((p1<=1)||(p1>100000007)||(p2<=1)||(p2>100000007)||(n<0)&&(n>100000007*100000007))
        {
            return 0;
        }
        while(pow(p1,i)<=n)
        {
            if((n%pow(p1,i))== 0)
            {
                max1 = i;
            }
            i++;
        }
        i = 0;
        while(pow(p2,i)<=n)
        {
            if((n%pow(p2,i))==0)
            {
                max2 = i;
            }
            i++;
        }
        if(max1 > max2)
        {
            arr[j] = max1 ;
        }
        else
        {
            arr[j] = max2;
        }
        i = 0;
        max1 = 0;
        max2 = 0;
        j++;
        nq--;
    }
    nq = tmp;
    for(int i = 0; i < nq; i++)
    {
        if(arr[i]==0)
        {
            cout << "infinity" << endl;
        }
        else
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}

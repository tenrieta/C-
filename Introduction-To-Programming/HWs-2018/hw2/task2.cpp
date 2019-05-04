/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 2
 * @compiler GCC
 *
 */
#include <iostream>

using namespace std;

int main()
{
    unsigned long n;
    int cnt = 0;
    int tmp = 1, i = 3;
    do
    {
        cin>> n;
    }while(n>=100000);
    while(n!=0)
    {
        for(int j=i; j>1; j--)
        {
            if((i%j)==0)
            {
                cnt++;
            }
        }
        if(cnt==1)
        {
            if((tmp == i-2) && (i != 3))
            {
                cout << tmp << " " << i <<endl;
                tmp = i;
                n--;
            }
            else
            {
                tmp = i;
            }
        }
        cnt = 0;
        i++;
    }
    return 0;
}


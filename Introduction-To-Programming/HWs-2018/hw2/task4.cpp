/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 4
 * @compiler GCC
 *
 */
#include <iostream>
using namespace std;

int Counter(int a)
{
    int cnt = 0;
    while(a!=0)
    {
        a = a/10;
        cnt++;
    }
return cnt;
}

int main()
{
    int a, b, cntA, cntB, tmpA, tmpB, counter = 0, b1, prev;
    bool flag = 0;
    cin>>a>>b;
    if(a<0)
    {
        a = a - (2*a);
    }
    if(b<0)
    {
        b = b - (2*a);
    }
    cntA = Counter(a);
    cntB = Counter(b);
    tmpA = a;
    tmpB = b;
    prev = b%10;
    for(int i=0; i<cntA; i++)
    {
        tmpA = a%10;
        b1 = b;
        for(int j=0; j<cntB; j++)
        {
            tmpB = b%10;
            if(tmpA==tmpB)
            {
                if(((a/10)%10)==((b/10)%10))
                {
                    if((((a/10)%10)==0)&&(cntA==(i+1)))
                    {
                        flag = false;
                    }
                    else
                    {
                        flag = true;
                    }
                }
                else if(((a/10)%10)==prev)
                {
                    if((((a/10)%10)==0)&&(cntA!=(i+2)))
                    {
                        flag = false;
                    }
                    else
                    {
                       flag = true;
                    }
                }
            }
            b = b/10;
            prev = tmpB;
        }
        a = a/10;
        b = b1;
    }
    if(flag)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }


    return 0;
}

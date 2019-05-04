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
using namespace std;

int counter(int n)
{
    int cnt = 0;
    while(n!=0)
    {
        cnt++;
        n = n/10;
    }
return cnt;
}

void checkSubset(int cnt1, int cnt2, int a, int b)
{
    int tmp1, tmp2, a1, equalCnt = 0, removableCnt = 0;
    for(int i = 0; i < cnt2; i++)
    {
        a1 = a;
        tmp2 = b%10;
        for(int j = 0; j < cnt1; j++)
        {
            tmp1 = a%10;
            if((tmp1==tmp2)&&(removableCnt<=1))
            {
                equalCnt++;
                a = a/10;
                break;
            }
            else
            {
                removableCnt++;
            }
            a = a/10;
            }
            b = b/10;
        }
        if(equalCnt == cnt2)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<< "No" <<endl;
        }
}


int main()
{
    unsigned int a, b, cnt1, cnt2;
    cin>> a >> b;
    cnt1 = counter(a);
    cnt2 = counter(b);
    if((cnt1==(cnt2+1))||((cnt1+1)==cnt2))
    {
        if(cnt1>cnt2)
        {
            checkSubset(cnt1, cnt2, a, b);
        }
        else
        {
            checkSubset(cnt2, cnt1, b, a);
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}

/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 3
 * @compiler GCC
 *
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long a, b, tmp, tmp1, tmp2, cnt2;
    unsigned long cnt = 0, sum = 1, counter = 1;
    bool flag = 0;
    do
    {
        cin>>a>>b;
    }while(((a>=4000000000)&&(a<=1))&&((b<=1)&&(b>=4000000000)));
    tmp = a;
    while(tmp!=0)
    {
        tmp = tmp/10;
        cnt++;
    }
    cnt2 = cnt;
    tmp = a;
    tmp2 = a%10;
    while(cnt2!=0)//proverka za ednakvost
    {
        tmp1 = tmp%(cnt2*10);
        if(tmp1==tmp2)
        {
            counter++;
        }
        cnt2--;
    }
    if(counter==cnt)
    {
        flag = 1;
    }
    tmp = b;
    while(cnt!=0)
    {
        sum *= 10;
        cnt--;
    }
    while(tmp!=0)
    {
        if(flag)
        {
            if((tmp%sum)==a)
            {
                cnt++;
            }
        }
        else if((tmp%sum)==a)
        {
            cnt++;
        }
        tmp = tmp/10;
    }
    cout<<cnt<<endl;
    return 0;
}

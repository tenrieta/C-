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

int countDigits(int n)
{
    int cnt = 0;
    while(n!=0)
    {
        cnt++;
        n = n/10;
    }
return cnt;
}

int biggerNum(int a, int b)
{
    a = countDigits(a);
    b = countDigits(b);
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int addBase(int a, int b, int n)
{
    int tmpA, tmpB, sum = 0, cnt = 1;
    int flag = 0;
    int bigNum = biggerNum(a,b);
    while(bigNum>=0)
    {
        tmpA = a % 10;
        tmpB = b % 10;
        if((tmpA + tmpB + flag) >= n)
        {
            sum += cnt*((tmpA + tmpB + flag) - n);
            flag = 1 ;
        }
        else
        {
            sum += cnt*(tmpA + tmpB + flag);
            flag = 0;
        }
        cnt *= 10;
        a = a/10;
        b = b/10;
        bigNum--;
    }
return sum;
}

void Sum(int a, int b, int n)
{
    int tmpA = a, tmpB = b, sum = 0, cnt = 1, tmp1 = 0, bigNum;
    while(a!=0)
    {
        if((a%10) >= n)
        {
            cout<<"Bad input data!"<<endl;
            return;
        }
        a = a/10;
    }
    while(b!=0)
    {
        if((b%10) >= n)
        {
            cout<<"Bad input data!"<<endl;
            return;
        }
        b = b/10;
    }
    if(n==2)
    {
        bigNum = biggerNum(tmpA, tmpB);
        while(bigNum != 0)
        {
            a = tmpA % 10;
            b = tmpB % 10;
            if( (((a+b+tmp1)==2) && (tmp1 == 1)) || (((a+b+tmp1)==2) && (tmp1 == 0)) )
            {
                sum += 0*cnt;
                tmp1 = 1;
            }
            else if((a+b+tmp1)==3)
            {
                sum += 1*cnt;
                tmp1 = 1;
            }
            else
            {
                sum += (a+b)*cnt;
                tmp1 = 0;
            }
            cnt *= 10;
            tmpA /= 10;
            tmpB /= 10;
            bigNum--;
            if(bigNum == 0)
            {
                sum = sum + cnt;
            }
        }
    }
    else
    {
        sum = addBase(tmpA, tmpB, n);
    }
    cout << sum << endl;
    return;
}

int main()
{
    int a, b, n, tmp;
    do
    {
       cin>>a>>b>>n;
    }while( (a<0) && (b<0) && (a>500000) && (b>500000) );
    Sum(a, b, n);

    return 0;
}

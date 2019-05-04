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
    unsigned long long id;
    int year, month, day, gender;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    cin>>id;
    if((id<1000000000)&&(id>99999999999))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    year = id/(10000*10000);
    month = id/(1000*1000);
    month = month%100;
    day = id/10000;
    day = day%100;
    gender = id%100;
    gender = gender/10;
    a1 = (id/(100000*10000))%10;
    a2 = (id/(100000*1000))%10;
    a3 = (id/(10000*1000))%10;
    a4 = (id/(10000*100))%10;
    a5 = (id/(10000*10))%10;
    a6 = (id/10000)%10;
    a7 = (id/1000)%10;
    a8 = (id/100)%10;
    a9 = (id/10)%10;
    a10 = id%10;
    int sum = a1*2 + a2*4 + a3*8 + a4*5 + a5*10 + a6*9 + a7*7 + a8*3 + a9*6;
    sum = sum % 11;
    if((sum>=10)&&(a10!=0))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((sum<10)&&(sum!=a10))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((month<1)||(month>71))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((day<1)||(day>31))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((day==30)&&(month==1))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((day==30)&&(month<8)&&(month%2!=0))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((day==31)&&(month<8)&&(month%2==0))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((day==31)&&(month>=8)&&(month%2!=0))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((day==30)&&(month>=8)&&(month%2==0))
    {
        cout<<"Bad input data!"<<endl;
        return 0;
    }
    if((month>0)||(month<13))
    {
        if((((year+1900)%4)!=0)&&(((year+1900)%400)!=0))
        {
            if(month==2)
            {
                if(day>28)
                {
                    cout<<"Bad input data!"<<endl;
                    return 0;
                }
            }
        }
        if((day < 10) && (month < 10))
        {
            cout<<"0"<<day<<"."<<"0"<<month<<".19"<<year<<" ";
        }
        else if(month < 10)
        {
            cout<<day<<"."<<"0"<<month<<".19"<<year<<" ";
        }
        else if((month==11)&&(month==12))
        {
            cout<<day<<"."<<month<<".19"<<year<<" ";
        }
        else if(month>12)
        {
            cout<<"Bad input data!"<<endl;
            return 0;
        }
        else if(day < 10)
        {
            cout<<"0"<<day<<"."<<month<<".19"<<year<<" ";
        }
        else
        {
            cout<<day<<"."<<month<<".19"<<year<<" ";
        }
    }
    else if((month>20)||(month<33))
    {
        if((((year+1800)%4)!=0)&&(((year+1800)%400)!=0))
        {
            if(month==22)
            {
                if(day>28)
                {
                    cout<<"Bad input data!"<<endl;
                    return 0;
                }
            }
        }
        if(month>32)
        {
            cout<<"Bad input data!"<<endl;
            return 0;
        }
        cout<<day<<"."<<month<<".18"<<year<<" ";
    }
    else if((month>40)||(month<53))
    {
        if((((year+2000)%4)!=0)&&(((year+2000)%400)!=0))
        {
            if(month==42)
            {
                if(day>28)
                {
                    cout<<"Bad input data!"<<endl;
                    return 0;
                }
            }
        }
        if(month>32)
        {
            cout<<"Bad input data!"<<endl;
            return 0;
        }
        cout<<day<<"."<<month<<".20"<<year<<" ";
    }
    if((gender%2)==0)
    {
        cout<<"M";
    }
    else
    {
        cout<<"F";
    }
    cout<<endl;
    return 0;
}

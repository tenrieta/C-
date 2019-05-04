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
using namespace std;

int main()
{
    unsigned int num;
    cin>>num;
    int mask = 15;
    int num1, num2, num3, num4, num5, num6, num7, num8;
    num1 = num& mask;
    num = num >> 4;
    num2 = num& mask;
    num = num >> 4;
    num3 = num& mask;
    num = num >> 4;
    num4 = num& mask;
    num = num >> 4;
    num5 = num& mask;
    num = num >> 4;
    num6 = num& mask;
    num = num >> 4;
    num7 = num& mask;
    num = num >> 4;
    num8 = num& mask;
    num = num >> 4;
    if(num1==num2)
    {
        if(num2==num3)
        {
            if(num3==num4)
            {
                if(num4==num5)
                {
                    if(num5==num6)
                    {
                        if(num6==num7)
                        {
                           if(num7==num8)
                               cout<<"Yes"<<endl;
                           else if(num8==0)
                               cout<<"Yes"<<endl;
                           else
                           {
                               cout<<"No"<<endl;
                               return 0;
                           }
                        }
                        else if(num7==0)
                        {
                            if(num7==num8)
                            {
                                cout<<"Yes"<<endl;
                            }
                            else
                            {
                                cout<<"No"<<endl;
                            }
                        }
                        else
                        {
                            cout<<"No"<<endl;
                            return 0;
                        }
                    }
                    else if(num6==0)
                    {
                        if((num6==num7)&&(num6==num8))
                        {
                            cout<<"Yes"<<endl;
                        }
                        else
                        {
                            cout<<"No"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"No"<<endl;
                    }
                }
                else if(num5==0)
                {
                    if((num5==num6)&&(num5==num7)&&(num5==num8))
                    {
                        cout<<"Yes"<<endl;
                    }
                    else
                    {
                        cout<<"No"<<endl;
                    }
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
            else if(num4==0)
            {
                if((num4==num5)&&(num4==num6)&&(num4==num7)&&(num4==num8))
                {
                    cout<<"Yes"<<endl;
                }
                else
                {
                    cout<<"No"<<endl;
                }
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else if(num3==0)
        {
            if((num3==num4)&&(num3==num5)&&(num3==num6)&&(num3==num7)&&(num3==num8))
                cout<<"Yes"<<endl;
            else
            {
                cout<<"No"<<endl;
            }
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    else if(num2==0)
    {
        if((num2==num3)&&(num2==num4)&&(num2==num5)&&(num2==num6)&&(num2==num7)&&(num2==num8))
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
 return 0;
}

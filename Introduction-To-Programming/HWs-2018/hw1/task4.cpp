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
#include <cmath>
using namespace std;

int convertX(char X);

int main()
{
    char X, Y, type, kingX, kingY;
    cin>>type;
    if((type!='Q')&&(type!='B')&&(type!='N')&&(type!='R'))
    {
        cout<<"Error";
    }
    cin>>X>>Y;
    if(((X<'a')||(X>'h'))||((Y<'1')||(Y>'8')))
    {
        cout<<"Error"<<endl;
    }
    X = convertX(X);
    cin>>kingX>>kingY;
    if(((kingX<'a')||(kingX>'h'))||((kingY<'1')||(kingY>'8')))
    {
        cout<<"Error"<<endl;
    }
    kingX = convertX(kingX);
    switch(type)
    {
    case 'Q':
        if((X==kingX)&&((Y>kingY)||(Y<kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((Y==kingY)&&((X>kingX)||(X<kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X>kingX)&&(Y>kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X<kingX)&&(Y<kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X<kingX)&&(Y>kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X>kingX)&&(Y<kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        break;
    case 'B':
        if((X>kingX)&&(Y>kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X<kingX)&&(Y<kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X<kingX)&&(Y>kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((X>kingX)&&(Y<kingY)&&(abs(X-kingX)==abs(Y-kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        break;
    case 'N':
        if((X==kingX-1)&&(Y==kingY-2))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX+1)&&(Y==kingY+2))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX+1)&&(Y==kingY+2))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX+1)&&(Y==kingY-2))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX+2)&&(Y==kingY+1))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX-2)&&(Y==kingY+1))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX-2)&&(Y==kingY-1))
        {
            cout<<"Yes"<<endl;
        }
        else if((X==kingX+2)&&(Y==kingY-1))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        break;
    case 'R':
        if((X==kingX)&&((Y>kingY)||(Y<kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else if((Y==kingY)&&((X>kingX)||(X<kingY)))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        break;
    default:
        break;
    }

    return 0;
}

int convertX(char X)
{
    switch(X)
    {
    case 'a':
        X = 1;
        break;
    case 'b':
        X = 2;
        break;
    case 'c':
        X = 3;
        break;
    case 'd':
        X = 4;
        break;
    case 'e':
        X = 5;
        break;
    case 'f':
        X = 6;
        break;
    case 'g':
        X = 7;
        break;
    case 'h':
        X = 8;
        break;
    }
return X;
}

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
#include <cstring>
#include <cmath>
using namespace std;

char* twisted(char* str, int n)
{
    int cnt = 0, pos;
    char* pointer1;
    char* pointer2;
    char* newStr = new char[strlen(str)+1];
    pos = strlen(str) - n;
    pos = abs(pos);
    if(strlen(str)==1)
    {
        pos = 1;
    }
    pointer1 = str;
    pointer2 = newStr;
    if(n<1)
    {
        newStr = "Bad input data!";
        return newStr;
    }
    while(cnt != pos)
    {
        str++;
        cnt++;
    }
    while(*str)
    {
        *newStr = *str;
        newStr++;
        str++;
    }
    cnt = 0;
    str = pointer1 ;
    while(cnt != pos)
    {
        *newStr = *str;
        newStr++;
        str++;
        cnt++;
    }
    *newStr = '\0';
    newStr = pointer2;
return newStr;
}

int main()
{
    char* str = new char[10000];
    int n, cnt = 0, counter = 0,pos;
    bool flag = false;
    char* pointer1;
    char* pointer2;
    char* pointer3;
    char* symbol = new char[10];
    cin.getline(str,10000);
    cin>>n;
    char* newStr = new char[strlen(str)+1];
    newStr = strcpy(newStr,"");
    char* tmpStr = new char[strlen(str)+1];
    pointer1 = tmpStr;
    pointer2 = newStr;
    pointer3 = symbol;
    while(*str)
    {
       if(*str == ' ')
       {
           *tmpStr = '\0';
           tmpStr = pointer1;
           newStr = strcat(newStr, twisted(tmpStr,n));
           if(flag == 1)
           {
               newStr = strcat(newStr, symbol);
               flag = false;
           }
           newStr = strcat(newStr, " ");
           tmpStr = pointer1;
           newStr = pointer2;
           str++;
       }
       else if((*str >= '!')&& (*str <= '?'))
       {
           if(*str == '-')
           {
               *tmpStr = *str;
               flag = false;
               str++;
               tmpStr++;
           }
           else
           {
                *symbol = *str;
                symbol++;
                *symbol = '\0';
                symbol = pointer3;
                flag = true;
                str++;
           }
       }
       else
       {
           *tmpStr = *str;
           tmpStr++;
           str++;
       }
    }
    *tmpStr = '\0';
    tmpStr = pointer1;
    newStr = strcat(newStr,twisted(tmpStr, n));
    if(flag == true)
    {
        newStr = strcat(newStr, symbol);
    }
    newStr = pointer2;
    cout<<newStr<<endl;
    delete[] newStr;
    delete[] tmpStr;
    delete[] symbol;
    return 0;
}

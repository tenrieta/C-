/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 5
 * @compiler GCC
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int pow(int num, int power)
{
    int sum = 1;
    while(power > 0)
    {
        sum *= num;
        power--;
    }
return sum;
}

unsigned long long convertNumber(unsigned long long number,int type)
{
    int power = 0;
    unsigned long long converted = 0, n;
    if(type == 2)
    {
        while(number!=0)
        {
            n = number % 10;
            converted += pow(2,power)*n;
            power++;
            number = number/10;
        }
    }
    else if(type == 8)
    {
        while(number!=0)
        {
            n = number % 10;
            converted += pow(8,power)*n;
            power++;
            number = number/10;
        }
    }
    else if(type == 10)
    {
        converted += number;
    }
return converted;
}

int main()
{
    char* str = new char[1000];
    char* newStr = new char[1000];
    unsigned long long number = 0;
    unsigned long long sum = 0;
    int flag = 0, cntLength = 0;
    int i = 0, j = 0, k = 0;
    cin.getline(str,1000);
    while(str[i]!=0)
    {
        if((str[i] == '0')&&(flag == 0))
        {
            if(str[i+1] == 'b')
            {
                while((str[i+2] != ' ')&&(str[i+2]!='\0'))
                {
                    newStr[j] = str[i+2];
                    j++;
                    i++;
                }
                newStr[j] = '\0';
                number = atoll(newStr);
                sum += convertNumber(number, 2);
                number =  0;
            }
            else if(str[i+1] == 'x')
            {
                k = i;
                while((str[i+2] != ' ')&&(str[i+2]!='\0'))
                {
                    cntLength++;
                    i++;
                }
                i = k;
                while((str[i+2] != ' ')&&(str[i+2]!='\0'))
                {
                    if(str[i+2]=='A')
                    {
                        newStr[j] = '1';
                        newStr[j+1] = '0';
                        newStr[j+2] = '\0';
                        j++;
                    }
                    else if(str[i+2]=='B')
                    {
                        newStr[j] = '1';
                        newStr[j+1] = '1';
                        newStr[j+2] = '\0';
                        j++;
                    }
                    else if(str[i+2]=='C')
                    {
                        newStr[j] = '1';
                        newStr[j+1] = '2';
                        newStr[j+2] = '\0';
                        j++;
                    }
                    else if(str[i+2]=='D')
                    {
                        newStr[j] = '1';
                        newStr[j+1] = '3';
                        newStr[j+2] = '\0';
                        j++;
                    }
                    else if(str[i+2]=='E')
                    {
                        newStr[j] = '1';
                        newStr[j+1] = '4';
                        newStr[j+2] = '\0';
                        j++;
                    }
                    else if(str[i+2]=='F')
                    {
                        newStr[j] = '1';
                        newStr[j+1] = '5';
                        newStr[j+2] = '\0';
                        j++;
                    }
                    else
                    {
                        newStr[j] = str[i+2];
                        newStr[j+1] = '\0';
                    }
                    number += atoll(newStr)* pow(16,cntLength-1);
                    cntLength--;
                    j = 0;
                    i++;
                }
                newStr[j] = '\0';
                sum += number;
                number = 0;
            }
            else if((str[i+1] != '\0')&&(str[i+1] != ' '))
            {
                while((str[i+1] != ' ')&&(str[i+1]!='\0'))
                {
                    newStr[j] = str[i+1];
                    j++;
                    i++;
                }
                newStr[j] = '\0';
                number = atoll(newStr);
                sum += convertNumber(number, 8);
                number = 0;
            }
            else
            {
                sum += 0;
            }
            flag = 1;
        }
        else if(flag==0)
        {
            while((str[i] != ' ')&&(str[i]!='\0'))
                {
                    newStr[j] = str[i];
                    j++;
                    i++;
                }
            newStr[j] = '\0';
            number = atoll(newStr);
            sum += convertNumber(number, 10);
            flag = 1;
        }
        if(str[i] == ' ')
        {
            if((str[i+1] == '+') && (str[i+2] == ' '))
            {
                i = i + 2;
                flag = 0;
            }
            j = 0;
        }
        i++;
    }
    cout<<sum<<endl;
    delete[] str;
    delete[] newStr;

    return 0;
}

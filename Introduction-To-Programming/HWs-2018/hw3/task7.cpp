/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 7
 * @compiler GCC
 *
 */
#include <iostream>
#include <cstring>

using namespace std;

bool isUpper(char symbol)
{
    if((symbol>='A') && (symbol<='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char* str = new char[10000];
    char* newStr = new char[10000];
    int i = 0, j = 0, flag = 0, check = 0, tmp, first;
    cin.getline(str, 10000);
    while(str[i] != 0)
    {
        first = i;
        if((str[i]=='a') || (str[i]=='o') || (str[i]=='u') || (str[i]=='e') || (str[i]=='i') || (str[i]=='A') || (str[i]=='O') || (str[i]=='U') || (str[i]=='E') || (str[i]=='I'))
        {
            flag = 1;
        }
        else
        {
            if((str[i+1]=='a') || (str[i+1]=='o') || (str[i+1]=='u') || (str[i+1]=='e') || (str[i+1]=='i'))
            {
                flag = 2;
                i = i + 1;
            }
            else if((str[i+1]=='A') || (str[i+1]=='O') || (str[i+1]=='U') || (str[i+1]=='E') || (str[i+1]=='I'))
            {
                flag = 2;
                i = i + 1;
            }
            else
            {
                flag = 3;
                i = i + 2;
            }
            if(isUpper(str[i]))
            {
                check = 1;
            }
            if(isUpper(str[i+1]))
            {
                check = 2;
            }
        }
        tmp = check;
        while((str[i]!=' ') && (str[i]!=0))
        {
            if(check == 1)
            {
                newStr[j] = str[i] - 0x20;
                check = 0;
            }
            else
            {
                newStr[j] = str[i];
            }
            i++;
            j++;
        }
        check = tmp;
        tmp = i;
        i = first;
        if(flag == 1)
        {
            newStr[j] = '\0';
            if(check == 2)
            {
                newStr = strcat(newStr, "WAY");
            }
            else
            {
                newStr = strcat(newStr, "way");
            }
        }
        else if(flag == 2)
        {
            if(check == 1)
            {
                newStr[j] = str[i] + 0x20;
            }
            else
            {
                newStr[j] = str[i];
            }
            newStr[j+1] = '\0';
            if(check == 2)
            {
                newStr = strcat(newStr, "AY");
            }
            else
            {
                newStr = strcat(newStr, "ay");
            }
        }
        else if(flag == 3)
        {
            if(check == 1)
            {
                newStr[j] = str[i] - 0x20;
                newStr[j+1] = str[i+1];
            }
            else
            {
                newStr[j] = str[i];
                newStr[j+1] = str[i+1];
            }
            newStr[j+2] = '\0';
            if(check == 2)
            {
                newStr = strcat(newStr, "AY");
            }
            else
            {
                newStr = strcat(newStr, "ay");
            }
        }
        i = tmp;
        j = strlen(newStr);
        if(str[i] == ' ')
        {
            newStr[j] = ' ';
            j++;
            i++;
        }
    }
    cout<< newStr <<endl;
    delete[] str;
    delete[] newStr;
    return 0;
}

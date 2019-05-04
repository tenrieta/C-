/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 1
 * @compiler GCC
 *
 */
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

char* sequence(int n, char* num, char* str, int cnt = 3)
{
    if(n == 1)
    {
        char* tmpN = new char[2];
        strcpy(tmpN,"1");
        return tmpN;
    }
    else if(n == 2)
    {
        return num;
    }
    else if(cnt== n)
    {
        char* tmpN = new char[strlen(str)+1];
        itoa(n,tmpN,10);
        char* tmpStr = new char[2*strlen(str)+1];
        strcpy(tmpStr, str);
        //strcpy(tmpStr, num);
        strcat(tmpStr,tmpN);
        strcat(tmpStr,str);
        return tmpStr;
    }
    else
    {
        char* tmpCnt = new char[strlen(str)+1];
        char* tmpStr = new char[strlen(str)+1];
        char* tmpStr2 = new char[strlen(str)+1];
        itoa(cnt, tmpCnt, 10);
        strcpy(tmpStr, str);
        strcpy(tmpStr2, tmpStr);
        strcat(tmpStr, tmpCnt);
        strcat(tmpStr,tmpStr2);
        return sequence(n,num, tmpStr, cnt+1);

    }
}

int main()
{
    int current;
    cin>>current;
    if((current<1)||(current>20))
    {
        cout<<"Bad input data!"<<endl;
    }
    else
    {
        cout<< sequence(current,"121","121", 3) << endl;
    }
    return 0;
}

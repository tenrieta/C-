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

using namespace std ;

int main()
{
    int n;
    int j = 0;
    cin>> n;
    if((n<=0)||(n>=100000))
    {
        cout<<"Bad input data"<< endl;
    }
    int* num = new int[n];
    int* newNum = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
    }
    for(int i=0; i<n; i++)
    {
        if((num[i] % 3) == 0)
        {
            newNum[j] = num[i];
            j++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if((num[i] % 3) == 1)
        {
            newNum[j] = num[i];
            j++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(((num[i] % 3) != 1) && ((num[i] % 3) !=0))
        {
            newNum[j] = num[i];
            j++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(i!=(n-1))
        {
            cout << newNum[i] <<" ";
        }
        else
        {
            cout << newNum[i] << endl;
        }
    }


    delete[] num;
    delete[] newNum;
    return 0;
}

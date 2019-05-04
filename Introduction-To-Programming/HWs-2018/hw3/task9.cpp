/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 9
 * @compiler GCC
 *
 */
#include <iostream>

using namespace std;

int main()
{
    unsigned int n;
    do
    {
        cin >> n;
    }while(n>=100000);
    unsigned int* value = new unsigned int[n];
    unsigned long* minutes = new unsigned long[n];
    unsigned long* megabytes = new unsigned long[n];
    unsigned long* smses = new unsigned long[n];
    unsigned long minute, megabyte, sms;
    int* index = new int[n];
    int flag = 0, flag2 = 0, j = 0, idx = 0, idx2 = 0, m = 0, k = 0;
    unsigned int tmp, tmp1, tmp2, tmp3;
    for(int i=0; i<n; i++)
    {
         cin >> value[i] >> minutes[i] >> megabytes[i] >> smses[i];
         if(value[i]>1000)
         {
             cout<<"Bad input data!"<<endl;
         }
         if(minutes[i]>100000)
         {
             cout<<"Bad input data!"<<endl;
         }
         if(megabytes[i]>100000)
         {
             cout<<"Bad input data!"<<endl;
         }
         if(smses[i]>100000)
         {
             cout<<"Bad input data!"<<endl;
         }
    }
    cin >> minute >> megabyte >> sms;
    for(int i = 0; i< n ; i++)
    {
        if(minutes[i] >= minute)
        {
            if(megabytes[i] >= megabyte)
            {
                if(smses[i] >= sms)
                {
                    flag = 1;
                    flag2 = 2;
                }
            }
        }
        if(flag)
        {
            index[j] = i;
            j++;
            flag = 0;
        }
    }
    while(idx!=j)
    {
        m = index[idx];
        idx2 = idx + 1;
        while(idx2<j)
        {
            k = index[idx2];
            if(value[m]>value[k])
            {
              tmp = index[idx2];
              index[idx2] = index[idx];
              index[idx] = tmp;
            }
            idx2++;
        }
        idx++;
    }
    idx = 0;
    int i;
    if(flag2 == 2)
    {
        while(idx != j)
        {
            i = index[idx];
            cout<< value[i] <<" "<< minutes[i] << " "<< megabytes[i] <<" "<<smses[i] << endl;
            idx++;
        }
    }
    else
    {
        cout<<"No solution"<<endl;
    }

    delete[] value;
    delete[] minutes;
    delete[] megabytes;
    delete[] smses;
    delete[] index;

    return 0;
}

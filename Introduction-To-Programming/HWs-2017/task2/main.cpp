#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0, tmpSum = 0;
    bool flag = true;
    cin>>n;
    int tmp = n*n;
    int arr[tmp];
    for(int i=0; i<tmp; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    for(int i=n; i<tmp; i++)//redove
    {
        for(int j=0; j<n; j++)
        {
            tmpSum += arr[j];
        }
        if(sum != tmpSum)
        {
            flag = false;
        }
        i+=n-1;
    }
    for(int i=0; i<tmp; i++)//koloni
    {
        for(int j=0; j<tmp; j++)
        {
            tmpSum += arr[j];
            j+=n-1;
        }
        if(sum != tmpSum)
        {
            flag = false;
        }
    }
    for(int i=0; i<tmp; i++)//purvi diagonal
    {
        tmpSum += arr[i];
        if(sum != tmpSum)
        {
            flag = false;
        }
        i+=n;
    }
    for(int i=0; i<n*n; i++)//vtori diagonal
    {
        tmpSum += arr[i];
        if(sum != tmpSum)
        {
            flag = false;
        }
        i+=n-1;
    }
    if(flag == true)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    return 0;
}

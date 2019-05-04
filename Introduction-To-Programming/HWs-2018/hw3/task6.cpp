/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Teya Andreeva
 * @idnumber 45168
 * @task 6
 * @compiler GCC
 *
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned int n;
    cin>>n;
    unsigned long* fn = new unsigned long[n];
    unsigned int* number = new unsigned int[n];
    double* points = new double[n];
    unsigned int* index = new unsigned int[n];
    unsigned long tmp;
    unsigned int k = 0, idx;
    for(int i = 0; i<n; i++)
    {
        index[i] = i;
    }
    for(int i=0; i<n; i++)
    {
        cin>>fn[i]>>number[i]>>points[i];
        if((fn[i]<1)||(fn[i]>1000000))
        {
            cout << "Bad input data!" << endl;
        }
        if((number[i]<1)||(number[i]>10))
        {
            cout << "Bad input data!" << endl;
        }
        if((points[i]<0)&&(points[i]>2))
        {
            cout << "Bad input data!" << endl;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(fn[i] > fn[j])
            {
                tmp = index[j];
                index[j] = index[i];
                index[i] = tmp;
            }
            else if(fn[i] == fn[j])
            {
                if(number[i] > number[j])
                {
                    tmp = index[j];
                    index[j] = index[i];
                    index[i] = tmp;
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        cout<< fn[index[i]] << " "<< number[index[i]] << " "<< setprecision(2)<< points[index[i]] <<endl;
    }
    delete[] fn;
    delete[] number;
    delete[] points;
    delete[] index;
    return 0;
}

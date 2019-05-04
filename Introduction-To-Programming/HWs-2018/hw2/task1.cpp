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
#include <cmath>
#include <iomanip>

using namespace std;

double Dist(float* x, float* y, int i)
{
    double distance = 0;
    double length = 0;
    distance = sqrt((abs(x[i]-x[i+1]))*(abs(x[i]-x[i+1]))+(abs(y[i]-y[i+1])*(abs(y[i]-y[i+1]))));
    length = ((3.14*distance)/2 + distance)/2;
return length;
}

int main()
{
    unsigned int requests;
    int rX1 = 5, rY1 = -2, rX2 = -5, rY2 = 2;
    int flagX = 0, flagY = 0;
    double distance, length = 0, tmpX, tmpY;
    do
    {
        cin>>requests;
    }while((requests<1)&&(requests>=2000000000));
    float x[requests], y[requests];
    for(int i = 0; i < requests; i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i = 0; i < requests-1; i++)
    {
        if(((x[i]<=rX1)&&(x[i]>=rX2)&&(y[i]>=rY1)&&(y[i]<=rY2))&&((x[i+1]<=rX1)&&(x[i+1]>=rX2)&&(y[i+1]>=rY1)&&(y[i+1]<=rY2)))
        {
            length += Dist(x, y, i);
        }
        else if(((x[i]<=rX1)&&(x[i]>=rX2)&&(y[i]>=rY1)&&(y[i]<=rY2))&&(!((x[i+1]<=rX1)&&(x[i+1]>=rX2)&&(y[i+1]>=rY1)&&(y[i+1]<=rY2))))
        {
            if(x[i+1]>rX1)
            {
                 tmpX = x[i+1];
                 flagX = 1;
                 x[i+1] = rX1;
            }
            else if(x[i+1]<rX2)
            {
                 tmpX = x[i+1];
                 flagX = 1;
                 x[i+1] = rX2;
            }
            if(y[i+1]<rY1)
            {
                 tmpY = y[i+1];
                 flagY = 2;
                 y[i+1] = rY1;
            }
            else if(y[i+1]>rY2)
            {
                 tmpY = y[i+1];
                 flagY = 2;
                 y[i+1] = rY2;
            }
            length += Dist(x, y, i);
            if(flagX == 1)
            {
                x[i+1] = tmpX;
                flagX = 0;
            }
            if(flagY == 2)
            {
                y[i+1] = tmpY;
                flagY = 0;
            }
        }
        else if(!((x[i]<=rX1)&&(x[i]>=rX2)&&(y[i]>=rY1)&&(y[i]<=rY2))&&(!((x[i+1]<=rX1)&&(x[i+1]>=rX2)&&(y[i+1]>=rY1)&&(y[i+1]<=rY2))))
        {
            length += 0;
        }
        else if((!((x[i]<=rX1)&&(x[i]>=rX2)&&(y[i]>=rY1)&&(y[i]<=rY2)))&&((x[i+1]<=rX1)&&(x[i+1]>=rX2)&&(y[i+1]>=rY1)&&(y[i+1]<=rY2)))
        {
            if(x[i]>rX1)
            {
                 tmpX = x[i];
                 flagX = 1;
                 x[i] = rX1;
            }
            else if(x[i]<rX2)
            {
                 tmpX = x[i];
                 flagX = 1;
                 x[i] = rX2;
            }
            if(y[i]<rY1)
            {
                 tmpY = y[i];
                 flagY = 2;
                 y[i] = rY1;
            }
            else if(y[i]>rY2)
            {
                 tmpY = y[i];
                 flagY = 2;
                 y[i] = rY2;
            }
            length += Dist(x, y, i);
            if(flagX == 1)
            {
                x[i] = tmpX;
                flagX = 0;
            }
            if(flagY == 2)
            {
                y[i] = tmpY;
                flagY = 0;
            }
        }
    }
    cout<<fixed<<setprecision(3)<<length<<endl;
    return 0;
}

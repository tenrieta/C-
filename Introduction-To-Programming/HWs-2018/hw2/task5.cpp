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
#include <iomanip>
using namespace std;

int main()
{
    unsigned int values;
    double time, speed0 = 0, speed1 = 0, sum = 0;
    cin>>values>>time;
    double value[values];
    for(int i = 0; i<values; i++)
    {
        cin>>value[i];
    }
    for(int i = 0; i<values; i++)
    {
        speed1 = speed0 + time*value[i];
        if(speed1<0)
        {
            speed1 = 0;
        }
        sum += speed0*time + 0.5*(time*time)*value[i];
        speed0 = speed1;
    }
    cout<<fixed<<setprecision(5)<<sum<<endl;

    return 0;
}

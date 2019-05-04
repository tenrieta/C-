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
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    cin>>x>>y;
    double distance1 = sqrt (x*x + y*y);
    double distance2 = sqrt (x*x + (y-3)*(y-3));
    double distance3 = sqrt (x*x + (y+3)*(y+3));
    double distance4 = sqrt (x*x + (y-1)*(y-1));
    double distance5 = sqrt (x*x + (y+1)*(y+1));
    if(distance1<=6)
    {
        if(distance2<=3)
        {
            if(distance4<=1)
            {
                if((x>=-1)&&(x<=0)&&(y>2)&&(y<4))
                {
                    cout<<"Evil"<<endl;
                }
                else if((x>-1)&&(x<0)&&(y>=2)&&(y<=4))
                {
                    cout<<"Evil"<<endl;
                }
                else if((x>=0)&&(x<=1)&&(y>2)&&(y<4))
                {
                    cout<<"Evil"<<endl;
                }
                else if((x>0)&&(x<1)&&(y>=2)&&(y<=4))
                {
                    cout<<"Evil"<<endl;
                }
                else
                {
                    cout<<"Neutral"<<endl;
                }
            }
            else if((x>=0)&&(x<=3)&&(y>0)&&(y<3))
            {
                cout<<"Good"<<endl;
            }
            else if((x>0)&&(x<3)&&(y>=0)&&(y<=3))
            {
                cout<<"Good"<<endl;
            }
            else if((x>=-3)&&(x<=0)&&(y>0)&&(y<3))
            {
                cout<<"Good"<<endl;
            }
            else if((x>-3)&&(x<0)&&(y>=0)&&(y<=3))
            {
                cout<<"Good"<<endl;
            }
            else
            {
                cout<<"Neutral"<<endl;
            }
        }
        else if(distance2<=3)
        {
            if(distance5<=1)
            {
                if((x>=-1)&&(x<=0)&&(y>-4)&&(y<-2))
                {
                   cout<<"Good"<<endl;
                }
                else if((x>-1)&&(x<0)&&(y>=-4)&&(y<=-2))
                {
                   cout<<"Good"<<endl;
                }
                else if((x>=0)&&(x<=1)&&(y>-4)&&(y<-2))
                {
                   cout<<"Good"<<endl;
                }
                else if((x>0)&&(x<1)&&(y>=-4)&&(y<=-2))
                {
                   cout<<"Good"<<endl;
                }
                else
                {
                    cout<<"Neutral"<<endl;
                }
            }
            else if((x>=-3)&&(x<=0)&&(y>-3)&&(y<0))
            {
                cout<<"Evil"<<endl;
            }
            else if((x>-3)&&(x<0)&&(y>=-3)&&(y<=0))
            {
                cout<<"Evil"<<endl;
            }
            else if((x>=0)&&(x<=3)&&(y<0)&&(y>-3))
            {
               cout<<"Evil"<<endl;
            }
            else if((x>0)&&(x<3)&&(y<=0)&&(y>=-3))
            {
               cout<<"Evil"<<endl;
            }
            else
            {
                cout<<"Neutral"<<endl;
            }
        }
        else if((x>=-6)&&(x<=0)&&(y>0)&&(y<6))
        {
            cout<<"Good"<<endl;
        }
         else if((x>-6)&&(x<0)&&(y>=0)&&(y<=6))
        {
            cout<<"Good"<<endl;
        }
        else if((x>=0)&&(x<=6)&&(y>0)&&(y<6))
        {
            cout<<"Evil"<<endl;
        }
        else if((x>0)&&(x<6)&&(y>=0)&&(y<=6))
        {
            cout<<"Evil"<<endl;
        }
        else if((x>=-6)&&(x<=0)&&(y>-6)&&(y<0))
        {
            cout<<"Good"<<endl;
        }
        else if((x>-6)&&(x<0)&&(y>=-6)&&(y<=0))
        {
            cout<<"Good"<<endl;
        }
        else if((x>=0)&&(x<=6)&&(y>-6)&&(y<0))
        {
            cout<<"Evil"<<endl;
        }
        else
        {
            cout<<"Neutral"<<endl;
        }
    }
    else
    {
        cout<<"Neutral"<<endl;
    }
    return 0;
}

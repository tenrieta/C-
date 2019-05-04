#include <iostream>

using namespace std;
int main()
{
     unsigned long long num;
     int x,y,z, cnt = 0;
     bool flag = true;
     do
     {
        cin>> num;
     }while(num>=1000000000);
     if(num==0)
          cout<<"yes"<<endl;
     if(num==1)
     {
         cin>>x;
         if(x>=1000000)
            cout<<"nevalidni danni"<<endl;
         else
            cout<<"yes"<<endl;
     }
     if(num==2)
     {
         cin>>x;
         cin>>y;
         if(x>=1000000||y>=1000000)
             cout<<"nevalidni danni"<<endl;
         else
             cout<<"yes"<<endl;
     }
     else
     {
         cin>>x;
         cin>>y;
         for(int i=2; i<num;i++)
         {
                cin>>z;
                if(x>=1000000|| y>=1000000 || z>=1000000)
                    flag = false;
                if(x<y&&z<y)
                     cnt++;
                else if(x>y&&z>y)
                     cnt++;
                 x = y;
                 y = z;

         }
         if(flag == false)
            cout<<"nevalidni danni"<<endl;
         if(cnt == num-2)
              cout<<"yes"<<endl;
         else
              cout<<"no"<<endl;
     }


return 0;
}

#include <iostream>

using namespace std;

int main()
{
    unsigned int num, tmp, cnt = 0, counter = 0, tmpi = 0;
    cin>>num;
    tmp = num;
    while(tmp!=0)
    {
        tmp /= 10;
        cnt++;
    }
    if(cnt>9)
    {
        cout<<"Chisloto e s poveche ot 9 cifri"<<endl;
    }
    for(int i=0; i<32; i++)
    {
        if((num>>i)&1 == 1)
        {
            cnt=i;
        }
    }
    if(cnt!=0)
        cnt+=1;
    for(int i = 0; i<cnt; i++)
    {
        counter = 0;
        if(((num>>i)&1) == 1)
        {
            while(((num>>i)&1) == 1)
            {
                counter++;
                i++;
            }
            i = i - counter;
            if(counter%2 != 0)
            {
                i +=1;
            }
            while(counter>=i)
            {
                num = num&~(1<<i);
                i += 2;
            }
        }
        else
        {
            do
            {
                counter++;
                i++;
            }while(((num>>i)&1)==0);
            i = i-counter;
            if(counter%2 != 0)
            {
                i +=1;
            }
            while(counter>i)
            {
                num = num|(1<<i);
                i += 2;
            }
        }
        i-=1;
    }
    cout<<num<<endl;
return 0;
}

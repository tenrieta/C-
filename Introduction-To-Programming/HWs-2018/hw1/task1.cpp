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
using namespace std;

int main()
{
    unsigned int n, tmp;
    cin>>n;
    if(n>3000)
    {
        cout<<"Invalid number!"<<endl;
        return 0;
    }
    if(n==3000)
    {
        cout<<"MMM";
    }
    if((n>1999)&&(n<3000))
    {
         cout<<"MM";
         n = n%1000;
    }
    if((n>999)&&(n<2000))
    {
        cout<<"M";
        n = n%1000;
    }
    if((n>899)&&(n<1000))
    {
         cout<<"CM";
         n = n%100;
    }
    if((n>799)&&(n<900))
    {
         cout<<"DCCC";
         n = n%100;
    }
    if((n>699)&&(n<800))
    {
         cout<<"DCC";
         n = n%100;
    }
    if((n>599)&&(n<700))
    {
         cout<<"DC";
         n = n%100;
    }
    if((n>499)&&(n<600))
    {
         cout<<"D";
         n = n%100;
    }
    if((n>399)&&(n<500))
    {
         cout<<"CD";
         n = n%100;
    }
    if((n>299)&&(n<400))
    {
        cout<<"CCC";
        n = n%100;
    }
    if((n>199)&&(n<300))
    {
         cout<<"CC";
         n = n%100;
    }
    if((n>99)&&(n<200))
    {
         cout<<"C";
         n = n%100;
    }
    if((n>89)&&(n<100))
    {
        cout<<"XC";
    }
    if((n>79)&&(n<90))
    {
        cout<<"LXXX";
    }
    if((n>69)&&(n<80))
    {
        cout<<"LXX";
    }
    if((n>59)&&(n<70))
    {
        cout<<"LX";
    }
    if((n>49)&&(n<60))
    {
        cout<<"L";
    }
    if((n>39)&&(n<50))
    {
        cout<<"XL";
    }
    if((n>29)&&(n<40))
    {
        cout<<"XXX";
    }
    if((n>19)&&(n<30))
    {
        cout<<"XX";
    }
    if((n>9)&&(n<20))
    {
        cout<<"X";
    }
    n = n%10;
    switch(n)
    {
    case 1:
        cout<<"I";
        break;
    case 2:
        cout<<"II";
        break;
    case 3:
        cout<<"III";
        break;
    case 4:
        cout<<"IV";
        break;
    case 5:
        cout<<"V";
        break;
    case 6:
        cout<<"VI";
        break;
    case 7:
        cout<<"VII";
        break;
    case 8:
        cout<<"VIII";
        break;
    case 9:
        cout<<"IX";
        break;
    default:
        break;
    }

    return 0;
}

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
using namespace std;

int main()
{
    int a1, b1, h1, w1;
    int a2, b2, h2, w2;
    cin>>a1>>b1>>h1>>w1;
    cin>>a2>>b2>>h2>>w2;
    int c1, d1, s1, t1, u1, v1;
    int c2, d2, s2, t2, u2, v2;
    int nh, nw, sum;
    c1 = a1;
    d1 = h1 + b1;
    s1 = a1 + w1;
    t1 = d1;
    u1 = s1;
    v1 = b1;
    c2 = a2;
    d2 = h2 + b2;
    s2 = a2 + w2;
    t2 = d2;
    u2 = s2;
    v2 = b2;
   if((b2>=b1)&&(b2<=d1)&&(s2>=c1)&&(s2<=s1))
   {
       nw = s2 - c1;
       nh = t1 - v2;
       sum = nw * nh;
   }
   else
   {
       sum = 0;
   }
   cout<<sum<<endl;

return 0;
}

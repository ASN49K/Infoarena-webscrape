#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);



   int a,b,d,t,i;

   cin>>t;
   for(i=1;i<=t;i++)
   {
       cin>>a>>b;
       if (a-b>=0)
       {
        d=b;
       }
       else
       {
           d=a;
       }
       while (1)
       {
          if (a%d==0 and b%d==0)
          {
            break;
          }
          else
          {
            d--;
          }
       }
       cout<<d<<"\n";
   }
}

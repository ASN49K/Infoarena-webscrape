#include <iostream>

using namespace std;
int T,i,a,b;
int main()
{int d;
   cin>>T;
   for (i=1;i<=T;i++)
   {
       cin>>a>>b;

       while (b!=0)
       {
           d=b;
           b=a%b;
           a=d;

       }
       cout<<a<<" ";
   }
}

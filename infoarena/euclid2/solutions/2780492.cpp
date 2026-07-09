#include <iostream>
#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
  if (a==0) return b;
  if (b==0) return a;
  if (b<a) swap(a,b);
  /// a<=b

  /// a=3
  /// b=100
  return cmmdc(a,b%a);
}



int main()
{
   freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);

   int a,b,t,i;

   cin>>t;
   for(i=1;i<=t;i++)
   {
       cin>>a>>b;
       cout<<cmmdc(a,b)<<"\n";
   }
}

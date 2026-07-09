#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   freopen("euclid2.in","r",stdin);
   freopen("euclid2.out","w",stdout);
   int _;
   cin>>_;
   for(int __=0;__<_;__++)
   {
      int a,b;
      cin>>a>>b;
      int c;
      while(b!=0)
      {
	 c=a;
	 a=b;
	 b=c%b;
      }
      cout<<a<<"\n";
   }
   return 0;
}

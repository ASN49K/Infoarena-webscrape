#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   long long a,b,r,n;
   f>>n;
   for (int i=0;i<n;i++)
   {
     f>>a>>b;
     r=a%b;
     if (!r) g<<min(a,b)<<'\n';
     else
     {
         while (r)
         {
            r=a%b;
            a=b;
            b=r;
         }
         g<<a<<'\n';
     }

   }

}

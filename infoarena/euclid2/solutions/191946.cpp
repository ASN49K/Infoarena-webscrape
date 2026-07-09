#include <fstream.h>
int main()
{
   long t,a,b,r,i;

   ifstream f("euclid2.in");
   ofstream g("euclid2.out");
   f>>t;
   for (i=1; i<=t; i++)
   {
     f>>a>>b;
     while (b!=0)
     {
       r=a%b;
       a=b;
       b=r;
       };
     g<<a<<endl;
     };
   f.close();
   g.close();
   }

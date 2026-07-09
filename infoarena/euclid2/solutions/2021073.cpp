#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,c,t,i;
int main()
{
   f>>t;
   for(i=0;i<t;i++)
   {
       f>>a>>b;
     while(a%b)
     {
         c=a%b;
         a=b;
         b=c;
     }
  g<<b<<'\n';
   }
}

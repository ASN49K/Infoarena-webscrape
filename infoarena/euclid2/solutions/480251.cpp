#include<fstream.h>

int main()
{

int T,a,b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

f>>T;

for(int i=1;i<=T;i++)
   {
   f>>a>>b;

   while(a!=b && a!=0 && b!=0)
      {
      if(a>b)
      	a=a%b;
      else                       
         b=b%a;
      }

   if(a!=0)
      g<<a<<"\n";
   else
   	g<<b<<"\n";
   }

return 0;
}

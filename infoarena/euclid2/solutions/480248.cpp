#include<fstream.h>
#include<conio.h>

int main()
{

int T,a,b;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

f>>T;

for(int i=1;i<=T;i++)
   {
   f>>a>>b;

   while(a!=b)
      {
      if(a>b)
      	a=a/b;
      if(b>a)
         b=b/a;
      }                                                   

   g<<a<<"\n";
   }

return 0;
}

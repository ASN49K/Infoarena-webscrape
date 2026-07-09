#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
long t,a,b,i,r;
f>>t;
for(i=1;i<=t;i++)
 {
 f>>a>>b;
 r=a%b;
   while(r!=0)
    {
     a=b;
     b=r;
     r=a%b;
    }
 g<<b<<"\n";
 }
return 0;
}


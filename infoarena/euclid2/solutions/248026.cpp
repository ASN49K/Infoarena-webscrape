#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{long int a,b,r,z,d,i;
f>>d;
for(i=1;i<=d;i++)
{f>>a>>b;
r=a%b;
z=r;
while(r!=0)
      {r=b%z;
      b=z;
      z=r;}
g<<b<<"\n";}
return 0;
}

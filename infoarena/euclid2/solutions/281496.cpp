#include<fstream.h>
#include<iostream.h>
#include<math.h>

int main()
{

unsigned long j,min,a,b,T,i,max;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for(i=1;i<=T;i++)
{f>>a>>b;
if(a>b)max=a;else max=b;
if(max==a)min=b;else min=b;
while(min!=0)
{
j=max%min;
max=min;
min=j;
}
g<<max<<"\n";
}

g.close();
f.close();
return 0;
}
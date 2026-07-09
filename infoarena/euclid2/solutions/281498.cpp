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

while(b!=0)
{
j=a%b;
a=b;
b=j;
}
if(b==0)g<<a<<"\n";
}

g.close();
f.close();
return 0;
}
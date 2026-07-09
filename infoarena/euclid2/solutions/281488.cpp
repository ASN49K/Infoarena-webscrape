#include<fstream.h>
#include<iostream.h>

int main()
{

unsigned long a,b,T,i;
ifstream f("euclid2.in");
f>>T;
ofstream g("euclid2.out");
for(i=1;i<=T-1;i++)
{f>>a>>b;
while(a!=b)if(a>b)a=a-b;else b=b-a;

g<<a<<endl;
}
f>>a>>b;
while(a!=b)if(a>b)a=a-b;else b=b-a;

g<<a;

g.close();
f.close();
return 0;
}
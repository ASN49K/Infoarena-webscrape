#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long i,n,a,b;
int main()
{f>>n;
i=0;
while (i<n)
{i++;
f>>a>>b;
while (a!=b)
{if (a>b)
a=a-b;
else
b=b-a;}
g<<a;
g<<endl;}
f.close();
g.close();
return 0;}
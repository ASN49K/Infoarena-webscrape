#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long i,n,a,b;
int main()
{f>>n;
for (i=1;i<=n;i++)
{f>>a>>b;
while (a!=b)
if (a>b)
a=a-b;
else
b=b-a;
if (b==1)
g<<0<<'\n';
else
g<<b<<'\n';}
f.close();
g.close();
return 0;}
#include <fstream.h>
int x,i;
long a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main ()
{ f>>x;
for(i=1;i<=x;i++)
{
f>>a>>b;
r=a%b;
while(r!=0) a=b,b=r,r=a%b;
g<<b<<'\n';
}
f.close();
g.close();
return 0;
}

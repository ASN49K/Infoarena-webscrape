#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long t,i,a,b;
int euc   (int a, int b)
{
if(!b)
return a;
else
return euc(b, b%a);
}
int main()
{
f>>t;
for(i=1;i<=t;i++)
{
f>>a>>b;
g<<euc(a,b);
}
f.close();
g.close();
return 0;
}

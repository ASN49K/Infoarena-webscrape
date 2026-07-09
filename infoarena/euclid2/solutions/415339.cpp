#include<fstream>
using namespace std;
long n,i,x,y;
long cmmdc(long x, long y)
{
if(x>y)
return cmmdc(x-y,y);
if(y>x)
return cmmdc(x,y-x);
else
return x;
}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
{
f>>x>>y;
g<<cmmdc(x,y)<<"\n";
}
return 0;
}
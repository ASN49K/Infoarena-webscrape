#include<fstream>
using namespace std;
int t,i,a,b;
int cmmdc(int x,int y)
{if ((!x)||(!y)) return x+y;
if (x>y) return cmmdc(y,x%y); return cmmdc(x,y%x);
}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for (i=1;i<=t;i++)
{
f>>a>>b;
g<<cmmdc(a,b)<<"\n";
}
return 0;
}

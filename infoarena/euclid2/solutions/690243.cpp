#include <fstream>
using namespace std;
int a,b,c,i,t,r;
int cmmdc(int a,int b)
{
int r;
while(b)
{
r=a%b;
a=b;
b=a;
}
return a;
}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
for(i=1;i<=t;i++)
{
f>>a>>b;
g<<cmmdc(a,b)<<"\n";
}
}


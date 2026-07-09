#include <iostream>
#include <fstream>
using namespace std;
long t,i,x,y,rez;
int cmmdc(int a,int b)
{
int r;
while (b!=0)
{
r=a%b;
a=b;
b=r;
}
return a;
}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for (i=1;i<=t;i++)
{
f>>x>>y;
rez=cmmdc(x,y);
g<<rez<<"\n";
}
f.close();
g.close();}
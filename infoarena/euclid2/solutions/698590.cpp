#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i;
 
void citire()
{
f>>a;
f>>b;
}
int cmmdc(int x,int y)
{
while(x!=y)
{
if(x>y) x=x-y;
else y=y-x;
}
return x;
}
int main()
{
f>>n;
for(i=1;i<=n;i++)
{
citire();
g<<cmmdc(a,b)<<'\n';
}
f.close();
g.close();
return 0;
}
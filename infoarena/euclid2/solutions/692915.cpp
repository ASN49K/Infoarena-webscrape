#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
unsigned int a,b,t,i;
f>>t;
for(i=1;i<=t;i++)
{
f>>a>>b;
while(a!=b)
{
if(a>b)
a-=b;
else b-=a;
}
g<<b<<endl;
}
}

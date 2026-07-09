#include<fstream>
using namespace std;
long n,i,a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
f>>n;
for(i=1;i<=n;i++)
{
f>>a>>b;
r=a%b;
while(r!=0)
{
a=b;
b=r;
r=a%b;	
}
g<<b<<"\n";
}
f.close();
g.close();
return 0;	
}

#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long t,a,b,i;

int cmmdc(long a,long b)
{
if(b==0)
return a;
return cmmdc(b,a%b);
}
int main()
{
f>>t;
for(i=t;t>=1;t--)
	{
	f>>a>>b;
	g<<cmmdc(a,b)<<'\n';
	}
return 0;
}

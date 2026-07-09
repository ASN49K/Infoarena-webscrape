#include<fstream.h>
#include<string.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long t,a,b;
int euclid(long a,long b)
{
if(b==0)
	return a;
return euclid(b,a%b);
}
int main()
{
f>>t;
for(;t>0;t--)
	{
	f>>a>>b;
	g<<euclid(a,b)<<'\n';

	}
g.close();
return 0;
}
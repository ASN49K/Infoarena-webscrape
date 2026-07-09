#include<fstream.h>
long n,x,y,i;
long euclid(long a, long b)
	{
	while(b)
		{
		long s=a%b;
		a=b;b=s;
		}
	return a;
	}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=0;i<n;i++)
	{
	f>>x>>y;
	g<<euclid(x,y)<<'\n';
	}
return 0;
}

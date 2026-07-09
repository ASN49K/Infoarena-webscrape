#include<fstream.h>
long n,x,y,i;
int euclid(long a, long b)
	{
	while(b!=0)
		{
		if(a>b)a=a-b;
		else b=b-a;
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

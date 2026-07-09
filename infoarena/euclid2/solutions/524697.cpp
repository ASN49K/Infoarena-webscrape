#include<iostream.h>
#include<fstream.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
	int t,a,b,p,i,r;
	f>>t;
	for (i=1;i<=t;i++)
	{
		f>>a>>b;
		if (a<2) return 0;
		if (b<2) return 0;
		if (a>=2000000000) return 0;
		if (b>=2000000000) return 0;
		r=a%b;
		while (r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<endl;
	}
	return 0;
}

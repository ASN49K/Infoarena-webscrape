#include<iostream.h>
#include<fstream.h>

long long a, b, t;

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long long i, r;
	f>>t;
	for(i=1; i<=t; i++)
	{
		f>>a>>b;
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<endl;
	}
	return 0;
}
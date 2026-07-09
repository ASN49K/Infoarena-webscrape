#include<iostream.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a, b, t;

int main()
{
	int i, r;
	f>>t;
	for(i=1;i<=t;i++)
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
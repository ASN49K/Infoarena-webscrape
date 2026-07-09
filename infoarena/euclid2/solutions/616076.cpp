#include<iostream.h>
#include<fstream.h>

int a, b, t;

int main()
{
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
	int i, r;
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
		g<<b<<'\n';
	}
	return 0;
}
#include<fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main ()
{
	long a,b,c,t,i;
	f>>t;
	for (i=1; i<=t; i++)
	{
		f>>a>>b;
		while(b)
		{
			c=a%b;
			a=b;
			b=c;
		}
		g<<a;
		if (i<t) g<<"\n";
	}
	return 0;
}
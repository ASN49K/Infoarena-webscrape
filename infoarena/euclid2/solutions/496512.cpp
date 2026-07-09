#include <fstream.h>
long long a,b,rest,T,i;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for (i=0;i<T;i++)
	{
		f>>a>>b;
		rest=a%b;
		while (rest!=0)
		{
			a=b;
			b=rest;
			rest=a % b;
		}
		g<<b<<'\n';
	}
	f.close();
	g.close();
	return 0;
}

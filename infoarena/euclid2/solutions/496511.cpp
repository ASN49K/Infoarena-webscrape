#include <iostream.h>
#include <fstream.h>
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long a,b,rest,T,i;
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
	g<<b<<endl;;
	}
	f.close();
	g.close();
	return 0;
}
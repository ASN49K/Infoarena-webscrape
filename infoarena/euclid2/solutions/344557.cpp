#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
	if (a > b)
		cmmdc(b,a);
	if (a==b) return a;

	int r=a%b;
	while (r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

void Euclid()
{
	fstream f("euclid2.in", ios::in);
	fstream g("euclid2.out", ios::out);
	int n, i, a, b;
	f>>n;
	for (i=1; i<=n; ++i)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
	g.close();
}

int main()
{
	Euclid();
	return 0;
}
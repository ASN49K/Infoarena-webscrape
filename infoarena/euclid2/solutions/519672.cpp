#include<fstream>
using namespace std;
fstream f("euclid2.in", ios::in), g("euclid2.out", ios::out);
long long x, y, i, n;
int euclid(long long a, long long b)
{
	long long rest;
	while(b>0)
	{
		rest=a%b;
		a=b;
		b=rest;
	}
	return a;
}
int main()
{
	f>>n;
	for(i=1; i<=n; i++)
	{
		f>>x>>y;
		g<<euclid(x, y)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
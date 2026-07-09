#include <fstream>
using namespace std;

long cmmdc (long a, long b)
{
	long r=b;
	while (r)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	long x,y,t,i;
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	f>>t;
	for (i=0;i<t;++i)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<endl;
	}
	g.close();
}

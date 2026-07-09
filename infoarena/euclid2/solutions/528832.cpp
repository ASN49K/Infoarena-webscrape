#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

long euclid (long a,long b)
	{
	if (b==0) return a;
	return (b,a%b);
	}

int main ()
	{
	long a,b,x;
	f>>x;
	for (int i=0; i<x; i++)
		{
		f>>a>>b;
		g<<euclid(a,b)<<'\n';
		}
	g.close();
	return 0;
	}
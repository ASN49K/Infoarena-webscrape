#include <iostream.h>
#include <fstream.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,n,i;
int main ()
{
	f>>n;
	for (i=1;i<=n;i++)
	{
		f>>a>>b;
		while (b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<'\n';
	}
}
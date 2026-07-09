#include <fstream>
using namespace std;

int main ()
{
	int n, a, b, i, r;
	ifstream f("euclid2.in");
	ofstream g("euclid.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		while(b>=1)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<'\n';
	}
	return 0;
}

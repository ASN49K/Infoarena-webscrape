#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
	int n,a,b,r;
	f>>n;
	while(n--)
	{
		f>>a>>b;
		for(r=a%b;r;r=a%b)
		{
			a=b;
			b=r;
		}
		g<<b<<'\n';
	}
	return 0;
}

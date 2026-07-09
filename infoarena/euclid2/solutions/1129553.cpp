#include <fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n,a,b, r;
	f>>n;
	while(n)
	{
		f>>a>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<'\n';
		n--;
	}
	f.close();
	g.close();
	return 0;
}
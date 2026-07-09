#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a, b, t;
int main()
{
	
	f >> t;
	for (int i = 1; i <= t; i++)
	{
		f >> a >> b;
		int r = a % b;
		while (r)
		{
			a = b;
			b = r;
			r = a % b;

		}
		g << b<<"\n";
	}
}
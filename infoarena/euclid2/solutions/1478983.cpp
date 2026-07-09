// Galatan Tudor - Ion Luca High School
// Husi, Romania, Su, August 30, 2015

#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int n, a, b;

int gcd (int x, int y)
{
	int r=0;
	while (y)
	{
		r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main ()
{
	in >> n;
	for (i=1; i<=n; i++)
	{
		in >> a >> b;
		out << gcd (a, b) << "\n";
	}
	return 0;
}
// Galatan Tudor - Ion Luca Theoretical High School
// Husi, Romania, Th, August 28, 2015

#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T, i, a, b;

int gcd (int x, int y)
{
	int r;
	r = 0;
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
	in >> T;
	for (i=1; i<=T; i++)
	{
		in >> a >> b;
		out << gcd (a, b) << "\n";
	}
	return 0;
}
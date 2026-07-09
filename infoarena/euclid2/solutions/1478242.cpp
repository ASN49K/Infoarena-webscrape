// Galatan Tudor - Liceul Teoretic "Ion Luca"
// Vatra Dornei, 28.08.2015

#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T, i, a, b;

int cmmdc (int x, int y)
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
	f >> T;
	for (i=1; i<=T; i++)
	{
		in >> a >> b;
		out << cmmdc (a, b) << "\n";
	}
	return 0;
}
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
	int r;
	while (true)
	{
		r = a % b;
		if (r == 0)
			return b;
		a = b;
		b = r;
	}
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t, a, b;

	f >> t;
	for (int i = 1; i <= t; i++)
	{
		f >> a >> b;
		g << gcd(a, b) << "\n";
	}
	return 0;
}
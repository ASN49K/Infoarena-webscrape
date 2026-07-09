#include <fstream>
using namespace std;
int eud(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a & 1)
	{
		if (b & 1)
		{
			if (a > b)
				return eud(a - b, b);
			return eud(a, b - a);
		}
		else return eud(a, b >> 1);
	}
	else
	{
		if (b & 1)
			return eud(a >> 1, b);
		return eud(a >> 1, b >> 1) << 1;
	}
}

int main()
{
	int x, y, n;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> x >> y;
		g << eud(x, y) << "\n";
	}
	return 0;
}
#include <fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int n, k, x, y;

int main()
{
	f >> n;
	for (; n; n--)
	{
		f >> k >> x;
		k--;
		for (; k; k--)
			f >> y,
			x ^= y;
		g << (x ? "DA\n" : "NU\n");
	}
	return 0;
}
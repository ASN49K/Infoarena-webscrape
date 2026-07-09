#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T;
int cmmdc(int a, int b)
{
	int r = a % b;

	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int main()
{
	int a, b, i;
	f >> T;

	for (i = 1; i <= T; i++)
	{
		f >> a >> b;
		g << cmmdc(a, b) << "\n";
	}

	return 0;
}





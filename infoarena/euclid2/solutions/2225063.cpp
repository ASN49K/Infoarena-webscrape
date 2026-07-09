#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T;

int gcd(int a, int b) {

	if (!b) return a;
	return gcd(b, a % b);

}

int main()
{
	int a, b, i;
	f >> T;

	for (i = 1; i <= T; i++)
	{
		f >> a >> b;
		g << gcd(a, b) << "\n";
	}

	return 0;
}





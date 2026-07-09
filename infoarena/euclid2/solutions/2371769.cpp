#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
	int a, b, n, r;

	f >> n;
	for (int i = 1; i <= n; i++) {
		f >> a >> b;
		if (a < b) {
			r = a;
			a = b;
			b = r;
		}
		while (b) {
			r = a % b;
			a = b;
			b = r;
		}
		g << a << endl;
	}
}

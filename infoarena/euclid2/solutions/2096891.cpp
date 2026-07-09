#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, x, y;

int euclid2(int a, int b)
{
	if (!b) return a;
	return euclid2(b, a%b);
}

int main()
{
	f >> t;
	while (t) {
		f >> x >> y;
		g << euclid2(x, y) << '\n';
		t--;
	}
	f.close();
	g.close();
    return 0;
}

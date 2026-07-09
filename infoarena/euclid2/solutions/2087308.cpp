#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
	if (!b) return a;
	return cmmdc(b, a%b);
}
int n, a, b;
int main()
{
	f >> n;
	for (; n; --n)
	{
		f >> a >> b;
		g << cmmdc(a, b) << '\n';
	}
	f.close(); g.close();
}


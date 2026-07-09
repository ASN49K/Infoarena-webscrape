#include <fstream>
using namespace std;
int Euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return Euclid(b, a % b);
}
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	int a, b, n;
	ifstream g("euclid2.in");
	ofstream f("euclid2.out");
	g >> n;
	for (int i = 0; i < n; i++)
	{
		g >> a >> b;
		f << Euclid(a, b) << "\n";
	}
}
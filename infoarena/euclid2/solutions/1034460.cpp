#include <fstream>
using namespace std;
int main()
{
	fstream f("euclid2.in", ios::in);
	fstream g("euclid2.out", ios::out);
	int n, a, b, i, r;
	f >> n;
	for (i = 1; i <= n; i++)
	{
		f >> a >> b;
		while (a%b!=0)
		{
			r = a%b;
			a = b;
			b = r;

		}
		g << b << endl;
	}
	f.close();
	g.close();
	return 0;
}


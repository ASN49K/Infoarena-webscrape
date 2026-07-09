#include<fstream>

using namespace std;

int t, a, b, r;

int main()
{
	ifstream f("euclid2.in");
	ofstream h("euclid2.out");
	f >> t;
	for (int i = 1; i <= t; ++i)
	{
		f >> a >> b;
		while (b%a!=0)
		{
			r = b%a;
			b = a;
			a = r;
		}
		h << a << '\n';
	}
}

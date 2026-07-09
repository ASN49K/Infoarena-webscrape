#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	int T, a, b;
	f >> T;
	for (int i = 1; i <= T; ++i)
	{
		f >> a >> b;
		r = a % b;
		while (r)
		{
			a = b;
			b = r;
			r = a % b;
		}
		g <<  b << endl;
	}
	f.close();
	g.close();
	return 0;
}
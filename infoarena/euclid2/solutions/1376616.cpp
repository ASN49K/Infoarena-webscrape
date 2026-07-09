#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f;
ofstream g;
int main()
{
	int T, a, b, i;
	f.open("euclid2.in");
	f >> T;
	g.open("euclid2.out");
	for (i = 1; i <= T; i++)
	{
		f >> a >> b;
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		g << a << endl;
	}
	g.close();
	f.close();
	return 0;
}
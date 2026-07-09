#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int x, int y)
{
	if (y == 0)
		return x;
	else
		return euclid(y, x%y);
}
int main()
{
	int T;
	int x, y;
	f >> T;
	for (int i = 1; i <= T; ++i)
	{
		f >> x >> y;
		if (x < y)
			g << euclid(x, y) << endl;
		else
			g << euclid(y, x) << endl;
	}
	f.close();
	g.close();
	return 0;
}
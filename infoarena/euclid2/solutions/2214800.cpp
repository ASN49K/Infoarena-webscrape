#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long euclid(long long x,long long y)
{
	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}
int main()
{
	int T;
	long long x, y;
	f >> T;
	for (int i = 1; i <= T; ++i)
	{
		f >> x >> y;
		g << euclid(x, y) << endl;
	}
	return 0;
}
#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long euclid(long long x,long long y)
{
	int aux;
	if (x < y)
	{
		aux = x;
		x = y;
		y = aux;
	}
	while (y!=0)
	{
		aux = x % y;
		x = y;
		y = aux;
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
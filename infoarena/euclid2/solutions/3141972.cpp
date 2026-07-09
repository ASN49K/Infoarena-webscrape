#include <iostream>
#include <fstream>
#define euclid2.in test.in
#define euclid2.out test.out

using namespace std;

ifstream f("test.in");
ofstream g("test.out");

int cmmdc(int a, int b)
{
	int r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{

	int n, i;
	f >> n;
	for (i = 1; i <= n; i++)
	{
		int a, b;
		f >> a >> b;
		g << cmmdc(a, b) << "\n";
	}
	f.close();
	g.close();
	return 0;
}


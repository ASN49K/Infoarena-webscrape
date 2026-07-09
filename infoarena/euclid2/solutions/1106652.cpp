
#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
	while (a != b)
	if (a>b)
		a = a - b;
	else b = b - a;
	return a;
}
int main()
{
	int n, i, a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> n;
	for (i = 0; i < n; i++)
	{
		f >> a; f >> b;
		g << cmmdc(a, b);
		g << endl;
	}
}


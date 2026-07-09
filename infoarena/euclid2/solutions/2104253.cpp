#include<fstream>
#include<iostream>
using namespace std;

int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n = 0;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		int x1 = 0, x2 = 0;
		f >> x1 >> x2;
		g << gcd(x1, x2) << '\n';
	}
	f.close();
	g.close();
	return 0;
}